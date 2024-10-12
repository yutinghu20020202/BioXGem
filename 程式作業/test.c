# include <stdio.h>

int main(){
    int m[2][2] = {[0][1] = 1, [1][1] = 2};
    printf("%d", m);
    return 0;
}