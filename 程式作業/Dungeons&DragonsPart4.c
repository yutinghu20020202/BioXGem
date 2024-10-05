#include <stdio.h>

//0x01020304:
//00000001 | 00000010 | 00000011 | 00000100(輸進去電腦會自動變成二進位)
//1st byte | 2nd byte | 3rd byte | 4th byte

unsigned char get_byte(int N, int n){
    return (N >> ((4-n)*8)) & 0xFF; 
    /*0xFF: 00000000 0000000 0000000 11111111 / 0xFFFF: 00000000 00000000 11111111 11111111*/
}

int main () {
    unsigned int N, temp=0;
    int d1, d2, d3, d4;
    scanf("%u", &N);
    scanf("%d %d %d %d", &d1, &d2, &d3, &d4);
    temp |= ((get_byte(N, d1)) ^ (get_byte(N, d2))) << 24;//取完XOR會在最後第四組的位置
    temp |= ((get_byte(N, d2)) & (get_byte(N, d3))) << 16;
    temp |= ((get_byte(N, d3)) | (get_byte(N, d1))) << 8;
    temp |= (~(get_byte(N, d4))) & 0xFF;
    //00000000 00000000 000000000 00001111 ->反轉 11111111 11111111 11111111 11110000 所以要加& 0xFF把前面變0

    unsigned int rotateAmount = d1 + d2 + d3 + d4;
    temp = (temp >> rotateAmount )| (temp << ( 32- rotateAmount));// 假設d1 + d2 + d3 + d4 = 8，要平移8格
    // 00000001 00000010 00000100 00001000
    // 00000000 00000001 00000010 00000100 取OR 00001000 00000000 00000000 00000000

    unsigned int upper, lower, result;
    upper = (temp >> 16) & 0xFFFF;//把它全部移到會面兩組再取ＯＲ
    lower = temp & 0xFFFF;
    result = upper ^ lower;

    printf("%u\n", result);//記得用%u（不然會被當掉）
    
    return 0;
}
