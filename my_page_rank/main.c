#include <stdlib.h>
#include <stdio.h>


int nombre_de_page;
int nombre_de_lien;

struct arc{
	float val;
	int ori;
	int dest;	
};
typedef struct arc arc;

struct limite_double_inclusive{
	int debut;
	int fin;
};
typedef struct limite_double_inclusive limite;

/// objectif 
//stoquer la matrice
// 2 lectures 
// pour trouver le nombre d'element par collone  et ensuite pour les placer dedans


// numero page degre sortant (destination proba), destination proba


int main (){
// malloc de taille m pour le tableau irregulier

// malloc de taille n pour le tableau de comptage du nombre de lien 	
// collone = arc entrant


FILE* fichier = fopen("web1.txt", "r");

//fscanf(fichier, "%d %d %d", &score[0], &score[1], &score[2]);
// 1 ere ligne = nombre de page
fscanf(fichier,"%d",&nombre_de_page);
printf ("%d nombre de page \n",nombre_de_page);
// 2 emme ligne = nombre d'arc
fscanf(fichier,"%d",&nombre_de_lien);
printf ("%d nombre de lien \n",nombre_de_lien);


arc* tab = malloc(sizeof(arc) * nombre_de_lien);

//  remplissage du tab

float test;
fscanf(fichier,"%f",&test);
printf ("%f  test \n",test);







fclose(fichier);
return 0;

}
