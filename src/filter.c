#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fonction pour vérifier si un mot contient une lettre spécifique
int contientLettre(char* mot, char lettre) {
    return strchr(mot, lettre) != NULL;
}

// Fonction pour lire les mots d'un fichier et les filtrer
void filtreMots(char* cheminFichier, char lettre) {
    FILE* fichier = fopen(cheminFichier, "r");
    if (fichier == NULL) {
        printf("Impossible d'ouvrir le fichier %s\n", cheminFichier);
        return;
    }

    char mot[100];
    while (fscanf(fichier, "%s", mot) != EOF) {
        if (contientLettre(mot, lettre)) {
            printf("%s\n", mot);
        }
    }

    fclose(fichier);
}

int main() {
    filtreMots("/home/Linux/wordle_sharon/src/bdd_wordle.txt", 'a');
    return 0;
}
