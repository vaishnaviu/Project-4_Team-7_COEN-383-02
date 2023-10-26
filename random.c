#include "page.h"
//random algorithm
void random(LISTOFPAGES* PRM) {
    page* FITR = PRM->HDL;
    page* PGRNDMEVC = PRM->HDL;
    int CNTER = 0;
    int r = rand() % total_page_count;
    while(FITR) {
        if(FITR->name>0 && CNTER < r){
            PGRNDMEVC = FITR;
        }
        FITR = FITR->next;
        CNTER++;
    }
    printf("%d / %d", PGRNDMEVC->name, PGRNDMEVC->PGENUMBER);
    PGRNDMEVC->name = -1;
    PGRNDMEVC->PGENUMBER = -1;
}