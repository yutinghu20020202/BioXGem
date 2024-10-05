#include<stdio.h>

typedef int Strength;
typedef int Obedience;

#define INIT_STRENGTH 50
#define INIT_OBEDIENCE 20

#define STRENGTH_EAT 5
#define OBEDIENCE_EAT 2

#define STRENGTH_TRAIN 4
#define OBEDIENCE_TRAIN 5

#define LEARN_STRENGTH 55
#define LEARN_OBEDIENCE 28

int main () {
    char input[1000];//scanf出來的時候要用arr,不然他只會吃一個字
    int i;
    Strength strength = INIT_STRENGTH;
    Obedience obedience = INIT_OBEDIENCE;
    int temp;//存訓練次數

    scanf("%s", input);//有arr不用＆
    
    for (i=0; input[i] != '\0'; i++){// while ((input= getchar()) != '\n' ){}, input= getchar()會自己幫我迭代，一個一個字吃進去
        if (input[i] == 'e'){
            strength += STRENGTH_EAT;
            obedience -= OBEDIENCE_EAT;
        }else if (input[i] == 't'){
            strength -= STRENGTH_TRAIN;
            obedience += OBEDIENCE_TRAIN;
        }

        if (obedience >= LEARN_OBEDIENCE && strength <= LEARN_STRENGTH){
            obedience = INIT_OBEDIENCE;
            temp++;
        }

        if (temp >= 5){
            printf("Yes\n");
            return 0; //break只會出去迴圈，但要結束整支main
        }
    }
    printf("No\n");

    return 0;
}