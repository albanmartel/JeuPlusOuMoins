#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CHAR (int)10e6

typedef struct constantes{
    char invite[MAX_CHAR];
    char dessus[MAX_CHAR];
    char dessous[MAX_CHAR];
    char reussite[MAX_CHAR];
    int MAX;
    int MIN;
    int nombreMystere;
    int nombreUtilisateur;
    int res;
    int compteur;
} s_constantes, *p_constantes;

p_constantes intialisation(p_constantes donneeInit){
    donneeInit = (p_constantes) malloc(sizeof(s_constantes));

    if (donneeInit == NULL){
        fprintf(stderr , "erreur d'allocation\n");
        return (p_constantes) EXIT_FAILURE;
    }
    memset(donneeInit->invite , 0 , MAX_CHAR);
    memset(donneeInit->dessous , 0 , MAX_CHAR);
    memset(donneeInit->reussite , 0 , MAX_CHAR);
    donneeInit->MAX = 0;
    donneeInit->MIN = 0;

    return donneeInit;
}

p_constantes definition(p_constantes donneeInit ){
    if (donneeInit == NULL){
        fprintf(stderr , "pas de structure en entree !\n");
        return (p_constantes) EXIT_FAILURE;
    }
    strcpy(donneeInit->invite ,  "Quel est le nombre Mystère ?\n");
    strcpy(donneeInit->dessus , "C'est Moins !\n");
    strcpy(donneeInit->dessous , "C'est Plus !\n");
    strcpy(donneeInit->reussite , "Bravo vous avez trouvez le nombre mystère en");
    donneeInit->MAX = 100;
    donneeInit->MIN = 0;

    return donneeInit;
}

void desallocation(p_constantes donneeInit){
    free(donneeInit);
    donneeInit = NULL;
}

int jeu(p_constantes donneeInit){

}

int main(int argc , char *argv[]){
    p_constantes donneeInit;
    donneeInit = intialisation(donneeInit);
    donneeInit = definition(donneeInit);
    int nombreMystere = 0 , nombreUtilisateur = 0, res = 0 , compteur = 0;

    srand(time(NULL));
    nombreMystere = (rand() % (donneeInit->MAX - donneeInit->MIN + 1)) + donneeInit->MIN;

    do {
        res = 0;
        printf("%s", donneeInit->invite);
        res = scanf("%d", &nombreUtilisateur);
        if (res == 0){
            printf("Erreur de format!");
            res = scanf("%d", &nombreUtilisateur);
            return EXIT_FAILURE;
        }
        compteur++;
        if(nombreUtilisateur < nombreMystere){
            printf("%s", donneeInit->dessous);
        } else if (nombreUtilisateur > nombreMystere){
            printf("%s", donneeInit->dessus);
        } else {
            printf("%s %d coups!!!\n", donneeInit->reussite, compteur);
        }
    } while(nombreUtilisateur != nombreMystere);

    desallocation(donneeInit);

    return EXIT_SUCCESS;
}
