#include <stdio.h>
#include <stdlib.h>

struct ESPer {
    char name[64];
    int level;
};

int cmp(const void *a, const void *b){
    return (((struct ESPer*)a) -> level - ((struct ESPer*)b) -> level);
}
void sort_level(struct ESPer *arr, int length){
    //size_t arr_size = sizeof(*arr) / sizeof(arr[0]);

    for (int i=0; i<length; i++){
        qsort (arr, length, sizeof(struct ESPer), cmp);
    }


}

int main()
{
    int n;
    struct ESPer tokiwadai[100];

    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d %s", &(tokiwadai[i].level), tokiwadai[i].name);
    }

    sort_level(tokiwadai, n);

    for(int i = 0;i < n;++i) {
        printf("%d %s\n", tokiwadai[i].level, tokiwadai[i].name);
    }

    return 0;
}