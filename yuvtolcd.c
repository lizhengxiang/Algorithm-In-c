#include <linux/videodev2.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/fb.h>

#define YCbCrtoR(Y,Cb,Cr) (1000000*Y + 1370705*(Cr-128))/1000000
#define YCbCrtoG(Y,Cb,Cr) (1000000*Y - 337633*(Cb-128) - 698001*(Cr-128))/1000000
#define YCbCrtoB(Y,Cb,Cr) (1000000*Y + 1732446*(Cb-128))/1000000

typedef unsigned long  u32;
typedef unsigned short u16;
typedef unsigned char  u8;

u32 Conv_YCbCr_Rgb(u8 y0, u8 y1, u8 cb0, u8 cr0)
{
	// bit order is
	// YCbCr = [Cr0 Y1 Cb0 Y0] ---> RGB=[R1,G1,B1,R0,G0,B0].

	int r0, g0, b0, r1, g1, b1;
	u16 rgb0, rgb1;
	u32 rgb;

	r0 = YCbCrtoR(y0, cb0, cr0);
	g0 = YCbCrtoG(y0, cb0, cr0);
	b0 = YCbCrtoB(y0, cb0, cr0);
	r1 = YCbCrtoR(y1, cb0, cr0);
	g1 = YCbCrtoG(y1, cb0, cr0);
	b1 = YCbCrtoB(y1, cb0, cr0);

	if (r0 > 255) r0 = 255;
	if (r0 < 0  ) r0 = 0;
	if (g0 > 255) g0 = 255;
	if (g0 < 0  ) g0 = 0;
	if (b0 > 255) b0 = 255;
	if (b0 < 0  ) b0 = 0;

	if (r1 > 255) r1 = 255;
	if (r1 < 0  ) r1 = 0;
	if (g1 > 255) g1 = 255;
	if (g1 < 0  ) g1 = 0;
	if (b1 > 255) b1 = 255;
	if (b1 < 0  ) b1 = 0;

	// 5:6:5 16bit format
	rgb0 = (((u16)r0>>3)<<11) | (((u16)g0>>2)<<5) | (((u16)b0>>3)<<0);
	rgb1 = (((u16)r1>>3)<<11) | (((u16)g1>>2)<<5) | (((u16)b1>>3)<<0);

	rgb = (rgb1<<16) | rgb0;

	return(rgb);
}

typedef struct VideoBuffer{
	u8 *start;
	size_t length;
}VIDEOBUF;

int main(int argv, char **argc)
{
	/*open fb device*/
	int fb = open("/dev/fb0", O_RDWR);
	if (fb < 0) {
		printf("Error: cannot open framebuffer device.\n");
		exit(1);
	}

	/* Get variable screen information */
	struct fb_var_screeninfo vinfo;
	if (ioctl(fb, FBIOGET_VSCREENINFO, &vinfo)) {
		printf("Error reading variable information.\n");
		exit(3);
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	printf("%dx%d, %dbpp\n", vinfo.xres, vinfo.yres, vinfo.bits_per_pixel);

	// Figure out the size of the screen in bytes
	u32 screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;
	// Map the device to memory
	u8 *fbp = \
			(u8 *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fb, 0);
	if (NULL == fbp) {
		printf("Error: failed to map framebuffer device to memory.\n");
		exit(4);
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	printf("The framebuffer device was mapped to memory[%lubytes] successfully.\n", screensize);

	/* open video device */
	int vfd = open("/dev/video0",O_RDWR);
	if(vfd < 0){
		perror("open");
		exit(1);
	}

	/* enum video type */
	struct v4l2_fmtdesc fmtd;
	memset(&fmtd, 0, sizeof(fmtd));
	fmtd.index = 0;
	fmtd.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	while (ioctl(vfd, VIDIOC_ENUM_FMT, &fmtd) == 0) {
		fmtd.index++;
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		printf("{ pixelformat = ''%c%c%c%c'', description = ''%s'' }\n",
			fmtd.pixelformat & 0xFF, (fmtd.pixelformat >> 8) & 0xFF,
			(fmtd.pixelformat >> 16) & 0xFF, (fmtd.pixelformat >> 24) & 0xFF,
			fmtd.description);
	}
	struct v4l2_format v4l2_fmt;  
	ioctl(vfd, VIDIOC_G_FMT, &v4l2_fmt);
	printf("w=%d - h=%d - sizeimage=%d\n", v4l2_fmt.fmt.pix.width, \
				v4l2_fmt.fmt.pix.height,\
				v4l2_fmt.fmt.pix.sizeimage);

	/* set video format*/
	//struct v4l2_format v4l2_fmt;  
	v4l2_fmt.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;  
	v4l2_fmt.fmt.pix.width = vinfo.yres;  
	v4l2_fmt.fmt.pix.height= vinfo.xres;  
//	v4l2_fmt.fmt.pix.pixelformat = V4L2_PIX_FMT_YUYV;  
	v4l2_fmt.fmt.pix.pixelformat = fmtd.pixelformat;
	v4l2_fmt.fmt.pix.field       = V4L2_FIELD_INTERLACED;  
	ioctl(vfd, VIDIOC_S_FMT, &v4l2_fmt);

	/* mmap buffer*/
	struct v4l2_requestbuffers  v4l2_reqbuf;
	memset(&v4l2_reqbuf, 0, sizeof(struct v4l2_requestbuffers));
 	v4l2_reqbuf.count = 4;
	v4l2_reqbuf.type  = V4L2_BUF_TYPE_VIDEO_CAPTURE;  
	v4l2_reqbuf.memory= V4L2_MEMORY_MMAP;
 	ioctl(vfd, VIDIOC_REQBUFS, &v4l2_reqbuf);

	VIDEOBUF *map_buf = calloc(v4l2_reqbuf.count,sizeof(VIDEOBUF));

	struct v4l2_buffer v4l2_buf;  
	int i=0;
	for(i = 0;i < v4l2_reqbuf.count; i++)
	{
		memset(&v4l2_buf, 0, sizeof(struct v4l2_buffer));
		v4l2_buf.type  = V4L2_BUF_TYPE_VIDEO_CAPTURE;  
		v4l2_buf.memory= V4L2_MEMORY_MMAP;  
		v4l2_buf.index = i;
	
		if(ioctl(vfd, VIDIOC_QUERYBUF, &v4l2_buf)== -1)
			return -1;

		map_buf[i].length=v4l2_buf.length;
		map_buf[i].start = \
			(char *) mmap(NULL,v4l2_buf.length,PROT_READ | PROT_WRITE,MAP_SHARED,
                   	   vfd, v4l2_buf.m.offset);
		if(map_buf[i].start == MAP_FAILED){
			return -1;
		}		
		ioctl(vfd, VIDIOC_QBUF, &v4l2_buf);
	}

	/* start to sample*/
	enum v4l2_buf_type v4l2_type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
	ioctl(vfd, VIDIOC_STREAMON, &v4l2_type);

	fd_set rfds;
	struct timeval ts;
	ts.tv_sec =2;
	ts.tv_usec=0;
	FD_ZERO(&rfds);
	FD_SET(vfd,&rfds);

	while(1)
	{ 
		int ret = select(vfd+1, &rfds, NULL, NULL, &ts);
		if(ret < 0)
		{
			perror("select");
			exit(1);
		}
		else if(0 == ret)
		{
			printf("timeout \n");
			continue;
		}
		else 
		{
			if(FD_ISSET(vfd,&rfds))
			{
				if(ioctl(vfd, VIDIOC_DQBUF, &v4l2_buf)< 0){
					perror("ioctl-DQBUF");
					exit(5);
				}

				u8 *yuv = map_buf[v4l2_buf.index].start;
				int k=0;
				u32 *lcd=(unsigned long *)fbp;
				do
				{
					u8 y0 = *(yuv++);
					u8 cb0= *(yuv++);
					u8 y1 = *(yuv++);
					u8 cr0= *(yuv++);
					*lcd = Conv_YCbCr_Rgb(y0,y1,cb0,cr0);
					lcd++;
					k++;
				}while(k<(map_buf[v4l2_buf.index].length/4));

				if(ioctl(vfd, VIDIOC_QBUF, &v4l2_buf)< 0){
					perror("ioctl-QBUF");
					exit(5);
				}
			}

			usleep(200000);
		}
	}

	return 0;
}
