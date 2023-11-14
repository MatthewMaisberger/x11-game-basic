#include "GameDisplay.hpp"
#include <X11/Xlib.h>

class Game
{
public:
	Game(); // default constructor
	void run();

private:
	GameDisplay m_gamedisplay;
	XEvent m_event;
	bool m_is_running {true};
	int m_x {10};
	int m_y {10};
	int m_vx {4};
	int m_vy {4};

	bool getEvent();
	void handleEvent();
};

namespace GameKeys
{
	constexpr int KEY_UP    	 = 111;
	constexpr int KEY_RIGHT  	 = 114;
	constexpr int KEY_DOWN       = 116;
	constexpr int KEY_LEFT       = 113;
	constexpr int KEY_ESCAPE	 = 9;
	constexpr int KEY_SPACEBAR   = 65;
};
