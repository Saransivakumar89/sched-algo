#include <stdio.h>

/* FCFS - First Come First Serve */

typedef struct {

    int pid;   // Process ID
    int at;    // Arrival Time
    int bt;    // Burst Time
    int ct;    // Completion Time
    int tat;   // Turnaround Time
    int wt;    // Waiting Time

} process_t;

int main(void) {

    int i;

    /* PID, AT, BT */

    process_t p[2] = {

        {1, 0, 5},
        {2, 3, 2},
    };

    /* 
       Completion Time
    */

    /* First process */

    p[0].ct = p[0].at + p[0].bt;

    /* Remaining processes */

    for(i = 1; i < 2; i++) {

        /*
         * If previous process finishes
         * before current process arrives,
         * CPU becomes idle.
         */

        if(p[i - 1].ct < p[i].at) {

            p[i].ct = p[i].at + p[i].bt;
        }

        /*
         * Otherwise current process waits
         * for previous process to finish.
         */

        else {

            p[i].ct = p[i - 1].ct + p[i].bt;
        }
    }

    /* 
       TAT and WT
    */

    for(i = 0; i < 2; i++) {

        /*
         * Turnaround Time
         * TAT = CT - AT
         */

        p[i].tat = p[i].ct - p[i].at;

        /*
         * Waiting Time
         * WT = TAT - BT
         */

        p[i].wt = p[i].tat - p[i].bt;
    }

    /* 
       Output
    */

    printf("P\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < 2; i++) {

        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].at,
               p[i].bt,
               p[i].ct,
               p[i].tat,
               p[i].wt);
    }

    return 0;
}
