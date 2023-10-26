#include "page.h"

void initialize_pagelist(LISTOFPAGES* pl) {
    // Allocate memory for the head of the page list.
    pl->HDL = malloc(sizeof(page));
    
    // Initialize the page list.
    page* currentPage = pl->HDL;
    for (int i = 0; i < total_process; i++) {
        currentPage->name = -1;
        currentPage->PGENUMBER = -1;
        currentPage->next = NULL;
        
        if (i < 99) {
            // Allocate memory for the next page if not at the end of the list.
            currentPage->next = malloc(sizeof(page));
            currentPage = currentPage->next;
        }
    }
}

// Display all pages in the list.
void display_page(LISTOFPAGES* pl) {
    page* currentPage = pl->HDL;
    int cnt = 0;
    
    while (currentPage) {
        printf(currentPage->name > 0 ? "%03d " : " .  ", currentPage->name, currentPage->CNTER, currentPage->LONE);
        cnt++;
        
        if ((cnt % 10) == 0) {
            printf("\n");
        }
        
        currentPage = currentPage->next;
    }
    
    printf("\n");
}


// pages which are free
int free_pages(LISTOFPAGES* pl,int CNTER) {
    page* it = pl->HDL;
    while(it) {
        if(it->name == -1) { // page not being used by any process;
            CNTER--;
        }
        if(!CNTER) return 1;
        it = it->next;
    }
    return 0;
}

//memory in pages
int pages_in_memory(LISTOFPAGES* pl,int name,int PGENUMBER) {
    page* it = pl->HDL;
    while(it) {
        if(it->name == name && it->PGENUMBER == PGENUMBER) return 1;
        it = it->next;
    }
    return 0;
}


//
page* PAGEfrreeeg(LISTOFPAGES* pl) {
    page* pg = pl->HDL;
    while(pg) {
        if(pg->name == -1) return pg;
        pg = pg->next;
    }
    return NULL;
}
//memeory getting free
void free_Memory(LISTOFPAGES* pl,int p_id) {
    page* pg = pl->HDL;
    while(pg) {
        if(pg->name == p_id) {
            pg->name = -1;
            pg->PGENUMBER = -1;
        }
        pg = pg->next;
    }
}
//Page number next one

int next_page_number(int curr_page_no,int max_page_size) {
    int x = rand()%11;
    if(0<= x < 7) {
        x = curr_page_no+(rand()%3)-1 < 0;
    } else {
        x = rand()%max_page_size;
        while(abs(x-curr_page_no) <= 1) 
            x = rand()%max_page_size;
    }
    return x;
}

// Page id which are free
page* next_page_number(LISTOFPAGES* pl,int name,int PGENUMBER) {
    page* it = pl->HDL;
    while(it) {
        if(it->name == name && it->PGENUMBER == PGENUMBER) return it;
        it = it->next;
    }
    return NULL;
}

// Compare arrival times of processes
int arrival_time_compare(const void* a, const void* b) {
    const int arrivalTimeA = ((process*)a)->arrival_time;
    const int arrivalTimeB = ((process*)b)->arrival_time;
    return arrivalTimeA - arrivalTimeB;
}
