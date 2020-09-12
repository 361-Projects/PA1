#include "mp3.h"

extern node_t *head;

void printFTB()
{
  node_t *temp;
  int  i = 0;

  temp = head;

  while (temp != NULL) {
    printf("(%d)--%s--%d--\n", ++i, temp->name, temp->data);
    temp = temp->next;
  }
}

void printBTF()
{
  node_t *tmp;
  int i = 2;
  tmp = head;

  node_t *last = NULL;

  while (tmp->next != NULL) {
    tmp = tmp->next;
    i++;
  }
  //i++;
  last = tmp;

  while (tmp != NULL) {
    printf("(%d)--%s--%d--\n", --i, tmp->name, tmp->data);
    tmp = tmp->prev;
  }
}
