#include "Game.hpp"
#include <cstdio>
#include <X11/Xlib.h>

Game::Game()
{
	
}

void Game::run()
{
	while (m_is_running)
	{
		if (getEvent())
		{
			handleEvent();
		}
	}	
}

bool Game::getEvent()
{
	if (XPending(m_gamedisplay.getDisplay()))
	{
		XNextEvent(m_gamedisplay.getDisplay(), &m_event);
		printf("Event: %d\n", m_event.type);
		return true;
	}	
	return false;
}

void Game::handleEvent()
{	
	if (m_event.type == KeyPress)
	{
		printf("KeyPress Event: %d\n", m_event.xkey.keycode);
	}

	switch (m_event.xkey.keycode)
	{
		case GameKeys::KEY_UP:
			printf("KEY_UP\n");
			break;

		case GameKeys::KEY_RIGHT:
			printf("KEY_RIGHT\n");
			break;

		case GameKeys::KEY_DOWN:
			printf("KEY_DOWN\n");
			break;

		case GameKeys::KEY_LEFT:
			printf("KEY_LEFT\n");
			break;

		case GameKeys::KEY_SPACEBAR:
			printf("KEY_SPACEBAR\n");
			break;

		case GameKeys::KEY_ESCAPE:
			printf("QUITTING GAME\n");
			m_is_running = false;
			break;
	}
}
