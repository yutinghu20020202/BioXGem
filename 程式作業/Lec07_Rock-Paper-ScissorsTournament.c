#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    int id;
    char shape;
} Player;

int decideWinner(Player p1, Player p2, char jug) {    
    if (p1.shape == p2.shape) {
        if (jug == 's') {
            return (p1.id < p2.id) ? p1.id : p2.id;
        } else {
            return (p1.id > p2.id) ? p1.id : p2.id;
        }
    } else {
        
        if ((p1.shape == 'r' && p2.shape == 's') || 
            (p1.shape == 's' && p2.shape == 'p') || 
            (p1.shape == 'p' && p2.shape == 'r')) {
            return p1.id; 
        } else {
            return p2.id; 
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);
    
    char shapes[N + 1];
    scanf("%s", shapes);
    
    
    int rounds = (int)log2(N);
    char jug[rounds + 1];
    scanf("%s", jug);
    
    Player players[N];
    for (int i = 0; i < N; ++i) {
        players[i].id = i + 1;
        players[i].shape = shapes[i];
    }
    
    int round = 0;
    while (N > 1) {
        int index = 0;
        for (int i = 0; i < N; i += 2) {
            
            int winnerId = decideWinner(players[i], players[i + 1], jug[round]);
            
            
            if (winnerId == players[i].id) {
                players[index++] = players[i];
            } else {
                players[index++] = players[i + 1];
            }
        }
        
        N /= 2;
        round++;
    }
    
    printf("%d\n", players[0].id);
    
    return 0;
}
