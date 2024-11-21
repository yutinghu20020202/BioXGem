#include<stdio.h>

int main () {
    int N=0; //students
    int score[1024];//不可放[N]，要指定，因為N一開始是0
    int T=0; //umber of different [B, A]
    int A, B;

    scanf("%d", &N);//不用加\n(考試小心)

    for(int i = 0; i < N; i++){//不用加\n
        scanf("%d", &score[i]);
    }

    scanf("%d", &T);//不用加\n

    int temp1=0, temp2=0, temp3=0;
    int result[T][3];

    for(int j = 0; j < T; j++){//不用加\n
        scanf("%d %d", &B, &A);
        

        for(int i = 0; i < N; i++){
            if(score[i] >= A){
                temp3++;
            }else if(score[i] >= B && score[i] < A){
                temp2++;
            }else{
                temp1++;
            }
            result[j][0] = temp1;
            result[j][1] = temp2;
            result[j][2] = temp3;
        }
        temp1 = 0;//記得歸零
        temp2 = 0;
        temp3 = 0;
        
    }
    
    for(int j = 0; j < T; j++){
        printf("%d %d %d\n", result[j][0], result[j][1], result[j][2]);
    }

    return 0;
}