#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

int checkFiles();							//Vérification de l'existence des fichiers.
char *getFileContent(char *filePath);		//Récupération du contenu d'un fichier.
int checkOpenEndDTD(char *dtd);					//Vérification du nombre d'élément dans la dtd
void removeMultipleSpaces(char *str);		//Remplace les espaces multiples par un espace.
void replaceTabAndLineWithSpace(char *str);	//Remplace les \t et \n par un espace.

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
//	checkStartToEndDTD(dtdContent);
	if (checkOpenEndDTD(dtdContent) == -1) {
		printf("\nErreur\n");
		return -1;
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


int checkOpenEndDTD(char *dtd) {
	int nbOp = 0;
	if (dtd[0] != '<' && dtd[1] != '!') {	//On vérifie que les 2 premiers caractères correspondent à l'ouverture d'une DTD.
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
