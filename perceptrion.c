#include <stdlib.h>
 #include <stdio.h>
 #include <math.h>

// Structure for the training and testing set
typedef struct s_xor_set
 {
  double inputs[2]; // 2 inputs: a XOR b
  double result;    // The expected result: 0 or 1
} t_xor_set;

// All the possibilities you can make with the XOR operator
t_xor_set xor_set[] = {
   {{0, 0}, 0},
   {{0, 1}, 1},
   {{1, 0}, 1},
   {{1, 1}, 0},
 };

#define NEURON_SIZE 2 // The non-modular part ;-)
// Why 2 inputs for every neuron and every layer ?
// The intermediate layer feeds itself directly from the input, so a 2 input
// array, and the output layer feeds itself from the intermediate layer,
// which has two neurons, which is why we also need a 2 input array

// The neuron structure
typedef struct s_neuron
 {
  double inputs[NEURON_SIZE];
  double weights[NEURON_SIZE]; // We need a weight for each input
  double bias;
} t_neuron;



#define SIGMOID(x)       ( 1. / (1. + exp(-x)) )
#define SIGMOID_DERIV(x) ( x * (1. - x) )

// Returns int between 0 and max:
#define RANDOM_RANGE(max) ( rand() % max )
// Returns double between 0 and 1:
#define RAND_DOUBLE       ( (double)rand()/(double)RAND_MAX )

void initialize_neuron(t_neuron *n)
{
  /* Initializes the neuron weights and bias with random values */
  for(size_t i = 0; i < NEURON_SIZE; i++)
    n->weights[i] = RAND_DOUBLE;
  n->bias = RAND_DOUBLE;
}

double forward(t_neuron *n)
{
  /* Computes the result for the neuron */

  double result = 0;

  for(size_t i = 0; i < NEURON_SIZE; i++)
    result += n->inputs[i] * n->weights[i];
  result += n->bias;

  return SIGMOID(result);
}

void backward(t_neuron *n, double error)
{
  /* Updates the neuron weights and bias in function of the given error */

  for(size_t i = 0; i < NEURON_SIZE; i++)
    n->weights[i] += error * n->inputs[i];
  n->bias += error;
}

int main()
{
  /* Creates and train our neural network */

  /* INIT */
  // Build intermediate layer
  t_neuron intermediate_neurons[NEURON_SIZE]; // == 2
  for (size_t i = 0; i < NEURON_SIZE; i++)
    initialize_neuron(&intermediate_neurons[i]);

  // Build output layer with one neuron
  t_neuron output_neuron;
  initialize_neuron(&output_neuron);
  /* END INIT */

  for (size_t epoch = 0; epoch < 4000; epoch++)
  {
    // We give it a random test
    t_xor_set t = xor_set[RANDOM_RANGE(4)];
     printf("\n%d XOR %d ", (int)t.inputs[0], (int)t.inputs[1]);

    /* FEEDFORWARD  */
    for (size_t i = 0; i < NEURON_SIZE; i++)
    {
      // Feed the intermediate_layer
      t_neuron *l = &intermediate_neurons[i];
      for (size_t j = 0; j < NEURON_SIZE; j++)
         l->inputs[j] = t.inputs[j];

      // Feed the output layer
      output_neuron.inputs[i] = forward(l);
    }

    // Determine the output of the neural network
    double output = forward(&output_neuron);
    /* END FEEDFORWARD */

    /* BACKWARD */
    // Determine the error between what we found and the expected result
    double output_err = SIGMOID_DERIV(output) * (t.result - output);

    // Update output neuron
    backward(&output_neuron, output_err);

    // Update the neurons in the intermediate layer
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