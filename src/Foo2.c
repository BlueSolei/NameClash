
#include "Foo.h"

#include <stdio.h>

extern "C"
{
	enum Actors
	{
		ChrisPratt = 1,
		ZoeSaldana = 2
	};

	typedef struct PlantesDistances
	{
		int earth;
		int mars;
		int venus;
	} Planets;

	void CalculateDistances(PlantesDistances* p, Actors actor)
	{
		p->earth = 42;
		p->mars = 43;
		p->venus = 44;
	}

	const char* groot = "I am Groot 2";

	void foo()
    {
		static int theAnswer = 42;
        printf("I am groot 2!\n");
		printf("Say: %s\n", groot);
		printf("The answer: %d\n", theAnswer);
		PlantesDistances pd;
		CalculateDistances(&pd, ChrisPratt);
		printf("The planet earth is %d away\n", pd.earth);
	}
}
