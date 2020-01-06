
#include "Foo.h"

#include <stdio.h>

extern "C"
{
	enum Actors
	{
		ChrisPratt = 11,
		ZoeSaldana = 22
	};

	typedef struct PlantesDistances
	{
		int earth;
		int mars;
		int venus;
	} Planets;

	void CalculateDistances(PlantesDistances* p, Actors actor)
	{
		p->earth = 1042;
		p->mars = 1043;
		p->venus = 1044;
	}

	const char* groot = "I am Groot 1";

	void foo()
	{
		static int theAnswer = 1042;
		printf("I am groot 1!\n");
		printf("Say: %s\n", groot);
		printf("The answer: %d\n", theAnswer);
		PlantesDistances pd;
		CalculateDistances(&pd, ChrisPratt);
		printf("The planet earth is %d away\n", pd.earth);
	}
}
