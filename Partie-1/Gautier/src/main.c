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


int checkFiles();							//Vérification de l'existence des fichiers.
char *getFileContent(char *filePath);		//Récupération du contenu d'un fichier.
int checkOpenEndDTD(char *dtd);				//Vérification du nombre d'élément dans la dtd.
void removeMultipleSpaces(char *str);		//Remplace les espaces multiples par un espace.
void replaceTabAndLineWithSpace(char *str);	//Remplace les \t et \n par un espace.
Element *getElements(char *dtd);			//Récupération des éléments de la DTD sous la forme d'un tableau de structures "Element".

int main(int argc, char **argv)
{
	if (argc != 3) {	//Vérification du nombre d'arguments donnés au lancement.
		printf("Invalids number of arguments : DTD file name - XML file name\n");
		return -1;
	}
	if (checkFiles(argv[1], argv[2]) == -1) {
		return -1;
	}
	char *dtdContent = getFileContent(argv[1]);
	char *xmlContent = getFileContent(argv[2]);
	replaceTabAndLineWithSpace(dtdContent);
	replaceTabAndLineWithSpace(xmlContent);
	removeMultipleSpaces(dtdContent);
	removeMultipleSpaces(xmlContent);
	printf("DTD :\n%s\n", dtdContent);
	printf("XML :\n%s\n", xmlContent);
	if (checkOpenEndDTD(dtdContent) == -1) {
		printf("\nErreur\n");
		return -1;
	}
	Element *elements = getElements(dtdContent);
	for (int i = 0; elements[i].name[0] != '\0'; i = i + 1) {
		printf("Element numéro %d : %s\n", i, elements[i].name);
	}
	return 0;
}

int checkFiles(char* dtd, char* xml) {
	if (access(dtd, F_OK) == -1) {		//Vérification de l'existence du fichier DTD.
		printf("No DTD file named %s found in the directory!\n", dtd);
		return -1;
	}
	if (access(xml, F_OK) == -1) {		//Vérification de l'existence du fichier XML.
		printf("No XML file named %s found in the directory!\n", xml);
		return -1;
	}
	return 0;
}

char *getFileContent(char *filePath) {
	FILE *file = fopen(filePath, "r");
	fseek(file, 0, SEEK_END);
	unsigned int fileSize = ftell(file);	//Détermination de la longueur du fichier.
	fseek(file, 0, SEEK_SET);
	char *content = malloc(fileSize + 1);	//Attribution de la mémoire.
	fread(content, 1, fileSize, file);		//Lecture et création de la chaine de caractères.
	fclose(file);
	return content;
}

void replaceTabAndLineWithSpace(char* str) {
	for (int i = 0; str[i] != '\0'; i = i + 1) {
		if (str[i] == '\t' || str[i] == '\n') {
			str[i] = ' ';
		}
	}
}

void removeMultipleSpaces(char *str)
{
    char *dest = str;
    while (*str != '\0') {
        while (*str == ' ' && *(str + 1) == ' ') {
            str++;
		}
       *dest++ = *str++;
    }
    *dest = '\0';
}

Element *getElements(char *dtd) {
	Element *elements = malloc(sizeof(Element) * 100);
	int indexElement = 0;
	for (int i = 0; dtd[i + 10] != '\0'; i = i + 1) {
		if (dtd[i] == '<' && dtd[i + 1] == '!' && dtd[i + 2] == 'E' && dtd[i + 3] == 'L' && dtd[i + 4] == 'E' && dtd[i + 5] == 'M' && dtd[i + 6] == 'E' && dtd[i + 7] == 'N' && dtd[i + 8] == 'T' && dtd[i + 9] == ' ') {	//On cherche les déclarations d'éléments : "<!ELEMENT ".
			i = i + 10;
			int j = 0;
			elements[indexElement].name = malloc(sizeof(char) * 100);
			while (dtd[i] != '(') {
				elements[indexElement].name[j] = dtd[i];
				j = j + 1;
				i = i + 1;
			}
			elements[indexElement].name[j] = '\0';
			indexElement = indexElement + 1;
		}
	}
	elements[indexElement].name = malloc(sizeof(char) * 2);
	elements[indexElement].name[0] = '\0';
	return elements;
}

int checkOpenEndDTD(char *dtd) {
	int nbOp = 0;
	if (strlen(dtd) < 10) {
		return -1;
	}
	if (dtd[0] != '<' && dtd[1] != '!' && dtd[2] != 'D' && dtd[3] != 'O' && dtd[4] != 'C' && dtd[5] != 'T' && dtd[6] != 'Y' && dtd[7] != 'P' && dtd[8] != 'E') {	//On vérifie que le fichier commence bien par : "<DOCTYPE".
		return -1;
	}
	for (int i = 0; dtd[i + 1] != '\0'; i = i + 1) {	//On compte les ouvertures : <! et fermeture : > afin de vérifier que le nombre d'ouverture corresponde au nombre de fermeture d'élément.
		if (dtd[i] == '<' && dtd[i + 1] == '!') {
			nbOp = nbOp + 1;
		}
		if (dtd[i] == '>') {
			nbOp = nbOp - 1;
		}
	}
	if (nbOp != 0) {
		return -1;
	}
	return 0;
}
