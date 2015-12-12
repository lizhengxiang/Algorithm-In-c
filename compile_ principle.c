#include<stdio.h>
#include<string.h>
char prog[80], token[8];
char ch;
int syn, p, m, n, sum;
char* rwtab[6] = {"function", "if", "then", "while", "do", "endfunc"};
void scaner();
int main(){
    int p = 0;
    printf("\nplrase input string:\n");
    do{
        scanf("%c", &ch);
        prog[++p] = ch;
    }while(ch != '#');
    p = 0;
    do{
        scaner();
        switch(syn){
            case 11: printf("\n (%d, %d)",syn,sum);
                break;
            case -1: //printf("\nerror");
                break;
            default: printf("\n(%d,%s)",syn, token);
        }
    }while(syn != 0);
    return 0;
}


void scaner(){
    //debug
    for(n = 0; n < 8; n++)
        token[n] = 0;
    ch = prog[++p];
    if(ch == ';'){
        syn = 26;  token[0] = ch;
        return ;
        token[1] = '\0';
    }

    if(ch != '#')
        ;
        //ch = prog[++p];

    if(ch >= 'a' && ch <= 'z'){
        m = 0;
        //--p;
        while(ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9'){
            token[m++] = ch;
            ch = prog[++p];
        }
        token[m] = '\0';
        ch = prog[--p];
        syn = 10;
        for(n = 0; n < 6; n++)
            if(strcmp(token, rwtab[n]) == 0){
                syn = n + 1;
                break;
            }
    }
    else{
        if(ch >= '0' && ch <= '9'){
            sum = 0;
            while(ch >= '0' && ch <= '9'){
                sum = sum * 10 + ch - '0';
                ch = prog[++p];
                syn = 11;
            }
            --p;
            return ;
        }else{
            switch(ch){
                case '<' : m = 0; token[m++] = ch;
                    ch = prog[++p];
                    if(ch == '='){
                        syn = 22;
                        token[m++] = ch;
                    }else{
                        syn = 20;
                        ch = prog[--p];
                    }
                    break;
                case '>': m = 0; token[m++] = ch;
                    ch = prog[++p];
                    if(ch == '='){
                        syn = 24;
                        token[m++] = ch;
                    }else{
                        syn = 23;
                        ch = prog[--p];
                    }
                    break;
                case'=': m = 0; token[m++] = ch;
                    ch = prog[++p];
                    if(ch == '='){
                        syn = 25;
                        token[m++] = ch;
                    }else{
                        syn = 18;
                        ch = prog[--p];
                    }
                break;
                case'!': m = 0; token[m++] = ch;
                    ch = prog[++p];
                    if(ch == '='){
                        syn = 22;
                        token[m++] = ch;
                    }else{
                        syn = -1;
                        }
                break;

                case'+': syn =13;  token[0] = ch; break;
                case'-': syn =14;  token[0] = ch; break;
                case'*': syn =15;  token[0] = ch; break;
                case'/': syn =16;  token[0] = ch; break;
                case';': syn =26;  token[0] = ch; break;
                case'(': syn =27;  token[0] = ch; break;
                case')': syn =28;  token[0] = ch; break;
                case'#': syn =0;  token[0] = ch; break;
                default: syn = -1;
            }//switch
        }//else
    }//else

}

