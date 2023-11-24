#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include "Rubix.cpp"
#include "Rubix.hpp"




int main()
{

    Rubix cube;
    cube.make_cube('W', 'G', 'Y', 'O', 'R', 'B');
   
    std::cout << "Fresh Cube!" << std::endl;
    cube.display_cube();
    cube.scramblecube();
    cube.white_cross();
    cube.white_corners();
    cube.second_layer();
    

    return 0;
}

