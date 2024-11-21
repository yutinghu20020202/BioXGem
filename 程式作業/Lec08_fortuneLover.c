#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void int_to_float (int n, uint32_t *bit) {

    union FortuneLover{
        float f;
        uint32_t u;
    }uni;

    uni.f = (float) n;
    *bit = uni.u;
    
}

void int_to_char (uint32_t n, char *str){
    
    int pos=0;
    for (int i=31; i>=0; i--){
        str[pos++] = ((n>>i) & 1)? '1' : '0';
        if (i%8 == 0 && i != 0){
            str[pos++] = ' ';
        }
    }
    str[pos]='\0';//所有的char後面都要加\0
}

int main(void){
    int num1, num2;
    scanf("%d %d", &num1, &num2);

    uint32_t  num1_32, num2_32, sum_32;
    int32_t result;
    char str1[40], str2[40], sum[40];

    int_to_float (num1, &num1_32);
    int_to_float (num2, &num2_32);
    sum_32 = num1_32 + num2_32;

    int_to_char(num1_32, str1);
    int_to_char(num2_32, str2);
    int_to_char(sum_32, sum);

    result = (int) sum_32;

    printf("   %s\n", str1);
    printf("+) %s\n", str2);
    printf("---------------------------------------\n");
    printf("   %s\n", sum);
    printf("%d + %d = %d\n", num1, num2, result);


    return 0;
}