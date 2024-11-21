#include <stdio.h>                                  
#include <string.h>                                                                                                                                                                          

#define MAX_CAND_CNT 20
#define MAX_NAME_LEN 32
struct ballot_counter_s {
    int count;
    char name[MAX_NAME_LEN];
} counter[MAX_CAND_CNT];
int cand_cnt;

void count(const char *name){
    
    for (int j=0; j<cand_cnt; j++){ 
        if(strcmp(name, counter[j].name)==0){//strcmp(char *str1, char *str2)
            counter[j].count ++;
        }
    }

}
const char *winner(){
    int temp = counter[0].count;
    //static char buffer[100]= "";
    //如果宣告char在function 要加static(像全域變數 不會被註銷記憶體位置)
    char *buffer;

    for (int j=0; j<cand_cnt; j++){
        if (temp <= (counter[j].count)){
            //strcpy(buffer, counter[j].name);
            //因為他是指標
            temp = counter[j].count;
            buffer = counter[j].name;
        }
    }
    return buffer;
}

int main()
{
    scanf("%d", &cand_cnt);
    for (int i = 0; i < cand_cnt; i++) {
        scanf("%s", counter[i].name);
        counter[i].count = 0;
    }

    char name[MAX_NAME_LEN];
    while (scanf("%s", name) != EOF)
        count(name);

    for (int i = 0; i < cand_cnt; i++)
        printf("%s %d\n", counter[i].name, counter[i].count);

    printf("%s\n", winner());

    return 0;
}