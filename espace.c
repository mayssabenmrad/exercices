#include <stdio.h>
#include <string.h>

void main() {
    // Get input from user
    char user_input[100];
    printf("Entrer un text: ");
    gets(user_input);

    // Determiner la longuer du texte donné
    int l = strlen(user_input);

    // Enlever tous les blancs dupliqués
    char resultat[100];

    for (int i = 0; i < l; i++) {
        int est_blanc = ((user_input[i] == ' ') || (user_input[i] == '\n') || (user_input[i] == '\t') || (user_input[i] == '\r'));

        int nextblanc = ((user_input[i + 1] == ' ') || (user_input[i + 1] == '\n') || (user_input[i + 1] == '\t') || (user_input[i + 1] == '\r'));

        if (est_blanc) {
            if (!nextblanc) {
                char espace = ' ';
                strncat(resultat, &espace, 1);
            }
        } else {
            strncat(resultat, &user_input[i], 1);
        }
    }

    char resultat_final[strlen(resultat)];
    if (resultat[0] == ' '){
        strcpy(resultat_final, resultat + 1);
    }

    // Afficher le resultat
    printf("Le resultat: %s\n", resultat_final);
}
