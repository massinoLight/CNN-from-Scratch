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
double vecteur[10] = {1.0, 3.0, 7.0, 3.0,2.0,7.0,4.0,2.0,1.0,0.0};   
init_n_conf(10);
//s_Layer layer1;
s_Neurone neurone1,neurone2;

neurone1=init_neurone(vecteur ,ReLU);
srand(time(NULL));
neurone2=init_neurone(vecteur ,ReLU);

/*layer1.n=3;
 s_Neurone* chouche1 = malloc(layer1.n * sizeof *(chouche1));


 for (int x = 0; x < layer1.n; x++)
    {
        chouche1[x]=init_neurone(chouche1[x],vecteur ,ReLU);
       
    }


for (int x = 0; x < s_Reseau.n; x++)
    {
        printf("%f  ,  %f \n", chouche1[0].x[x],chouche1[0].w[x]);
        
       
    }*/

for (int x = 0; x < s_Reseau.n; x++)
    {
        printf("%f  ,  %f \n", neurone2.x[x],neurone2.w[x]);
        
       
    }

    printf("***************************\n");
for (int x = 0; x < s_Reseau.n; x++)
    {
        printf("%f  ,  %f \n", neurone1.x[x],neurone1.w[x]);
        
       
    }
    printf("%f\n", neurone1.sortie);
    printf("%f\n",neurone2.sortie);
    

//neurone1=init_neurone(vecteur ,ReLU);







return 0;

}
