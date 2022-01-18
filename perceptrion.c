#include <stdlib.h>
 #include <stdio.h>
 #include <math.h>
#include "structure.h"




t_xor_set xor_set[] = {
   {{0, 0}, 0},
   {{0, 1}, 1},
   {{1, 0}, 1},
   {{1, 1}, 0},
 };





#define SIGMOID(x)       ( 1. / (1. + exp(-x)) )
#define SIGMOID_DERIV(x) ( x * (1. - x) )


#define RANDOM_RANGE(max) ( rand() % max )

#define RAND_DOUBLE       ( (double)rand()/(double)RAND_MAX )

void initialize_neuron(t_neuron *n)
{
  
  for(size_t i = 0; i < NEURON_SIZE; i++)
    n->weights[i] = RAND_DOUBLE;
  n->bias = RAND_DOUBLE;
}

double forward(t_neuron *n)
{
  

  double result = 0;

  for(size_t i = 0; i < NEURON_SIZE; i++)
    result += n->inputs[i] * n->weights[i];
  result += n->bias;

  return SIGMOID(result);
}

void backward(t_neuron *n, double error)
{
  

  for(size_t i = 0; i < NEURON_SIZE; i++)
    n->weights[i] += error * n->inputs[i];
  n->bias += error;
}

int main()
{
  
  t_neuron intermediate_neurons[NEURON_SIZE]; // == 2
  for (size_t i = 0; i < NEURON_SIZE; i++)
    initialize_neuron(&intermediate_neurons[i]);

  
  t_neuron output_neuron;
  initialize_neuron(&output_neuron);
  

  for (size_t epoch = 0; epoch < 10000; epoch++)
  {
    t_xor_set t = xor_set[RANDOM_RANGE(4)];
     printf("\n%d XOR %d ", (int)t.inputs[0], (int)t.inputs[1]);

    /* FEEDFORWARD  */
    for (size_t i = 0; i < NEURON_SIZE; i++)
    {
     
      t_neuron *l = &intermediate_neurons[i];
      for (size_t j = 0; j < NEURON_SIZE; j++)
         l->inputs[j] = t.inputs[j];

      
      output_neuron.inputs[i] = forward(l);
    }

    
    double output = forward(&output_neuron);
    /* END FEEDFORWARD */

    /* BACKWARD */
    double output_err = SIGMOID_DERIV(output) * (t.result - output);

    
    backward(&output_neuron, output_err);

    for (size_t i = 0; i < NEURON_SIZE; i++)
    {
      double err = SIGMOID_DERIV(output_neuron.inputs[i])
                 * output_err
                 * output_neuron.weights[i];

      backward(&intermediate_neurons[i], err);
    }
    /* END BACKWARD */

    printf("= %d(%d) %f(ERR:%f)", output > 0.5, (int)t.result, output, output_err);
  }

  return 0;
}