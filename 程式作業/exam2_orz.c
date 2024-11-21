#include <stdio.h>
#include <stdbool.h>
#define MAX_LEN 200000

int N;
char str[MAX_LEN];

void find_orz(int orz_position[], int *orz_num){
    *orz_num = 0;
    int j=0;
    for(int i=1; i<=N-2; i++){
        if (str[i] == 'o' && str[i+1] == 'r' && str[i+2] == 'z'){
            orz_position[j] = i+1;
            (*orz_num)++;
            j++;
            
        }
    }
    /*for (int k=0; k<*orz_num; k++){
        printf("%d\n", orz_position[k]);
    }
    printf("%d\n", *orz_num);*/
}
void calculate_worship(int worship_amount[], int range_index, int left_orz_position, int right_orz_position){
    int check[26];
    for (int i=0; i<26; i++){
        check[i] = -1;
    }

    int count=0;
    int char_count =0;

    for (int i=left_orz_position+2; i<right_orz_position-1; i++){
        if (str[i] >= 'a' && str[i] <= 'z'){
            //printf("%d\n", str[i]-'a');
            char_count++;
            if (check[str[i]-'a'] == -1){
                check[str[i]-'a'] = 1;
                //printf("%d, %d\n", str[i]-'a', i);
                count++;
            }
            //printf("%d\n", char_count);
        }
        
    }

    worship_amount[range_index] = char_count * count;
}
int max_worship=0;
int find_max_worship_range(int value, int *range_L, int *range_R, int left_orz_position, int right_orz_position){
    
    if (value > max_worship){
        max_worship = value;
        *range_L = left_orz_position;
        *range_R = right_orz_position;
    }
    return max_worship;
}

int main()
{
    scanf("%d", &N);
    scanf("%s", str);

    int orz_position[MAX_LEN] = {0}, worship_amount[MAX_LEN] = {0}, orz_num = 0;
    find_orz(orz_position, &orz_num);

    for (int i = 1; i < orz_num; i++)
    {
        calculate_worship(worship_amount, i - 1, orz_position[i - 1], orz_position[i]);
    }

    int max_worship, range_L, range_R;
    for (int i = 0; i < orz_num - 1; i++)
    {
        max_worship = find_max_worship_range(worship_amount[i], &range_L, &range_R, orz_position[i], orz_position[i + 1]);
    }
    printf("%d %d %d\n", max_worship, range_L, range_R);
}
