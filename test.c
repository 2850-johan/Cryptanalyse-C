#include <stdio.h>

// Fonction pour déchiffrer un message avec une clé donnée
void decrypt(int a, int b, char* ciphertext) {
    // Inverser la clé a
    int a_inv = 0;
    for (int i = 0; i < 26; i++) {
        if ((a * i) % 26 == 1) {
            a_inv = i;
            break;
        }
    }

    // Déchiffrer le message
    int i = 0;
    while (ciphertext[i] != '\0') {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            int c = (a_inv * (ciphertext[i] - 'A' - b + 26)) % 26;
            printf("%c", 'A' + c);
        } else if (ciphertext[i] >= 'a' && ciphertext[i] <= 'z') {
            int c = (a_inv * (ciphertext[i] - 'a' - b + 26)) % 26;
            printf("%c", 'a' + c);
        } else {
            printf("%c", ciphertext[i]);
        }
        i++;
    }
    printf("\n");
}

int main() {
    char ciphertext[100];
    printf("Entrez le texte chiffré : ");
    fgets(ciphertext, sizeof(ciphertext), stdin);

    printf("Clés possibles :\n");
    for (int a = 1; a < 26; a++) {
        for (int b = 0; b < 26; b++) {
            printf("Clé a = %d, b = %d : ", a, b);
            decrypt(a, b, ciphertext);
        }
    }

    return 0;
}

