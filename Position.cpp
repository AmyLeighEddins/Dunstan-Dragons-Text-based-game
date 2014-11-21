#include <iostream>
#include <cstdlib>
using namespace std;

 

class Position
{
	public: 
		Position(int colIn, int rowIn);
		int col;
		int row;
		
		int[13][13] hall = {0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0};
				{0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0};
				{0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0};
				{0, 0, 0, 0, 1, 0, 0, 1, 2, 0, 0, 0, 0};
				{0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0};
								 {0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0};
								 {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0};
								 {0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0};
								 {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0};
								 {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0};
								 {0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0};
								 {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
								 {0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0};

		int getCol();
		int getRow();
		//changePosition(double array); 
		//Position getPosition(); 
		void moveLeft(); 
		void moveRight(); 
		void moveUp(); 
		void moveDown();

	
};
Position::Position(int colIn, int rowIn)
{
	row = rowIn;
	col = colIn;
}
int Position::getCol()
{
	return col;
}
int Position::getRow()
{
	return row;
}
 
void Position::moveLeft()
{
	
}
void Position::moveRight()
{
	if (col + 1 < 13)
         {
            if (hall[row][col + 1].equals(3) 
            || hall[row][col + 1].equals(1))
            {
               if (!hall[row][col + 1].equals(2)
               && !hall[row][col + 1].equals(3))
               {
                  col = col + 1;
               }
               return true;
            }
            else 
            { 
               return false;
            }
         }
         else
         {
            return false;
         }

}
void Position::moveUp()
{
	if (row - 1 < 13)
         {
            if (hall[row - 1][col].equals(3) 
            || hall[row - 1][col].equals(1))
            {
               if (!hall[row - 1][col].equals(2)
               && !hall[row - 1][col].equals(3))
               {
                  row = row - 1;
               }
               return true;
            }
            else 
            { 
               return false;
            }
         }
         else
         {
            return false;
         }
}
void Position::moveDown()
{
}

