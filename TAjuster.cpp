#include "Collection.h"
#include <iostream>

using namespace std;

/**********TEST 5.1****************************/

int main()
{
	Collection collec(10);
	int aRetirer[10];

	for(int i(0); i<10; i++)
	{
		collec.Ajouter(i);
		aRetirer[i] = i;
	}
	
	// test Ajuster a taille plus grande
	collec.Ajuster(15);
	collec.Afficher(); 
	//test pour verifier si la memoire a bien la bonne taille
	for(int i(10); i<16; i++)
	{
		int codeRetour = collec.Ajouter(i);
		if(codeRetour != 0)
		{
			cout << "REALLOCATION : " << i << endl;
		}
	}
	
	// test Ajuster a taille plus petite
	collec.Ajuster(5);
	collec.Afficher();
	
	// test Ajuster a taille inferieure a zero -> reinitialisation de 
	// la collection
	collec.Ajuster(-15);
	collec.Afficher(); 
	
	return 0;

}

