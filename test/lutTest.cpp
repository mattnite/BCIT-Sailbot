// Look up table test

#include <iostream>
#include "LUT.hpp"

int main (void)
{
    LUT ailLift("naca0009_Lift.csv");
    LUT ailDrag("naca0009_Drag.csv");
    LUT mainLift("naca0018_Lift.csv");
    LUT mainDrag("naca0018_Drag.csv");
    
    std::cout << ailLift.interp(5.1, 300000.0) << std::endl;
    std::cout << ailDrag.interp(5.1, 300000.0) << std::endl;
    std::cout << mainLift.interp(5.1, 300000.0) << std::endl;
    std::cout << mainDrag.interp(5.1, 300000.0) << std::endl;
}
