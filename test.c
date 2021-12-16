#include <stdio.h>
#include <stdlib.h>
#include "fonction.c"
#include "init.c"



void init_n_conf(int tailleVecteur)
{
    s_Reseau.n=tailleVecteur;
    
}


int main()
{
srand(time(NULL));
double vecteur[10] = {1.0, 3.0, 7.0, 3.0,2.0,7.0,4.0,2.0,1.0,0.0};   
init_n_conf(10);
s_Layer layer1;
layer1.n=3;
 s_Neurone* chouche1 = malloc(layer1.n * sizeof *(chouche1));


 for (int x = 0; x < layer1.n; x++)
    {
        chouche1[x]=init_neurone(vecteur ,ReLU);
       
    }


for (int x = 0; x < layer1.n; x++)
    {
        printf("%f  \n", chouche1[x].sortie);
        
        
       
    }


    









return 0;

}
