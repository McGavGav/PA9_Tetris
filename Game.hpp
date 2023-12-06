#include "shape.cpp"
#include "Blocks.hpp"

using namespace std;
using namespace sf;

//inherits functions from blocks to write runGame
class Tetris :public Blocks
{
public:
    //runs game
    int runGame();
    int mainMenu();
   
private:
};