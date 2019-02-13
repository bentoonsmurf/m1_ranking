#include <stdlib.h>
#include <stdio.h>
/*
g=[0
espace entre g(1.1) et g(1.2) retout chariot a l afin de lignee


alpha = 1 solution pour p 0.166 0.083 0.122 0.194 0.083 0.138 0.159 0.067

q= p*g retour ch
q*g
*/
int nombre_de_page;
int nombre_de_lien;

struct arc{
	double val;
	int ori;// origine
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


// numero_page degre_sortant (destination proba), destination proba


int main (){
// malloc de taille m pour le tableau irregulier

// malloc de taille n pour le tableau de comptage du nombre de lien 	
// collone = arc entrant


FILE* fichier = fopen("web1.txt", "r");


// 1 ere ligne = nombre de page
fscanf(fichier,"%d",&nombre_de_page);
printf ("%d nombre de page \n",nombre_de_page);


// 2 emme ligne = nombre d'arc
fscanf(fichier,"%d",&nombre_de_lien);
printf ("%d nombre de lien \n",nombre_de_lien);


int* degre_entran = malloc(sizeof(int) * (nombre_de_page+1));// on commence a 1 et pas a 0 
limite* tab_lim = malloc(sizeof(limite) * (nombre_de_page+1));
double* p = malloc(sizeof(double) * (nombre_de_page+1));
double* p_temp = malloc(sizeof(double) * (nombre_de_page+1));

//  init des variables

int num_page;
int nb_arc_sortant;
int i;
int nb_page_lu=0;
int destination;
double poid;
i=0;
while (i<nombre_de_page){
	degre_entran[i]=0;
	i++;
}printf("\n");
i=0;

while (i<nombre_de_page+1){
	p[i]=(double)1/nombre_de_page;
	p[i]=(double)0;
	i++;
}
//p[3]=(double)1;

while(nb_page_lu <nombre_de_page){

	fscanf(fichier,"%d",&num_page);

	fscanf(fichier,"%d",&nb_arc_sortant);
	//printf ("%d  test \n",nb_arc_sortant);


	i=0;
	while(i < nb_arc_sortant){
		
		fscanf(fichier,"%d",&destination);
		printf("dest %d ",destination);
		fscanf(fichier,"%lf",&poid);	
		degre_entran[destination]=degre_entran[destination]+ 1;
		printf("degr %d ",degre_entran[destination]);
		i ++;
	}
printf("\n");

	nb_page_lu++;
}
//fin de la premiere lecture

// remplissage du tableau qui dit ou start et ou finissent les pages
tab_lim[0].debut=-1;
tab_lim[0].fin=-1;//degre_entran[0];  page 0 n'existe pas en theorie
for (i=1; i < nombre_de_page+1;i++){
	
	if(degre_entran[i]==0){
			
		tab_lim[i].debut=-1;
		tab_lim[i].fin=tab_lim[i-1].fin;
	}
	else{
		
		tab_lim[i].debut=tab_lim[i-1].fin +1;
		tab_lim[i].fin=tab_lim[i].debut + degre_entran[i]-1;
		printf("page  %d : degre entran %d , lim [%d , %d]\n",i,degre_entran[i],tab_lim[i].debut,tab_lim[i].fin);
	}
}

fclose(fichier);

/// ////////////////////////////////////////////////////////
// deuxiemme lecture
// remplissage du tableau d'arc
fichier = fopen("web1.txt", "r");

// lire les deux premieres lignes 
fscanf(fichier,"%d",&nombre_de_page);
fscanf(fichier,"%d",&nombre_de_lien);

arc* tab_arc = malloc(sizeof(arc) * nombre_de_lien);


nb_page_lu=0;

while(nb_page_lu <nombre_de_page){

	fscanf(fichier,"%d",&num_page);
	fscanf(fichier,"%d",&nb_arc_sortant);
	//printf ("%f  test \n",nb_arc_sortant);


	i=0;
	while(i < nb_arc_sortant){
		
		fscanf(fichier,"%d",&destination);
		fscanf(fichier,"%lf",&poid);	
		// je peut remplir tab_arc de [tab_lim.debut : tab_lim.fin]
		tab_arc[tab_lim[destination].debut + degre_entran[destination] -1].val=poid;//[.....] --> [....A] ---> [...BA]
		tab_arc[tab_lim[destination].debut + degre_entran[destination] -1].ori=num_page;
		tab_arc[tab_lim[destination].debut + degre_entran[destination] -1].dest=destination;
		degre_entran[destination] = degre_entran[destination] -1 ;
		i ++;
	}


nb_page_lu++;
}
fclose(fichier);

i=0;
while (i<nombre_de_lien){
	printf("%d ",i);
	printf("destination  %d ,",tab_arc[i].dest);
	printf("origine %d ,",tab_arc[i].ori);
	printf("val %f, ",tab_arc[i].val);
	printf("\n");
	i++;
}

// tab_arc contien maintenant touts les arcs trié par page d'arrivé


// tab[n]

	for(i=0;i<nombre_de_page+1;i++){
		p[i]=(double)1/nombre_de_page;
	}
i=0;
int j;
double somme=0;
int precision=0;
while(precision<1000	){
	while(i<nombre_de_page+1)
	{
		if(tab_lim[i].debut !=-1){
			
			for (j=tab_lim[i].debut ;  j<tab_lim[i].fin+1 ;j++){
				// (j,tab_arc[j].
				// i represente le numero de la page 
				// j represente l'indice de l'arc a traiter dans tab_arc
				// tab_lim[i]
				// p[ tab_arc[] ]
				// il faut mult l'indice de ligne avec l'origine de la matrice
				// dans ma matrice j'ai la val (4,1) et (8,1) a mult avec p(4) et p (1)
				//
				
				
				somme = somme+ 	p[tab_arc[j].ori]   *  tab_arc[j].val;// erreur
				printf("tab_arc.ori %d pourcent %lf somme : %lf\n",tab_arc[j].ori,p[tab_arc[j].ori],somme);
			}
			printf("%d \n",i);
			
			p_temp[i]= somme;	
			somme=0;
		}
		i++;
	}
	for(i=0;i<nombre_de_page+1;i++){
		p[i]=p_temp[i];
	}
	i=1;
	double somme2=0;
	while (i<nombre_de_page+1){
		printf("p[%d] = %lf ",i,p[i]);
		somme2=somme2+p[i];
		printf("\n");
		i++;
	}
	printf(" somme = %lf",somme2);
	printf("\n");
	j=0;
	i=0;
	precision++;
	
	
}
	


return 0;

}
