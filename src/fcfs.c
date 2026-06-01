#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stddef.h>
#include<stdint.h>

/* FCFS - First Come First Serve - The process arrives first will get executes first */

typedef struct {
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
} process_t;

int main(void){
    
    int i;
    
    /* PID/AT/BT*/
    process_t p[4] = {
        {1,0,5},
        {2,1,2},
        {3,2,3},
        {4,3,2}
    };   
    
    
    /* Completion Time  = Arrival Time  + Burst Time*/
    p[0].ct = p[0].at + p[0].bt;
    
    for(int i = 1 ; i < 4 ; i++){

        /* 
         * previous process completion time less than arrival time
         *  CT = AT + BT
         *  
         *  less than
         *   CT = Previous AT + BT 
         * 
         * */
	if(p[i-1].ct < p[i].at){
	    p[i].ct = p[i].at + p[i].bt;
	}
	else{
	    p[i].ct = p[i-1].ct + p[i].bt;
	}
    }

    for(int i = 0; i < 4 ; i++){
        /*
         *  TAT = CT - AT
         * */
        p[i].tat = p[i].ct - p[i].at;

        /*
         *  WT = TAT - BT
         * */

        p[i].wt = p[i].tat - p[i].bt;

    }

    /**/
    
    printf("P\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < 4; i++) {

        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].at,
               p[i].bt,
               p[i].ct,
               p[i].tat,
               p[i].wt);
    }
    

    return 0 ;
}

