/*
On déclare les fonctions d'actiovations sous forme d'énum pour faire plus propre 
*/

typedef enum fonctionActivation fonctionActivation;
enum fonctionActivation
{
    ReLU, sigmoide, tangante,Identite,Marche
};


typedef enum DerviveefonctionActivation DerviveefonctionActivation;
enum DerviveefonctionActivation
{
    ReLU, sigmoide, tangante,Identite,Marche
};



/*
 Structure de notre réseau de neurons
 */
struct s_conf
{
  int n;  // taille du vecteur d'entré 
   
  
} s_conf;



/*
 Structure d'un neurone
 
 
 x1___
      \w1 __________
 x2____\ |          |
 ._____  |somme | f | _______    Y
 ._____/ |          |           
 .____/wn|__________|
 xn__/
 
 
 */
 
 
 struct Neurone
{
  double *x;//vecteur d'entré
  double *w;//les poids synaptiques
  double bias;//le biais 
  double sortie;//valeur en sorite du neurone 
};
typedef struct Neurone s_Neurone;


/*
 Structure d'une couche
 */
struct Layer
{
   int n;  // Nb de neurone que comporte la couche 
  
  s_Neurone *couche; // un ensemble de neurones
  double *sortie; //vecteur de sortie de la couche (resultats des neurones de cette couche) 
  
};
typedef struct Layer s_Layer;





/*
 Structure de notre réseau de neurons
 */
struct Reseau
{
  
  int nb; //nb de couche que compotre le perceptron 
  s_Layer *couches; // un ensemble de couches 
  
};

typedef struct Reseau s_Reseau;


/*
Structure de nos base de données 
*/
typedef struct dataset{
    int n_entries;
    int n_features;
    int n_truths;
    double** features;
    double** truths;
    char** labels;
}dataset;



/*Structure pour nos training and testing set

*/
typedef struct s_xor_set
 {
  double inputs[2]; // 2 inputs: a XOR b
  double result;    // The expected result: 0 or 1
} t_xor_set;

