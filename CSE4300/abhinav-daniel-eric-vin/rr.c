#include "process.h"
#include "rr.h"

static int counter = 0; //Used to keep track of whose turn it is
const int timeQuantum = 1;

int tq = timeQuantum; //Keeps track of the remaining time quantum for current process

void rr(struct process **procArray, int procArraySize, int globalTime){
    int turn = counter%procArraySize;
    procArray[turn] -> remainingTime -= 1;
    if(procArray[turn] -> remainingTime <= 0){
        procArray[turn] -> finishTime = globalTime;
    }

    tq --;
    if(tq <= 0){
        tq = timeQuantum;
        counter++;
    }
}