#include<stdio.h>

int main () {
    int i, j;
    scanf("%d %d", &i, &j);
    if(i==1){//左上
        for(int row = j; row>0; row--){//遞減
            for(int col = 0; col<row; col++){
                printf("*");
            }
            printf("\n");
        }
    }else if(i==2){//左下
        for(int row = 1; row<=j; row++){//遞增
            for(int col = 0; col<row; col++){
                    printf("*");
            }
            printf("\n");
        }
    }else if(i==3){//右上
        for(int row = j; row>0; row--){//遞減
            for(int space = 0; space<j-row; space++){
                printf(" ");
            }
            for(int col = 0; col<row; col++){
                printf("*");
            }
            printf("\n");
        }
    }else{//右下
        for(int row = 1; row<=j; row++){//遞增
            for(int space = 0; space<j-row; space++){
                printf(" ");
            }
            for(int col = 0; col<row; col++){
                printf("*");
            }
            printf("\n");
        }
    }

    return 0;
}