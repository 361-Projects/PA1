/********************************************************
 * PROGRAM: PA1 - Linked Lists                          *
 * CLASS: CISC 361-011                                  *
 * AUTHORS:                                             *
 *    Alex Sederquest | alexsed@udel.edu | 702414270    *
 *    Ben Segal | bensegal@udel.edu | 702425559         *
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct node
{
    char *name;
    int   data;
    struct node *next;
    struct node *prev;
} node_t; 
