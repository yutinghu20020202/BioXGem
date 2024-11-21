#include <stdio.h>

unsigned long construct(unsigned char parts[16]){
    unsigned long long l1=0, l2=0, result=0;
    int j=0;
    for (int i=0; i<8; i++){
        
        l1 |= (((unsigned long long)parts[i] & 0XFF) << j);
        j += 8;
        
    }
    int k=0;
    for (int i=8; i<16; i++){
        l2 |= (((unsigned long long)parts[i] & 0XFF) << k);
        k += 8;
    }
    result = l1 ^ l2;
    return result;
}

int main()
{
    unsigned char parts[16];
    for (int i = 0; i < 16; i++)
        scanf("%hhx", parts + i);

    printf("%lu", construct(parts));

    return 0;
}