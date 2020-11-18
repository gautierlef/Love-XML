#include <my.h>

int checkElements(char *xml, Element *elements) {
	int indexElement = 0;
	int match = 1;
	int j = 0;
	for (int i = 0; xml[i + 1] != '\0'; i = i + 1) {
		if (xml[i] == '<' && xml[i + 1] != '?') {							//On vérifie la balise d'ouverture.
			if (xml[i + 1] == '/') {										//On vérifie la balise de fermeture.
				i = i + 1;
			}
			i = i + 1;
			while (elements[indexElement].name[0] != '\0' && match == 1) {	//On parcours les éléments tant que l'on ne trouve pas une correspondance.
				while (xml[i + j] != '>' && xml[i + j] != ' ') {			//Tant que l'on ne trouve pas la fermeture de la balise.
					if (xml[i + j] != elements[indexElement].name[j]) {		//On vérifie caractère par caractère que le nom de la balise correspond à un élément.
						indexElement = indexElement + 1;					//Si on noter une différence on passe à l'élément suivant et on recompare les 2 chaines.
						j = 0;
						break;
					}
					j = j + 1;
				}
				if (j + 1 == strlen(elements[indexElement].name)) {			//On vérifie que la longueur du nom de l'élément correspond à la longueur de celui de la balise.
					match = 0;												//Si cela correspond on sort de la boucle.
				} else {
					indexElement = indexElement + 1;						//Sinon il n'y a pas de correspondance et on passe à l'élément suivant.
				}
				j = 0;
			}
			if (match != 0) {												//Si aucune correspondace n'est trouvé par rapport aux éléments de la DTD, on retourne une erreur.
				printf("Un élement du fichier xml n'a pas été déclaré dans la dtd!\n");
			return -1;
			}
			i = i + strlen(elements[indexElement].name);					//On ajoute la longueur du nom de l'élément pour économiser des itérations non nécessaires.
		}
		match = 1;
		indexElement = 0;
	}
	return 0;
}
