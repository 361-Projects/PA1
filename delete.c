#include "mp3.h"

extern node_t *head;

void delete(char *name)
{
    node_t *cur, *tmp;
    cur = head;
    tmp = NULL;

    while (cur->next != NULL) {
        if (strcmp(cur->name, name) == 0) {
            tmp = cur;
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            cur = cur->next;
            free(tmp);
        } else
            cur = cur->next;
    }
}
