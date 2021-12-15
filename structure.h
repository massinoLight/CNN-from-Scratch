/*
On déclare les fonctions d'actiovations sous forme d'énum pour faire plus propre 
*/

typedef enum fonctionActivation fonctionActivation;
enum fonctionActivation
{
    ReLU, sigmoide, tangante,Identite,Marche
};


/*
 Structure d'un neurone
 
 
 x1___
      \   __________
 x2____\ |          |
 ._____  |somme | f | _______    Y
 ._____/ |          |           
 .____/  |__________|
 xn__/
 
 
 */
 
 
 struct Neurone
{
  double *x;//vecteur d'entré
  double *w;//les poids synaptiques
  double sortie;//valeur en sorite du neurone 
};
typedef struct Neurone s_Neurone;





/*
 Structure de notre réseau de neurons
 */
struct s_Reseau
{
  int n;  // Taille du vecteur d'entré
  
  s_Neurone couche[3]; // une couche de neurone 
  
} s_Reseau;
