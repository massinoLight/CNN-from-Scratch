#include <math.h>
#include <time.h>

/*
Fichier de déclaration et déscription des fonctions utilisées 

*/



/*
Identité/Rampe

      f(x)=x
*/

double fIdentite(double x);

double DfIdentite(double x);

/*********************************************************** Marche/Heaviside *************************************************************************/

/*    _
     |
     |0 si x<0
f(x)=|1 si x>=0
     |_
*/

double fMarche(double x);



/**************************************************************  sigmoïde ******************************************************************************/

/*
            1
f(x)= ---------------
        1  + e(-x)
*/
double fsigmoid(double x);


double Dfsigmoid(double x);


/*
https://fr.wikipedia.org/wiki/Fonction_d%27activation#/media/Fichier:Activation_tanh.svg

            2
f(x)= --------------- -1
        1  + e(-2x)
*/
double tanhfs(double x);


double Dtanhfs(double x);
/***********************************************************   Unité de rectification linéaire (ReLU)  ****************************************************/



/*    _
     |
     |0 si x<0
f(x)=|x si x>=0
     |_
*/

double fRelu(double x);
double DfRelu(double x);


double somme(double tab[], double taille);


double random_w();
double *init_rand_w(double tableau[],int tailleTableau);
double init_bias();  
double *init_rand_tab(double tableau[],int tailleTableau);
void affiche(int *tableau, int tailleTableau);






