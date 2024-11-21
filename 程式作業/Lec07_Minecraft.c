#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 21

int recipes[MAX_ITEMS][MAX_ITEMS]; 
int recipe_sizes[MAX_ITEMS];       
int visited[MAX_ITEMS];        

int countMaterials(int item){
    if(visited[item] != -1){
        return visited[item];
    }
    if(recipe_sizes[item] == 0){
        visited[item] = 1;
        return 1;
    }
    int total = 0;

    for(int i = 0; i < recipe_sizes[item]; ++i){
        total += countMaterials(recipes[item][i]);
    }
    visited[item] = total;  
    return total;
}

int main() {
    int N;
    scanf("%d", &N);  

    for (int i = 1; i <= N; ++i) {
        recipe_sizes[i] = 0;  
        visited[i] = -1;      
    }

    //scan data
    for (int i = 1; i <= N; ++i) {
        int M;
        scanf("%d", &M);  
        recipe_sizes[i] = M;
        for (int j = 0; j < M; ++j) {
            scanf("%d", &recipes[i][j]);  
        }
    }

    int totalMaterials = 0;
    
    for (int i = 1; i <= N; ++i) {
        totalMaterials += countMaterials(i);
    }
    printf("%d\n", totalMaterials);  
    return 0;
}