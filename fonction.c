
#include "fonction.h"



double fIdentite(double x){

return x;
}

/******************************************************************************************************************************/

double fMarche(double x){

 if(x<0)
    return 0;
 else
    return 1;

}


/******************************************************************************************************************************/


double fsigmoid(double x){

 return 1/(1+exp(-x));
}



/******************************************************************************************************************************/



double tanhfs(double x){

 return (2/(1+exp(-2*x)))-1;
}



/******************************************************************************************************************************/
double fRelu(double x){

 if(x<0)
    return 0.0;
 else
    return x;

}




/******************************************************************************************************************************/
double somme(double tab[], double taille) {
   int i;

   double sum = 0;
   for (i = 0; i < taille; ++i) {
      sum += tab[i];
   }

   return sum;
}



/******************************************************************************************************************************/
double random_w() { 
   srand ( time(NULL) );
   return ((double)rand())/((double)RAND_MAX); 
}


/******************************************************************************************************************************/
double *init_rand_tab(int tailleTableau) { 

     
    
    double *tableau=malloc(tailleTableau*sizeof(double));
     for (int i = 0 ; i < tailleTableau ; i++)
    {
        tableau[i]=random_w();
    }
   return  tableau;
}


/******************************************************************************************************************************/
void affiche(int *tableau, int tailleTableau)
{
    int i;
 
    for (i = 0 ; i < tailleTableau ; i++)
    {
        printf("%d\n", tableau[i]);
    }
}

/*********************************************************************************************************************************/







