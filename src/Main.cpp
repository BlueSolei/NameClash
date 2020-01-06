#include <iostream>

#include "RenameSym.h"
#include "Foo.h"
#include "Bar.h"

using namespace std;

extern "C"
{
    void oof();
}

int main() {
  printf("Call Foo1::foo(): ");
  foo();
  printf("Call oof(): ");
  //oof();
  UseNewSymbol();
  
  return 0;
}
