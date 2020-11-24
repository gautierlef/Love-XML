#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "list.h"

int main(int argc, char *argv[])
{
    // initialisation variables
    //char folderContent[200] = "<?xml version='1.0'?><classrooms><classroom>AL</classroom><classroom>IABD</classroom><classroom>MOC</classroom><classroom>IBC</classroom></classrooms>";
    //int cpt = 0;
    //int isParent = 0;

    List mylist = new_list();

    print_list(mylist);

    /* Marche pour les Balise de même niveau
    Element *element = malloc(sizeof(*element));

    // traitement
    for(int i=0 ; i<200-1 ; i++){
        if((folderContent[i] == '<')&&(folderContent[i+1] != '/')){
            cpt += 1;
            isParent +=1;

            if(isParent == 2){
                element->nombre = cpt;
                //element->suivant = NULL;
                isParent = 0;
            }


            //printf("Plus ");
            //printf("%d", cpt);
        }
        if((folderContent[i] == '<')&&(folderContent[i+1] == '/')) {
            cpt -= 1;
            //printf("Moins ");
            //printf("%d", cpt);
        }
    }

    printf("%d", cpt);

    return 0;

    //// Si au même niveau ça marche très bien
    /*
    char folderContent[200] = "<classroom>AL</classroom><classroom>IABD</classroom><classroom>MOC</classroom><classroom>IBC</classroom>";
    int cpt = 0;
    for(int i=0 ; i<200-1 ; i++){
        if((folderContent[i] == '<')&&(folderContent[i+1] != '/')){
            cpt += 1;
        }
        if((folderContent[i] == '<')&&(folderContent[i+1] == '/')) {
            cpt -= 1;
        }
    }

    printf("%d", cpt);

    */
    return 0;

}
