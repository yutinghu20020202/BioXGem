#include <stdio.h>
#include <stdlib.h> 

int main () {
    int d1=0, d2=0, d3=0, d4=0, d5=0, d6=0, temp=0, playerScore=100, dragonsScore=100;
    
    while(1){
        scanf("%d %d %d %d %d %d", &d1, &d2, &d3, &d4, &d5, &d6);
        int sum123 = d1 + d2 + d3;

        if(sum123%2 != 0){
            if (d6>d5 && d5>d4){
                dragonsScore-=25;
            }else if(d4%2 == d5%2 || d5%2 == d6%2){
                dragonsScore-=5;
            }else{
                continue;
            }
        }else{
            if(abs(d5-d4) > d6){
                playerScore-=15;
            }else if(d4+d5 != d6){
                playerScore-=5;
            }else{
                continue;
            }
        }
        if(playerScore<=0){
            printf("Dragon wins\n");
            break;
        }else if(dragonsScore<=0){
            printf("Player wins\n");
            break;
        }
    }
    return 0;
}