#include <stdexcept>
#include "GameDisplay.hpp"

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

	XSelectInput(m_display, m_window, KeyPressMask);
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
