#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

class FractalTree : public olc::PixelGameEngine
{
public:
	FractalTree()
	{
		sAppName = "Fractal Tree";
	}

protected:
	olc::vf2d pos;
	float fTheta;

	int nMovingRadius1 = 300;
	int nMovingRadius2 = 150;

	const olc::Pixel col = olc::Pixel(rand() % 256, rand() % 256, rand() % 256);

protected:
	virtual bool OnUserCreate() override
	{
		pos = { (float)ScreenWidth() / 2.0f, (float)ScreenHeight() / 2.0f };
		return true;
	}

	virtual bool OnUserUpdate(float fElapsedTime) override
	{
		if (GetKey(olc::SPACE).bHeld)
			return true;

		Clear(olc::BLACK);

		for (int i = 0; i < 30; i+=5)
		{
			float fSin = sinf(fTheta);
			float fCos = cosf(fTheta);

			float x1 = pos.x + nMovingRadius1 * fCos;
			float y1 = pos.y + nMovingRadius1 * fSin;
			
			float x2 = pos.x + nMovingRadius2 * fSin;
			float y2 = pos.y + nMovingRadius2 * fCos;

			FillCircle(x1, y1, i, olc::Pixel(col.r * fTheta, col.g * fTheta, col.b * fTheta));
			FillCircle(x2, y2, i, olc::Pixel(col.r * fTheta, col.g * fTheta, col.b * fTheta));

			fTheta += fElapsedTime / 10.0f;
		}

		return true;
	}
};

int main()
{
	
	FractalTree game;
	if (game.Construct(1024, 768, 1, 1))
		game.Start();

	return 0;
}
