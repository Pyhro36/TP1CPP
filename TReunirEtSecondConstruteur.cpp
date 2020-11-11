#include "Collection.h"
#include <iostream>

using namespace std;

int main()
{
	Collection collec(0);
	int deuxieme[10];

	for(int i(0); i<10; i++)
	{
		collec.Ajouter(i);
		deuxieme[i] = 2*i;
		//deuxieme[i+10]=3*i;
	}

	Collection collec2(deuxieme, 10);
	collec2.Afficher();

	collec.Afficher();

	collec.Reunir(collec2);

	collec.Afficher();

	collec2.Afficher();
	
	return 0;

}

