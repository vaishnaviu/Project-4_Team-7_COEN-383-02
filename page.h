#ifndef _page_h_
#define _page_h_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define total_process 150
#define total_duration 60
#define process_duration 5
#define total_page_count 100

extern int simulation_clock;
extern int *paging_options;

typedef struct {
    int name, size, arrival_time, duration, PGCRR;
} process;

typedef struct page {
    int name;
    int PGENUMBER;
    struct page* next;

    float FTBOUGHT;
    float LONE;
    int CNTER;
} page;

typedef struct {
    page* HDL;
} LISTOFPAGES;

// pages which are free
int free_pages(LISTOFPAGES*,int);

//Existing pages in memory
int pages_in_memory(LISTOFPAGES*,int,int);

page* PAGEfrreeeg(LISTOFPAGES*);

// freeing memortyss
void free_Memory(LISTOFPAGES*,int);

//initializing all pages
void initialize_pagelist(LISTOFPAGES*);

/// displaying all pages
void display_page(LISTOFPAGES*);

//getting all paages number
int next_page_number(int,int);

// comparision between arrival time
int arrival_time_compare(const void* ,const void*);

// Pagesid who are free
page* free_page_name(LISTOFPAGES*,int,int);

void fcfs_function(LISTOFPAGES*);
void lru_function(LISTOFPAGES*);
void lfu_function(LISTOFPAGES*);
void mfu_function(LISTOFPAGES*);
void random_function(LISTOFPAGES*);

#endif