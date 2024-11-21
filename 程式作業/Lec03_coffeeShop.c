#include <stdio.h>
#define AMERICANO  110
#define LATTE      150
#define CAPPUCCINO 135
#define MOCHA      145

int main() {
    int i=0, j=0;
    scanf("%d %d", &i, &j);
    if (i > 4 || i < 1){
        printf("Wait, what?\n");
        return 0;
    }
    switch(i){
        case 1:
            printf("The total price is %d dollars!\n", 110*j);
            break;
        case 2:
            printf("The total price is %d dollars!\n", 150*j);
            break;
        case 3:
            printf("The total price is %d dollars!\n", 135*j);
            break;
        case 4:
            printf("The total price is %d dollars!\n", 145*j);
            break;
    }

    return 0;
}