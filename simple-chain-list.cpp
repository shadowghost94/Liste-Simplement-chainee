#include <iostream>
using namespace std;

typedef struct Noeud Noeud;
struct Noeud
{
    char contenu;
    Noeud *successeur;
};

typedef struct List List;
struct List
{
    int numList=0;
    int tailleList=0;
    Noeud * tete;
};

void initialisaionList( List *premier)
{
    premier->numList+= 1;
    premier->tailleList= 0;
    premier->tete= nullptr;
};

int ajoutDebut( List *lecteur, char valeur)
{

    lecteur->tete= new Noeud;/*création d'une nouvelle cellule et affectation de cette cellule au pointeur de la cellule de tête*/

    lecteur->tete->contenu= valeur; //ajout de la valeur transmis par l'utilisateur
    lecteur->tete->successeur= nullptr;

    lecteur->tailleList+=1;//on ajoute 1, à la taille de la list

    return 1;
}

/*int ajoutFin( List *contenu )
{

}*/

void affichage( List list)
{
    Noeud *cur;
    cur= list.tete;

    while( cur->successeur != nullptr)
    {
        cout<<cur->contenu<<" ";
        cur=cur->successeur;
    }

    cout<<cur->contenu<<" "<<endl;
};

int main()
{
    List Linked;
    initialisaionList( &Linked );

    ajoutDebut(& Linked, 'A');

    affichage( Linked );

}
