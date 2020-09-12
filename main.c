/********************************************************
 * PROGRAM: PA1 - Linked Lists                          *
 * CLASS: CISC 361-011                                  *
 * AUTHORS:                                             *
 *    Alex Sederquest | alexsed@udel.edu | 702414270    *
 *    Ben Segal | bensegal@udel.edu | 702425559         *
 ********************************************************/

#include "mp3.h"
#define  BUFFERSIZE 128

node_t *head;

void insert(char *name, int data);
void printFTB();
void printBTF();
void freeList();
void delete(char *name);

int main()
{
  int i, num, len;
  struct node *n;
  char buffer[BUFFERSIZE], c;

  head = NULL;

  while (1) {
    printf("\nList Operations\n");
    printf("===============\n");
    printf("(1) Insert\n");
    printf("(2) Delete\n");
    printf("(3) Display (beginning to end)\n");
    printf("(4) Display (end to beginning)\n");
    printf("(5) Exit\n");
    printf("Enter your choice : ");
    if (scanf("%d%c", &i, &c) <= 0) {          // use c to capture \n
        printf("Enter only an integer...\n");
        exit(0);
    } else {
        switch(i)
        {
        case 1: printf("Enter the name to insert : ");
		        if (fgets(buffer, BUFFERSIZE , stdin) != NULL) {
                  len = strlen(buffer);
                  buffer[len - 1] = '\0';   // override \n to become \0
                } else {
                    printf("wrong name...");
                    exit(-1);
                  }
                printf("Enter the number to insert : ");
                scanf("%d%c", &num, &c);  // use c to capture \n
                printf("[%s] [%d]\n", buffer, num);
                insert(buffer, num);
                break;
        case 2: if (head == NULL){
                  printf("List is Empty\n");
                  break;
                }
                printf("Enter the name to be deleted : ");
		        if (fgets(buffer, BUFFERSIZE , stdin) != NULL) {
                  len = strlen(buffer);
                  buffer[len - 1] = '\0';   // override \n to become \0
                } else {
                    printf("wrong name...");
                    exit(-1);
                  }
                delete(buffer);
                break;
        case 3: if (head == NULL)
                  printf("List is Empty\n");
                else
                  printFTB();
                break;
        case 4: if (head == NULL)
                  printf("List is Empty\n");
                else
                  printBTF();
                break;
        case 5: freeList();
                return 0;
        default: printf("Invalid option\n");
        }
    }
  }
  return 0;
}
