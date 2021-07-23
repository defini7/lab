#pragma once

#include <windows.h>
#include <gl/gl.h>

class Objects
{
public:
	void ShowMine();
	void ShowField();
	void ShowFieldOpen();
	void ShowFlag();
	void ShowCross();
};

// Show Mine
void Objects::ShowMine()
{
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0, 0, 0);
    glVertex2f(0.3, 0.3);
    glVertex2f(0.7, 0.3);
    glVertex2f(0.7, 0.7);
    glVertex2f(0.3, 0.7);
    glEnd();
}

// Show Field
void Objects::ShowField()
{
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(0.8, 0.8, 0.8); glVertex2f(0, 1);
    glColor3f(0.7, 0.7, 0.7); glVertex2f(1, 1); glVertex2f(0, 0);
    glColor3f(0.6, 0.6, 0.6); glVertex2f(1, 0);
    glEnd();
}

// Show Open Field
void Objects::ShowFieldOpen()
{
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(0.3, 0.7, 0.3); glVertex2f(0, 1);
    glColor3f(0.3, 0.6, 0.3); glVertex2f(1, 1); glVertex2f(0, 0);
    glColor3f(0.3, 0.5, 0.3); glVertex2f(1, 0);
    glEnd();
}

// Flag
void Objects::ShowFlag()
{
    glBegin(GL_TRIANGLES);
    glColor3f(1, 0, 0);
    glVertex2f(0.25f, 0.75f);
    glVertex2f(0.85f, 0.5f);
    glVertex2f(0.25f, 0.25f);
    glEnd();
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex2f(0.25f, 0.75f);
    glVertex2f(0.25f, 0.0f);
    glEnd();
}

// Show X
void Objects::ShowCross()
{
    glLineWidth(5);
    glBegin(GL_LINES);
    glColor3f(1, 0, 0);
    glVertex2f(0.15f, 0.15f);
    glVertex2f(0.85f, 0.85f);
    glVertex2f(0.15f, 0.85f);
    glVertex2f(0.85f, 0.15f);
    glEnd();
}
