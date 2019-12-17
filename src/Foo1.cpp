
#include "Foo.h"

#include <stdio.h>

extern "C"
{
    void foo()
    {
        printf("I am groot!\n");
    }
}
