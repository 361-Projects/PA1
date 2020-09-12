#include "mp3.h"

extern node_t *head;

void delete(char *name)
{
    node_t *curr, *tmp;
    curr = head;
    tmp = NULL;

    while (curr != NULL) {
        if (strcmp(curr->name, name) == 0) {
            tmp = curr;
            // Deal with the 1st head case ;)
            if (curr == head && curr->next == NULL) {
                free(tmp->name);
                free(tmp);
                head = NULL;
                return;
            } else if (curr == head && curr->next != NULL) {
                head = curr->next;
                curr->next->prev = NULL;
                free(tmp->name);
                free(tmp);
            } else if (curr->next == NULL) {
                curr->prev->next = NULL;
                free(tmp->name);
                free(tmp);
            } else {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                free(tmp->name);
                free(tmp);
            }
        }
        curr = curr->next;
    }
}
