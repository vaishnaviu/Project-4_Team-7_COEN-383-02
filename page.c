#include "PAGE.h"

void Intializing_PGELIst(LISTOFPAGES* pl) {
    pl->HDL = malloc(sizeof(page));
    page* it = pl->HDL;
    int i;
    for(i=0;i<total_page_count;i++) {
        it->name = -1; it->PGENUMBER = -1;
        it->next = NULL;
        if(i < 99) {
            it->next = malloc(sizeof(page));
            it = it->next;
        }
    }
}

// displaying all pages
void PageeDisplayingg(LISTOFPAGES* pl) {
    page* it = pl->HDL;
    int cnt = 0;
    while(it) {
        printf(it->name > 0 ? "%03d " : " .  ",it->name, it->CNTER, it->LONE);
        cnt++;
        if((cnt % 10) == 0) printf("\n");
        it = it->next;
    }
    printf("\n");
}


// pages which are free
int PageWhoRFree(LISTOFPAGES* pl,int CNTER) {
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
int MEMinPGES(LISTOFPAGES* pl,int pid,int PGENUMBER) {
    page* it = pl->HDL;
    while(it) {
        if(it->name == pid && it->PGENUMBER == PGENUMBER) return 1;
        it = it->next;
    }
    return 0;
}


//
page* PAGEfrreeeg(LISTOFPAGES* pl) {
    page* it = pl->HDL;
    while(it) {
        if(it->name == -1) return it;
        it = it->next;
    }
    return NULL;
}
//memeory getting free
void MEMRFree(LISTOFPAGES* pl,int pid) {
    page* it = pl->HDL;
    while(it) {
        if(it->name == pid) {
            it->name = -1;
            it->PGENUMBER = -1;
        }
        it = it->next;
    }
}
//Page number next one

int PGNUMNXT(int curr_page_no,int max_page_size) {
    int x = rand()%10;
    if(x < 7) {
        x = curr_page_no+(rand()%3)-1 < 0;
    } else {
        x = rand()%max_page_size;
        while(abs(x-curr_page_no) <= 1) 
            x = rand()%max_page_size;
    }
    return x;
}

// Page id which are free
page* IDwhozPGrFree(LISTOFPAGES* pl,int pid,int PGENUMBER) {
    page* it = pl->HDL;
    while(it) {
        if(it->name == pid && it->PGENUMBER == PGENUMBER) return it;
        it = it->next;
    }
    return NULL;
}

// comaptring arrival time
int CMP_ARRtime(const void* a,const void* b) {
    return ((process*)a)->arrival_time - ((process*)b)->arrival_time;
}
