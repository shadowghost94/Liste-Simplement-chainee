#include <iostream>
using namespace std;

typedef struct Noeud Noeud;
struct Noeud
{
    char contenu;       //conteneur, variable de type caractère destiné à contenir l'élément à stocker
    Noeud *successeur;  //pointeur permettant à chaque cellule de garder l'adresse de son successeur
};

typedef struct List List;
struct List
{
    int numList= 0;     //designe le numéro de liste, à supposer qu'on devra enregistrer plusieurs listes
    int tailleList= 0;  //devra contenir pour une liste, le nombre de cellule
    Noeud * tete;   //pointeur de type Noeud qui devra contenir l'adresse de la première cellule
};

void initiatList( List *premier)
{
    premier->numList+= 1;       //Liste numéro 1


    Noeud *cellule= new Noeud;  //création  d'une cellule de fin qui par-défaut pointe sur nullptr
    premier->tete= cellule;     //affectation de l'adresse de la cellule de fin à la cellule de tête
    cellule->successeur= nullptr;
    /* cette cellule restera toujours par défaut la cellule de fin et son successeur sera nullptr */
    cellule->contenu= 0;  //la cellule de fin par défaut contiendra toujours zero
    premier->tailleList= 1; //une cellule que j'appelle la cellule neutre
};

int ajoutPos(List *list, char elem, int pos)
{
    Noeud *cellule= new Noeud;
    cellule->contenu= elem;


    if( list->tailleList=1 )
    {
        cellule->successeur= list->tete;
        list->tete=cellule;
    }else
    {
        Noeud *cur= list->tete;

        for( int i=0; i<pos; i++ )
        {
            cur= cur->successeur;
        }

        list->tete=cellule;
        cellule->successeur=cur;
        delete cur;
    }

    return 1;
};



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
    initiatList( &Linked );

    ajoutPos(&Linked, 'A', 1);
    ajoutPos(&Linked, 'C', 2);
    ajoutPos(&Linked, 'B', 3);
    ajoutPos(&Linked, 'D', 4);

    affichage( Linked );

}
