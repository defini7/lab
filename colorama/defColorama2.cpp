#include <iostream>
#include <vector>
#include "olcConsoleGameEngine.h"

using namespace std;

// Information about each drawn pixel
struct points
{
	int x;
	int y;
	wchar_t PixelColour;
	wchar_t BackgroundColour;
};

vector<points> positions;

class defColorama2 : public olcConsoleGameEngine
{
public:
	defColorama2()
	{
		m_sAppName = L"Colorama";
	}
private:
	wchar_t wtPixelColour;
  // Default background colour
	wchar_t wtBackgroundColour = FG_WHITE;
protected:
	virtual bool OnUserCreate()
	{
		return true;
	}
	virtual bool OnUserUpdate(float fElapsedTime)
	{
		Fill(0, 0, ScreenWidth(), ScreenHeight(), PIXEL_SOLID, wtBackgroundColour);

		{
      // C + R --> Background Colour Red
			if (m_keys[0x43].bHeld && m_keys[0x52].bHeld)
			{
				wtBackgroundColour = FG_RED;
				Fill(0, 0, ScreenWidth(), ScreenHeight(), PIXEL_SOLID, FG_RED);
			}
      // C + G --> Background Colour Green
			if (m_keys[0x43].bHeld && m_keys[0x47].bHeld)
			{
				wtBackgroundColour = FG_GREEN;
				Fill(0, 0, ScreenWidth(), ScreenHeight(), PIXEL_SOLID, FG_GREEN);
			}
      // C + B --> Background Colour Blue
			if (m_keys[0x43].bHeld && m_keys[0x42].bHeld)
			{
				wtBackgroundColour = FG_BLUE;
				Fill(0, 0, ScreenWidth(), ScreenHeight(), PIXEL_SOLID, FG_BLUE);
			}
      // C + W --> Background Colour White (default background colour)
			if (m_keys[0x43].bHeld && m_keys[0x57].bHeld)
			{
				wtBackgroundColour = FG_WHITE;
				Fill(0, 0, ScreenWidth(), ScreenHeight(), PIXEL_SOLID, FG_WHITE);
			}
      // R --> Red Pencil
			if (m_keys[0x52].bHeld)
			{
				wtPixelColour = FG_RED;
			}
      // G --> Green Pencil
			else if (m_keys[0x47].bHeld)
			{
				wtPixelColour = FG_GREEN;
			}
      // B --> Blue Pencil
			else if (m_keys[0x42].bHeld)
			{
				wtPixelColour = FG_BLUE;
			}
      // None --> Black Pencil
			else
			{
				wtPixelColour = FG_BLACK;
			}
		}
    // Left Mouse Button to draw
		if (m_keys[VK_LBUTTON].bHeld)
		{
			positions.push_back({ m_mousePosX, m_mousePosY, wtPixelColour, wtBackgroundColour });
			Draw(m_mousePosX, m_mousePosY, PIXEL_SOLID, wtPixelColour);
		}
    // Pictures drawing
		for (auto i = 0; i < positions.size(); i++)
		{
			Draw(positions[i].x, positions[i].y, PIXEL_SOLID, positions[i].PixelColour);
		}
		return true;
	}
};

int main()
{
	defColorama2 game;
	game.ConstructConsole(200, 160, 4, 4);
	game.Start();
	return 0;
}
