#include "page.h"
//FCFS algorithm
void fcfs(LISTOFPAGES* fcfs_pagelist) {
    //Initialize pointer to the current page in the list
    page* fcfs_currentPage = fcfs_pagelist->HDL;

    //Initialize pointer to the page selected for eviction
    page* fcfs_evictionPage = fcfs_pagelist->HDL;

    while(fcfs_currentPage) {
        if(fcfs_currentPage->FTBOUGHT < fcfs_evictionPage->FTBOUGHT) {
            fcfs_evictionPage = fcfs_currentPage;
        }
        fcfs_currentPage = fcfs_currentPage->next;
    }
    printf("%d / %d", fcfs_evictionPage->name, fcfs_evictionPage->PGENUMBER);
    fcfs_evictionPage->name = -1;
    fcfs_evictionPage->PGENUMBER = -1;
}