#include "init.h"
#include "fonction.h"

#define LEARNING_RATE  0.15
#define ITERATIONS     500
//pointer sur une case de la structure data set du xor 
#define RANDOM_RANGE(max) ( rand() % max )

int taille_vecteur_Entree =2;




void visalisation(s_Layer layer1,int tailleVecteur){

for (int x = 0; x < layer1.n; x++)
    {
        printf("**********neurone %d**********\n",x);
        printf("* %f  *\n", layer1.couche[x].bias);
        for (int j = 0; j <=tailleVecteur; j++)
        {
        
        if (j==(taille_vecteur_Entree/2))
        
           printf("* %f ,%f *------->%f \n", layer1.couche[x].x[j],layer1.couche[x].w[j],layer1.couche[x].sortie);
        
        else
        printf("* %f ,%f *\n", layer1.couche[x].x[j],layer1.couche[x].w[j]);
      }
        printf("\n********************");
       
    }

printf("\n");
}


void init_n_conf(int tailleVecteur)
{
    
    s_conf.taille_vecteur_entree=tailleVecteur;
    taille_vecteur_Entree=tailleVecteur;
    
}



s_Neurone init_neurone_vide(s_Neurone neurone){
neurone.x=(double*)malloc(sizeof(double)*taille_vecteur_Entree);
neurone.w=(double*)malloc(sizeof(double)*taille_vecteur_Entree);
neurone.sortie=0;
   for (int j=0;j<s_conf.taille_vecteur_entree;j++)
   {
   neurone.w[j]=0;
   neurone.x[j]=0;
   }
   neurone.sortie=0.0;
return neurone;

}


//initialisation d'un neuron  pour la partie FEEDFORWARD
s_Neurone init_neurone(double vecteurEntree[],double poids[],fonctionActivation activation)
{
s_Neurone neurone;


neurone.x=(double*)malloc(sizeof(double)*s_conf.taille_vecteur_entree);
neurone.w=(double*)malloc(sizeof(double)*s_conf.taille_vecteur_entree);
neurone.sortie=0.0;

double somme=0.0;
neurone.w=poids;


neurone.x=vecteurEntree;

neurone.bias=init_bias();

//on somme les entrées 
for (int i = 0 ; i <= s_conf.taille_vecteur_entree ; i++)
{
somme=somme+(neurone.w[i]*neurone.x[i]);
}

//on ajoute le bias 
somme=somme+neurone.bias;

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
s_Layer init_layer(double vecteur[],double poids[],int nbNeurone,fonctionActivation activation){


s_Layer layer1;
layer1.n=nbNeurone;
s_Neurone* coucheN = malloc(layer1.n * sizeof *(coucheN));
double *sortie=(double*)malloc(sizeof(double)*layer1.n);

layer1.couche = malloc(layer1.n * sizeof *(layer1.couche ));
layer1.sortie=(double*)calloc(taille_vecteur_Entree,sizeof(double)*taille_vecteur_Entree);

 for (int x = 0; x < layer1.n; x++)
    {
        coucheN[x]=init_neurone(vecteur,poids ,activation);
       
    }

for (int x = 0; x < s_conf.taille_vecteur_entree; x++)
    {
        sortie[x]=coucheN[x].sortie;
   }

//layer1.couche=coucheN;


for (int x = 0; x < s_conf.taille_vecteur_entree; x++)
    {
    layer1.sortie[x]=sortie[x];
    layer1.couche[x]=coucheN[x];
    }
return layer1;
}



//initalisation d'un perceptron avec un vecteur en entre et sa profondeur ici on décrémente le nombre de neurones pour chaque layer au fur et a mesure
s_Reseau init_perceptron(double vecteurEntree[],double poids[],int profondeur,
                    int nbNeuroneParCouche,fonctionActivation activation){


s_Reseau perceptron;
perceptron.nb=profondeur;
perceptron.couches = malloc(perceptron.nb * sizeof *(perceptron.couches));
//nombre de neurones par couche quon va décrémenter au fur et a mesure afin d'eviter l overfiting
int nb=nbNeuroneParCouche;
//Notre premiére couche avec notre vecteur d'entre 
perceptron.couches[0]=init_layer(vecteurEntree,poids,nb,activation);
nb--;
printf("Feedforward\n");
printf("couche %d\n",0);
taille_vecteur_Entree=perceptron.couches[0].n;

visalisation(perceptron.couches[0],taille_vecteur_Entree);

 for (int x = 1; x < perceptron.nb; x++)
    {
        //printf('%f,',perceptron.couches[x-1].sortie[x]);
        perceptron.couches[x]=init_layer(perceptron.couches[x-1].sortie,perceptron.couches->couche->w,nb,activation);
        nb--;
        taille_vecteur_Entree=perceptron.couches[x].n;
        printf("couche %d\n",x);
        visalisation(perceptron.couches[x],taille_vecteur_Entree);
        
    }


return perceptron;

}


/*********************************************************************************************************************************/

void backward(s_Reseau* perceptron, double* gradients, double learning_rate, int layer_index)
{
  /* Updates the neuron weights and bias in function of the given error */
  
  for(size_t i = 0; i < taille_vecteur_Entree; i++)
   {
    perceptron->couches[i].couche->w[i] += LEARNING_RATE *gradients[i]* perceptron->couches[i].couche->x[i];
    //n.w[i]=LEARNING_RATE*2;
    perceptron->couches[i].couche->bias += LEARNING_RATE*gradients[i];
   }


}


/********************************************************************************************************************************/
/*
void train(s_Reseau p,t_xor_set sortie_attendu,DerviveefonctionActivation derivee){
printf("Entrainement\n");
double output_err =0.0;




for (int x = (p.couches->n)-1; x >= 0; --x){

switch( derivee )
{
    case DReLU:        
        output_err= (sortie_attendu.result - p.couches[x].couche->sortie);
        
        break;
    case Dtangante:
        output_err = Dtanhfs((p.couches[x].couche->sortie) * (sortie_attendu.result - p.couches[x].couche->sortie));
        break;
    case Dsigmoide:
        output_err = Dfsigmoid((p.couches[x].couche->sortie) * (sortie_attendu.result - p.couches[x].couche->sortie));
        break;
    case DIdentite:
        output_err = DfIdentite((p.couches[x].couche->sortie) * (sortie_attendu.result - p.couches[x].couche->sortie));
        break;
    case Marche:
        output_err = fMarche((p.couches[x].couche->sortie) * (sortie_attendu.result - p.couches[x].couche->sortie));
        break;
    default:
       output_err = Dfsigmoid((p.couches[x].couche->sortie) * (sortie_attendu.result - p.couches[x].couche->sortie));
       break;

}
printf("erreur %f\n",output_err);

backward(p.couches->couche[x],output_err);  

visalisation(p.couches[x],taille_vecteur_Entree);    
       
    }


//double output_err = SIGMOID_DERIV((p.couches[1].couche->sortie) * (sortie_attendu.result - p.couches[1].couche->sortie));


//backward(p.couches[i].couche,taille_vecteur_Entree,output_err);

}
*/

/*****************************************************************************************************************************/
void free_perceptro(s_Reseau perceptron){
  //free(perceptron.nb);
  free(perceptron.couches);

}








void train(s_Reseau* self, t_xor_set sortie_attendu, int n_epochs)
{
    int n_output_values = self->couches[self->nb-1].n;
    for(int epoch = 0;epoch<n_epochs;epoch++)
    {
        printf("Epoch %d\n", epoch+1);
        for(int i=0;i<s_conf.taille_vecteur_entree;i++)
        {
            double *output = self->couches[i].sortie;
            double truth = sortie_attendu.result;
            //Forward pass
            for(int i=0;i<self->couches->n;i++)
            {
                output = self->couches[i].sortie;
            }
            
            
            double* gradients= get_gradient(output, truth, n_output_values);
            //Backward pass
            for(int i=self->nb-1;i>=0;i--)
            {
                backward(self, gradients,LEARNING_RATE,i);
            }
            visalisation(self->couches[i],taille_vecteur_Entree);
        }
        printf("\n");
        
    }      
}

