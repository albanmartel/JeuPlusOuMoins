#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CHAR (int)10e3

/**
* Structure de donnees pour le jeu
*
**/
typedef struct donneeJeu{
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
} s_donneeJeu, *p_donneeJeu;



/**
* Initialisation de la structure donneeJeu
* @param[in] la structure elle-même
***/
p_donneeJeu intialisation();


/**Genere un nombre aleatoire avex srand l'heureu et rand
* @param[in] la structure de donnees elle-même
**/
int genererNombreMystere();


/**desaloue la structure de donnees
* @param[in] la structure de donnees elle-même
**/
void desallocation();

/**
* lectureClavier
* @param[in] structure de donnees
* fait une lecture au claviers console
* tant qu'un entier n'est pas rentre la saisie est redemandee
**/
int lectureClavier(p_donneeJeu donneeInit);

/** gestionCasUtilisation
* @param[in] la structure de donnees elle-même
* Compare les nombres entre eux pour indiquer comment reduire l'interval du nombre mystere
**/
int gestionCasUtilisation(p_donneeJeu donneeInit);


/** Jeu
* @param[in] la structure de donnees elle-même
*lance le jeu
**/
int jeu(p_donneeJeu donneeInit);


/**
* point d'entree du programme
*
**/
int main(int argc , char *argv[]);



#endif // JEU_H_INCLUDED
