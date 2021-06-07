#include <iostream>
using namespace std;

#include "olcConsoleGameEngine.h"

class defColorama1 : public olcConsoleGameEngine
{
public:
	defColorama1()
	{
		m_sAppName = L"defColorama1";
	}
	virtual bool OnUserCreate()
	{
		return true;
	}
	virtual bool OnUserUpdate(float fElapsedTime)
	{
		Fill(0, 0, ScreenWidth(), ScreenHeight(), PIXEL_SOLID, BG_BLACK);
		for (int x = 0; x < ScreenWidth()/2; x++)
		{
			for (int y = 0; y < ScreenHeight()/2; y++)
			{
				Draw(x, y, PIXEL_SOLID, FG_RED);
			}
		}
		for (int x = ScreenWidth() / 2; x < ScreenWidth(); x++)
		{
			for (int y = 0; y < ScreenHeight() / 2; y++)
			{
				Draw(x, y, PIXEL_SOLID, FG_GREEN);
			}
		}
		for (int x = 0; x < ScreenWidth() / 2; x++)
		{
			for (int y = ScreenHeight()/2; y < ScreenHeight(); y++)
			{
				Draw(x, y, PIXEL_SOLID, FG_DARK_BLUE);
			}
		}
		for (int x = ScreenWidth() / 2; x < ScreenWidth(); x++)
		{
			for (int y = ScreenHeight() / 2; y < ScreenHeight(); y++)
			{
				Draw(x, y, PIXEL_SOLID, FG_WHITE);
			}
		}
		return true;
	}
private:
	
};

int main()
{
	defColorama1 demo;
	demo.ConstructConsole(160, 100, 8, 8);
	demo.Start();
	return 0;
}
