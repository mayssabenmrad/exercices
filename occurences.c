#include <stdio.h>
#include <string.h>

void main() {
    // chaine
    char phrase[100];
    printf("Entrer une phrase: ");
    gets(phrase);

    char mots[100][50];

    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 50; ++j) {
            mots[i][j] = '\0';
        }
    }

    int nombre_de_mots = 0;

    int z = 0;
    // remplir le tableau avec les mots de la chaine
    for (int k = 0; k <= strlen(phrase); ++k) {

        if (phrase[k] == ' ' || phrase[k] == '\0') {

            strncpy(mots[nombre_de_mots], phrase + z, k - z);
            nombre_de_mots++;
            z = k + 1;
        }
    }

    int occurences[nombre_de_mots];

    for (int occurence_pos = 0; occurence_pos < nombre_de_mots; ++occurence_pos) {
        occurences[occurence_pos] = 1;
    }

    int position_de_mot = 0;

    while (position_de_mot < nombre_de_mots) {
        for (int mot = position_de_mot + 1; mot < nombre_de_mots; ++mot) {
            if (strlen(mots[mot]) > 0) {
                if (strcmp(mots[position_de_mot], mots[mot]) == 0) {
                    occurences[position_de_mot]++;
                    mots[mot][0] = '\0';
                }
            }
        }
        position_de_mot++;
    }

    //afficher les résultats
    for (int word = 0; word < nombre_de_mots; ++word) {
        if (mots[word][0] != '\0') {
            printf("Le mot %s est repeté %d fois\n", mots[word], occurences[word]);
        }
    }
}
