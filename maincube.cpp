#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include "Rubix.cpp"
#include "Rubix.hpp"




int main()
{

    Rubix cube;
    
   
    std::cout << "Premade cube!" << std::endl;
    cube.Up();
    cube.display_cube();
    cube.F();
    cube.right_shimmy();
    cube.Fp();
    cube.F();
    cube.right_shimmy();
    cube.Fp();
    cube.U();
    cube.display_cube();
    cube.yellow_cross();
    
    

    return 0;
}

