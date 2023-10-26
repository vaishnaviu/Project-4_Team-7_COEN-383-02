#include "page.h"

void mfu(LISTOFPAGES *PMFUL){
    page* FITMFU = PMFUL->HDL;
    page* PGMFUEVC = PMFUL->HDL;
    int max = FITMFU->CNTER;
    while(FITMFU) {
        if(FITMFU->CNTER > max){
            PGMFUEVC = FITMFU;
            max = FITMFU->CNTER;
        }
        FITMFU = FITMFU->next;
    }
    printf("%d / %d", PGMFUEVC->name, PGMFUEVC->PGENUMBER);
    PGMFUEVC->name = -1;
    PGMFUEVC->PGENUMBER = -1;

}
