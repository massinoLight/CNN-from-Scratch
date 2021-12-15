#include "init.h"
#include "fonction.h"


void init_n_conf()
{
    s_Reseau.n=10;
    
}


//initialisation d'un neuron  
s_Neurone init_neurone(double *vecteurEntree,fonctionActivation activation)
{

s_Neurone neurone;


init_n_conf();
neurone.x=(double*)malloc(sizeof(double)*s_Reseau.n);
neurone.w=(double*)malloc(sizeof(double)*s_Reseau.n);

double somme=0.0;

for (int j=0;j<s_Reseau.n;j++)
{
neurone.w[j]=random_w();
}

neurone.x=vecteurEntree;




for (int j=0;j<s_Reseau.n;j++)
{
printf("%f\n", neurone.x[j]);
neurone.w[j]=random_w();			
}


//on somme les entrées 
for (int i = 0 ; i < 4 ; i++)
{
somme=somme+(neurone.w[i]*neurone.x[i]);
}


//On applique la fonction d'activation selon celle choisit en paramétre 

switch( activation )
{
    case ReLU:
        neurone.sortie=fRelu(somme);
    case tangante:
        neurone.sortie=tanhf(somme);
    case sigmoide:
        neurone.sortie=fsigmoid(somme);
    case Identite:
        neurone.sortie=fIdentite(somme);
    case Marche:
        neurone.sortie=fMarche(somme);
}


return neurone;

}
