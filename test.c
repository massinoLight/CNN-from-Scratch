#include <stdio.h>
#include <stdlib.h>
#include "fonction.c"
#include "init.c"


//pointer sur une case de la structure data set du xor 
#define RANDOM_RANGE(max) ( rand() % max )

void visalisationNeurone(s_Neurone n,int tailleVecteur){

 printf("* %f  *\n", n.bias);
for (int x = 0; x < tailleVecteur; x++)
    {
        printf("* %f ,%f *\n", n.x [x],n.w[x]);
      }
        printf("\n********************");
     
printf("\n");
}



int main()
{
srand(time(NULL));


t_xor_set xor_set[] = {

   {{0, 0}, 0},
   {{0, 1}, 1},
   {{1, 0}, 1},
   {{1, 1}, 0},
 };

t_xor_set xor = xor_set[RANDOM_RANGE(4)];
//on calcule la taille du vecteur d'entrée 
int length = sizeof(xor.inputs)/sizeof(xor.inputs[0]); 
init_n_conf(length);

double *poids=(double*)malloc(sizeof(double)*s_conf.taille_vecteur_entree);
poids=init_rand_w(poids,s_conf.taille_vecteur_entree);





s_Reseau perceptron=init_perceptron(xor.inputs,poids,2,2,ReLU);

//boucler ici pour n nombre diteration ou jusqua condition darret
train(&perceptron,xor,1);



free_perceptro(perceptron);
return 0;

}



