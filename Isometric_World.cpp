#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

class IsometricWorld : public olc::PixelGameEngine
{
public:
	IsometricWorld()
	{
		sAppName = "Isometrical world";
	}

private:
	olc::vi2d vWorldSize = { 14, 10 };
	olc::vi2d vTileSize = { 40, 20 };
	olc::vi2d vOrigin = { 5, 1 };
	olc::Sprite* sprIsom = nullptr;
	olc::Sprite* sprGround = nullptr;
	olc::Sprite* sprWallLeft = nullptr;
	olc::Sprite* sprWallRight = nullptr;
	int* pWorld = nullptr;
	olc::vi2d vSelectorPos1 = { -1, -1 };
	olc::vi2d vSelectorPos2 = { -1, -1 };
	bool bSelecting = false;
	bool bPlayMode = false;

	struct Player
	{
		olc::Sprite* spr = nullptr;
		int wx, wy;
	} player;

protected:
	bool OnUserCreate() override
	{
		sprIsom = new olc::Sprite("Sprites/isometric_demo.png");
		sprGround = new olc::Sprite("Sprites/ground_tile.png");
		sprWallLeft = new olc::Sprite("Sprites/wall_left.png");
		sprWallRight = new olc::Sprite("Sprites/wall_right.png");
		player.spr = new olc::Sprite("Sprites/player.png");
		pWorld = new int[vWorldSize.x * vWorldSize.y]{ 0 };

		player.wx = vWorldSize.x / 2;
		player.wy = vWorldSize.y / 2;

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		Clear(olc::WHITE);

		auto ToScreen = [&](int x, int y)
		{
			return olc::vi2d
			{
				(vOrigin.x * vTileSize.x) + (x - y) * (vTileSize.x / 2),
				(vOrigin.y * vTileSize.y) + (x + y) * (vTileSize.y / 2)
			};
		};

		auto IsBoard = [&](int nx, int ny)
		{
			if (nx < -1 || ny < -1 || ny > vWorldSize.x 
				|| nx > vWorldSize.x - 2 || ny > vWorldSize.y - 2)
				return true;
			return false;
		};

		olc::vi2d vMouse = { GetMouseX(), GetMouseY() };
		olc::vi2d vCell = { vMouse.x / vTileSize.x, vMouse.y / vTileSize.y };

		olc::vi2d vOffset = { vMouse.x % vTileSize.x, vMouse.y % vTileSize.y };
		olc::Pixel col = sprIsom->GetPixel(3 * vTileSize.x + vOffset.x, vOffset.y);

		olc::vi2d vSelected =
		{
			(vCell.y - vOrigin.y) + (vCell.x - vOrigin.x),
			(vCell.y - vOrigin.y) - (vCell.x - vOrigin.x)
		};

		if (col == olc::RED) vSelected += {-1, +0};
		if (col == olc::BLUE) vSelected += {0, -1};
		if (col == olc::GREEN) vSelected += {+0, +1};
		if (col == olc::YELLOW) vSelected += {+1, +0};

		if (GetKey(olc::Key::G).bPressed) bPlayMode = !bPlayMode;

		if (GetKey(olc::Key::R).bPressed)
		{
			for (int x = 0; x < vWorldSize.x; x++)
			{
				for (int y = 0; y < vWorldSize.y; y++)
				{
					olc::vi2d vWorld = ToScreen(x, y);

					pWorld[y * vWorldSize.x + x] = 0;
				}
			}

			vSelectorPos1 = { -1, -1 };
			vSelectorPos2 = { -1, -1 };
			bSelecting = false;
			bPlayMode = false;

			player.wx = vWorldSize.x/2;
			player.wy = vWorldSize.y/2;
		}

		if (!bPlayMode)
		{
			if (GetMouse(0).bPressed)
			{
				if (vSelected.x >= 0 && vSelected.x < vWorldSize.x && vSelected.y >= 0 && vSelected.y < vWorldSize.y)
					++pWorld[vSelected.y * vWorldSize.x + vSelected.x] %= 10;
			}

			if (GetKey(olc::Key::Z).bPressed)
			{
				if (vSelected.x >= 0 && vSelected.x < vWorldSize.x && vSelected.y >= 0 && vSelected.y < vWorldSize.y)
				{
					vSelectorPos1.x = vSelected.x;
					vSelectorPos1.y = vSelected.y;
				}
			}

			if (GetKey(olc::Key::X).bPressed && vSelectorPos1.x != -1)
			{

				if (vSelected.x >= 0 && vSelected.x < vWorldSize.x && vSelected.y >= 0 && vSelected.y < vWorldSize.y)
				{
					vSelectorPos2.x = vSelected.x; vSelectorPos2.x++;
					vSelectorPos2.y = vSelected.y; vSelectorPos2.y++;
				}
				bSelecting = true;
			}
		}
		else
		{
			if (GetKey(olc::Key::E).bPressed && !IsBoard(0, player.wy - 1)) player.wy -= 1;
			if (GetKey(olc::Key::Z).bPressed && !IsBoard(0, player.wy + 1)) player.wy += 1;
			if (GetKey(olc::Key::Q).bPressed && !IsBoard(player.wx - 1, 0)) player.wx -= 1;
			if (GetKey(olc::Key::C).bPressed && !IsBoard(player.wx + 1, 0)) player.wx += 1;
			if (GetKey(olc::Key::W).bPressed && !IsBoard(player.wx - 1, player.wy - 1))
			{
				player.wx -= 1;
				player.wy -= 1;
			}
			if (GetKey(olc::Key::D).bPressed && !IsBoard(player.wx + 1, player.wy - 1))
			{
				player.wx += 1;
				player.wy -= 1;
			}
			if (GetKey(olc::Key::A).bPressed && !IsBoard(player.wx - 1, player.wy + 1))
			{
				player.wx -= 1;
				player.wy += 1;
			}
			if (GetKey(olc::Key::X).bPressed && !IsBoard(player.wx + 1, player.wy + 1))
			{
				player.wx += 1;
				player.wy += 1;
			}
		}

		SetPixelMode(olc::Pixel::MASK);

		for (int x = 0; x < vWorldSize.x; x++)
		{
			for (int y = 0; y < vWorldSize.y; y++)
			{
				olc::vi2d vWorld = ToScreen(x, y);

				switch (pWorld[y * vWorldSize.x + x])
				{
				case 0:
					// Invisble Tile
					DrawPartialSprite(vWorld.x, vWorld.y, sprIsom, 1 * vTileSize.x, 0, vTileSize.x, vTileSize.y);
					break;
				case 1:
					// Visible Tile
					DrawPartialSprite(vWorld.x, vWorld.y, sprIsom, 2 * vTileSize.x, 0, vTileSize.x, vTileSize.y);
					break;
				case 2:
					// Tree
					DrawPartialSprite(vWorld.x, vWorld.y - vTileSize.y, sprIsom, 0 * vTileSize.x, 1 * vTileSize.y, vTileSize.x, vTileSize.y * 2);
					break;
				case 3:
					// Spooky Tree
					DrawPartialSprite(vWorld.x, vWorld.y - vTileSize.y, sprIsom, 1 * vTileSize.x, 1 * vTileSize.y, vTileSize.x, vTileSize.y * 2);
					break;
				case 4:
					// Sand
					DrawPartialSprite(vWorld.x, vWorld.y - vTileSize.y, sprIsom, 2 * vTileSize.x, 1 * vTileSize.y, vTileSize.x, vTileSize.y * 2);
					break;
				case 5:
					// Water
					DrawPartialSprite(vWorld.x, vWorld.y - vTileSize.y, sprIsom, 3 * vTileSize.x, 1 * vTileSize.y, vTileSize.x, vTileSize.y * 2);
					break;
				case 6:
					// Ground
					DrawSprite({ vWorld.x, vWorld.y }, sprGround);
					break;
				case 7:
					// Left Wall with ground
					DrawSprite({ vWorld.x, vWorld.y - vTileSize.y * 2 }, sprWallLeft);
					DrawSprite({ vWorld.x, vWorld.y }, sprGround);
					break;
				case 8:
					// Right Wall with ground
					DrawSprite({ vWorld.x, vWorld.y - vTileSize.y * 2 }, sprWallRight);
					DrawSprite({ vWorld.x, vWorld.y }, sprGround);
					break;
				case 9:
					// Forward Wall with ground
					DrawSprite({ vWorld.x, vWorld.y - vTileSize.y * 2 }, sprWallLeft);
					DrawSprite({ vWorld.x, vWorld.y - vTileSize.y * 2 }, sprWallRight);
					DrawSprite({ vWorld.x, vWorld.y }, sprGround);
					break;
				}
			}
		}

		SetPixelMode(olc::Pixel::ALPHA);
		olc::vi2d vWorld = ToScreen(player.wx, player.wy);
		DrawSprite(vWorld.x, vWorld.y, player.spr);
		SetPixelMode(olc::Pixel::NORMAL);
		//std::cout << player.wx << player.wy << std::endl;

		SetPixelMode(olc::Pixel::ALPHA);
		olc::vi2d vSelectedWorld = ToScreen(vSelected.x, vSelected.y);
		DrawPartialSprite(vSelectedWorld.x, vSelectedWorld.y, sprIsom, 0 * vTileSize.x, 0, vTileSize.x, vTileSize.y);

		if (bSelecting)
		{
			for (int i = vSelectorPos1.x; i < vSelectorPos2.x; i++)
			{
				for (int j = vSelectorPos1.y; j < vSelectorPos2.y; j++)
				{
					++pWorld[j * vWorldSize.x + i] %= 10;
				}
			}
			vSelectorPos1.x = -1;
			bSelecting = false;
		}

		SetPixelMode(olc::Pixel::NORMAL);

		DrawString(4, 4, "Mouse	  : " + std::to_string(vMouse.x) + ", " + std::to_string(vMouse.y), olc::BLACK);
		DrawString(4, 14, "Player  : " + std::to_string(player.wx) + ", " + std::to_string(player.wy), olc::BLACK);
		DrawString(4, 24, "Cell	   : " + std::to_string(vCell.x) + ", " + std::to_string(vCell.y), olc::BLACK);
		DrawString(4, 34, "Selected: " + std::to_string(vSelected.x) + ", " + std::to_string(vSelected.y), olc::BLACK);
		DrawString(4, 44, "Builder Mode: " + std::to_string(!bPlayMode), olc::BLACK);

		return true;
	}
};

int main()
{
	IsometricWorld game;
	if (game.Construct(512, 480, 2, 2))
		game.Start();
	return 0;
}
