/*
Fichier de déclaration et déscription des fonctions utilisées 

*/


/*
Identité/Rampe

      f(x)=x
*/

double fIdentite(int x);



/*********************************************************** Marche/Heaviside *************************************************************************/

/*    _
     |
     |0 si x<0
f(x)=|1 si x>=0
     |_
*/

double fMarche(int x);



/**************************************************************  sigmoïde ******************************************************************************/

/*
            1
f(x)= ---------------
        1  + e(-x)
*/
double fsigmoid(int x);


/*
https://fr.wikipedia.org/wiki/Fonction_d%27activation#/media/Fichier:Activation_tanh.svg

            2
f(x)= --------------- -1
        1  + e(-2x)
*/
double tanhf(int x);

/***********************************************************   Unité de rectification linéaire (ReLU)  ****************************************************/



/*    _
     |
     |0 si x<0
f(x)=|x si x>=0
     |_
*/

double fRelu(int x);


double somme(int tab[], int taille);


double random_w();

double *init_rand_tab(int tailleTableau);
void affiche(int *tableau, int tailleTableau);



