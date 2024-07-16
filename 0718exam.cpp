#include <cstdio>
using namespace std;

int main() {
    int x ;
    int y ;
    double average;

    printf ("please input your score on test1....");
    scanf ("%d", &x);
    printf ("please input your score on test2....");
    scanf ("%d", &y);
    average = (x+y)/2.0;
    printf("Average score: %.2f\n", average);
    
    
    if (average >= 90 && average <= 100) {
        printf("A\n");
    } else if (average >=80 && average < 90) {
        printf("B\n");
    } else if (average >=70 && average < 80) {
        printf("C\n");
    } else if (average >=60 && average < 70) {
        printf("D\n");

    } else {
        printf("F\n");

    }

    return 0;
}