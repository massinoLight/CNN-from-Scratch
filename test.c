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
s_Neurone neurone1,neurone2;
neurone1=init_neurone(vecteur ,ReLU);


neurone2=init_neurone(vecteur ,ReLU);
/*s_Layer layer1;
layer1.n=3;
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

/*double *t1=(double*)malloc(sizeof(double)*10);
double *t2=(double*)malloc(sizeof(double)*10);

t1=init_rand_w(t1,5);
t2=init_rand_w(t2,5);
shuffle(t2,5);

    printf("***************************\n");
for (int x = 0; x <5; x++)
    {
        printf("%f  ,  %f \n", t1[x],t2[x]);
        
       
    }*/
    printf("%f\n", neurone1.sortie);
    printf("%f\n",neurone2.sortie);
    









return 0;

}
