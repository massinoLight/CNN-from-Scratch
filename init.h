#include "structure.h"

void init_n_conf(int tailleVecteur);
void read_data();
s_Neurone init_neurone_vide(s_Neurone);
s_Neurone init_neurone(double vecteurEntree[],double poids[],fonctionActivation activation);
s_Layer init_layer(double vecteur[],double poids[],int nbNeurone,fonctionActivation activation);
s_Reseau init_perceptron(double vecteurEntree[],double poids[],int profondeur,int nbNeuroneParCouche,fonctionActivation activation);
void visalisation(s_Layer layer1,int tailleVecteur);

