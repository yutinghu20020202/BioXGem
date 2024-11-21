#include <stdio.h>

int main () {
    int d1, d2;
    int rotaryDisk[6]={0, 0, 0, 0, 0, 0};


    for (int i=0; i<75; i++){
        scanf("%d %d", &d1, &d2);
        1 <= d1 <= 6;
        1 <= d2 <= 8;

        if (d2%2 == 1){
            rotaryDisk[d1-1] = (rotaryDisk[d1-1]+1)%10;

        }else if (d2%2 == 0){
            rotaryDisk[d1-1] = (rotaryDisk[d1-1]-1+10)%10;
        }
    }
    for (int i=0; i<6; i++){
        printf("%d ", rotaryDisk[i]);
    }
    printf("\n");
    return 0;
}