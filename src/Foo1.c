
#include "Foo.h"

#include <stdio.h>

typedef enum Actors_ { ChrisPratt = 11, ZoeSaldana = 22 } Actors;

typedef struct PlantesDistances_ {
  int earth;
  int mars;
  int venus;
} PlantesDistances;

void CalculateDistances(PlantesDistances *p, Actors actor) {
  (void)actor;
  p->earth = 1042;
  p->mars = 1043;
  p->venus = 1044;
}

const char *groot = "I am Groot 1";

void foo() {
  static int theAnswer = 1042;
  printf("I am groot 1!\n");
  printf("Say: %s\n", groot);
  printf("The answer: %d\n", theAnswer);
  PlantesDistances pd;
  CalculateDistances(&pd, ChrisPratt);
  printf("The planet earth is %d away\n", pd.earth);
}
