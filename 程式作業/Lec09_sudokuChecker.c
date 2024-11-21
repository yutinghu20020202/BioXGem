#include <stdio.h>
#define NUM 9

void check_sudoku(int (*grid_p)[NUM]){
   int violating[NUM][NUM] = {0};

   int seen_row[NUM][10]; 
   int seen_col[NUM][10];
   int seen_subgrid[NUM][10];

   for(int i=0; i<NUM; ++i){
    for(int num=1; num<=9; ++num){
        seen_row[i][num] = -1;
        seen_col[i][num] = -1;
        seen_subgrid[i][num] = -1;
    }
   }

   for (int i=0; i<NUM; ++i){
    for (int j=0; j<NUM; ++j){
        
        int num = grid_p[i][j];
        int subgrid_index = (i/3) *3 + (j/3);

        if (seen_row[i][num] != -1){
            violating[i][j] = 1;
            int prev_j = seen_row[i][num];
            violating[i][prev_j] = 1;
        }else{
            seen_row[i][num] = j;
        }

        if (seen_col[j][num] != -1){
            violating[i][j] = 1;
            int prev_i = seen_col[j][num];
            violating[prev_i][j] = 1;
        }else{
            seen_col[j][num] = i;
        }

        if (seen_subgrid[subgrid_index][num] != -1){
            violating[i][j] = 1;
            int prev_pos = seen_subgrid[subgrid_index][num];
            int prev_i = prev_pos/NUM;
            int prev_j = prev_pos%NUM;
            violating[prev_i][prev_j] = 1;
        }else{
            seen_subgrid[subgrid_index][num] = i*NUM + j;
        }

    }
   }
   for (int i=0; i<NUM; ++i){
        for (int j=0; j<NUM; ++j){
            if(violating[i][j]){
                printf("(%d,%d)\n", i, j);
            }
        }
    }
   
}

int main(void){
    int grid[NUM][NUM]; // sudoku puzzle
    for(int i = 0; i < NUM; ++i){
        for(int j = 0; j < NUM; ++j){
            scanf("%d", &grid[i][j]);
        }
    }
    check_sudoku(grid);
    return 0;
}
