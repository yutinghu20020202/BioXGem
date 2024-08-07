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
        printf("Grade: A\n");
    } else if (average >=80 && average < 90) {
        printf("Grade: B\n");
    } else if (average >=70 && average < 80) {
        printf("Grade: C\n");
    } else if (average >=60 && average < 70) {
        printf("Grade: D\n");

    } else {
        printf("Grade: F\n");

    }

    return 0;
}