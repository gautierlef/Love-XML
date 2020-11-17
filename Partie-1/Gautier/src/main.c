#include <my.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

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
