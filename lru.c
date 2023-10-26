#include "page.h"

// LRU algorithm
void lru(LISTOFPAGES* PLLRU) {
  // Find the least recently used page.
  page* least_recently_used_page = PLLRU->HDL;
  int least_recently_used_time = least_recently_used_page->LONE;
  page* current_page = PLLRU->HDL->next;
  while (current_page != NULL) {
    if (current_page->LONE < least_recently_used_time) {
      least_recently_used_page = current_page;
      least_recently_used_time = current_page->LONE;
    }
    current_page = current_page->next;
  }

  // Print the PID and page number of the least recently used page.
  printf("%d / %d\n", least_recently_used_page->name, least_recently_used_page->PGENUMBER);

  // Clear the PID and page number of the least recently used page.
  least_recently_used_page->name = -1;
  least_recently_used_page->PGENUMBER = -1;
}