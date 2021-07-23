#pragma once

#include <windows.h>
#include <gl/gl.h>
#include <time.h>

#include "Objects.h"

#define mapW 20
#define mapH 20

Objects obj;

typedef struct
{
    BOOL mine;
    BOOL flag;
    BOOL open;
    BOOL checkMine;
    BOOL mineToCheck;
    int cntAround;
} Map;

Map map[mapW][mapH];
int mines;
int closedCell;
int minesToCheckAlive;
BOOL isFailed;

class GameLogic
{
public:
    BOOL isCellInMap(int x, int y);
    void ScreenToOpenGL(HWND hwnd, int x, int y, float* ox, float* oy);
    void GameNew();
    void OpenFields(int x, int y);
    void Line(float x1, float y1, float x2, float y2);
    void ShowCount(float a);
    void GameShow();
};

BOOL GameLogic::isCellInMap(int x, int y)
{
    return (x >= 0) && (y >= 0) && (x < mapW) && (y < mapH);
}

void GameLogic::ScreenToOpenGL(HWND hwnd, int x, int y, float* ox, float* oy)
{
    RECT rct;
    GetClientRect(hwnd, &rct);
    *ox = x / (float)rct.right * mapW;
    *oy = mapH - y / (float)rct.bottom * mapW;
}

void GameLogic::GameNew()
{
    srand(time(NULL));
    memset(map, 0, sizeof(map));

    mines = 70;
    closedCell = mapW * mapH;
    isFailed = FALSE;
    for (int i = 0; i < mines; i++)
    {
        int x = rand() % mapW;
        int y = rand() % mapH;
        if (map[x][y].mine) i--;
        else
        {
            map[x][y].mine = TRUE;
            for (int dx = -1; dx < 2; dx++)
                for (int dy = -1; dy < 2; dy++)
                    if (isCellInMap(x + dx, y + dy))
                        map[x + dx][y + dy].cntAround += 1;
        }
    }
}

// Open Fields
void GameLogic::OpenFields(int x, int y)
{
    if (!isCellInMap(x, y) || map[x][y].open) return;
    map[x][y].open = TRUE;
    closedCell--;
    if (map[x][y].cntAround == 0)
        for (int dx = -1; dx < 2; dx++)
            for (int dy = -1; dy < 2; dy++)
                OpenFields(x + dx, y + dy);
    if (map[x][y].mine)
    {
        isFailed = TRUE;
        for (int y = 0; y < mapH; y++)
            for (int x = 0; x < mapW; x++)
                map[x][y].open = TRUE;
    }
}

void GameLogic::Line(float x1, float y1, float x2, float y2)
{
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
}

// Show Count
void GameLogic::ShowCount(float a)
{
    glLineWidth(3);
    glColor3f(1, 1, 0);
    glBegin(GL_LINES);
    if ((a != 1) && (a != 4)) Line(0.3, 0.85, 0.7, 0.85);
    if ((a != 0) && (a != 1) && (a != 7)) Line(0.3, 0.5, 0.7, 0.5);
    if ((a != 1) && (a != 4) && (a != 7)) Line(0.3, 0.15, 0.7, 0.15);

    if ((a != 5) && (a != 6)) Line(0.7, 0.5, 0.7, 0.85);
    if (a != 2) Line(0.7, 0.5, 0.7, 0.15);

    if ((a != 1) && (a != 2) && (a != 3) && (a != 7)) Line(0.3, 0.5, 0.3, 0.85);
    if ((a == 0) || (a == 2) || (a == 6) || (a == 8)) Line(0.3, 0.5, 0.3, 0.15);
    glEnd();
}

void GameLogic::GameShow()
{
    glLoadIdentity();
    glScalef(2.0f / mapW, 2.0f / mapH, 1.0f);
    glTranslatef(-mapW * 0.5f, -mapH * 0.5f, 0);
    for (int y = 0; y < mapH; y++)
    {
        for (int x = 0; x < mapW; x++)
        {
            glPushMatrix();
            glTranslatef(x, y, 0);

            if (map[x][y].open)
            {
                obj.ShowFieldOpen();
                if (map[x][y].mine)
                    obj.ShowMine();
                else if (map[x][y].cntAround > 0)
                    ShowCount(map[x][y].cntAround);
            }
            else
            {
                obj.ShowField();
                if (map[x][y].flag) obj.ShowFlag();
            }

            if (map[x][y].mineToCheck)
            {
                obj.ShowCross();
                minesToCheckAlive--;
            }

            if (map[x][y].checkMine && map[x][y].open)
            {
                minesToCheckAlive++;
                {
                    if (map[x][y + 1].mine || map[x - 1][y].mine || map[x][y - 1].mine || map[x - 1][y - 1].mine || map[x + 1][y + 1].mine || map[x - 1][y + 1].mine || map[x + 1][y - 1].mine || map[x + 1][y].mine)
                    {
                        if (!map[x][y + 1].open && !map[x][y + 1].flag)
                            map[x][y + 1].mineToCheck = TRUE;
                        if (!map[x - 1][y].open && !map[x - 1][y].flag)
                            map[x - 1][y].mineToCheck = TRUE;
                        if (!map[x][y - 1].open && !map[x][y - 1].flag)
                            map[x][y - 1].mineToCheck = TRUE;
                        if (!map[x - 1][y - 1].open && !map[x][y - 1].flag)
                            map[x - 1][y - 1].mineToCheck = TRUE;
                        if (!map[x + 1][y + 1].open && !map[x][y - 1].flag)
                            map[x + 1][y + 1].mineToCheck = TRUE;
                        if (!map[x - 1][y + 1].open && !map[x][y - 1].flag)
                            map[x - 1][y + 1].mineToCheck = TRUE;
                        if (!map[x + 1][y - 1].open && !map[x][y - 1].flag)
                            map[x + 1][y - 1].mineToCheck = TRUE;
                        if (!map[x + 1][y].open && !map[x][y - 1].flag)
                            map[x + 1][y].mineToCheck = TRUE;
                    }
                }
            }
            else if (map[x][y].checkMine && map[x][y].open && !map[x][y + 1].mine && !map[x - 1][y].mine && !map[x][y - 1].mine && !map[x - 1][y - 1].mine && !map[x + 1][y + 1].mine && !map[x - 1][y + 1].mine && !map[x + 1][y - 1].mine && !map[x + 1][y].mine)
            {
                map[x][y + 1].open = TRUE;
                map[x - 1][y].open = TRUE;
                map[x][y - 1].open = TRUE;
                map[x - 1][y - 1].open = TRUE;
                map[x + 1][y + 1].open = TRUE;
                map[x - 1][y + 1].open = TRUE;
                map[x + 1][y - 1].open = TRUE;
                map[x + 1][y].open = TRUE;
            }

            if (minesToCheckAlive == 0)
                for (int x = 0; x < mapW; x++)
                    for (int y = 0; y < mapH; y++)
                        map[x][y].mineToCheck = FALSE;
            map[x][y].checkMine = FALSE;

            glPopMatrix();
        }
    }
}
