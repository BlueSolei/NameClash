
#include "Foo.h"

#include <stdio.h>

typedef enum Actors_ { ChrisPratt = 1, ZoeSaldana = 2 } Actors;

typedef struct PlantesDistances_ {
  int earth;
  int mars;
  int venus;
} PlantesDistances;

void CalculateDistances(PlantesDistances *p, Actors actor) {
  (void)actor;
  p->earth = 42;
  p->mars = 43;
  p->venus = 44;
}

const char *groot = "I am Groot 2";

void foo() {
  static int theAnswer = 1042;
  printf("I am groot 2!\n");
  printf("Say: %s\n", groot);
  printf("The answer: %d\n", theAnswer);
  PlantesDistances pd;
  CalculateDistances(&pd, ChrisPratt);
  printf("The planet earth is %d away\n", pd.earth);
}
