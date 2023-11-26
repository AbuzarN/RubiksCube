#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include "Rubix.cpp"
#include "Rubix.hpp"




int main()
{

    Rubix cube;
    cube.make_cube('W','G','Y','O','R','B');
    std::cout << "Fresh cube!" << std::endl;
    cube.display_cube();
    cube.scramblecube();
    cube.white_cross();
    cube.white_corners();
    cube.second_layer();
    cube.yellow_cross();
    cube.yellow_edges();
    cube.yellow_corners();
    cube.final_step();
    
    
    

    
    
    
    
   
    
    
    

    return 0;
}

