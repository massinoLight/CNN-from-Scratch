
#include "fonction.h"



double fIdentite(double x){

return x;
}

/******************************************************************************************************************************/

double fMarche(double x){

 if(x<0)
    return 0;
 else
    return 1;

}


/******************************************************************************************************************************/


double fsigmoid(double x){

 return 1/(1+exp(-x));
}



/******************************************************************************************************************************/



double tanhfs(double x){

 return (2/(1+exp(-2*x)))-1;
}



/******************************************************************************************************************************/
double fRelu(double x){

 if(x<0)
    return 0.0;
 else
    return x;

}




/******************************************************************************************************************************/
double somme(double tab[], double taille) {
   int i;

   double sum = 0;
   for (i = 0; i < taille; ++i) {
      sum += tab[i];
   }

   return sum;
}



/******************************************************************************************************************************/
double random_w() { 
   srand ( time(NULL) );
   return ((double)rand())/((double)RAND_MAX); 
}


/******************************************************************************************************************************/
double *init_rand_w(double tableau[],int tailleTableau) { 

     
    
    //double *tableau=malloc(tailleTableau*sizeof(double));
    for (int i = 0 ; i < tailleTableau ; i++)
    {
       
        tableau[i]=((double)rand())/((double)RAND_MAX);
    }
   return  tableau;
}


/******************************************************************************************************************************/
void affiche(int *tableau, int tailleTableau)
{
    int i;
 
    for (i = 0 ; i < tailleTableau ; i++)
    {
        printf("%d\n", tableau[i]);
    }
}

/*********************************************************************************************************************************/


// Backprop
void backpropagation(int numInputs ,int numHiddenNodes ,int numOutputs){


            double deltaOutput[numOutputs];
            for (int j=0; j<numOutputs; j++) {
                double errorOutput = (training_outputs[i][j]-outputLayer[j]);
                deltaOutput[j] = errorOutput*dSigmoid(outputLayer[j]);
            }

            double deltaHidden[numHiddenNodes];
            for (int j=0; j<numHiddenNodes; j++) {
                double errorHidden = 0.0f;
                for(int k=0; k<numOutputs; k++) {
                    errorHidden+=deltaOutput[k]*outputWeights[j][k];
                }
                deltaHidden[j] = errorHidden*dSigmoid(hiddenLayer[j]);
            }

            for (int j=0; j<numOutputs; j++) {
                outputLayerBias[j] += deltaOutput[j]*lr;
                for (int k=0; k<numHiddenNodes; k++) {
                    outputWeights[k][j]+=hiddenLayer[k]*deltaOutput[j]*lr;
                }
            }

            for (int j=0; j<numHiddenNodes; j++) {
                hiddenLayerBias[j] += deltaHidden[j]*lr;
                for(int k=0; k<numInputs; k++) {
                    hiddenWeights[k][j]+=training_inputs[i][k]*deltaHidden[j]*lr;
                }
            }


}
