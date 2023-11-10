#include <X11/Xlib.h>

class GameDisplay
{
public:
	GameDisplay();
	~GameDisplay();
	
	Display* getDisplay();

private:
	Display* m_display;
	Window m_window;
	int m_screen;
};

