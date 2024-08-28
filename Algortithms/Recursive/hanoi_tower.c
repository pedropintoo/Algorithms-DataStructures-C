///
/// This module is part of a project that implements
/// a bound of algorithm and data structures in C
///
/// You may freely use and modify this code, at your own risk.
///
/// Pedro Pinto <pmap@ua.pt>
/// 2024

#include <stdio.h>

int MOVES = 0;

void moveDisc(char start, char dest){
    printf("%c -> %c\n",start,dest);
}

// Moves: O(2^n)
void hanoi(char start, char aux, char dest, int n) {

    if (n == 1) {
        moveDisc(start, dest);
        return;
    }

    hanoi(start, dest, aux, n-1); // move all to aux less the base

    moveDisc(start,dest); // move the base

    hanoi(aux, start, dest, n-1); // Do the same for all, less the base
}
