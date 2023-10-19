#include <iostream>
#include <iomanip>

  int width = 9;
  int rowlength = 3;
  int columnlength = 3;
  
  char white [3][3] =  {{'W','W','W'},
                        {'W','W','W'},
                        {'W','W','W'}};

  char orange [3][3] = {{'O','O','O'},
                        {'O','O','O'},
                        {'O','O','O'}};

  char green [3][3] =  {{'G','G','G'},
                        {'G','G','G'},
                        {'G','G','G'}};

  char red [3][3] =    {{'R','R','R'},
                        {'R','R','R'},
                        {'R','R','R'}};
        
  char blue [3][3] =   {{'B','B','B'},
                        {'B','B','B'},
                        {'B','B','B'}};

  char yellow [3][3] = {{'Y','Y','Y'},
                        {'Y','Y','Y'},
                        {'Y','Y','Y'}};


void printcube();
void F();
int main() 
{

  F();
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
  std::cout << std::endl;




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
  std::cout << std::endl;

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

void F()
{
  char tempE = green[0][0];
  char tempM= green[0][1];
  char temp1=white[2][0];
  char temp2=white[2][1];
  char temp3=white[2][2];

  green[0][0]=green[2][0];
  green[2][0]=green[2][2];
  green[2][2]=green[0][2];
  green[0][2]=tempE;
  green[0][1]=green[1][0];
  green[1][0]=green[2][1];
  green[2][1]=green[1][2];
  green[1][2]=tempM;

  white[2][0]=orange[2][2];
  white[2][1]=orange[1][2];
  white[2][2]=orange[0][2];

  orange[2][2]=yellow[0][2];
  orange[1][2]=yellow[0][1];
  orange[0][2]=yellow[0][0];

  yellow[0][2]=red[0][0];
  yellow[0][1]=red[1][0];
  yellow[0][0]=red[2][0];
  
  red[0][0]=temp1;
  red[1][0]=temp2;
  red[2][0]=temp3;
}
