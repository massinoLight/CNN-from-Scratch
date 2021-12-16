#include <stdio.h>
#include <stdlib.h>
#include "fonction.c"
#include "init.c"


void visalisation(s_Layer layer1){

for (int x = 0; x < layer1.n; x++)
    {
        printf("********************\n");
        for (int j = 0; j < s_conf.n; j++)
        {
        if (j==(s_conf.n/2))
        {
           printf("* %f ,%f *------->%f \n", layer1.couche[x].x[j],layer1.couche[x].w[j],layer1.couche[x].sortie);
        }
        
        printf("* %f ,%f *\n", layer1.couche[x].x[j],layer1.couche[x].w[j]);
      }
        printf("\n********************");
       
    }

printf("\n");
}




int main()
{
srand(time(NULL));
double vecteur[10] = {1.0, 3.0, 7.0, 3.0,2.0,7.0,4.0,2.0,1.0,0.0};  
//on initalise la taille du vecteur d'entre je met 10 au depart mais on va recup ca selon les images dentrées  
init_n_conf(10);
s_Reseau perceptron=init_perceptron(vecteur,3);

for (int x = 0; x < perceptron.nb; x++)
    {
         printf("couche %d\n",x);
         visalisation(perceptron.couches[x]);
       
    }

return 0;

}



