#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int rando() {
    int r; time_t t;
    srand((unsigned) time(&t));
    r = rand()%3;
    return r;
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
        scanf("%d %d", &x, &y);  cSet[x][y] = 1; 

        /* Random CPU Input (will be modified later, 
        we will build a function for it)*/
        cSet[rando()][rando()] = 1;
        
        // Print our coordinates
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                printf("%4d", cSet[i][j]);
            }
            printf("\n");
        }
        temp++;
    }
    return 0;
}
