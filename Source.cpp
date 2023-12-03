#include "Header.hpp"

int main(void)
{
	//makes requirements for window and size/open/close/title
	RenderWindow window(VideoMode(720, 480), "Game Time", Style::Titlebar | Style::Close | Style::Default | Style::Resize);
	//event item to track when things like clicks/keyboard entries are made/entered
	Event events;

	//while window isnt closed
	while (window.isOpen())
	{
		//events while window is open
		while (window.pollEvent(events))
		{
			switch (events.type)
			{
				//hit exit
			case Event::Closed:
				window.close();
				break;
				//closes on hitting 'esc' key
			case Event::KeyPressed:
				if (events.key.code == Keyboard::Escape)
				{
					window.close();
				}
				break;
			}
		}

		//update?
		
		//render?

		//clears the window
		window.clear(Color::Black);

		//displays what we have netered to be displayed
		window.display();

	}
	return 0;
}
