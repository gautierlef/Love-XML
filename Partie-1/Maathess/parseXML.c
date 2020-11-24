#include <my.h>
#include <stdlib.h>

int parseXML(char *xml, Element *elements) {
	//int indexElement = 0;
	int j = 0;
	for (int i = 0; xml[i + 1] != '\0'; i = i + 1) {
		if (xml[i] == '<' && xml[i + 1] != '?') { //On vérifie la balise d'ouverture.
			if (xml[i + 1] == '/') {		//On vérifie la balise de fermeture.
				i = i + 1;
			}

			}

		else {								

			printf("Le Prolog du fichier XML est inexistant!\n");
			exit( EXIT_FAILURE );
		}

			while (elements[indexElement].name[0] != '\0'/* && ... */) {	// On parcours jusqu'à la fin de chaîne
				while (xml[i + j] != '>' && xml[i + j] != ' ') {			//Tant que l'on ne trouve pas la fermeture de la balise.
					/*if (xml[i + j] != elements[indexElement].name[j]) {		//On vérifie caractère par caractère que le nom de la balise correspond à un élément.
						indexElement = indexElement + 1;					//Si on noter une différence on passe à l'élément suivant et on recompare les 2 chaines.
						j = 0;
						break;
					}*/
					j = j + 1;
}

		}
		indexElement = 0;



	return 0;
}

///////////////TODO////////////////////////
//les premieres balises (voir avec partie 2)
//checker les données en brutes (regex)
//la case des tag
// la fermeture des balise dans l'ordre
//les entity references en XML (&lt; &gt; &amp; &apos; &quot;...)
//les commentaires en XML
