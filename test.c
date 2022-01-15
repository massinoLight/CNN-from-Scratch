#include <stdio.h>
#include <stdlib.h>
#include "fonction.c"
#include "init.c"


//pointer sur une case de la structure data set du xor 
#define RANDOM_RANGE(max) ( rand() % max )



int main()
{
srand(time(NULL));
double input[] = {0.0, 1.0};  
t_xor_set xor_set[] = {

   {{0, 0}, 0},
   {{0, 1}, 1},
   {{1, 0}, 1},
   {{1, 1}, 0},
 };

t_xor_set t = xor_set[RANDOM_RANGE(4)];


int length = sizeof(input)/sizeof(input[0]); 

 
init_n_conf(length);
s_Reseau perceptron=init_perceptron(t.inputs,2,2,sigmoide);


free_perceptro(perceptron);
return 0;

}



