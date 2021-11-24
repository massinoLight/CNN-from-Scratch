/*#include <stdio.h>
#include <stdlib.h>

int main()
{

    printf("Hello world!\n");
    return 0;
}

int layerSizes[10] = {0,0,0,0,0,0,784,1000,1000,10};
float* layers[10] = {0};
float* errors[10] = {0};
float*  weights[10] = {0};
int i,j;
int activation=1;
// INITIALIZATION
void initNet(){
    // ALOCATE MEMORY
    layers[0] = (float*)malloc((layerSizes[0]+1) * sizeof(float));
    errors[0] = (float*)malloc(layerSizes[0] * sizeof(float));
    for (i=1;i<10;i++){
        layers[i] = (float*)malloc((layerSizes[i]+1) * sizeof(float));
        errors[i] = (float*)malloc(layerSizes[i] * sizeof(float));
        weights[i] = (float*)malloc(layerSizes[i] * (layerSizes[i-1]+1) * sizeof(float));
    }
    // RANDOMIZE WEIGHTS AND BIAS
    float scale;
    for (i=0;i<10;i++) layers[i][layerSizes[i]]=1.0;
    for (j=1;j<10;j++){
        // XAVIER-HE INITIALIZATION
        scale = 2.0 * sqrt(6.0/(layerSizes[j] + layerSizes[j-1]));
        if (j!=9 && activation==1) scale = scale * 1.41; // RELU
        else if (j!=9) scale = scale * 4.0; // TANH
        for (i=0;i<layerSizes[j] * (layerSizes[j-1]+1);i++)
            weights[j][i] = scale * ( (float)rand()/RAND_MAX - 0.5 );
        for (i=0;i<layerSizes[j];i++) // BIASES
            weights[j][(layerSizes[j-1]+1)*(i+1)-1] = 0.0;
    }
}
*/
