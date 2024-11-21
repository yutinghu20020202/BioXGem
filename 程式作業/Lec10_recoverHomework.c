#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 4096

int valid_word (char *word, char *pun){
    int len = strlen(word);
    if (len < 1 || len > 21){
        return 0;
    }
    
    
    *pun = '\0';
    if (word[len-1]=='.' || word[len-1]==',' || word[len-1]=='?' || word[len-1]=='!' ){
        
        *pun = word[len-1];
        word[len-1] = '\0';
        len--;
    }

    if (len < 1 || len > 21){
        return 0;
    }
    
    for (int i=0; i<len; i++){
        if (!isalpha(word[i])){
            return 0;
        }
    }
    //printf("%s", word);
    return 1;
}


void recovery(char *homework){
    char result[MAX_LEN+1] = "";
    char *word = strtok(homework, " ");
    int first_word = 1;
    char pun;

    while (word != NULL){
        
        if (valid_word(word, &pun)){
            if(!first_word){
                strcat (result, " ");
            }
            strcat(result, word);

            if (pun != '\0'){
            result[strlen(result)] = pun;
            result[strlen(result)+1] = '\0';
            }

            first_word = 0;
        }
        
        word = strtok (NULL, " ");
        
    }
    
    // 抓字串長度 21 （標點符號位置  （合法英文字 （虎誒誒去

    strcpy(homework, result);
    
  
}

int main () {
    char homework[MAX_LEN + 1];
    
    // Get the homework content.
    fgets(homework, MAX_LEN , stdin);
    recovery(homework);

    // Print the recovered homework.
    fputs(homework, stdout);

    return 0;
}