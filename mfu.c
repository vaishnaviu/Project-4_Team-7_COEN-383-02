#include "page.h"

void mfu_function(LISTOFPAGES *mfu_pagelist){
    page* current_mfu_page = mfu_pagelist->HDL;
    page* mfu_eviction_page = mfu_pagelist->HDL;
    int max = current_mfu_page->CNTER;
    while(current_mfu_page) {
        if(current_mfu_page->CNTER > max){
            mfu_eviction_page = current_mfu_page;
            max = current_mfu_page->CNTER;
        }
        current_mfu_page = current_mfu_page->next;
    }
    printf("%d / %d", mfu_eviction_page->name, mfu_eviction_page->PGENUMBER);
    mfu_eviction_page->name = -1;
    mfu_eviction_page->PGENUMBER = -1;

}
