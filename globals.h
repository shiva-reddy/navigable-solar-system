
#ifndef SOLAR_SYSTEM_GLOBALS_H 

const GLfloat PI = 3.1415926535;
const GLfloat TO_RADIANS = PI/180.0;
// Window Position/Resizing Constants
const GLint INIT_WINDOW_POSITION[2] = { 150, 150 };
const GLfloat ASPECT_RATIO = 1.5;
// Lighting Constants

const GLfloat LIGHT_0_POSITION[]    = { 1.0, 0.0, 0.0, 0.0};
const GLfloat LIGHT_1_POSITION[]    = {-1.0,0.0, 0.0, 0.0};
const GLfloat LIGHT_2_POSITION[]    = { 0.0, 0.0, 0.0, 0.0};
const GLfloat LIGHT_3_POSITION[]    = { 0.0, 0.0, .0, 0.0};

const GLfloat LIGHT_AMBIENT[]       = { 0.8, 0.8, 0.8, 1.0};
const GLfloat LIGHT_DIFFUSE[]       = { 0.9, 0.9, 0.9, 1.0};
const GLfloat LIGHT_SPECULAR[]      = { 1.0, 1.0, 1.0, 1.0};
const GLfloat LIGHT_MODEL_AMBIENT[] = { 0.2, 0.2, 0.2, 1.0};
// Viewer Positioning Constants
const GLfloat MAXIMUM_VIEWER_DISTANCE    = 20;
const GLfloat MINIMUM_VIEWER_DISTANCE    = 2;
const GLfloat INITIAL_VIEWER_DISTANCE    = 10;
const GLfloat VIEWER_DISTANCE_INCREMENT  = 0.1;
const GLfloat INITIAL_VIEWER_AZIMUTH     = 0.0;
const GLfloat INITIAL_VIEWER_ZENITH      = PI / 2.0;
const GLfloat VIEWER_ANGLE_INCREMENT     = PI / 60.0;
const GLfloat LOOK_AT_POSITION[] = { 0.0, 0.0, 0.0 };
//Additional Planets Constants for bitmap files
const char SUN_BMP_FILENAME[]="images/sunmap.bmp";
const char MERCURY_BMP_FILENAME[] ="images/mercurymap.bmp";
const char VENUS_BMP_FILENAME[] = 	"images/venusmap.bmp";
const char EARTH_BMP_FILENAME[] = "images/earthmap.bmp";
const char MARS_BMP_FILENAME[] = 	"images/marsmap.bmp";
const char JUPITER_BMP_FILENAME[] = "images/jupitermap.bmp";
const char SATURN_BMP_FILENAME[] = "images/saturnmap.bmp";
const char URANUS_BMP_FILENAME[] = "images/uranusmap.bmp";
const char NEPTUNE_BMP_FILENAME[] = "images/neptunemap.bmp";
const char PLUTO_BMP_FILENAME[] = 	"images/plutomap.bmp";
//Additional Planets Constants for Planet Radiuses
const GLfloat MERCURY_RADIUS =0.1;
const GLfloat VENUS_RADIUS =0.18;
const GLfloat EARTH_RADIUS= 0.18;
const GLfloat MARS_RADIUS = 0.11;
const GLfloat JUPITER_RADIUS = 0.6;
const GLfloat SATURN_RADIUS = 0.5;
const GLfloat URANUS_RADIUS = 0.3;
const GLfloat NEPTUNE_RADIUS = 0.3;
const GLfloat PLUTO_RADIUS = 0.05;
const GLfloat SUN_RADIUS = 1.0;
//Additional Planets Constants for Orbit Radius
const GLfloat MERCURY_ORBIT_RADIUS = 1.5;
const GLfloat VENUS_ORBIT_RADIUS =	 2.0;
const GLfloat EARTH_ORBIT_RADIUS =  3.0;
const GLfloat MARS_ORBIT_RADIUS = 3.5;
const GLfloat JUPITER_ORBIT_RADIUS = 5.0;
const GLfloat SATURN_ORBIT_RADIUS =  7.0;
const GLfloat URANUS_ORBIT_RADIUS = 8.5;
const GLfloat NEPTUNE_ORBIT_RADIUS = 9.0;
const GLfloat PLUTO_ORBIT_RADIUS =  10.0;
//Additional Planets Constants for Orbit Duration
const GLfloat MERCURY_ORBIT_DUR = 88;
const GLfloat VENUS_ORBIT_DUR=225;
const GLfloat EARTH_ORBIT_DUR=365;
const GLfloat MARS_ORBIT_DUR= 686;
const GLfloat JUPITER_ORBIT_DUR=4333;
const GLfloat SATURN_ORBIT_DUR=10759;
const GLfloat URANUS_ORBIT_DUR=30685;
const GLfloat NEPTUNE_ORBIT_DUR= 60190;
const GLfloat PLUTO_ORBIT_DUR= 90800;
//Additional Planets Constants for Rotation Duration
const GLfloat MERCURY_ROTATION_DUR = 59;
const GLfloat VENUS_ROTATION_DUR=-243;
const GLfloat EARTH_ROTATION_DUR = 1.00;
const GLfloat MARS_ROTATION_DUR= 1;
const GLfloat JUPITER_ROTATION_DUR= 0.4;
const GLfloat SATURN_ROTATION_DUR= 0.4;
const GLfloat URANUS_ROTATION_DUR=-0.7;
const GLfloat NEPTUNE_ROTATION_DUR= 0.7;
const GLfloat PLUTO_ROTATION_DUR=-6;
//Additional Planets Constants for Inclination
const GLfloat MERCURY_INCLINATION = 7;
const GLfloat VENUS_INCLINATION   = 3;
const GLfloat MARS_INCLINATION    = 2;
const GLfloat JUPITER_INCLINATION = 1;
const GLfloat SATURN_INCLINATION  = 2;
const GLfloat URANUS_INCLINATION  = 1;
const GLfloat NEPTUNE_INCLINATION = 2;
const GLfloat PLUTO_INCLINATION   = 1;
const GLfloat EARTH_INCLINATION   = 7;

// Viewer positioning angles.
GLfloat phi = INITIAL_VIEWER_AZIMUTH;
GLfloat theta  = INITIAL_VIEWER_ZENITH;

// ID numbers for all texture maps.
GLuint EarthTextureName = 3;
GLuint MoonTextureName  = 4;
GLuint SunTextureName   = 0;
GLuint MercuryTextureName = 1;
GLuint VenusTextureName = 2;
GLuint MarsTextureName = 5;
GLuint JupiterTextureName = 6;
GLuint SaturnTextureName = 7;
GLuint UranusTextureName = 8;
GLuint NeptuneTextureName = 9;
GLuint PlutoTextureName = 10;

// Variables to keep track of current day status.
GLfloat CurrentEarthRotation = 0.00;
GLfloat EarthDaysTranspired  = 0.00;
GLfloat EarthDayIncrement    = 0.02;

GLint currWindowSize[2]   = { 750, 750/ASPECT_RATIO };
GLint currViewportSize[2] = { 750, 750/ASPECT_RATIO };

GLfloat ViewerDistance = INITIAL_VIEWER_DISTANCE;
#define SOLAR_SYSTEM_H
#endif
