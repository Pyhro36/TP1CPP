#include "Collection.h"
#include <iostream>

using namespace std;

/**********TEST 3.1 - 3.2****************************/

void test(int nombreARetirer, Collection & coll);

int main()
{
	Collection collec(10);
	int aRetirer[10];

	for(int i(0); i<10; i++)
	{
		collec.Ajouter(i);
		aRetirer[i] = i;
	}

	collec.Ajouter(3);
	collec.Afficher();

	//tests de debut et de fin
	test(0, collec); 
	test(9, collec);

	//test de doublons
	test(3, collec);
	test(3, collec);

	//test d'element inexistant
	test(78, collec);
	
	//test d'elements multiples
	int code = collec.Retirer(aRetirer, 10);
	cout << code << endl;
	collec.Afficher();

	return 0;

}

void test(int nombreARetirer, Collection & coll)
{
	//retrait d'un nombre
	int tabN[1];
	tabN[0] = nombreARetirer;
	coll.Retirer(tabN, 1);
	coll.Afficher();

	//test pour verifier si la memoire est au plus juste
	int codeRetour = coll.Ajouter(0);
	if(codeRetour == 0)
	{
		cout << "ATTENTION mauvaise reallocation memoire" << endl;
	}
	tabN[0] = 0;
	coll.Retirer(tabN, 1);

}
