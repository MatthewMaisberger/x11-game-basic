#include "GameDisplay.hpp"
#include <stdexcept>

GameDisplay::GameDisplay()
{
	m_display = XOpenDisplay(nullptr);
	if (!m_display)
	{
		throw std::runtime_error("Unable to open the display\n");
	}
	
	m_screen = DefaultScreen(m_display);

	m_window = XCreateSimpleWindow(m_display, RootWindow(m_display, m_screen), 10, 10, 1000, 1000, 1,
			BlackPixel(m_display, m_screen), WhitePixel(m_display, m_screen));

	XSelectInput(m_display, m_window, KeyPressMask | ExposureMask);
	XMapWindow(m_display, m_window);
}

GameDisplay::~GameDisplay()
{
	XCloseDisplay(m_display);
}

Display* GameDisplay::getDisplay()
{
	return m_display;
}

Window GameDisplay::getWindow()
{
	return m_window;
}

void GameDisplay::drawRect(unsigned long color, int x, int y, int width, int height)
{
	XSetForeground(m_display, DefaultGC(m_display, m_screen), color);
	XFillRectangle(m_display, m_window, DefaultGC(m_display, m_screen), x, y, width, height);
		
}

void GameDisplay::redraw()
{
	Window root_window;
	int x, y;
	unsigned int width, height, border_width, depth;
	XGetGeometry(m_display, m_window, &root_window, &x, &y, &width,
			&height, &border_width, &depth);

	XEvent event;
	event.xexpose.type = Expose;
	event.xexpose.display = m_display;
	event.xexpose.window = m_window;
	event.xexpose.x = x;
	event.xexpose.y = y;
	event.xexpose.width = width;
	event.xexpose.height = height;
	event.xexpose.count = 0;

	XSendEvent(m_display, m_window, false, ExposureMask, &event);
}
