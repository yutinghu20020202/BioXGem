#include<stdio.h>

int main () {
    int i=0, j;
    int studentsWithoutGroups = 0, studentsInEachGroup = 0;

    scanf("%d %d", &i, &j );

    studentsWithoutGroups = i%j;
    studentsInEachGroup = i/j;

    printf("%d %d\n", studentsInEachGroup, studentsWithoutGroups);
    return 0;
}