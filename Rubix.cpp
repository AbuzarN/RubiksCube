#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include "Rubix.hpp"

Rubix::Rubix()
{
    std::cout<< "hi" << std::endl;
}

void Rubix::make_cube(char face1, char face2, char face3, char face4, char face5, char face6)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            top[i][j] = face1, front[i][j] = face2, bottom[i][j] = face3, left[i][j] = face4, right[i][j] = face5, back[i][j] = face6;
        }
    }
}

void Rubix::display_cube()
{
    std::cout << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << std::setfill(' ') << std::setw(9);
        for (int j = 0; j < 3; j++)
        {
            std::cout << top[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << left[i][j] << " ";
        }
        std::cout << "\t";
        for (int j = 0; j < 3; j++)
        {
            std::cout << "" << front[i][j] << " ";
        }
        std::cout << "\t";
        for (int j = 0; j < 3; j++)
        {
            std::cout << right[i][j] << " ";
        }
        std::cout << "\t";
        for (int j = 0; j < 3; j++)
        {
            std::cout << "" << back[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    for (int i = 2; i >= 0; i--)
    {
        std::cout << std::setfill(' ') << std::setw(9);
        for (int j = 2; j >= 0; j--)
        {
            std::cout << bottom[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}



void Rubix::flip_cube_clockwise()
{
    rotate_180(front);
    rotate_180(back);
    rotate_180(left);
    rotate_180(right);


    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            std::swap(top[i][j], bottom[i][j]);
            std::swap(left[i][j], right[i][j]);
        }
    }
}

void Rubix::bring_bottom_up()
{
    
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            std::swap(back[i][j], bottom[i][j]);
            std::swap(top[i][j], front[i][j]);
            std::swap(back[i][j], front[i][j]);
        }
    }
    
    rotate_90p(left);
    rotate_90(right);
    reverse_matrix_column(back);
    reverse_matrix_column(front);
    reverse_matrix_row(back);
    reverse_matrix_row(front);
}

void Rubix::turn_cube_left()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            std::swap(back[i][j], left[i][j]);
            std::swap(front[i][j], right[i][j]);
            std::swap(right[i][j], left[i][j]);
        }
    }

    rotate_90(top);
    rotate_90p(bottom);
}

void Rubix::turn_cube_right()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            std::swap(left[i][j], right[i][j]);
            std::swap(right[i][j], front[i][j]);
            std::swap(left[i][j], back[i][j]);
        }
    }

    rotate_90p(top);
    rotate_90(bottom);
}

void Rubix::rotate_90(char arr[][3])
{
   transpose(arr);
   reverse_matrix_row(arr);
    
}

void Rubix::transpose(char arr[][3])
{
 for(int i = 0; i < 3; i++)
    {
        for(int j = i + 1; j < 3; j++)
        {
            std::swap(arr[i][j], arr[j][i]);
        }
    }
}

void Rubix::reverse_matrix_row(char arr[][3])
{
for(int i = 0; i < 3; i++)
    {
        int start = 0, end = 2;
        while(start < end)
        {
            std::swap(arr[i][start], arr[i][end]);
            start++;
            end--;
        }
    }
}

void Rubix::reverse_matrix_column(char arr[][3])
{
for(int j = 0; j < 3; j++)
    {
        int start = 0, end = 2;
        while(start < end)
        {
            std::swap(arr[start][j], arr[end][j]);
            start++;
            end--;
        }
    }
}

void Rubix::rotate_90p(char arr[][3])
{
    transpose(arr);
    reverse_matrix_column(arr);   
}

void Rubix::rotate_180(char arr[][3])
{
   reverse_matrix_row(arr);
   reverse_matrix_column(arr);
}



void Rubix::F()
{
    rotate_90(front);
    for(int k = 0; k < 3; k++)
        {
            std::swap(left[k][2], right[k][0]);
            std::swap(right[k][0], top[2][k]);
            std::swap(left[k][2], bottom[2][k]);
        }
    reverse_row(top, 2);
    reverse_column(left, 2);

}

void Rubix::Fp()
{
    rotate_90p(front);
       for(int k = 0; k < 3; k++)
        {
            std::swap(bottom[2][k], left[k][2]);
            std::swap(top[2][k], right[k][0]);
            std::swap(right[k][0], left[k][2]);
        }
    reverse_column(left, 2);
    reverse_row(bottom, 2);
}

void Rubix::R()
{
    rotate_90(right);
    for(int k = 0; k < 3; k++)
        {
            std::swap(bottom[k][0], top[k][2]);
            std::swap(top[k][2], front[k][2]);
            std::swap(bottom[k][0], back[k][0]);
        }
    reverse_column(front, 2);
    reverse_column(back, 0);
  
}

void Rubix::Rp()
{
    rotate_90p(right);
    for(int k = 0; k < 3; k++)
        {
            std::swap(back[k][0], bottom[k][0]);
            std::swap(front[k][2], top[k][2]);
            std::swap(top[k][2], bottom[k][0]);
        }
    reverse_column(top, 2);
    reverse_column(bottom, 0);
}

void Rubix::U()
{
    rotate_90(top);
    for(int k = 0; k < 3; k++)
    {
        std::swap(back[0][k], left[0][k]);
        std::swap(front[0][k], right[0][k]);
        std::swap(right[0][k], left[0][k]);
    }
    
}

void Rubix::Up()
{
    rotate_90p(top);
    for(int k = 0; k < 3; k++)
    {
        std::swap(left[0][k], right[0][k]);
        std::swap(right[0][k], front[0][k]);
        std::swap(left[0][k], back[0][k]);
    }
}

void Rubix::L()
{
    rotate_90(left);
    for(int k = 0; k < 3; k++)
        {
            std::swap(back[k][2], bottom[k][2]);
            std::swap(front[k][0], top[k][0]);
            std::swap(top[k][0], bottom[k][2]);
        }
    reverse_column(top, 0);
    reverse_column(bottom, 2);
}

void Rubix::Lp()
{
    rotate_90p(left);
    for(int k = 0; k < 3; k++)
        {
            std::swap(bottom[k][2], top[k][0]);
            std::swap(top[k][0], front[k][0]);
            std::swap(bottom[k][2], back[k][2]);
        }
    reverse_column(front, 0);
    reverse_column(back, 2);
}

void Rubix::D()
{
    rotate_90(bottom);
    for(int k = 0; k < 3; k++)
    {
        std::swap(left[2][k], right[2][k]);
        std::swap(right[2][k], front[2][k]);
        std::swap(left[2][k], back[2][k]);
    }
}

void Rubix::Dp()
{
    rotate_90p(bottom);
    for(int k = 0; k < 3; k++)
    {
        std::swap(back[2][k], left[2][k]);
        std::swap(front[2][k], right[2][k]);
        std::swap(right[2][k], left[2][k]);
    }
}

void Rubix::reverse_row(char arr[][3], int k)
{
    int start = 0, end = 2;
        while(start < end)
        {
            std::swap(arr[k][start], arr[k][end]);
            start++;
            end--;
        }
}

void Rubix::reverse_column(char arr[][3], int k)
{
    int start = 0, end = 2;
        while(start < end)
        {
            std::swap(arr[start][k], arr[end][k]);
            start++;
            end--;
        }
}

void Rubix::scramblecube()
{

  std::cout << "Casting a spell to scramble the cube" << std::endl;
  srand(time(NULL));
  int move[20];
  std::string rotations[20];
  for(int i = 0; i < 20; i++){

    move[i] = 1 + rand() % 10;
    
  }

    for(int i = 0; i < 20; i++){
      
      if(move[i] == 1){
        F();
        rotations[i] = "F";
      }
      else if(move[i] == 2){
        Fp();
        rotations[i] = "Fp";
      }
      else if(move[i] == 3){
        R();
        rotations[i] = "R";
      }
      else if(move[i] == 4){
        Rp();
        rotations[i] = "Rp";
      }
      else if(move[i] == 5){
        U();
        rotations[i] = "U";
      }
      else if(move[i] == 6){
        Up();
        rotations[i] = "Up";
      }
      else if(move[i] == 7){
        L();
        rotations[i] = "L";
      }
      else if(move[i] == 8){
        Lp();
        rotations[i] = "Lp";
      }
      else if(move[i] == 9){
        D();
        rotations[i] = "D";
      }
      else{
        Dp();
        rotations[i] = "Dp";
      }
    }

    std::cout << std::endl;
    std::cout << "List of rotations, i mean encantations:" << std::endl;
    std::cout << std::endl;

    for(int i = 0; i < 20; i++)
    {
        std::cout << rotations[i] << "   ";
    }
    std::cout << std::endl;

}

void Rubix::green_front()
{
    while(front[1][1] != 'G')
    {
        turn_cube_right();
    }
}

void Rubix::orange_front()
{
    while(front[1][1] != 'O')
    {
        turn_cube_right();
    }
}

void Rubix::blue_front()
{
    while(front[1][1] != 'B')
    {
        turn_cube_right();
    }
}

void Rubix::red_front()
{
    while(front[1][1] != 'R')
    {
        turn_cube_right();
    }
}

void Rubix::white_cross()
{
    if(scan_top() == 4 && scan_adj() == true)
    {
        std::cout << "Go buy a lottery ticket! White cross is already done" << std::endl;
        display_cube();
    }
    
    else if(scan_top() == 4 && scan_adj() == false)
    {
        std::cout << "White cross is on top but adjacent pieces do not match" << std::endl;
        green_front();
        cross_to_bottom();
        std::cout << "Pieces moved to bottom" << std::endl;
        display_cube();
        std::cout << "Shifting pieces to final position" << std::endl;
        set_cross();
        display_cube();
        std::cout << "White Cross Complete" << std::endl;
    }

    else if(scan_top() < 4 && scan_top() !=0)
    {
        std::cout << scan_top() << " white are on top " << std::endl;
        green_front();
        cross_to_bottom();
        std::cout << "Pieces moved to bottom" << std::endl;
        display_cube();
        std::cout << "Processing middle section" << std::endl;
        middle_cross_check();
        std::cout << "All white pieces moved to the bottom" << std::endl;
        display_cube();
        std::cout << "Shifting pieces to final position" << std::endl;
        set_cross();
        display_cube();
        std::cout << "White Cross Complete" << std::endl;
    }
    else
    {
        std::cout << "No white pieces on the top. Moving to the middle" << std::endl;
        std::cout << "Processing middle section" << std::endl;
        middle_cross_check();
        display_cube();
        std::cout << "All white pieces moved to the bottom" << std::endl;
        std::cout << "Shifting pieces to final position" << std::endl;
        set_cross();
        display_cube();
        std::cout << "White Cross Complete" << std::endl;
    }
    
}

int Rubix::scan_top()
{
    int pieces = 0;
    if(top[0][1]=='W')
    {
        pieces++;
    }
    if(top[1][2]=='W')
    {
        pieces++;
    }
    if(top[2][1]=='W')
    {
        pieces++;
    }
    if(top[1][0]=='W')
    {
        pieces++;
    }

    return pieces;
    
}

bool Rubix::scan_adj()
{
   
    if(front[0][1]==front[1][1] && left[0][1]==left[1][1] && right[0][1]==right[1][1] && back[0][1]==back[1][1])
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

void Rubix::cross_to_bottom()
{
    
    for(int i = 0; i <4; i++)
    {
        if(top[2][1] == 'W')
        {
            while(bottom[2][1] == 'W')
            {
                D();
            }
            F();
            F();
        }
        else
        {
            turn_cube_right();
        }
    }
   
}

void Rubix::middle_cross_check()
{
    green_front();

    while(bottom[0][1] != 'W' || bottom[1][2] != 'W' || bottom[2][1] != 'W' || bottom[1][0] != 'W' )
    {
        
        if(top[2][1] == 'W')
        {
            while(bottom[2][1] == 'W')
            {
                D();
            }
            F();
            F();
            
        }
            
        if(front[1][0] == 'W')
        {
            while(bottom[1][2] =='W')
            {
                D();
            }
            L();
            

        }
        if(front[1][2] == 'W')
        {
            while(bottom[1][0] == 'W')
            {
                D();
            }
            Rp();
            
        }
        if(front[2][1] == 'W')
        {
            while(bottom[2][1] == 'W')
            {
                D();
            }
            Fp();
            while(bottom[1][0] == 'W')
            {
                D();
            }
            Rp();
            
        }
        if(front[0][1] == 'W')
        {
            while(bottom[2][1] == 'W')
            {
                D();
            }
            Fp();
            while(bottom[1][2] == 'W')
            {
                D();
            }
            L();
            
        }
        else
        {
            turn_cube_right(); 
        }
    }

    green_front();
}

void Rubix::set_cross()
{
    while(top[0][1] != 'W' || top[1][0] != 'W' || top[2][1] != 'W' || top[1][2] != 'W' )
    {
        while(front[1][1] != front[2][1] || bottom[2][1] != 'W')
        {
            D();
        }
        F();
        F();
        turn_cube_right();
    }
    green_front();
}



void Rubix::white_corners()
{
    green_front();
    flip_cube_clockwise();
    std::cout << "Begining white corners solution" << std::endl;
    std::cout << std::endl;
    while(bottom_corners_check() == false || adj_corners_check() == false)
    {
        const char color1 = front[1][1];
        const char color2 = right[1][1];
        
        if(scan_corners(color1, color2) == "final position")
        {
            std::cout << "This corner has already been set. Moving on" << std::endl;
            turn_cube_right();
        }

        else if(scan_corners(color1, color2) == "top right")
        {
            std::cout << "piece found on top right" << std::endl;
            while(scan_corners(color1, color2) != "final position")
            {
                right_shimmy();
            }
            std::cout << "corner set" << std::endl;
            turn_cube_right();
        }

        else if(scan_corners(color1, color2) == "bottom right")
        {
            std::cout << "piece found on bottom right" << std::endl;
            while(scan_corners(color1, color2) != "final position")
            {
                right_shimmy();
            }
            std::cout << "corner set" << std::endl;
            turn_cube_right();
        }

        else if(scan_corners(color1, color2) == "top left")
        {
            std::cout << "piece found on top left" << std::endl;
            Up();
            while(scan_corners(color1, color2) != "final position")
            {
                right_shimmy();
            }
            std::cout << "corner set" << std::endl;
            turn_cube_right();
        }

        else if(scan_corners(color1, color2) == "bottom left")
        {
            std::cout << "piece found on bottom left" << std::endl;
            left_shimmy();
            Up();
            while(scan_corners(color1, color2) != "final position")
            {
                right_shimmy();
            }
            std::cout << "corner set" << std::endl;
            turn_cube_right();
        }

        else if(scan_corners(color1, color2) == "not here")
        {
            std::cout << "piece was not found on this face. Searching the others" << std::endl;
            int turns = 1;
            turn_cube_right();
            
            while(scan_corners(color1, color2) == "not here")
            {
                turn_cube_right();
                turns++;
            }
            if(scan_corners(color1, color2) == "top left" || scan_corners(color1, color2) == "top right")
            {
                std::cout << "Piece found on the top left or right of a different face" << std::endl;
                for(int i = 0; i != turns; i++)
                {
                    turn_cube_left();
                }
                while(scan_corners(color1, color2) != "top right")
                {
                    Up();
                }
            }

            else if(scan_corners(color1, color2) == "bottom left")
            {
                std::cout << "Piece found on the bottom left of a different face" << std::endl;
                left_shimmy();
                for(int i = 0; i != turns; i++)
                {
                    turn_cube_left();
                }
                while(scan_corners(color1, color2) != "top right")
                {
                    Up();
                }
            }

            else if(scan_corners(color1, color2) == "bottom right")
            {
                right_shimmy();
                for(int i = 0; i != turns; i++)
                {
                    turn_cube_left();
                }
                while(scan_corners(color1, color2) != "top right")
                {
                    Up();
                }
            }

            while(scan_corners(color1, color2) != "final position")
            {
                right_shimmy();
            }
            std::cout << "corner set" << std::endl;
            turn_cube_right();
        }
    }

    display_cube();
    std::cout << std::endl;
    std::cout << "White corners solved!" << std::endl;
    std::cout << std::endl;

}

void Rubix::right_shimmy()
{
    R(); U(); Rp(); Up();
}

void Rubix::left_shimmy()
{
    Lp(); Up(); L(); U();
}

void Rubix::set_corner()
{
    
}

std::string Rubix::scan_corners(char color1, char color2)
{
    std::string position = "";

    if(front[2][2] == color1 && bottom[2][0] == 'W' && right[2][0] == color2)
        {
            position = "final position";
        }
    
    else if((front[0][2] == 'W' || front[0][2] == color1 || front[0][2] == color2) && 
            (top[2][2] == 'W' || top[2][2] == color1 || top[2][2] == color2) &&
            (right[0][0] == 'W' || right[0][0] == color1 || right[0][0] == color2))
        {
        position = "top right";
        }
    
    else if((front[2][2] == 'W' || front[2][2] == color1 || front[2][2] == color2) && 
            (bottom[2][0] == 'W' || bottom[2][0] == color1 || bottom[2][0] == color2) &&
            (right[2][0] == 'W' || right[2][0] == color1 || right[2][0] == color2))
        {
            position = "bottom right";
        }
    
    else if((front[0][0] == 'W' || front[0][0] == color1 || front[0][0] == color2) && 
            (top[2][0] == 'W' || top[2][0] == color1 || top[2][0] == color2) &&
            (left[0][2] == 'W' || left[0][2] == color1 || left[0][2] == color2))
        {
        position = "top left";
        }

    else if((front[2][0] == 'W' || front[2][0] == color1 || front[2][0] == color2) && 
            (bottom[2][2] == 'W' || bottom[2][2] == color1 || bottom[2][2] == color2) &&
            (left[2][2] == 'W' || left[2][2] == color1 || left[2][2] == color2))
        {
        position = "bottom left";
        }
    
    else
    {
        position = "not here";
    }

    return position;
}

bool Rubix::bottom_corners_check()
{
    bool bottom_check = false;
    if(bottom[0][0] == 'W' && bottom[0][2] == 'W' && bottom[2][0] == 'W' && bottom[2][2] == 'W')
    {
        bottom_check = true;
    }
    return bottom_check;
}

bool Rubix::adj_corners_check()
{
    bool adjacent_check = false;
    if(front[2][2] == front[1][1] && front[2][0] == front[1][1] && right[2][2] == right[1][1] && right[2][0] == right[1][1] &&
       left[2][2] == left[1][1] && left[2][0] == left[1][1] && back[2][2] == back[1][1] && back[2][0] == back[1][1])
        {
            adjacent_check = true;
        }
    return adjacent_check;
}



void Rubix::second_layer()
{
    green_front();
    std::cout << "Starting to work the second layer" << std::endl;
    
    while(side_pieces_check() == false)
    {
        const char color1 = front[1][1];
        const char color2 = right[1][1];
        
        if(scan_side_pieces(color1, color2) == "final position")
        {
            std::cout << "This piece is already in its final position. Moving on to the next face" << std::endl;
            turn_cube_right();
        }
        else if(scan_side_pieces(color1, color2) == "right middle")
        {
            std::cout << "The piece is in its final position but the colors are switched. Fixing now" << std::endl;
            pop_piece_right();
            U();
            pop_piece_right();
            std::cout << "Piece set. Moving on" << std::endl;
            turn_cube_right();
        }
        else if(scan_side_pieces(color1, color2) == "top middle matching front")
        {
            std::cout << "The piece is in the top middle and matches the front face. Setting now" << std::endl;
            pop_piece_right();
            std::cout << "Piece set. Moving on" << std::endl;
            turn_cube_right();

        }
        else if(scan_side_pieces(color1, color2) == "top middle matching right")
        {
            std::cout << "The piece is in the top middle and matches the right face. Setting now" << std::endl;
            turn_cube_left();
            Up();
            pop_piece_left();
            std::cout << "Piece set. Moving on" << std::endl;
            turn_cube_right();

        }
        else if(scan_side_pieces(color1, color2) == "left middle")
        {
            std::cout << "The piece is in the left middle. Popping it out now" << std::endl;
            pop_piece_left();
            Up();
            std::cout << "Piece popped. Setting now" << std::endl;
            pop_piece_right();
            std::cout << "Piece set. Moving on" << std::endl;
            turn_cube_right();

        }
        else if(scan_side_pieces(color1, color2) == "not here")
        {
            std::cout << "The piece we need is not on this face. Searching the other faces now" << std::endl;
            int turns = 1;
            turn_cube_right();

            while(scan_side_pieces(color1, color2) == "not here")
            {
                turn_cube_right();
                turns++;
            }

            if(scan_side_pieces(color1, color2) == "top middle matching front")
            {
                std::cout << "The piece was found in the top middle of a different face and matches the front. Bringing it back now" << std::endl;
                for(int i = 0; i != turns; i++)
                {
                    turn_cube_left();
                    Up();
                }
                std::cout << "Piece brought back. Setting into final position" << std::endl;
                pop_piece_right();
            }
            else if(scan_side_pieces(color1, color2) == "top middle matching right")
            {
                std::cout << "The piece was found in the top middle of a different face and matches the right. Bringing it back now" << std::endl;
                for(int i = 0; i != turns; i++)
                {
                    turn_cube_left();
                    Up();
                }
                std::cout << "Piece brought back. Setting into final position" << std::endl;
                turn_cube_left();
                Up();
                pop_piece_left();
                turn_cube_right();
            }
            else if(scan_side_pieces(color1, color2) == "left middle")
            {
                std::cout << "The piece was found in the left middle of a different face. Popping it out and bringing it back now" << std::endl;
                pop_piece_left();
                Up();
                for(int i = 0; i != turns; i++)
                {
                    turn_cube_left();
                    Up();
                }
                std::cout << "Piece brought back. Setting into final position" << std::endl;
                
                if(scan_side_pieces(color1, color2) == "top middle matching front")
                {
                    pop_piece_right();
                }
                else
                {
                    turn_cube_left();
                    Up();
                    pop_piece_left();
                    turn_cube_right();
                }

            }

        }
    }

    std::cout << "Second Layer Complete!" << std::endl;
    display_cube();
}

void Rubix::pop_piece_left()
{
    Up();
    left_shimmy();
    turn_cube_right();
    right_shimmy();
    turn_cube_left();
}

void Rubix::pop_piece_right()
{
    U();
    right_shimmy();
    turn_cube_left();
    left_shimmy();
    turn_cube_right();
}

std::string Rubix::scan_side_pieces(char color1, char color2)
{
    std::string position = "";

    //color1 = front color2 = right
    if(front[1][2] == color1 && right[1][0] == color2)
    {
        position = "final position";
    }

    else if(front[1][2] == color2 && right[1][0] == color1)
    {
        position ="right middle";
    }
    
    else if(front[0][1] == color1 && top[2][1] == color2)
    {
        position = "top middle matching front";
    }

    else if(front[0][1] == color2 && top[2][1] == color1)
    {
        position = "top middle matching right";
    }

    else if((front[1][0] == color1 || front[1][0] == color2) && (left[1][2] == color1 || left[1][2] == color2))
    {
        position = "left middle";
    }

    else
    {
        position = "not here";
    }

    return position;
}

bool Rubix::side_pieces_check()
{
    bool check = false;
    if( (front[1][1] == front[1][2] && front[1][1] == front[1][0])&& (left[1][1] == left[1][2] && left[1][1] == left[1][0]) &&
        (right[1][1] == right[1][2] && right[1][1] == right[1][0]) && (back[1][1] == back[1][2] && back[1][1] == back[1][0]) )
        {
            check = true;
        }
    return check;
}



void Rubix::yellow_cross()
{

}

std::string Rubix::scan_yellow_cross(char color1)
{
    std::string status = "";

    if(top[0][1] == color1 && top[1][0] == color1 && top[2][1] == color1 && top[1][2] == color1)
    {
        status = "Cross complete";
    }

    else if(top[0][1] == color1 && top[1][1] == color1 && top[2][1] == color1)
    {
        status = "line not set";
    }

    else if((top[1][0] == color1 && top[1][1] == color1 && top[2][1] == color1) || 
            (top[0][1] == color1 && top[1][1] == color1 && top[1][2] == color1) ||
            (top[2][1] == color1 && top[1][1] == color1 && top[1][2] == color1)   )
    {
        status = "L-shape not set";
    }

    return status;
}




