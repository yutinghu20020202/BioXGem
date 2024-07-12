#include <cstdio>

int main() {
    char name[11];
    char department;
    int score1, score2;
    double average;

    
    printf("Please input your name....");
    scanf("%10s",name);

    printf("Please select your department....(a:CS b:Bio c:Math)");
    getchar();
    scanf("%c", &department);

    getchar();
    
    printf("Please input your score on test 1....");
    scanf("%d", &score1);

    getchar();

    printf("Please input your score on test 2....");
    scanf("%d", &score2);

    average = (score1 + score2) / 2.0;

    // 輸出部分
    printf("+---------------------+----------+------+------+-------+\n");
    printf("|        Name         |Department|Test 1|Test 2|Average|\n");
    printf("+---------------------+----------+------+------+-------+\n");
    
    // 使用printf來格式化輸出%20讓字符保留20個位子
    printf("|%21s|%10c|%6d|%6d|%7.2f|\n", name, department, score1, score2, average);
    
    printf("+---------------------+----------+------+------+-------+\n");




    return 0;
}