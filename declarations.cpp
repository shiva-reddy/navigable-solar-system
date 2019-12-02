#include <GL/glut.h>
#include <math.h>
#include "RGBpixmap.h" 
#include "RGBpixmap.cpp"
#include "globals.h"
void KeyboardPress(unsigned char pressedKey, int mouseXPosition, int mouseYPosition);
void arrowKeyPress(int pressedKey, int mouseXPosition, int mouseYPosition);
void TimerFunction(int value);
void Display();
void MakeAllImages();
void MakeImage(const char bitmapFilename[], GLuint &textureName, bool hasAlpha);
void SetLights();
void UpdateLight();
void drawSun();
void drawAllPlanets();
void drawGenericPlanet(GLfloat inclination, GLfloat orbitDuration,
		GLfloat orbitRadius, GLfloat rotationDuration, GLuint texturename, GLfloat radius);


