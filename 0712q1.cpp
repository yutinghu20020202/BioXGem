#include <cstdio>;
using namespace std;

int main() {
    int seconds;
    int seconds2;
    int hours;
    int minutes;

    printf("Please input your seconds ....");
    scanf("%d", &seconds);

    hours= seconds/3600;
    minutes= (seconds/60)-(hours*60);
    seconds2= seconds-(minutes*60)-(hours*3600);


    printf("%d hour %d minute %d second \n", hours, minutes, seconds2);

    return 0 ;
}
