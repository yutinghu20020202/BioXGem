#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20000

typedef struct {
    char kind[15];
    int num;
}Fruits;

void find_fruit(char input[], char fruit[][15]){
    char *token = strtok(input, "+_+");

    Fruits fruits[20];

    for (int i=0; i<20; i++){
        //fruits[i].kind = fruit[i][15];
        strcpy(fruits[i].kind, fruit[i]/*[15]*/);
        fruits[i].num = 0;
    }

    while (token != NULL){
        for (int i=0; i<20; i++){
            
            if (strcmp(token, fruit[i])==0){
                fruits[i].num ++;
                break;
            }
            
        }
        token = strtok (NULL, "+_+");
    }

    int temp = 0;
    int j=0;

    for (int i=0; i<20; i++){
        if (fruits[i].num > temp){
            temp = fruits[i].num;
        }
    }
    
    for (int i=0; i<20; i++){
        if(fruits[i].num == temp){
            printf("%s\n", fruits[i].kind);
        }
    }

}

int main(void) {
	char fruit[20][15] = {
        "guava",
        "litchi",
        "longan",
        "watermelon",
        "pomelo",
        "pear",
        "banana",
        "papaya",
        "pumpkin",
        "tomato",
        "mango",
        "kiwi",
        "persimmon",
        "cantaloupe",
        "strawberry",
        "grape",
        "peach",
        "orange",
        "coconut",
        "lemon"
    };
    char input[N];
    scanf("%s", input);
    find_fruit(input, fruit);
    return 0;
}