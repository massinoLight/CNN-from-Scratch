/*
 Structure d'un neurone
 */
struct neurone
{
  double *x;//vecteur d'entr�
  double *w;//les poids synaptiques
  char fonction; // Fonction d'activation 1 2 3 4 selon le fichier fonction.h.

  double *sortie;//vecteur  position du neurone qui va �tre ajustable
};

