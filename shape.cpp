#pragma once
#include "Header.hpp"

//Sets up shapes in a 4x4
static int shapes[7][4][4] =
{
    //L piece
    1,0,0,0,
    1,0,0,0,
    1,1,0,0,
    0,0,0,0, 
    //S piece
    0,1,0,0,
    1,1,0,0,
    1,0,0,0,
    0,0,0,0, 
    //T piece
    1,0,0,0,
    1,1,0,0,
    1,0,0,0,
    0,0,0,0, 
    //J piece
    0,1,0,0,
    0,1,0,0,
    1,1,0,0,
    0,0,0,0, 
    //O piece
    1,1,0,0,
    1,1,0,0,
    0,0,0,0,
    0,0,0,0, 
    //I piece
    1,0,0,0,
    1,0,0,0,
    1,0,0,0,
    1,0,0,0, 
    //Z piece
    1,0,0,0,
    1,1,0,0,
    0,1,0,0,
    0,0,0,0,
};

//Sets colors for pieces
const Color colorArr[] =
{
    Color::White, Color::Magenta, Color::Cyan, Color::Green,
    Color::Blue, Color::Red, Color::Yellow
};

