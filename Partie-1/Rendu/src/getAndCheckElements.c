#include <my.h>

void getAttributs(Element element) {
	
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
			getAttributs(elements[indexElement]);
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
