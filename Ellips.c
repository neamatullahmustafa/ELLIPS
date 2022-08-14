#include <windows.h>
 #include <gl/gl.h>
 #include <gl/glu.h>
 #include <GL/glut.h>
 #include <stdio.h>
 #include <math.h>
 int rx, ry;//maximum & minimum
 int xCenter, yCenter;//center of ellipse
 void myinit(void)
 {
	 glClearColor(1.0, 1.0, 1.0, 0);
	 glColor3f(0.0, 0.0, 0.0);
	 gluOrtho2D(-500, 500, -500, 500);
	 }
 void setPixel(GLint x, GLint y)
 {
	 glBegin(GL_POINTS);
	 glVertex2i(x, y);
	 glEnd();
	 }

 void ellipseMidPoint()
 {
	 //----------------------Region-1------------------------//
		 float x = 0;
        float y = ry;
	 //(0,ry) ---
	   float p1 = ry * ry - (rx * rx) * ry + (rx * rx) * (0.25);
	 //slope
		 float dx = 2 * (ry * ry) * x;
	 float dy = 2 * (rx * rx) * y;
	 while (dx < dy)
		 {
	 //plot (x,y)
			 setPixel(xCenter + x, yCenter + y);
		 setPixel(xCenter - x, yCenter + y);
		 setPixel(xCenter + x, yCenter - y);
		 setPixel(xCenter - x, yCenter - y);
		 if (p1 < 0)
			 {
			 x = x + 1;
			 dx = 2 * (ry * ry) * x;
			 p1 = p1 + dx + (ry * ry);
		 }
		else
			 {
			 x = x + 1;
			 y = y - 1;
			 dx = 2 * (ry * ry) * x;
			 dy = 2 * (rx * rx) * y;
			 p1 = p1 + dx - dy + (ry * ry);
			 }
		}
	//----------------------Region-2------------------------//
		 float p2 = (ry * ry) * (x + 0.5) * (x + 0.5) + (rx * rx) * (y - 1) * (y -
			1) - (rx * rx) * (ry * ry);
	
		
		 while (y > 0)
		 {
		 //plot (x,y)
			 setPixel(xCenter + x, yCenter + y);
		 setPixel(xCenter - x, yCenter + y);
		 setPixel(xCenter + x, yCenter - y);
		 setPixel(xCenter - x, yCenter - y);
		 if (p2 > 0)
			 {
			 x = x;
			 y = y - 1;
			 dy = 2 * (rx * rx) * y;
			 p2 = p2 - dy + (rx * rx);
			 }
		 else
			 {
			 x = x + 1;
			 y = y - 1;
			 dx = 2 * (ry * ry) * x;
			 dy = 2 * (rx * rx) * y;
			 p2 = p2 + dx - dy + (rx * rx);
			
				 }
		 }
	
		 }
 void display()
 {
	 glClear(GL_COLOR_BUFFER_BIT); // clear the screen
	 glColor3f(1.0, 0.0, 0.0); // red foreground
	 glPointSize(2.0); // size of points to be drawin (in pixel)
	
		 //establish a coordinate system for the image
		
		 ellipseMidPoint();
	 glFlush(); // send all output to the display
	 }

 int main(int argc, char** argv)
 {
	 printf("\n\nEnter Center Of Ellipse \n\n");
	 printf("\n x = ");
	 scanf("%d", &xCenter);
	
		 printf("\n y = ");
	 scanf("%d", &yCenter);
	
		 printf(" Enter a rx : ");
	 scanf("%d", &rx);
	 printf(" \nEnter a yx : ");
	 scanf("%d", &ry);
	 glutInit(&argc, argv);
	 glutInitWindowSize(1000, 1000); // set the size of the window
	 glutInitWindowPosition(0, 0); // the position of the top-left of window
	 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	 glutCreateWindow("Midpoint Ellipse Drawing Algorithm");
	 myinit();
	 glutDisplayFunc(display); // set the gl display callback function
	 glutMainLoop(); // enter the GL event loop
	
		 }