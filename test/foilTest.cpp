// foil test program

#include <iostream>
#include "foil.hpp"

int main (void)
{
    foil aileron("naca0009", 5.0, 5.0);
    aileron.force(10.0, 10.0);

}
