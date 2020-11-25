#include <my.h>

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
