#include <iostream>
#include <iomanip>

  int width = 9;
  int rowlength = 3;
  int columnlength = 3;
  
  char white [3][3] =   {{'W','W','W'},
                      {'W','W','W'},
                      {'W','W','W'}};

  char orange [3][3] =   {{'O','O','O'},
                      {'O','O','O'},
                      {'O','O','O'}};

  char green [3][3] =   {{'G','G','G'},
                      {'G','G','G'},
                      {'G','G','G'}};

  char red [3][3] =   {{'R','R','R'},
                      {'R','R','R'},
                      {'R','R','R'}};
        
  char blue [3][3] =   {{'B','B','B'},
                      {'B','B','B'},
                      {'B','B','B'}};

  char yellow [3][3] =   {{'Y','Y','Y'},
                      {'Y','Y','Y'},
                      {'Y','Y','Y'}};


void printcube();

int main() 
{


  printcube();
  return 0;
}


void printcube()
{

  for (auto &row : white)
  {
    std::cout << std::setfill(' ') << std::setw(width);
    for (auto &column : row)
    {
      std::cout << column << " ";
    }
    std::cout << std::endl;
  }




  for (int row = 0; row < rowlength; row++)
  {
    
      for (int column = 0; column < columnlength; column++)
      {
        std::cout << orange[row][column] << " ";
      }
      
      std::cout << "\t";

      for (int column = 0; column < columnlength; column++)
      {
        std::cout << "" << green[row][column] << " ";
      }
      
      std::cout << "\t";


      for (int column = 0; column < columnlength; column++)
      {
        std::cout << red[row][column] << " ";
      }
      
      std::cout << "\t";

      for (int column = 0; column < columnlength; column++)
      {
        std::cout << "" << blue[row][column] << " ";
      }
      std::cout << std::endl;
    
    
  }

  
  
  
  
  
  
  for (auto &row : yellow)
  {
    std::cout << std::setfill(' ') << std::setw(width);
    for (auto &column : row)
    {
      std::cout << column << " ";
    }
    std::cout << std::endl;
  }

}

