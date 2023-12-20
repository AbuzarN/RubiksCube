#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "Rubix.cpp"
#include "Rubix.hpp"




int main()
{

    Rubix cube;
    cube.make_cube('W','G','Y','O','R','B');
    std::cout << "Fresh Cube!" << std::endl;
    cube.display_cube();
    cube.scramblecube();
    cube.solution_rotations();
   
   
   

  

 
    


    return 0;
}

