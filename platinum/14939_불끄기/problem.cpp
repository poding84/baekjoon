#include <stdio.h> 
// #include <vector>
// #include <utility>
// #include <queue>
// #include <string.h>
// #include <map>
// #include <math.h>
// #include <set>





char board[11][11];

void printboard() {
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}


int main() {
    
    for(int i=0; i<10; i++) {
        scanf("%s", board[i]);
    }

    // printboard();

}