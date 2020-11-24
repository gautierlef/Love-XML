#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List new_list(void)
{
    return NULL;
}


Bool is_empty_list(List li)
{
    if(li == NULL){
        return true;
    }
    return false;
}


int list_length(List li)
{
    int size = 0;

    if(!is_empty_list(li))
    {
        while(li != NULL)
        {
            ++size;
            li = li->next;
        }
    }

    return size;
}

void print_list(List li)
{
    if(is_empty_list(li))
    {
        printf("Liste vide")
        return;
    }

    while(li != NULL)
    {
        printf("%d", li->value);
        li = li->next;
    }
    printf("\n");
}


List push_back_list(List li, int x)
{
    ListElement *element;

    element = malloc(sizeof(*element));

    if(element == NULL)
    {
        fprintf(stderr, "Erreur : allocation dynamique");
        exit(EXIT_FAILURE);
    }

    element->value = x;
    element->next = NULL;

    if(is_empty_list(li))
    {
        return element;
    }

    ListElement *temp;
    temp = li;

    while(temp->newt != NULL)
    {
        temp = temp->next;
    }

    temp->next = element;

    return li;
}

