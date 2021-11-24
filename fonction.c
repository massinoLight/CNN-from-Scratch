/*
int layerSizes[10] = {0,0,0,0,0,0,784,1000,1000,10};
float* layers[10] = {0};
float* errors[10] = {0};
float*  weights[10] = {0};
int i,j;
int activation=1;//relu
// FORWARD PROPAGATION
int forwardProp(int x){
    int i,j,k,imax;
    float sum, esum, max;
    // INPUT LAYER - RECEIVES 28X28 IMAGES
    for (i=0;i<784;i++) layers[10-numLayers][i] = trainImages[x][i];
    // HIDDEN LAYERS - RELU ACTIVATION
    for (k=11-numLayers;k<9;k++)
    for (i=0;i<layerSizes[k];i++){
        sum = 0.0;
        for (j=0;j<layerSizes[k-1]+1;j++)
            sum += layers[k-1][j]*weights[k][i*(layerSizes[k-1]+1)+j];
        if (activation==1) layers[k][i] = ReLU(sum);
        else if (activation==2) layers[k][i] = TanH(sum);
    }
    // OUTPUT LAYER - SOFTMAX ACTIVATION
    esum = 0.0;
    for (i=0;i<layerSizes[9];i++){
        sum = 0.0;
        for (j=0;j<layerSizes[8]+1;j++)
            sum += layers[8][j]*weights[9][i*(layerSizes[8]+1)+j];
        if (sum>30) return -1; //GRADIENT EXPLODED
        layers[9][i] = exp(sum);
        esum += layers[9][i];
    }
    // SOFTMAX FUNCTION
    max = layers[9][0]; imax=0;
    for (i=0;i<layerSizes[9];i++){
        if (layers[9][i]>max){
            max = layers[9][i];
            imax = i;
        }
        layers[9][i] = layers[9][i] / esum;
    }
    return imax;
}
*/
