#include "init.h"
#include "fonction.h"



s_Neurone init_neurone_vide(s_Neurone neurone){
neurone.x=(double*)malloc(sizeof(double)*s_Reseau.n);
neurone.w=(double*)malloc(sizeof(double)*s_Reseau.n);
neurone.sortie=0;
   for (int j=0;j<s_Reseau.n;j++)
   {
   neurone.w[j]=0;
   neurone.x[j]=0;
   }
   neurone.sortie=0.0;
return neurone;

}


//initialisation d'un neuron  
s_Neurone init_neurone(double vecteurEntree[],fonctionActivation activation)
{
s_Neurone neurone;
neurone=init_neurone_vide(neurone);

neurone.x=(double*)malloc(sizeof(double)*s_Reseau.n);
neurone.w=(double*)malloc(sizeof(double)*s_Reseau.n);
neurone.sortie=0.0;

double somme=0.0;
double result=0.0;

neurone.w=init_rand_w(s_Reseau.n);


neurone.x=vecteurEntree;



//on somme les entrées 
for (int i = 0 ; i < s_Reseau.n ; i++)
{
somme=somme+(neurone.w[i]*neurone.x[i]);
}

//On applique la fonction d'activation selon celle choisit en paramétre 

switch( activation )
{
    case ReLU:
        result=fRelu(somme);
        break;
    case tangante:
        result=tanhf(somme);
        break;
    case sigmoide:
        result=fsigmoid(somme);
        break;
    case Identite:
        result=fIdentite(somme);
        break;
    case Marche:
        result=fMarche(somme);
        break;
    default:
       result=fRelu(somme);
       break;

}

 
neurone.sortie=result;

    return neurone;
}
