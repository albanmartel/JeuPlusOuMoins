#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_CHAR (int)10e2
#include "jeu.h"

p_donneeJeu intialisation(p_donneeJeu donneeInit){
    donneeInit = (p_donneeJeu) malloc(sizeof(s_donneeJeu));

    if (donneeInit == NULL){
        fprintf(stderr , "erreur d'allocation\n");
        return (p_donneeJeu) EXIT_FAILURE;
    }
    memset(donneeInit->invite , 0 , MAX_CHAR);
    memset(donneeInit->dessous , 0 , MAX_CHAR);
    memset(donneeInit->reussite , 0 , MAX_CHAR);
    donneeInit->MAX = -1;
    donneeInit->MIN = -1;
    donneeInit->nombreMystere = -1;
    donneeInit->nombreUtilisateur = -1;
    donneeInit->res  = -1;
    donneeInit->compteur  = 0;

    return donneeInit;
}


int genererNombreMystere(p_donneeJeu donneeInit){

    srand(time(NULL));

    return (rand() % (donneeInit->MAX - donneeInit->MIN + 1)) + donneeInit->MIN;
}

p_donneeJeu definition(p_donneeJeu donneeInit ){
    if (donneeInit == NULL){
        fprintf(stderr , "pas de structure en entree !\n");
        return (p_donneeJeu) EXIT_FAILURE;
    }
    strcpy(donneeInit->invite ,  "Quel est le nombre Mystère ?\n");
    strcpy(donneeInit->dessus , "C'est Moins !\n");
    strcpy(donneeInit->dessous , "C'est Plus !\n");
    strcpy(donneeInit->reussite , "Bravo vous avez trouvez le nombre mystère en");
    donneeInit->MAX = 100;
    donneeInit->MIN = 0;
    donneeInit->nombreMystere = genererNombreMystere(donneeInit);

    return donneeInit;
}


void desallocation(p_donneeJeu donneeInit){
    free(donneeInit);
    donneeInit = NULL;
}


int lectureClavier(p_donneeJeu donneeInit){
    int test = 0;
    int nombre;
    do{
        float saisie;
        printf("Entrez un nombre entier : \n");

        test = scanf("%f",&saisie);

        // Vider le buffer
        scanf("%*[^\n]%*c");
        // vérifier que la saisie est un nombre entier
        if(saisie != (int)saisie){
            test = 0;
        } else {
            donneeInit->nombreUtilisateur = saisie;
        }


    }while(test!=1);

    return EXIT_SUCCESS;
}


int gestionCasUtilisation(p_donneeJeu donneeInit){

    do {
        printf("%s", donneeInit->invite);
        lectureClavier(donneeInit);
        donneeInit->compteur++;
        if(donneeInit->nombreUtilisateur < donneeInit->nombreMystere){
            printf("%s", donneeInit->dessous);
        } else if (donneeInit->nombreUtilisateur > donneeInit->nombreMystere){
            printf("%s", donneeInit->dessus);
        } else {
            printf("%s %d coups!!!\n", donneeInit->reussite, donneeInit->compteur);
        }
    } while(donneeInit->nombreUtilisateur != donneeInit->nombreMystere);

    return EXIT_SUCCESS;

}


int jeu(p_donneeJeu donneeInit){
    donneeInit = intialisation(donneeInit);
    donneeInit = definition(donneeInit);

    gestionCasUtilisation(donneeInit) ;

    desallocation(donneeInit);

    return EXIT_SUCCESS;

}


int main(int argc , char *argv[]){
    p_donneeJeu donneeInit;


    jeu(donneeInit);

    return EXIT_SUCCESS;
}
