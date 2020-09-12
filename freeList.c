/********************************************************
 * PROGRAM: PA1 - Linked Lists                          *
 * CLASS: CISC 361-011                                  *
 * AUTHORS:                                             *
 *    Alex Sederquest | alexsed@udel.edu | 702414270    *
 *    Ben Segal | bensegal@udel.edu | 702425559         *
 ********************************************************/

#include "mp3.h"

extern node_t *head;

void freeList()
{
  node_t *temp;
  int  i = 0;

  while (head != NULL) {
    temp = head;
    head = head->next; // point to next MP3 record
    free(temp->name);  // first free name inside MP3 record
    free(temp);        // then free MP3 record
    i++;
  }
  printf("free %d MP3 records...\n", i);
}
