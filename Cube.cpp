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
void Fp();
void RotateSecondRow(char (*)[3], char (*)[3], char (*)[3], char(*)[3], char (*)[3]);
int main() 
{

  F();
  //Fp();
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
  RotateSecondRow(green, orange, red, white, yellow);
}
void Fp()
{
  F();
  F();
  F();
}

void RotateSecondRow(char (*F)[3], char (*L)[3], char (*R)[3], char(*U)[3], char (*D)[3])
{
  char tempE = F[0][0];
  char tempM= F[0][1];
  char temp1=U[2][0];
  char temp2=U[2][1];
  char temp3=U[2][2];

  F[0][0]=F[2][0];
  F[2][0]=F[2][2];
  F[2][2]=F[0][2];
  F[0][2]=tempE;
  F[0][1]=F[1][0];
  F[1][0]=F[2][1];
  F[2][1]=F[1][2];
  F[1][2]=tempM;

  U[2][0]=L[2][2];
  U[2][1]=L[1][2];
  U[2][2]=L[0][2];

  L[2][2]=D[0][2];
  L[1][2]=D[0][1];
  L[0][2]=D[0][0];

  D[0][2]=R[0][0];
  D[0][1]=R[1][0];
  D[0][0]=R[2][0];
  
  R[0][0]=temp1;
  R[1][0]=temp2;
  R[2][0]=temp3;
}
