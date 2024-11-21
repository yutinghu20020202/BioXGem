#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define GOODS_SIZE 120
#define MAX_ORDER_SIZE 30
#define MAX_NAME_LEN 15

int valid (const char *names, const char *substring){
    char *pos = strstr(names, substring);
    return pos ? (pos - names) : -1;
}

void find_best_match (const char *substring, char *result){
    int best_position = MAX_NAME_LEN;
    int min_len = MAX_NAME_LEN;

    for (int i=0; i<GOODS_SIZE; i++){
        int position = valid (names[i], substring);
        if (position != -1){
            int len = strlen(names[i]);
            if (position < best_position ||
                position == best_position && len < min_len ||
                position == best_position && len == min_len && strcmp(names[i], result)<0){
                    strcpy (result, names[i]);
                    best_position = position;
                    min_len = len;
                }
        }
    }
}

void recovering_order(char *order, char **result){
    char *token = strtok(order, ":");
    char temp[500] = "";
    char best_match[MAX_NAME_LEN] = "";

    while (token != NULL){
        best_match[0] = '\0';
        find_best_match(token, best_match);
        if (strlen(best_match)>0){
            if (strlen(temp)>0){
                strcat(temp, "+");
            }
            strcat(temp, best_match);
        }
        token = strtok (NULL, ":");
    }
    *result = strdup(temp);//strdup 會動態分配內存來存儲 temp，不加會有堆碟問題，出現 segmentation fault

}

char names[GOODS_SIZE][MAX_NAME_LEN] = {
    "aluminum", "ammunition", "orange", "aspirin", "ax",
    "basketball", "zipper", "bell", "blanket", "drum",
    "canvas", "flute", "eraser", "mirror", "comb",
    "eggplant", "diamond", "zucchini", "door", "butter",
    "egg", "dart", "chair", "encyclopedia", "china",
    "fan", "glue", "elevator", "flower", "hat",
    "garlic", "strawberry", "glove", "flour", "ice",
    "ship", "hammer", "fur", "key", "honey",
    "grape", "icecream", "lock", "iron", "ivory",
    "jacket", "oil", "uniform", "kiwi", "pan",
    "helmet", "keyboard", "yoyo", "jet", "knife",
    "tie", "lemon", "xerox", "ink", "mutton",
    "newspaper", "melon", "coconut", "motorcycle", "longan",
    "nail", "rice", "magnet", "peanut", "ointment",
    "oar", "jeans", "nut", "arrow", "oven",
    "jewel", "wool", "noodle", "pencil", "lamp",
    "refrigerator", "needle", "roast", "vest", "yarn",
    "saw", "hamburger", "soap", "glass", "wine",
    "tangerine", "pillow", "umbrella", "zinc", "train",
    "uglifruit", "toast", "underwear", "vanilla", "jeep",
    "unicycle", "vase", "rope", "violin", "warship",
    "volleyball", "water", "yogurt", "submarine", "passionfruit",
    "yacht", "rose", "window", "yolk", "kite",
    "liquor", "xylophone", "toothbrush", "battery", "doll"
};



int main(void) {
    char order[500] = "", *result = NULL;
    scanf("%s", order);
    recovering_order(order, &result);
    printf("%s", result);
    free(result);
    return 0;
}