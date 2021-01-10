#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rando() {
    int r; 
    srand(time(NULL));
    r = rand()%3;
    return r;
}

int printGame(int ourArr[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%4d", ourArr[i][j]);
        }
        printf("\n");
    }
}

int gameOver(int ourArr[3][3]) {
    
}

int main() {

    int x, y; // User input coordinates 
    int i, j; // Increment variables to be used elsewhere
    int temp = 1; // For temporary use, cuz we dont have game logic
    int cSet[3][3];  // Our coordinate set

    // Define all the elements of our array to be 0 initially
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            cSet[i][j] = 0;
        }
    }

    // Game will be over when this while loop ends
    while (temp < 4) {
        // Scan for coordinates and set it to be 1 (user input)
        printf("You choose : ");
        scanf("%d %d", &x, &y);  cSet[x][y] = 1;
        printGame(cSet); // User turn
        
        /* Random CPU Input (will be modified later, 
        we will build a function for it)*/

        i = 0; 
        while (i == 0) {
            int cX = rando(); int cY = rando();
            //printf("%d %d", cX, cY);
            if (cSet[cX][cY] != 1 && cSet[cX][cY] != 9) { 
                printf("Computer chose: %d %d\n", cX, cY);
                cSet[cX][cY] = 9;
                i++; // Alt for break
            }
            else continue;
        }

        printGame(cSet); // CPU turn 

        temp++;
    }
    return 0;
}
