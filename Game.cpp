#include "Game.hpp"

int Tetris::runGame()
{
    //window to display the game to
    RenderWindow window(VideoMode(Rows * sectionSize, Columns * sectionSize), "Tetriz PA9");
    //draws a section into the program
    RectangleShape section(Vector2f(sectionSize, sectionSize));
    //makes a block
    newBlock();
    // boundary check for a block
    checkBounds();
    // clear lines when a row is full
    wipeLines();
    // instantly drop a block
    descend();
    // rotate 
    rotate();
    //called to help manage "ticks" in the game so pieces can descend
    Clock clock;
    //when window is open do the following...
    while (window.isOpen())
    {
        // starts clock
        static float prev = clock.getElapsedTime().asSeconds();
        if (clock.getElapsedTime().asSeconds() - prev >= 0.5)
        {
            prev = clock.getElapsedTime().asSeconds();
            descend();
        }
        // for tracking events like keys being pressed
        Event events;
        while (window.pollEvent(events))
        {
            // close window from hitting 'x'
            if (events.type == Event::Closed)
            {
                window.close();
            }
            //tracks keys pressed and responds appropriately
            if (events.type == Event::KeyPressed)
            {
                if (events.key.code == Keyboard::Escape) // esc closes game
                {
                    window.close();
                }
                else if (events.key.code == Keyboard::Left) //left moves left, checks for bounds and adjusts
                {
                    xblock--;
                    if (checkBounds() == false)
                    {
                        xblock++;
                    }
                }
                else if (events.key.code == Keyboard::Right) //right moves right, checks for bounds and adjusts
                {
                    xblock++;
                    if (checkBounds() == false)
                    {
                        xblock--;
                    }
                }
                else if (events.key.code == Keyboard::Down) //down key descends a line
                {
                    descend();
                }
                else if (events.key.code == Keyboard::Space) //instantly drops the piece to bottom
                {
                    while (descend() == true);
                }
                else if (events.key.code == Keyboard::Up) // rotates, if not possible due to bounds goes back to start position
                {
                    rotate();
                    if (checkBounds() == false)
                    {
                        rotate(), rotate(), rotate();
                    }
                }
            }
        }
        // clears window every frame
        window.clear(Color::Black);
        //draws the blocks each time
        for (int y = 0; y < Columns; y++)
        {
            for (int x = 0; x < Rows; x++)
            {
                if (playField[y][x])
                {
                    section.setFillColor(colorArr[playField[y][x] - 1]);
                    section.setPosition(Vector2f(x * sectionSize, y * sectionSize));
                    window.draw(section);
                }
            }
        }
        section.setFillColor(colorArr[block]);
        for (int y = 0; y < 4; y++)
        {
            for (int x = 0; x < 4; x++)
            {
                if (shapes[block][y][x])
                {
                    section.setPosition(Vector2f((xblock + x) * sectionSize, (yblock + y) * sectionSize));
                    window.draw(section);
                }
            }
        }
        // display all thats called to be on screen
        window.display();
    }
    return 0;
}

int Tetris::mainMenu()
{
    int choice = 0;
    while (choice != 3)
    {
        cout << "~~~~~Welcome to Tetriz!~~~~~~~" << endl << endl;
        cout << "1. Play!" << endl;
        cout << "2. Controls." << endl;
        cout << "3. Exit." << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            system("cls");
            runGame();   
            break;
        case 2:
            system("cls");
            cout << "~~~~~Controls~~~~~" << endl << endl;
            cout << "Up = Rotate." << endl;
            cout << "Left/Right = Move side to side." << endl;
            cout << "Down = Move down a row." << endl;
            cout << "Space = Instant Drop!" << endl;
            cout << "Esc. = Close Program." << endl;
            system("pause");
            system("cls");      
            break;
        case 3:
            system("cls");
            cout << "Thanks for Using!" << endl;
            system("pause");
        }
    }
    return 0;
}
