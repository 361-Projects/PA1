/********************************************************
 * PROGRAM: PA1 - Linked Lists                          *
 * CLASS: CISC 361-011                                  *
 * AUTHORS:                                             *
 *    Alex Sederquest | alexsed@udel.edu | 702414270    *
 *    Ben Segal | bensegal@udel.edu | 702425559         *
 ********************************************************/

#include "mp3.h"

extern node_t *head;

void delete(char *name)
{
    node_t *curr, *tmp;
    curr = head;
    tmp = NULL;

    while (curr != NULL) {
        tmp = curr;
        if (strcmp(curr->name, name) == 0) {
            // Deal with the 1st head case ;)
            if (curr == head && curr->next == NULL) {
                free(tmp->name);
                free(tmp);
                head = NULL;
                return;
            } else if (curr == head) {
                head = curr->next;
                curr->next->prev = NULL;
                curr = curr->next;
                free(tmp->name);
                free(tmp);
            } else if (curr->next == NULL) {
                curr->prev->next = NULL;
                free(tmp->name);
                free(tmp);
                return;
            } else {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                curr = curr->next;
                free(tmp->name);
                free(tmp);
            }
        } else {
            curr = curr->next;
        }
    }
}
