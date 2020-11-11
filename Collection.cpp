/*************************************************************************
                           Collection  -  description
                             -------------------
    debut                : 05/10/2015
    copyright            : (C) 2015 par B3113
*************************************************************************/

//---------- Realisation de la classe <Collection> (fichier Collection.cpp) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include systeme
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Collection.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Collection::Afficher ( ) const
// Algorithme :
// afficheSurUneLigne(contenu) + retour chariot
{
	for(int i(0); i<tailleEffective; i++)
	{
		cout << contenu[i] << " ";
	}

	cout << endl;
} //----- Fin de Afficher

int Collection::Ajouter ( int element )
// Algorithme :
// si contenu est plein alors tailleMax += 1;
// ajout de l'element, avec ou sans allocation
{
	int renvoi = 0;
	if(tailleEffective >= tailleMax)
	{
		tailleMax++;
		Ajuster(tailleMax);
		renvoi = 1; 
	}
	contenu[tailleEffective] = element;
	tailleEffective++;

	return renvoi;
}

int Collection::Retirer ( int const elements[] , int tailleElements)
// Algorithme :
// pour chaque element, parcourt contenu et retiens l'indice
// puis condense le tableau en fonction des elements supprimes
// renvoi le nombre d'elements supprimes
{
	int indices[tailleElements];

	int compteur(0);

	for(int i(0); i<tailleElements; i++)
	{
		for(int j(0); j<tailleEffective; j++)
		{
			if(contenu[j] == elements[i])
			{
				indices[compteur] = j; // retiens les indices des elements a supprimer
				compteur++;
				break;
			}
		} // fin for contenu
	} // fin for elements

	//passe les indices des elements a supprimer a une methode supprimerTrous
	if(compteur > 0)
	{
		supprimeTrous(indices, compteur);
	}
	
	return compteur;

}

int Collection::Ajuster ( int nouvelleTaille )
// Algorithme :
// change la taille du tableau : ajout de cases vides si 
// nouvelleTaille > tailleMax, 
{
	// test si la taille demandee est inferieure ou egale a zero
	// reinitialisation de la collection a zero valeurs (contenu est un tableau
	// a une valeur non consideree)
	if(nouvelleTaille <= 0)
	{
		delete[] contenu;
		contenu = new int[1];
		contenu[0] = 0;
		tailleMax = 1;
		tailleEffective = 0;
		return -1;
	} // fin si nouvelleTaille <= 0
	else
	{
		// creation d'un nouveau tableau a la taille demandee
		int* nouveau = new int[nouvelleTaille];
		// remplissage du nouveau tableau au maximum avec les valeurs de la 		
		// collection
		for(int i(0); i<nouvelleTaille && i < tailleEffective; i++)
		{
			nouveau[i] = contenu[i];	
		}

		// remplacement de l'ancien tableau de la collection par le nouveau
		delete[] contenu;
		contenu = nouveau;
		tailleMax = nouvelleTaille;		

		//reaffectation de la tailleEffective si necessaire et retour du code
		if(nouvelleTaille < tailleEffective)
		{
			tailleEffective = nouvelleTaille;
			return 1;
		}
		else
		{
			return 0;
		}

	} //fin sinon nouvelleTaille <= 0
}


void Collection::Reunir ( Collection & coll2 )
// Algorithme :
// compare les tailles max, puis les combine en utilisant le contenu de 
// plus grande taille, plus susceptible de contenir les deux collections
{
	if(tailleMax < coll2.tailleMax)
	{
		coll2.combiner(*this);
		delete[] contenu;
		contenu = coll2.contenu;
		
	}
	else
	{
		combiner(coll2);
	}
	
	coll2.contenu = NULL; // coll2.contenu ne doit pas pointer sur le
			      // contenu de *this (entraine une suppression 
			      // necessaire de coll2) (necessaire uniquement dans le si alors, mais 
			      // effectue generalement pour avoir le meme comportement peut importe le cas)
}


//-------------------------------------------- Constructeurs - destructeur

Collection::Collection ( int dimMaximale): tailleEffective(0), tailleMax(dimMaximale)
// Algorithme :
// tailleEffective = 0; tailleMax = dimMaximale; allocation dynamique de contenu a
// tailleMax
{
#ifdef MAP
    cout << "Appel au constructeur de <Collection>" << endl;
#endif

	contenu = new int[tailleMax];
} //----- Fin de Collection

Collection::Collection ( int entrees[], int tailleEntrees): tailleEffective(tailleEntrees),
tailleMax(tailleEntrees)
// Algorithme :
// tailleEffective = tailleMax = tailleEntrees, contenu = entrees (en copie)
{
#ifdef MAP
    cout << "Appel au constructeur de <Collection>" << endl;
#endif

	contenu = new int[tailleMax];

	for(int i(0); i<tailleMax; i++)
	{
		contenu[i] = entrees[i];
	}
} //----- Fin de Collection(int[], int)

Collection::~Collection ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Collection>" << endl;
#endif

	delete [] contenu;
} //----- Fin de ~Collection


//------------------------------------------------------------------ PRIVE

//------------------------------------------------------- Methodes privees

void Collection::supprimeTrous(int const indices[], int tailleIndices)
// Algorithme :
// condense un tableau en le copiant dans un nouveau, en sautant les indices a 
// supprimer
{
	if(tailleEffective == tailleIndices)
	{
		Ajuster(0);
		return;
	}

	int *nouveau = new int[tailleEffective - tailleIndices];
	int trousPasse = 0;

	for(int i(0); i<tailleEffective; i++)
	{
		for(int j(0); j<tailleIndices; j++)
		{
			if(indices[j] != i)
			{
				nouveau[i-trousPasse] = contenu[i];
			}
			else
			{
				trousPasse++; // saut d'indice
			}
			
		} // fin pour j < tailleIndice, parcours du tableau des indices
		  // elements a suppirmer
		
	} // fin pour i < tailleEffective, parcours de contenu

	//mise a jour des tailles
	tailleEffective = tailleEffective - tailleIndices;
	tailleMax = tailleEffective;

	delete[] contenu;
	contenu = nouveau;

}

void Collection::combiner ( Collection & coll2 )
// Algorithme :
// combine *this et coll2, les met dans *this
// realloue de la memoire uniquement si necessaire
{
	if(tailleEffective + coll2.tailleEffective > tailleMax)
	{
		Ajuster(tailleEffective + coll2.tailleEffective);
	}

	for(int i(tailleEffective); i < tailleMax; i++)
	{
		contenu[i] = coll2.contenu[i-tailleEffective];
	}

	tailleEffective = tailleMax;

}


