/*************************************************************************
                           Collection  -  description
                             -------------------
    debut                : 01/09/2015
    copyright            : (C) ${year} par B3113
*************************************************************************/

//---------- Interface de la classe <Collection> (fichier Collection.h) --
#if ! defined ( COLLECTION_H )
#define COLLECTION_H

//--------------------------------------------------- Interfaces utilisees

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Role de la classe <Collection>
// Classe permettant de gerer des collections d'entiers de taille fixee a 
// la creation avec reajustement automatique ou a la demande
//------------------------------------------------------------------------ 

class Collection
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Methodes publiques

    void Afficher ( ) const;
    // Mode d'emploi :
    // Imprime sur la sortie standard tous les éléments conteus dans la
    // collection, sur une ligne, separes les uns des autres par un espace et
    // termine par un retour-chariot
    // Contrat :
	// aucun

    int Ajouter ( int element );
    // Mode d'emploi :
    // Ajoute a la collection un entier passe en parametre (jeton), en 
    // reallouant eventuellement si la collection a atteint sa taille 
    // maximale (ne verifie pas les doublons)
    // Renvoie code d'action : 
      // 0 : ajout sans reallocation
      // 1 : ajout avec reallocation
    // Contrat : 
	// aucun

    int Retirer ( int const elements[] , int tailleElements);
    // Mode d'emploi :
    // Retire le premier element de la collection trouve correspondant a
    // element du tableau d'entiers (elements[]) passe en parametre 
    // Renvoie nombre d'éléments supprimes    
    // Contrat :
      // tailleElements >= 0
      // tailleElements est le nombre d'elements a retirer
    
    int Ajuster ( int nouvelleTaille );
    // Mode d'emploi :
    // Re-alloue en mémoire la collection pour que sa taille maximale 
    // corresponde a la nouvelleTaille passee en parametre.
    // Renvoie code d'ajustement
      // 0 : nouvelleTaille => tailleEffective
      // 1 : 0 < nouvelleTaille < tailleEffective
      // -1 : nouvelleTaille <= 0
    // Contrat :
      // aucun

    void Reunir ( Collection & coll2 );
    // Mode d'emploi : 
    // Methode permettant de reunir deux collections, la courante et celle 
    // passee en parametre (coll2) en une seule
    // detruit la collection en parametre et place le contenu reuni 
    // dans l'objet appelant obligatoirement
    // Contrat :
      // la methode reunit la collection en parametre dans la collection courante
      // et rend inutilisable la collection en parametre (delete juste apres si
      // dynamique)

//-------------------------------------------- Constructeurs - destructeur
    Collection ( const Collection & uneCollection );
    // Mode d'emploi (constructeur de copie) :
    // declaration sans definition pour rednre l'appel impossible
    // Contrat :
      // aucun

    Collection ( int dimMaximale = 1 );
    // Mode d'emploi :
    // Constructeur d'une collection vierge d'une dimension maximale deja 
    // allouee donnee en parametre
    // Contrat :
      // requiert dimMaximale > 0

    Collection ( int entrees[], int tailleEntrees);
    // Mode d'emploi
    // Constructeur d'une collection en utilisant un groupe d'entiers 
    // predefini (entrees), avec la taille du tableau d'entrees 
    // (tailleEntree) en parametre
    // Contrat : 
      // requiert tailleEntrees > 0
      // tailleEntrees est egal au nombre d'entiers dans entrees

    virtual ~Collection ( );
    // Mode d'emploi :
    // Libere la memoire prise par la collection courante et la supprime du meme 
    // coup
    // Contrat :
      // aucun

//------------------------------------------------------------------ PRIVE 

private:
//------------------------------------------------------- Méthodes privees

	void supprimeTrous ( int const indices[], int tailleIndices );
	// Mode d'emploi
	// Supprime les trous dans contenu apres appel de Retirer,
	// selon les indices des vides
	// Contrat : 
	  // requiert tailleIndices >= 0
	  // tailleIndices est le nombre d'indices des elements à supprimer

	void combiner ( Collection & coll2 );
	// Mode d'emploi
	// combine *this et coll2 en ajoutant coll2 dans *this, *this devenant
	// mutli-ensemble de *this et coll2
	// Contrat :
	  // requiert non utilisation de coll2 apres l'appel de la fonction

private:
//------------------------------------------------------- Attributs prives

	// nombre d'elements rentres par l'utilisateur dans la collection
	int tailleEffective;

	// nombre d'elements actuellement stockables par la collection, sans reallocation
	int tailleMax;

	// tableau contenant les elements de la collection
	int *contenu;
};

//----------------------------------------- Types dépendants de <Collection>

#endif // COLLECTION_H
