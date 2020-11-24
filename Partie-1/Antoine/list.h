#ifndef __LIST__H__
#define __LIST__H__

/* D�finition du type bool�en */
typedef enum
{
    false,
    true
}Bool;

/* D�finition d'une liste */
typedef struct ListElement
{
    int value;
    struct ListElement *next;
}ListElement, *List;

/* Prototypes */
List new_list(void);
Bool is_empty_list(List li);
int list_length(List li);
void print_list(List li);
List push_back_list(List li, int x);

#endif // __LIST__H__
