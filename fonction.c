
#include "fonction.h"



double fIdentite(double x){

return x;
}



/******************************************************************************************************************************/

double fMarche(double x){

 if(x<0)
    return 0.0;
 else
    return 1.0;

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
double *init_rand_w(double tableau[],int tailleTableau) { 

     
    
    //double *tableau=malloc(tailleTableau*sizeof(double));
    for (int i = 0 ; i < tailleTableau ; i++)
    {
       
        tableau[i]=((double)rand())/((double)RAND_MAX);
    }
   return  tableau;
}




/*********************************************************************************************************************************/










/*
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



void backprop(){


int loop = 0;
int times = 500;
double error;
int i, j, m;



// Training
	while(loop < times){
		loop++;
		error = 0.0;

		for(m=0; m<datanum ; m++){
			// Feedforward
			max = 0.0;
			min = 0.0;
			for(i=0; i<InputN; i++){
				x_out[i] = data[m].input[i];
				if(max < x_out[i])
					max = x_out[i];
				if(min > x_out[i])
					min = x_out[i];
			}
			for(i=0; i<InputN; i++){
				x_out[i] = (x_out[i] - min) / (max - min);
			}

			for(i=0; i<OutN ; i++){
				y[i] = data[m].teach[i];
			}

			for(i=0; i<HN; i++){
				sumtemp = 0.0;
				for(j=0; j<InputN; j++)
					sumtemp += w[j][i] * x_out[j];
				hn_out[i] = sigmoid(sumtemp);		// sigmoid serves as the activation function
			}

			for(i=0; i<OutN; i++){
				sumtemp = 0.0;
				for(j=0; j<HN; j++)
					sumtemp += v[j][i] * hn_out[j];
				y_out[i] = sigmoid(sumtemp);
			}

			// Backpropagation
			for(i=0; i<OutN; i++){
				errtemp = y[i] - y_out[i];
				y_delta[i] = -errtemp * sigmoid(y_out[i]) * (1.0 - sigmoid(y_out[i]));
				error += errtemp * errtemp;
			}

			for(i=0; i<HN; i++){
				errtemp = 0.0;
				for(j=0; j<OutN; j++)
					errtemp += y_delta[j] * v[i][j];
				hn_delta[i] = errtemp * (1.0 + hn_out[i]) * (1.0 - hn_out[i]);
			}

			// Stochastic gradient descent
			for(i=0; i<OutN; i++){
				for(j=0; j<HN; j++){
					deltav[j][i] = alpha * deltav[j][i] + beta * y_delta[i] * hn_out[j];
					v[j][i] -= deltav[j][i];
				}
			}

			for(i=0; i<HN; i++){
				for(j=0; j<InputN; j++){
					deltaw[j][i] = alpha * deltaw[j][i] + beta * hn_delta[i] * x_out[j];
					w[j][i] -= deltaw[j][i];
				}
			}
		}

		// Global error 
		error = error / 2;
		if(loop%1000==0){
			
			sprintf(buffer, "%f", error);
		}
		if(error < errlimit)
			break;

		printf("The %d th training, error: %f\n", loop, error);
	}

}*/