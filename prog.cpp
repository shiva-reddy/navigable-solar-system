#include "declarations.cpp"

int main(int argc, char** argv)
{
	glutInit (&argc, argv);

	// Set up the display window.
	glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGBA | GLUT_STENCIL | GLUT_DEPTH);
    	glutInitWindowPosition( INIT_WINDOW_POSITION[0], INIT_WINDOW_POSITION[1] );
	glutInitWindowSize( currWindowSize[0], currWindowSize[1] );
    	glutCreateWindow( "Display" );

	// Specify the resizing and refreshing routines.
	glutKeyboardFunc( KeyboardPress );
	glutSpecialFunc( arrowKeyPress );
	glutDisplayFunc( Display );
	glutTimerFunc( 20, TimerFunction, 1 );
	glViewport(0, 0, currWindowSize[0], currWindowSize[1]);

	// Set up standard lighting, shading, and depth testing.
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	//glDepthFunc(GL_LEQUAL);							
	glEnable(GL_CULL_FACE);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	SetLights();
	MakeAllImages();
	glutMainLoop();
	return 0;
}

void KeyboardPress(unsigned char pressedKey, int mouseXPosition, int mouseYPosition)
{
	char pressedChar = char(pressedKey);
	switch(pressedKey)
	{
		case '+': {
						EarthDayIncrement *= 2.0;
						if (EarthDayIncrement > 10.0)
							EarthDayIncrement = 10.0;
						break;
				  }
		case '-': {		
						EarthDayIncrement *= 0.5;
						if (EarthDayIncrement < 0.01)
							EarthDayIncrement = 0.01;
						break;
				  }
		case 'w': {
						ViewerDistance -= VIEWER_DISTANCE_INCREMENT;
						if (ViewerDistance < MINIMUM_VIEWER_DISTANCE)
							ViewerDistance = MINIMUM_VIEWER_DISTANCE;
						break; 
				  }
		case 's': {
						ViewerDistance += VIEWER_DISTANCE_INCREMENT;
						if (ViewerDistance > MAXIMUM_VIEWER_DISTANCE)
							ViewerDistance = MAXIMUM_VIEWER_DISTANCE;
						break; 
				  }
						
	
}
}
void arrowKeyPress(int pressedKey, int mouseXPosition, int mouseYPosition)
{
	glutIgnoreKeyRepeat(false);
	switch(pressedKey)
	{
		case GLUT_KEY_RIGHT: { 
								phi += VIEWER_ANGLE_INCREMENT; 
								if (phi > 2*PI) 
									phi -= 2*PI; 
								break; 
							 }
		case GLUT_KEY_LEFT:  { 
								phi -= VIEWER_ANGLE_INCREMENT; 
								if (phi < 0.0)  
									phi += 2*PI; 
								break; 
							 }
		case GLUT_KEY_UP:    { 
								theta -= VIEWER_ANGLE_INCREMENT; 
								if (theta < VIEWER_ANGLE_INCREMENT) 
									theta = VIEWER_ANGLE_INCREMENT; 
								break; 
							 }
		case GLUT_KEY_DOWN:  { 
								theta += VIEWER_ANGLE_INCREMENT; 
								if (theta > PI - VIEWER_ANGLE_INCREMENT)  
									theta = PI - VIEWER_ANGLE_INCREMENT; 
								break; 
							 }
	}
}

void TimerFunction(int value)
{
	CurrentEarthRotation += EarthDayIncrement;
	EarthDaysTranspired += EarthDayIncrement;
	if (EarthDaysTranspired == EARTH_ORBIT_DUR)
		EarthDaysTranspired = 0;
	glutPostRedisplay();
	glutTimerFunc(20, TimerFunction, 1);
}
void Display()
{
	// Initialize lighting.
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, LIGHT_MODEL_AMBIENT);	
	glEnable(GL_LIGHTING);
	
	// Set up the properties of the viewing camera.
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
        gluPerspective(60.0, ASPECT_RATIO, 0.2, 100.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT| GL_STENCIL_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Position and orient viewer.
	gluLookAt(LOOK_AT_POSITION[0] + ViewerDistance * sin(theta) * sin(phi), 
				LOOK_AT_POSITION[1] + ViewerDistance * cos(theta), 
				LOOK_AT_POSITION[2] + ViewerDistance * sin(theta) * cos(phi),
				LOOK_AT_POSITION[0], LOOK_AT_POSITION[1], LOOK_AT_POSITION[2],
				0.0, 1.0, 0.020);

	// Render scene.
	UpdateLight();
	drawSun();
	drawAllPlanets();
	glDisable(GL_LIGHTING);
	glutSwapBuffers();
	glFlush();
}
//
void MakeAllImages()
{
	MakeImage(EARTH_BMP_FILENAME, EarthTextureName, false);
	MakeImage(SUN_BMP_FILENAME,SunTextureName,false);
	MakeImage(MERCURY_BMP_FILENAME, MercuryTextureName, false);
	MakeImage(VENUS_BMP_FILENAME, VenusTextureName, false);
	MakeImage(MARS_BMP_FILENAME, MarsTextureName, false);
	MakeImage(JUPITER_BMP_FILENAME, JupiterTextureName, false);
	MakeImage(SATURN_BMP_FILENAME, SaturnTextureName, false);
	MakeImage(URANUS_BMP_FILENAME, UranusTextureName, false);
	MakeImage(NEPTUNE_BMP_FILENAME, NeptuneTextureName, false);
	MakeImage(PLUTO_BMP_FILENAME, PlutoTextureName, false);
	return;
}

//Function that draws all the planets
void drawAllPlanets(){
	drawGenericPlanet(MERCURY_INCLINATION, MERCURY_ORBIT_DUR, MERCURY_ORBIT_RADIUS,
			MERCURY_ROTATION_DUR, MercuryTextureName, MERCURY_RADIUS);
	drawGenericPlanet(VENUS_INCLINATION, VENUS_ORBIT_DUR, VENUS_ORBIT_RADIUS,
			VENUS_ROTATION_DUR, VenusTextureName, VENUS_RADIUS);
	drawGenericPlanet(EARTH_INCLINATION,EARTH_ORBIT_DUR,EARTH_ORBIT_RADIUS,EARTH_ROTATION_DUR,EarthTextureName,EARTH_RADIUS);
	drawGenericPlanet(MARS_INCLINATION, MARS_ORBIT_DUR, MARS_ORBIT_RADIUS,
			MARS_ROTATION_DUR, MarsTextureName, MARS_RADIUS);
	drawGenericPlanet(JUPITER_INCLINATION, JUPITER_ORBIT_DUR, JUPITER_ORBIT_RADIUS,
			JUPITER_ROTATION_DUR, JupiterTextureName, JUPITER_RADIUS);
	drawGenericPlanet(SATURN_INCLINATION, SATURN_ORBIT_DUR, SATURN_ORBIT_RADIUS,
			SATURN_ROTATION_DUR, SaturnTextureName, SATURN_RADIUS);
	drawGenericPlanet(URANUS_INCLINATION, URANUS_ORBIT_DUR, URANUS_ORBIT_RADIUS,
			URANUS_ROTATION_DUR, UranusTextureName, URANUS_RADIUS);
	drawGenericPlanet(NEPTUNE_INCLINATION, NEPTUNE_ORBIT_DUR, NEPTUNE_ORBIT_RADIUS,
			NEPTUNE_ROTATION_DUR, NeptuneTextureName, NEPTUNE_RADIUS);
	drawGenericPlanet(PLUTO_INCLINATION, PLUTO_ORBIT_DUR, PLUTO_ORBIT_RADIUS,
			PLUTO_ROTATION_DUR, PlutoTextureName, PLUTO_RADIUS);

}
// Convert the bitmap into an OpenGL texture
void MakeImage(const char bitmapFilename[], GLuint &textureName, bool hasAlpha)
{
	RGBpixmap pix;
	pix.readBMPFile(bitmapFilename, hasAlpha);
	pix.setTexture(textureName);
	return;
}
// Set the two lights to illuminate the scene
//Gllightfv()
void SetLights()
{
	glLightfv(GL_LIGHT0, GL_AMBIENT,  LIGHT_AMBIENT);
	glLightfv(GL_LIGHT0, GL_DIFFUSE,  LIGHT_DIFFUSE);
	glLightfv(GL_LIGHT0, GL_SPECULAR, LIGHT_SPECULAR);
	glLightfv(GL_LIGHT0, GL_POSITION, LIGHT_0_POSITION);

	glLightfv(GL_LIGHT1, GL_AMBIENT,  LIGHT_AMBIENT);
	glLightfv(GL_LIGHT1, GL_DIFFUSE,  LIGHT_DIFFUSE);
	glLightfv(GL_LIGHT1, GL_SPECULAR, LIGHT_SPECULAR);
	glLightfv(GL_LIGHT1, GL_POSITION, LIGHT_1_POSITION);
	
	glLightfv(GL_LIGHT2, GL_AMBIENT,  LIGHT_AMBIENT);
	glLightfv(GL_LIGHT2, GL_DIFFUSE,  LIGHT_DIFFUSE);
	glLightfv(GL_LIGHT2, GL_SPECULAR, LIGHT_SPECULAR);
	glLightfv(GL_LIGHT2, GL_POSITION, LIGHT_2_POSITION);

	glLightfv(GL_LIGHT3, GL_AMBIENT,  LIGHT_AMBIENT);
	glLightfv(GL_LIGHT3, GL_DIFFUSE,  LIGHT_DIFFUSE);
	glLightfv(GL_LIGHT3, GL_SPECULAR, LIGHT_SPECULAR);
	glLightfv(GL_LIGHT3, GL_POSITION, LIGHT_3_POSITION);
}
// Enable the scene's lighting
void UpdateLight()
{
	glPushMatrix();
		glLightfv(GL_LIGHT0, GL_POSITION, LIGHT_0_POSITION);
		glLightfv(GL_LIGHT1, GL_POSITION, LIGHT_1_POSITION);
		glLightfv(GL_LIGHT2, GL_POSITION, LIGHT_2_POSITION);
		glLightfv(GL_LIGHT3, GL_POSITION, LIGHT_3_POSITION);
	glPopMatrix();
	
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
}
//Function to draw and texture map the sun at the origin
void drawSun()
{
	GLUquadricObj* quadro = gluNewQuadric();							
	gluQuadricNormals(quadro, GLU_SMOOTH);		
	gluQuadricTexture(quadro, GL_TRUE);			
	glEnable(GL_TEXTURE_2D);
		glPushMatrix();
			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
			glPushMatrix();
				glRotatef( -90.0, 1.0, 0.0, 0.0 );
				glBindTexture(GL_TEXTURE_2D, SunTextureName);
				gluSphere(quadro, SUN_RADIUS, 48, 48);
			glPopMatrix();
		glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	gluDeleteQuadric(quadro);
}
//Used to draw planets.
//GLrotatef(angle,vector x,y,z)
//glusphere(object,radius,)
void drawGenericPlanet(GLfloat inclination, GLfloat orbitDuration,
		GLfloat orbitRadius, GLfloat rotationDuration, GLuint texturename, GLfloat radius)
{	
	GLUquadricObj* quadro = gluNewQuadric();							
	gluQuadricNormals(quadro, GLU_SMOOTH);		
	gluQuadricTexture(quadro, GL_TRUE);			
	glEnable(GL_TEXTURE_2D);
		glPushMatrix();
			glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
			glPushMatrix();
				glRotatef( inclination, 0.0, 0.0, 1.0);
				glRotatef( 360.0 * (EarthDaysTranspired/orbitDuration), 0.0, 1.0, 0.0);
				glTranslatef(orbitRadius, 0.0, 0.0 );
				glRotatef( 360.0 * (CurrentEarthRotation/rotationDuration), 0.0, 1.0, 0.0 );
				glRotatef( -90.0, 1.0, 0.0, 0.0 );
				glBindTexture(GL_TEXTURE_2D, texturename);
				gluSphere(quadro, radius, 100, 100);
			glPopMatrix();
		glPopMatrix();
	glDisable(GL_TEXTURE_2D);
	gluDeleteQuadric(quadro);
}



