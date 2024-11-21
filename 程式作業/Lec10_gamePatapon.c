#include <stdio.h>
#include <string.h>

//判斷合法性
int legal (char *arr){
    if (strcmp(arr, "PATA PATA PATA PON") == 0){
        return 1;
    }else if (strcmp(arr, "PON PON PATA PON") == 0){
        return 2;
    }else if (strcmp(arr, "CHAKA CHAKA PATA PON") == 0){
        return 3;
    }
    return 0;
}

int main (){
    //輸入處理
    int distance=0, mon_blood=0;
    scanf("%d %d", &distance, &mon_blood);
    getchar();
    /*scanf() 讀取 distance 和 mon_blood 後，
    標準輸入緩衝區中還留有一個換行符。這導致 fgets()
    第一次調用時，直接讀取了這個換行符，並沒有讀取到
    後續的輸入。*/

    char input[1000];
    fgets (&input[0], 1000, stdin);

    char arr[1000][1000];
    int j=0, k=0;

    for (int i=0; i<strlen(&input[0]); i++){
        if (input[i] == ',' || input[i] == '.' || input[i] == '\n'){//error1: 換行符號也要算進去
            arr[j][k] = '\0';
            j++;
            k=0;
        }else if (input[i] == '\n'){
            arr[j][k] = '\0';
            break;
        }else {
            arr[j][k] = input[i];
            k++;
        }
    }

    //規則處理
    int legal_count = 0;
    int total_count = 0;
    int defense = 0;
    for (int i=0; i<j; i++){
        total_count ++;

        if (legal(arr[i])==1){
            distance -= 1;
            if (distance <= 0){
                printf("NO ");
                printf("%d\n", mon_blood);
                return 0;
            }
            legal_count ++;

        }else if (legal(arr[i])==2){
            if (distance <= 3 && distance > 0){
                mon_blood -= 1;
            }
            legal_count++;

        }else if (legal(arr[i])==3){
            distance += 1;
            defense = 1;
            legal_count++;
        }

        if (total_count % 10 == 0){
            if (defense == 0){
                printf("NO ");
                printf("%d\n", mon_blood);
                return 0;
            }else {
                defense = 0;//error2: 防禦成功要記得重置
            }
        }

        if (mon_blood == 0){
            printf("YES ");
            printf("%d\n", legal_count);
            return 0;
        }
    }

    printf("NO ");
    printf("%d\n", mon_blood);

    

    return 0;
}