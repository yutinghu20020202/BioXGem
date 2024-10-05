#include<stdio.h>

int main () {
    int num;
    char str[10000];
    int cap = 1;

    scanf("%d", &num);
    getchar();
    scanf("%[^\n]", str);

    for(int i =0; str[i]!='\0'; i++){
        if(str[i]==',' || str[i]=='.' || str[i]==';'){
            printf("\n");
            cap = 1;
        }else if(str[i]== ' '){
            printf(" ");
            cap = 1;
        }else{
            if(cap){
                if(str[i]>= 'a' && str[i]<= 'z'){
                    printf("%c", str[i]-'a'+'A');
                
                }else{
                    printf("%c", str[i]);
                    
                }
                cap=0;
            }else{
                if(str[i]>='A'&& str[i]<='Z' ){
                    printf("%c", str[i]-'A'+'a');
                }else{
                    printf("%c", str[i]);
                }
            }
        }
    }

    return 0;
}