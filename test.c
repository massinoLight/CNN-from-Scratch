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
init_n_conf(10);

s_Reseau perceptron;
perceptron.nb=3;
s_Layer *layer = malloc(perceptron.nb* sizeof *(layer));
//premiere couche a initaliser a part ici on met 3 neurones 
perceptron.couche[0].n=3;

//premiere couche a initaliser a part ici on met 3 neurones 

 s_Neurone* chouche1 = malloc(layer[0].n * sizeof *(chouche1));


 for (int x = 0; x < perceptron.couche[0].n; x++)
    {
        chouche1[x]=init_neurone(vecteur ,ReLU);
       
    }
layer[0].couche=chouche1;





visalisation(layer[0]);


return 0;

}



