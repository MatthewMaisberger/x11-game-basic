#include <X11/Xlib.h>

class GameDisplay
{
public:
	GameDisplay();
	~GameDisplay();
	
	Display* getDisplay();
	Window getWindow();
	void drawRect(unsigned long color, int x, int y, int width, int height);
	void redraw();

private:
	Display* m_display;
	Window m_window;
	int m_screen;
};

