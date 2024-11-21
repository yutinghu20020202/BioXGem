#include <stdio.h>
#include <stdlib.h>
#define MESSAGE_LENGTH 64
#define NAME_LENGTH 10

struct timestamp {
    int hour, minute;
};

struct message_info {
    struct timestamp time;
    char name[NAME_LENGTH];
    char message[MESSAGE_LENGTH];
};

int cmp(const void *a, const void *b){//void是不確定他裡面的型態，所以喔要富與他型態，再加一個*傳值
    struct message_info *msgA = (struct message_info *)a;
    struct message_info *msgB = (struct message_info *)b;

    if (msgA -> time.hour != msgB -> time.hour){
        return msgA->time.hour - msgB->time.hour;
    }else {
        return msgA->time.minute - msgB->time.minute;
    }
}
void sort_message(struct message_info *m, int *total){

    for (int i=0; i<*total; i++){
        qsort (m, *total, sizeof(struct message_info), cmp);
    }

}

/*
int cmp(const void *a, const void *b){
   return *(int*)a-*(int*)b;
}
qsort(a, n, sizeof(int), cmp); 
*/

int main(void) {
    struct message_info m[100];
    int total;
    scanf("%d", &total);
    for(int i = 0; i < total; i++) {
        scanf("%d:%d %s %[^\n]", &m[i].time.hour, &m[i].time.minute, m[i].name, m[i].message);
    }
    sort_message(m, &total);
    for(int i = 0; i < total; i++) {
        printf("%02d:%02d %s %s\n", m[i].time.hour, m[i].time.minute, m[i].name, m[i].message);
    }
    return 0;
}