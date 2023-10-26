#include "PAGE.h"

int main(int argc, char* argv[]) {
    int PageAccess = 0;
    int TimeStamp = 0; // simulator timestamp
    int stepTwo = 0;
    //paging options
    int *PGCoptn = malloc(sizeof(int)*4);
        PGCoptn[0] = 5;
        PGCoptn[1] = 11;
        PGCoptn[2] = 17;
        PGCoptn[3] = 31;


    //pointer to the Page
    page *Page_pointer;

    void (*AlgoFunction)(LISTOFPAGES*);
    if (argc < 3){
        printf("usage: %s [FCFS, LRU, LFU, MFU or Random] randomSeed(RAND for random).\n", argv[0]);
        return -1;
    }

    if(strcmp(argv[1], "FCFS") == 0){
        AlgoFunction = fcfs;
    }else if(strcmp(argv[1], "LRU") == 0){
        AlgoFunction = lru;
    }else if(strcmp(argv[1], "LFU") == 0){
        AlgoFunction = lfu;
    }else if(strcmp(argv[1], "MFU") == 0){
        AlgoFunction = mfu;
    }else if(strcmp(argv[1], "Random") == 0){
        AlgoFunction = random;
    }else {
        printf("usage: %s [FCFS, LRU, LFU, MFU or Random] randomSeed(RAND for random).\n", argv[0]);
        return -1;
    }

    if (argc == 4 && atoi(argv[3]) == 1) {
        stepTwo = 1;
    }

    int swappingInProcess = 0;
    if (strcmp(argv[2], "RAND") == 0)
        srand(time(NULL));
    else
        srand(atoi(argv[2]));
  
    int i;
    for(i = 0; i < 5; i++) {
        //redirection all the printing to the file
        char fileName[100];
        char runNum[10];
        strcpy(fileName, "../output/");
        strcat(fileName, argv[1]);
        strcat(fileName, "_");
        sprintf(runNum, "%d", i + 1);
        strcat(fileName, runNum);
        strcat(fileName, ".txt");
        freopen(fileName, "w", stdout);

        LISTOFPAGES pl;
        initialize_pagelist(&pl);
        process Q[total_process];
	    int i;
        for(i=0;i<total_process;i++) {
            Q[i].name = i;
            Q[i].size = PGCoptn[rand()%4];
            Q[i].arrival_time = rand()%60;
            Q[i].duration = rand() % process_duration + 1;// maximum process duration
            Q[i].PGCRR = 0; // all processes begin with page 0
        }
        qsort(Q,total_process,sizeof(process),arrival_time_compare);

        int index = 0; // index to the start of process queue
        for(TimeStamp = 0; TimeStamp < total_duration; TimeStamp++) {   

            //looking for new process at start of every second
            while(index < total_process && Q[index].arrival_time <= TimeStamp) {

		        //To check atleast four pages
                if(PageWhoRFree(&pl, 4)) {
			        // if its present then bring it in the memory
                    page* p = PAGEfrreeeg(&pl);
                    p->name = Q[index].name;
                    p->PGENUMBER = Q[index].PGCRR;
                    p->FTBOUGHT = 1.0*TimeStamp;
                    p->CNTER = 1;
                    p->LONE = TimeStamp;
                    printf("<%d, %d, Enter, %d, %d, \n", TimeStamp, Q[index].name, Q[index].size, Q[index].duration);
                    PageeDisplayingg(&pl);
                    printf(">\n");
                    swappingInProcess++;
                    index++;
                    PageAccess++;
                } else break;
            }
	        int i;
            for(i=0;i<10;i++) {
		        int j;
		        for(j=0;j<index;j++) 
                    if(Q[j].duration > 0) {
                            Q[j].PGCRR = PGNUMNXT(Q[j].PGCRR,Q[j].size);
                            if(MEMinPGES(&pl,Q[j].name,Q[j].PGCRR)) {

                                Page_pointer = IDwhozPGrFree(&pl,Q[j].name,Q[j].PGCRR);
                                printf("<%d, %d, %d, True, >\n", TimeStamp, Q[j].name, Q[j].PGCRR);

                                Page_pointer->CNTER++;
                                Page_pointer->LONE = TimeStamp;
                                PageAccess++;
                                continue;
                            }

                        // if we are here then that means we refered a page which is not there in memory. So we need to bring it in.

                        page* pageeeg = PAGEfrreeeg(&pl);
                        if(!pageeeg) {

                            printf("<%d, %d, %d, False ", TimeStamp, Q[j].name, Q[j].PGCRR);
                            AlgoFunction(&pl);
                            printf(">\n");

                            pageeeg = PAGEfrreeeg(&pl);
                        }
                        pageeeg->name = Q[j].name;
                        pageeeg->PGENUMBER = Q[j].PGCRR;
                        pageeeg->FTBOUGHT = TimeStamp+(0.1*i);
                        pageeeg->LONE = TimeStamp+(0.1*i);
                        pageeeg->CNTER = 0;
                        swappingInProcess++;
                        PageAccess++;
                    }

            }
	        int j;

            for(j=0;j<index;j++) if(Q[j].duration > 0) {
                Q[j].duration--;
                if(Q[j].duration == 0) {
                    MEMRFree(&pl,Q[j].name);
                    printf("<%d, %d, Exit, %d, %d, \n", TimeStamp, Q[j].name, Q[j].size, Q[j].duration);
                    PageeDisplayingg(&pl);
                    printf(">\n");
                }
            }
            usleep(900);
            if (stepTwo && PageAccess >= 100)
                break;
        }
   
    }
    freopen("/dev/tty", "w", stdout);
    printf("Averge number of processes that were successfully swapped in %d\n", (swappingInProcess / 5));
}
