#include <stdio.h>
#include <stdlib.h>
#include "fonction.c"
#include "init.c"


void visalisation(s_Layer layer1){

for (int x = 0; x < layer1.n; x++)
    {
        printf("********************\n");
        for (int j = 0; j < s_Reseau.n; j++)
        {
        if (j==(s_Reseau.n/2))
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
init_n_conf(10);

s_Layer layer1;
layer1.n=3;
 s_Neurone* chouche1 = malloc(layer1.n * sizeof *(chouche1));


 for (int x = 0; x < layer1.n; x++)
    {
        chouche1[x]=init_neurone(vecteur ,ReLU);
       
    }
layer1.couche=chouche1;

visalisation(layer1);

return 0;

}



