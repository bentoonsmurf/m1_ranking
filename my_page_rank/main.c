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

struct limite_double_inclusive{// l indice du tableau correspond au num de la page
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

int* degre_entran = malloc(sizeof(int) * nombre_de_page);
limite* tab_lim = malloc(sizeof(limite) * nombre_de_page);

// 2 emme ligne = nombre d'arc
fscanf(fichier,"%d",&nombre_de_lien);
printf ("%d nombre de lien \n",nombre_de_lien);


arc* tab = malloc(sizeof(arc) * nombre_de_lien);

//  remplissage du tab


int num_page;
int nb_arc_sortant;
int i;
int nb_page_lu=0;
int destination;
float poid;
while(nb_page_lu <nombre_de_page){

	fscanf(fichier,"%d",&num_page);

	fscanf(fichier,"%d",&nb_arc_sortant);
	//printf ("%f  test \n",nb_arc_sortant);


	i=0;
	while(i < nb_arc_sortant){
		
		fscanf(fichier,"%d",&destination);

		fscanf(fichier,"%f",&poid);	
		degre_entran[destination]=degre_entran[destination]+ 1;
		i ++;
	}


nb_page_lu++;
}
//fin de la premiere lecture

// remplissage du tableau qui dit ou start et ou finissent les pages
tab_lim[0].debut=0;
tab_lim[0].fin=degre_entran[0];
for (i=1; i < nombre_de_page;i++){
	
	tab_lim[i].debut=tab_lim[i-1].fin +1;
	tab_lim[i].fin=tab_lim[i].debut + degre_entran[i];
	printf("page  %d : degre entran %d \n",i,degre_entran[i]);
}



fclose(fichier);
return 0;

}
