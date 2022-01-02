#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Activation function and its derivative
double sigmoid(double x) { return 1 / (1 + exp(-x)); }
double dSigmoid(double x) { return x * (1 - x); }// Init all weights and biases between 0.0 and 1.0
double init_weight() { return ((double)rand())/((double)RAND_MAX); }

static const int numInputs = 2;
static const int numHiddenNodes = 2;
static const int numOutputs = 1;double hiddenLayer[numHiddenNodes];
double outputLayer[numOutputs];double hiddenLayerBias[numHiddenNodes];
double outputLayerBias[numOutputs];double hiddenWeights[numInputs][numHiddenNodes];
double outputWeights[numHiddenNodes][numOutputs];

static const int numTrainingSets = 4;double training_inputs[numTrainingSets][numInputs] = { {0.0f,0.0f},{1.0f,0.0f},{0.0f,1.0f},{1.0f,1.0f} };
double training_outputs[numTrainingSets][numOutputs] = { {0.0f},{1.0f},{1.0f},{0.0f} };

int epochs=500;
double lr=0.1;

int main(){
	
// Iterate through the entire training for a number of epochs
for (int n=0; n < epochs; n++) {  // As per SGD, shuffle the order of the training set
  int trainingSetOrder[] = {0,1,2,3};
  shuffle(trainingSetOrder,numTrainingSets);  // Cycle through each of the training set elements
  for (int x=0; x<numTrainingSets; x++) {
    int i = trainingSetOrder[x];
  }
}
// Compute hidden layer activation
for (int j=0; j<numHiddenNodes; j++) {
  double activation=hiddenLayerBias[j];
    for (int k=0; k<numInputs; k++) {
      activation+=training_inputs[i][k]*hiddenWeights[k][j];
    }
  hiddenLayer[j] = sigmoid(activation);
}


// Compute output layer activation
for (int j=0; j<numOutputs; j++) {
  double activation=outputLayerBias[j];
  for (int k=0; k<numHiddenNodes; k++) {
    activation+=hiddenLayer[k]*outputWeights[k][j];
  }
  outputLayer[j] = sigmoid(activation);
}


// Compute change in output weights
double deltaOutput[numOutputs];
for (int j=0; j<numOutputs; j++) {
  double dError = (training_outputs[i][j]-outputLayer[j]);
  deltaOutput[j] = dError*dSigmoid(outputLayer[j]);
}



// Compute change in hidden weights
double deltaHidden[numHiddenNodes];
  for (int j=0; j<numHiddenNodes; j++) {
    double dError = 0.0f;
    for(int k=0; k<numOutputs; k++) {
      dError+=deltaOutput[k]*outputWeights[j][k];
    }
  deltaHidden[j] = dError*dSigmoid(hiddenLayer[j]);
}

// Apply change in output weights
for (int j=0; j<numOutputs; j++) {
  outputLayerBias[j] += deltaOutput[j]*lr;
    for (int k=0; k<numHiddenNodes; k++) {
      outputWeights[k][j]+=hiddenLayer[k]*deltaOutput[j]*lr;
    }
}
// Apply change in hidden weights
for (int j=0; j<numHiddenNodes; j++) {
  hiddenLayerBias[j] += deltaHidden[j]*lr;
  for(int k=0; k<numInputs; k++) {
    hiddenWeights[k][j]+=training_inputs[i][k]*deltaHidden[j]*lr;
  }
}

return 0;
}