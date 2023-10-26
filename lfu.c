#include "page.h"
//LfU algorithm
void lfu(LISTOFPAGES* plLFU) {
    page* fit_LFU = plLFU->HDL;
    page* pg_removed = plLFU->HDL;
    int min = fit_LFU->CNTER;
    while(fit_LFU) {
        if(fit_LFU->CNTER < min){
            pg_removed = fit_LFU;
            min = fit_LFU->CNTER;
        }
        fit_LFU = fit_LFU->next;
    }
    printf("EVICTED ones :: p[%03d] c:%02d l:%02f\n", pg_removed->name, pg_removed->CNTER, pg_removed->LONE);
    pg_removed->name = -1;
    pg_removed->PGENUMBER = -1;
}
