#include "Header.hpp"
#include "shape.cpp"

class Blocks
{
public:
    // sets up dimensions for the playfield
    const int Rows = 10;
    const int Columns = 20;
    const int sectionSize = 25;
    int playField[20][10] = { 0 };
    // ints for block creation with x,y values as well
    int xblock;
    int yblock;
    int block;
    //function that makes a new block for the game
    auto newBlock()
    {
        block = rand() % 7;
        yblock = 0;
        xblock = Rows / 2;
    }
    //creates a rectangle shape and returns it
    RectangleShape makeItem()
    {
        RectangleShape section(Vector2f(sectionSize, sectionSize));
        return section;
    }
    //checks block coords vs the playfield to ensure staying in bounds
    bool checkBounds()
    {
        for (int y = 0; y < 4; y++)
        {
            for (int x = 0; x < 4; x++)
            {
                //no collision
                if (shapes[block][y][x] == 0)
                {
                    continue;
                }
                // hit the playfield boundary
                if (x + xblock < 0 || x + xblock >= Rows || y + yblock >= Columns)
                {
                    return false;
                }
                // hit blocks in the field
                if (playField[y + yblock][x + xblock])
                {
                    return false;
                }
            }
        }
        return true;
    };
    //function that clears full rows
    auto wipeLines()
    {
        //int to help track rows being full
        int deletedLine = Columns - 1;
        //check from bottom to top in the field
        for (int undeletedLine = Columns - 1; undeletedLine >= 0; undeletedLine--)
        {
            int countRow = 0;
            for (int x = 0; x < Rows; x++)
            {
                if (playField[undeletedLine][x])
                    countRow++;
            }
            // if current line is not full copy the lines // if not delete
            if (countRow < Rows)
            {
                for (int x = 0; x < Rows; x++)
                {
                    playField[deletedLine][x] = playField[undeletedLine][x];
                }
                deletedLine--;
            }
        }
    };

    bool descend()
    {
        //increase y int
        yblock++;
        //hit the bottom of the field
        if (checkBounds() == false)
        {
            yblock--;
            for (int y = 0; y < 4; y++)
            {
                for (int x = 0; x < 4; x++)
                {
                    if (shapes[block][y][x])
                    {
                        // +1 to not create issues with the bottom
                        playField[yblock + y][xblock + x] = block + 1;
                    }
                }
            }
            // delete lines
            wipeLines();
            // start next block
            newBlock();
            return false;
        }
        return true;
    };
    //function for rotating the blocks
    auto rotate()
    {
        // checking size for rotation
        int length = 0;
        for (int y = 0; y < 4; y++)
        {
            for (int x = 0; x < 4; x++)
            {
                if (shapes[block][y][x])
                {
                    length = std::max(std::max(x, y) + 1, length);
                }
            }
        }
        // for tracking a rotated block
        int rotateBlock[4][4] = { 0 };
        // rotate 90 degrees // only one direction
        for (int y = 0; y < length; y++)
        {
            for (int x = 0; x < length; x++)
            {
                if (shapes[block][y][x])
                {
                    rotateBlock[length - 1 - x][y] = 1;
                }
            }
        }
        for (int y = 0; y < 4; y++)
        {
            for (int x = 0; x < 4; x++)
            {
                shapes[block][y][x] = rotateBlock[y][x];
            }
        }
    };
private:
};

