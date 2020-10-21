#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int checkFiles();						//Vérification de l'existence des fichiers.
char *getFileContent(char *filePath);	//Récupération du contenu d'un fichier.
int checkStartToEndDTD();				//Vérification du début et de la fin de la DTD.

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
	printf("DTD :\n%s", dtdContent);
	printf("\nXML :\n%s", xmlContent);
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

/*
int checkStartToEndDTD() {
	
}*/
