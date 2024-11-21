#include <stdio.h>
#include <stdbool.h>

struct element {
    char val;        // 'A'~'Z': valid, 0: don't have value yet
    bool can_modify;       // true: white area in the figure, false: gray area in the figure
};

bool valid(struct element grid[9][9], int row, int col, char letter){
    for (int i=0; i<9; i++){
        if (grid[row][i].val == letter || grid[i][col].val == letter){
            return false;
        }
    }
    int start_row = (row/3) * 3;
    int start_col = (col/3) * 3;
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if (grid[start_row + i][start_col + j].val == letter){
                return false;
            }
        }
    }

    return true;
}

bool solve_sudoku (struct element grid[9][9]){
    for (int row=0; row<9; row++){
        for (int col=0; col<9; col++){
            if (grid[row][col].val == 0 && grid[row][col].can_modify == true){
                for(char letter = 'A'; letter <= 'I'; letter++){
                    if (valid (grid, row, col, letter)){
                        grid[row][col].val = letter;
                        if (solve_sudoku(grid)){ //如果這一額填的字可以繼續跑下去，表示填對了
                            return true;
                        }grid[row][col].val = 0;//填不對就把這一格清空
                    }
                }
            }return false;
        }
    }
    return true;
}

void solve(struct element (*grid_p)[9]){
    solve_sudoku(grid_p);
}

void print_grid(struct element (*grid_p)[9]) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            printf("%c ", grid_p[i][j].val);
        }
        printf("\n");
    }
}

int main(void) {
    struct element grid[9][9];
    char ch;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            scanf(" %c", &ch);
            if (ch == '.') {    // can_modify assign true, val assign 0
                grid[i][j].val = 0;
                grid[i][j].can_modify = true;
            }
            else {      // value gotten from input, so we can't change this
                grid[i][j].val = ch;
                grid[i][j].can_modify = false;
            }
        }
    }
    solve(grid);
    print_grid(grid);
    return 0;
}