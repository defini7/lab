#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

#define WIDTH 800
#define HEIGHT 600

class GameApp : public olc::PixelGameEngine
{
public:
	GameApp()
	{
		sAppName = "3D Sample";
	}
public:
	bool OnUserCreate() override
	{
		return true;
	}
	bool OnUserUpdate(float fElapsedTime) override
	{
		if (GetKey(olc::UP).bHeld)
		{
			nAngleUD -= 5;
		}
		if (GetKey(olc::DOWN).bHeld)
		{
			nAngleUD += 5;
		}

		if (GetKey(olc::LEFT).bHeld)
		{
			nAngleLR -= 5;
		}

		if (GetKey(olc::RIGHT).bHeld)
		{
			nAngleLR += 5;
		}
		FillRect({ 0, 0 }, { WIDTH, HEIGHT/2 - nAngleUD * 2 }, olc::VERY_DARK_BLUE);
		FillRect({ 0, HEIGHT/2 - nAngleUD * 2 }, { WIDTH, HEIGHT }, olc::DARK_GREEN);
		FillRect({ WIDTH / 3 - (nAngleLR * 2), HEIGHT / 3 - (nAngleUD * 2) }, {WIDTH / 3, HEIGHT / 3 + 10 }, olc::DARK_RED);
		return true;
	}

protected:
	int nAngleUD = 0;
	int nAngleLR = 0;
};
int main()
{
	GameApp game;
	if (game.Construct(WIDTH, HEIGHT, 1, 1));
		game.Start();
	return 0;
}
