#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

typedef struct Element Element;
struct Element {
	char *name;
    Element *type;
    int quantitator;
};

int checkFiles();									//Vérification de l'existence des fichiers.
char *getFileContent(char *filePath);				//Récupération du contenu d'un fichier.
int checkOpenEndDTD(char *dtd);						//Vérification du nombre d'élément dans la dtd.
void removeMultipleSpaces(char *str);				//Remplace les espaces multiples par un espace.
void replaceTabAndLineWithSpace(char *str);			//Remplace les \t et \n par un espace.
Element *getElements(char *dtd);					//Récupération des éléments de la DTD sous la forme d'un tableau de structures "Element".
int checkElements(char *xml, Element *elements);	//Vérification des éléments utilisés dans le XML.
