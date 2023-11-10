#include <X11/Xlib.h>
#include <cstdio>
#include <iostream>

#include "GameDisplay.hpp"

#define KEY_UP    111
#define KEY_RIGHT 114
#define KEY_DOWN  116
#define KEY_LEFT  113
#define KEY_ESCAPE	  9
#define KEY_SPACEBAR 65

int main()
{
	GameDisplay gamedisplay;

	XEvent event;
	bool exit_status = false;
	while (!exit_status)
	{
		if (XPending( gamedisplay.getDisplay() ));
		{
			XNextEvent( gamedisplay.getDisplay(), &event );

			printf("EVENT: %d\n", event.type);

			if (event.type == KeyPress)
			{
				printf("KeyPress Event: %d\n", event.xkey.keycode);
			}

			switch (event.xkey.keycode)
			{
				case KEY_UP:
					printf("KEY_UP\n");
					break;

				case KEY_RIGHT:
				   	printf("KEY_RIGHT\n");
				   	break;

				case KEY_DOWN:
				   	printf("KEY_DOWN\n");
				   	break;

				case KEY_LEFT:
				   	printf("KEY_LEFT\n");
				   	break;

				case KEY_SPACEBAR:
					printf("KEY_SPACEBAR\n");
					break;

				case KEY_ESCAPE:
					printf("QUITTING GAME\n");
					exit_status = true;
					break;
			}
		}
	}

	printf("EXITING\n");
		
	return 0;
}
