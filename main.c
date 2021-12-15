#include <stdio.h>
#include <stdlib.h>

double fRelu(double x){

 if(x<0)
    return 0.0;
 else
 
    return x;

}





int main()
{
    printf("%f\n", fRelu(12.0));
    printf("Hello world!\n");
    return 0;
}



