#include "init.h"
#include "fonction.h"

int taille_vecteur_Entree = 10;

void init_n_conf(int tailleVecteur)
{
    
    s_conf.n=tailleVecteur;
    
}

s_Neurone init_neurone_vide(s_Neurone neurone){
neurone.x=(double*)malloc(sizeof(double)*taille_vecteur_Entree);
neurone.w=(double*)malloc(sizeof(double)*taille_vecteur_Entree);
neurone.sortie=0;
   for (int j=0;j<taille_vecteur_Entree;j++)
   {
   neurone.w[j]=0;
   neurone.x[j]=0;
   }
   neurone.sortie=0.0;
return neurone;

}


//initialisation d'un neuron  
s_Neurone init_neurone(double vecteurEntree[],int tailleVecteurEntree,fonctionActivation activation)
{
s_Neurone neurone;


neurone.x=(double*)malloc(sizeof(double)*tailleVecteurEntree);
neurone.w=(double*)malloc(sizeof(double)*tailleVecteurEntree);
neurone.sortie=0.0;

double somme=0.0;


neurone.w=init_rand_w(neurone.w,tailleVecteurEntree);


neurone.x=vecteurEntree;



//on somme les entrées 
for (int i = 0 ; i < tailleVecteurEntree ; i++)
{
somme=somme+(neurone.w[i]*neurone.x[i]);
}

//On applique la fonction d'activation selon celle choisit en paramétre 

switch( activation )
{
    case ReLU:
        neurone.sortie=fRelu(somme);
        break;
    case tangante:
        neurone.sortie=tanhf(somme);
        break;
    case sigmoide:
        neurone.sortie=fsigmoid(somme);
        break;
    case Identite:
        neurone.sortie=fIdentite(somme);
        break;
    case Marche:
        neurone.sortie=fMarche(somme);
        break;
    default:
       neurone.sortie=fRelu(somme);
       break;

}

 


    return neurone;
}



//fonction pour initialiser une couche avec un vecteur en entré et le nombre de neurones que va comporter cette couche
s_Layer init_layer(double vecteur[],int nbNeurone){


s_Layer layer1;
layer1.n=nbNeurone;
 s_Neurone* chouche1 = malloc(layer1.n * sizeof *(chouche1));
double *sortie=(double*)malloc(sizeof(double)*layer1.n);

 for (int x = 0; x < layer1.n; x++)
    {
        chouche1[x]=init_neurone(vecteur ,taille_vecteur_Entree,ReLU);
        sortie[x]=chouche1[x].sortie;
       
    }
layer1.couche=chouche1;
layer1.sortie=sortie;

return layer1;
}



//initalisation d'un perceptron avec un vecteur en entre et sa profondeur ici on décrémente le nombre de neurones pour chaque layer au fur et a mesur e

s_Reseau init_perceptron(double vecteurEntree[],int profondeur){

s_Reseau perceptron;
perceptron.nb=profondeur;
perceptron.couches = malloc(perceptron.nb * sizeof *(perceptron.couches));
//nombre de neurones par couche quon va décrémenter au fur et a mesure
int nb=2;
//Notre premiére couche avec notre vecteur n'entre et 3 neurones 
perceptron.couches[0]=init_layer(vecteurEntree,3);
printf("couche %d\n",0);
visalisation(perceptron.couches[0]);
taille_vecteur_Entree=perceptron.couches[0].n;
 for (int x = 1; x < perceptron.nb; x++)
    {
        perceptron.couches[x]=init_layer(perceptron.couches[x-1].sortie,nb);
        nb--;
        taille_vecteur_Entree=perceptron.couches[x].n;
        printf("couche %d\n",x);
         visalisation(perceptron.couches[x]);

    }


return perceptron;

}