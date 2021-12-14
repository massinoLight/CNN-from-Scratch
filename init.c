#include "init.h"
#include "fonction.h"


void init_n_conf()
{
    s_Reseau.n=10;
    
}


//initialisation d'un neuron  
s_Neurone init_neurone(char fonctionActivation)
{

s_Neurone neurone;


init_n_conf();
neurone.x=(double*)malloc(sizeof(double)*s_Reseau.n);
neurone.w=(double*)malloc(sizeof(double)*s_Reseau.n);

double somme=0.0;

for (int j=0;j<4;j++)
{

neurone.w[j]=random_w();
//vecteur d'entree a recup a partir de read data**************
neurone.x[j]=random_w();
			
}



//on somme les entrées 
for (int i = 0 ; i < 4 ; i++)
{
somme=somme+(neurone.w[i]*neurone.x[i]);
}


//On applique la fonction d'activation selon celle choisit en paramétre 

switch( fonctionActivation )
{
    case 'R':
        neurone.sortie=fRelu(somme);
    case 'T':
        neurone.sortie=tanhf(somme);
    case 'S':
        neurone.sortie=fsigmoid(somme);
}


return neurone;

}
