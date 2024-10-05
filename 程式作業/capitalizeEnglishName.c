#include<stdio.h>

int main () {
    int num;
    char str[1000];
    int cap = 1, i = 0;

    scanf("%d", &num);
    getchar();
    scanf("%[^\n]", str);

    for(int i =0; str[i]!='\0'; i++){
        if(str[i]==44 || str[i]==46 || str[i]==59){
            printf("\n");
            cap = 1;
        }else if(str[i]== ' '){//空格不是0，其他符號才是（考試小心）
            printf(" ");
            cap = 1;
        }else{
            if(cap){
                if(str[i]>90){
                    str[i] -= 32;
                    printf("%c", str[i]);
                    cap=0;
                }else{
                    printf("%c", str[i]);
                }
            }else{
                if(str[i]<91){
                    str[i] += 32;
                    printf("%c", str[i]);
                }else{
                    printf("%c", str[i]);
                }
            }
        }
    }

    return 0;
}