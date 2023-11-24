#ifndef Rubix_H
#define Rubix_H
class Rubix
{
public:
  char top[3][3]={{'O','Y','R'},{'G','Y','R'},{'R','Y','O'}}, front[3][3] = {{'B','B','B'},{'G','G','G'},{'G','G','G'}}, 
       bottom[3][3] = {{'W','W','W'},{'W','W','W'},{'W','W','W'}}, left[3][3] = {{'G','Y','Y'},{'R','R','R'},{'R','R','R'}}, 
       right[3][3] = {{'Y','Y','G'},{'O','O','O'},{'O','O','O'}}, back[3][3] = {{'Y','O','Y'},{'B','B','B'},{'B','B','B'}};
  
  
  void make_cube(char , char , char , char , char , char);
  Rubix();
  
  void display_cube();
  void scramblecube();
  
  // rotational functions for the entire cube. Gives us the ability to manuver the cube in code like we would irl
  void flip_cube_clockwise();
  void bring_bottom_up();
  void turn_cube_left();
  void turn_cube_right();
  void green_front();
  void orange_front();
  void blue_front();
  void red_front();
  
  // single face transformation functions
  void rotate_180(char arr[][3]);
  void rotate_90(char arr[][3]);
  void rotate_90p(char arr[][3]);
  void transpose(char arr[][3]);
  void reverse_matrix_row(char arr[][3]);
  void reverse_matrix_column(char arr[][3]);
  void reverse_row(char arr[][3], int k);
  void reverse_column(char arr[][3], int k);
  
  //single row and column rotation functions
  void F();
  void Fp();
  void R();
  void Rp();
  void U();
  void Up();
  void L();
  void Lp();
  void D();
  void Dp();

//all functions for the white cross
  void white_cross();
  int scan_top();
  bool scan_adj();
  void middle_cross_check();
  void cross_to_bottom();
  void set_cross();

//all functions for the white corners
  void white_corners();
  void right_shimmy();
  void left_shimmy();
  std::string scan_corners(char color1, char color2);
  void set_corner();
  bool bottom_corners_check();
  bool adj_corners_check();

//all funtions for the second layer side pieces
void second_layer();
std::string scan_side_pieces(char color1, char color2);
void pop_piece_left();
void pop_piece_right();
bool side_pieces_check();

//all functions for yellow cross
void yellow_cross();
std::string scan_yellow_cross(char color1);


}; 
#endif