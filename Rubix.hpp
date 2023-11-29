#ifndef Rubix_H
#define Rubix_H
class Rubix
{
public:
  char top[3][3]={{'Y','R','Y'},{'Y','Y','R'},{'B','O','G'}}, front[3][3] = {{'Y','G','Y'},{'O','G','R'},{'G','G','G'}}, 
       bottom[3][3] = {{'W','W','W'},{'W','W','W'},{'W','W','W'}}, left[3][3] = {{'B','G','R'},{'B','R','Y'},{'R','R','R'}}, 
       right[3][3] = {{'R','G','G'},{'B','O','B'},{'O','O','O'}}, back[3][3] = {{'O','Y','O'},{'O','B','Y'},{'B','B','B'}};

  std::vector<std::vector<std::string>> solution = {{""}, {""}, {""}, {""},{""},{""},{""},{""}};
  
  
  void make_cube(char , char , char , char , char , char);
  Rubix();
  
  void display_cube();
  void scramblecube();
  void record_solution(int rownum, std::string rotation);
  void solution_rotations();

  
  
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

//all functions for the yellow edges
void yellow_edges();
void set_yellow_edges();
std::string scan_yellow_edge(char color1, char color2, char color3, char color4);


//all functions for yellow corners
void yellow_corners();
void set_yellow_corners();
int scan_yellow_corners();
std::string position_yellow_corners();

//all functions for the final step
void final_step();



}; 
#endif