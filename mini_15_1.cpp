#include<GL/freeglut.h>
#include<stdio.h>
#include<GL/glut.h>
#include <GL/gl.h>
#include <stdlib.h>
#include<windows.h>
#include<MMsystem.h>
#define SPEED 30.0

float i=0.0,m=0.0,n=0.0,o=0.0,c=0.0;    

int light=1,day=1,plane=0,comet=0,xm=900,train=0;      
char ch;

void declare(const char *string)
{
     while(*string)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *string++);
}

void draw_pixel(GLint cx, GLint cy)
{

	glBegin(GL_POINTS);
		glVertex2i(cx,cy);
	glEnd();
}

void plotpixels(GLint h,GLint k, GLint x,GLint y)
{
	draw_pixel(x+h,y+k);
	draw_pixel(-x+h,y+k);
	draw_pixel(x+h,-y+k);
	draw_pixel(-x+h,-y+k);
	draw_pixel(y+h,x+k);
	draw_pixel(-y+h,x+k);
	draw_pixel(y+h,-x+k);
	draw_pixel(-y+h,-x+k);
}


void draw_circle(GLint h, GLint k, GLint r)
{
	GLint d=1-r, x=0, y=r;
	while(y>x)
	{
		plotpixels(h,k,x,y);
		if(d<0) d+=2*x+3;
		else
		{
			d+=2*(x-y)+5;
			--y;
		}
		++x;
	}
	plotpixels(h,k,x,y);
}


void draw_object()
{
int l;
if(day==1)
{
//sky
glColor3f(0.0,0.9,0.9);
glBegin(GL_POLYGON);
glVertex2f(0,380);
glVertex2f(0,700);
glVertex2f(1100,700);
glVertex2f(1100,380);
glEnd();

//sun


  for(l=0;l<=35;l++)
{
		glColor3f(1.0,0.9,0.0);
		
	
		
		   draw_circle(100,625,l);
}


//plane
if(plane==1)
{
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(925+n,625+o);
    glVertex2f(950+n,640+o);
	glVertex2f(1015+n,640+o);
	glVertex2f(1030+n,650+o);
	glVertex2f(1050+n,650+o);
	glVertex2f(1010+n,625+o);
glEnd();

	glColor3f(0.8,0.8,0.8);
	glBegin(GL_LINE_LOOP);
	glVertex2f(925+n,625+o);
    glVertex2f(950+n,640+o);
	glVertex2f(1015+n,640+o);
	glVertex2f(1030+n,650+o);
	glVertex2f(1050+n,650+o);
	glVertex2f(1010+n,625+o);
glEnd();

}

//cloud1


	for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(160+m,625,l);

	}


	for(l=0;l<=35;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(200+m,625,l);
		draw_circle(225+m,625,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(265+m,625,l);
	}

//cloud2


	for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(370+m,615,l);
}




	for(l=0;l<=35;l++)
	{

		glColor3f(1.0,1.0,1.0);
		draw_circle(410+m,615,l);
		draw_circle(435+m,615,l);
		draw_circle(470+m,615,l);
	}

for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(500+m,615,l);
}






//grass
glColor3f(0.0,0.9,0.0);
glBegin(GL_POLYGON);
glVertex2f(0,160);
glVertex2f(0,380);
glVertex2f(1100,380);
glVertex2f(1100,160);
glEnd();

}


else
{

//sky
glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(0,380);
glVertex2f(0,700);
glVertex2f(1100,700);
glVertex2f(1100,380);
glEnd();

//moon
int l;

	for(l=0;l<=35;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(100,625,l);
	}


//comet
if(comet==1)
{
	for(l=0;l<=7;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(300+c,675,l);
	}

glColor3f(1.0,1.0,1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(200+c,675);
	glVertex2f(300+c,682);
	glVertex2f(300+c,668);
	glEnd();
}

//Plane
if(plane==1)
{

	for(l=0;l<=1;l++)
	{
		glColor3f(1.0,0.0,0.0);
		draw_circle(950+n,625+o,l);
		glColor3f(1.0,1.0,0.0);
		draw_circle(954+n,623+o,l);

	}



}

//grass
glColor3f(0.0,0.3,0.0);
glBegin(GL_POLYGON);
glVertex2f(0,160);
glVertex2f(0,380);
glVertex2f(1100,380);
glVertex2f(1100,160);
glEnd();

}


//track boundary
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(0,150);
glVertex2f(0,160);
glVertex2f(1100,160);
glVertex2f(1100,150);
glEnd();

//platform

glColor3f(0.560784,0.560784,0.737255);
glBegin(GL_POLYGON);
glVertex2f(0,160);
glVertex2f(0,250);
glVertex2f(1100,250);
glVertex2f(1100,160);
glEnd();

//table 1


//below track 
glColor3f(0.623529,0.623529,0.372549);
glBegin(GL_POLYGON);
glVertex2f(0,0);
glVertex2f(0,150);
glVertex2f(1100,150);
glVertex2f(1100,0);
glEnd();

//Railway track

glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(-100,0);
glVertex2f(-100,20);
glVertex2f(1100,20);
glVertex2f(1100,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(-100,80);
glVertex2f(-100,100);
glVertex2f(1100,100);
glVertex2f(1100,80);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(0,0);
glVertex2f(0,80);
glVertex2f(10,80);
glVertex2f(10,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(80,0);
glVertex2f(80,80);
glVertex2f(90,80);
glVertex2f(90,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(150,0);
glVertex2f(150,80);
glVertex2f(160,80);
glVertex2f(160,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(220,0);
glVertex2f(220,80);
glVertex2f(230,80);
glVertex2f(230,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(290,0);
glVertex2f(290,80);
glVertex2f(300,80);
glVertex2f(300,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(360,0);
glVertex2f(360,80);
glVertex2f(370,80);
glVertex2f(370,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(430,0);
glVertex2f(430,80);
glVertex2f(440,80);
glVertex2f(440,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(500,0);
glVertex2f(500,80);
glVertex2f(510,80);
glVertex2f(510,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(570,0);
glVertex2f(570,80);
glVertex2f(580,80);
glVertex2f(580,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(640,0);
glVertex2f(640,80);
glVertex2f(650,80);
glVertex2f(650,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(710,0);
glVertex2f(710,80);
glVertex2f(720,80);
glVertex2f(720,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(770,0);
glVertex2f(770,80);
glVertex2f(780,80);
glVertex2f(780,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(840,0);
glVertex2f(840,80);
glVertex2f(850,80);
glVertex2f(850,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(900,0);
glVertex2f(900,80);
glVertex2f(910,80);
glVertex2f(910,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(970,0);
glVertex2f(970,80);
glVertex2f(980,80);
glVertex2f(980,0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(1040,0);
glVertex2f(1040,80);
glVertex2f(1050,80);
glVertex2f(1050,0);
glEnd();

//track boundary

//railway station boundary (fence)
glColor3f(0.647059,0.164706,0.164706);
glBegin(GL_POLYGON);
glVertex2f(0,250);
glVertex2f(0,310);
glVertex2f(5,320);
glVertex2f(10,310);
glVertex2f(10,250);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(90,250);
glVertex2f(90,310);
glVertex2f(95,320);
glVertex2f(100,310);
glVertex2f(100,250);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(140,250);
glVertex2f(140,310);
glVertex2f(145,320);
glVertex2f(150,310);
glVertex2f(150,250);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(190,250);
glVertex2f(190,310);
glVertex2f(195,320);
glVertex2f(200,310);
glVertex2f(200,250);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(240,250);
glVertex2f(240,310);
glVertex2f(245,320);
glVertex2f(250,310);
glVertex2f(250,250);
glEnd();

//////
glBegin(GL_POLYGON);
glVertex2f(290,250);
glVertex2f(290,310);
glVertex2f(295,320);
glVertex2f(300,310);
glVertex2f(300,250);
glEnd();


/////




glBegin(GL_POLYGON);
glVertex2f(340,250);
glVertex2f(340,310);
glVertex2f(345,320);
glVertex2f(350,310);
glVertex2f(350,250);
glEnd();


glBegin(GL_POLYGON);
glVertex2f(390,250);
glVertex2f(390,310);
glVertex2f(395,320);
glVertex2f(400,310);
glVertex2f(400,250);
glEnd();

////
glBegin(GL_POLYGON);
glVertex2f(440,250);
glVertex2f(440,310);
glVertex2f(445,320);
glVertex2f(450,310);
glVertex2f(450,250);
glEnd();


glBegin(GL_POLYGON);
glVertex2f(490,250);
glVertex2f(490,310);
glVertex2f(495,320);
glVertex2f(500,310);
glVertex2f(500,250);
glEnd();



glBegin(GL_POLYGON);
glVertex2f(540,250);
glVertex2f(540,310);
glVertex2f(545,320);
glVertex2f(550,310);
glVertex2f(550,250);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(580,250);
glVertex2f(580,310);
glVertex2f(585,320);
glVertex2f(590,310);
glVertex2f(590,250);
glEnd();


glBegin(GL_POLYGON);
glVertex2f(620,250);
glVertex2f(620,310);
glVertex2f(625,320);
glVertex2f(630,310);
glVertex2f(630,250);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(660,250);
glVertex2f(660,310);
glVertex2f(665,320);
glVertex2f(670,310);
glVertex2f(670,250);
glEnd();


glBegin(GL_POLYGON);
glVertex2f(710,250);
glVertex2f(710,310);
glVertex2f(715,320);
glVertex2f(720,310);
glVertex2f(720,250);
glEnd();
glBegin(GL_POLYGON);
glVertex2f(760,250);
glVertex2f(760,310);
glVertex2f(765,320);
glVertex2f(770,310);
glVertex2f(770,250);
glEnd();
glBegin(GL_POLYGON);
glVertex2f(810,250);
glVertex2f(810,310);
glVertex2f(815,320);
glVertex2f(820,310);
glVertex2f(820,250);
glEnd();
glBegin(GL_POLYGON);
glVertex2f(860,250);
glVertex2f(860,310);
glVertex2f(865,320);
glVertex2f(870,310);
glVertex2f(870,250);
glEnd();


glBegin(GL_POLYGON);
glVertex2f(910,250);
glVertex2f(910,310);
glVertex2f(915,320);
glVertex2f(920,310);
glVertex2f(920,250);
glEnd();





////

glBegin(GL_POLYGON);
glVertex2f(950,250);
glVertex2f(950,310);
glVertex2f(955,320);
glVertex2f(960,310);
glVertex2f(960,250);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(1000,250);
glVertex2f(1000,310);
glVertex2f(1005,320);
glVertex2f(1010,310);
glVertex2f(1010,250);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(1050,250);
glVertex2f(1050,310);
glVertex2f(1055,320);
glVertex2f(1060,310);
glVertex2f(1060,250);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(0,295);
glVertex2f(0,305);
glVertex2f(1100,305);
glVertex2f(1100,295);
glEnd();


//lower
glBegin(GL_POLYGON);
glVertex2f(0,265);
glVertex2f(0,275);
glVertex2f(1100,275);
glVertex2f(1100,265);
glEnd();


glBegin(GL_POLYGON);
glVertex2f(0,295);
glVertex2f(0,305);
glVertex2f(400,305);
glVertex2f(400,295);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(0,265);
glVertex2f(0,275);
glVertex2f(400,275);
glVertex2f(400,265);
glEnd();


//tree 1
glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(50,185);
glVertex2f(50,255);
glVertex2f(65,255);
glVertex2f(65,185);
glEnd();


	for(l=0;l<=30;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(40,250,l);
		draw_circle(80,250,l);
	}

	for(l=0;l<=25;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(50,290,l);
		draw_circle(70,290,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(60,315,l);
	}


//tree 5
glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(600,185);
glVertex2f(600,255);
glVertex2f(615,255);
glVertex2f(615,185);
glEnd();


	for(l=0;l<=30;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(590,250,l);
		draw_circle(630,250,l);
	}

	for(l=0;l<=25;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(600,290,l);
		draw_circle(620,290,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(610,315,l);
	}



//signal
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(1060,160);
		glVertex2f(1060,350);
		glVertex2f(1070,350);
		glVertex2f(1070,160);
	glEnd();


	glColor3f(0.7,0.7,0.7);
	glBegin(GL_POLYGON);
		glVertex2f(1040,350);
		glVertex2f(1040,500);
		glVertex2f(1090,500);
		glVertex2f(1090,350);
	glEnd();

	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.0,0.0);
		draw_circle(1065,475,l);
		glColor3f(1.0,1.0,0.0);
		draw_circle(1065,425,l);
		glColor3f(0.0,0.0,0.0);
		draw_circle(1065,375,l);
	}
if(train==1)
{
//train carrier 3

glColor3f(0.258824,0.435294,0.258824);
glBegin(GL_POLYGON);
glVertex2f(-600+i-xm,50); 
glVertex2f(-600+i-xm,300);
glVertex2f(-1000+i-xm,300);
glVertex2f(-1000+i-xm,50);
glEnd();

//top

glColor3f(0.1f, 0.0f, 0.0f);
glBegin(GL_POLYGON);
glVertex2f(-590+i-xm,300); 
glVertex2f(-590+i-xm,310);
glVertex2f(-1010+i-xm,310);
glVertex2f(-1010+i-xm,300);
glEnd();

// Windows

glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(-825+i-xm,175); 
glVertex2f(-825+i-xm,285);
glVertex2f(-985+i-xm,285);
glVertex2f(-985+i-xm,175);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(-615+i-xm,175); 
glVertex2f(-615+i-xm,285);
glVertex2f(-775+i-xm,285);
glVertex2f(-775+i-xm,175);
glEnd();

// carrier 3 Wheels

for(l=0;l<50;l++)
   {
	glColor3f(0.35,0.16,0.14);
	draw_circle(-675+i-xm,50,l);
	draw_circle(-925+i-xm,50,l);
   }

//train carrier 2

glColor3f(0.258824,0.435294,0.258824);
glBegin(GL_POLYGON);
glVertex2f(-150+i-xm,50); 
glVertex2f(-150+i-xm,300);
glVertex2f(-550+i-xm,300);
glVertex2f(-550+i-xm,50);
glEnd();

//top

glColor3f(0.1f, 0.0f, 0.0f);
glBegin(GL_POLYGON);
glVertex2f(-140+i-xm,300); 
glVertex2f(-140+i-xm,310);
glVertex2f(-560+i-xm,310);
glVertex2f(-560+i-xm,300);
glEnd();

// Windows

glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(-375+i-xm,175); 
glVertex2f(-375+i-xm,285);
glVertex2f(-535+i-xm,285);
glVertex2f(-535+i-xm,175);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(-165+i-xm,175); 
glVertex2f(-165+i-xm,285);
glVertex2f(-325+i-xm,285);
glVertex2f(-325+i-xm,175);
glEnd();

//connecter

glColor3f(0.309804,0.184314,0.184314);
glBegin(GL_POLYGON);
glVertex2f(-550+i-xm,75); 
glVertex2f(-550+i-xm,95);
glVertex2f(-600+i-xm,95);
glVertex2f(-600+i-xm,75);
glEnd();

// carrier 2 Wheels

for(l=0;l<50;l++)
   {
	glColor3f(0.35,0.16,0.14);
	draw_circle(-225+i-xm,50,l);
	draw_circle(-475+i-xm,50,l);
   }

// train carrier 1


glColor3f(0.258824,0.435294,0.258824);
glBegin(GL_POLYGON);
glVertex2f(300+i-xm,50); 
glVertex2f(300+i-xm,300);
glVertex2f(-100+i-xm,300);
glVertex2f(-100+i-xm,50);
glEnd();

//top

glColor3f(0.1f, 0.0f, 0.0f);
glBegin(GL_POLYGON);
glVertex2f(310+i-xm,300); 
glVertex2f(310+i-xm,310);
glVertex2f(-110+i-xm,310);
glVertex2f(-110+i-xm,300);
glEnd();

// Windows

glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(75+i-xm,175); 
glVertex2f(75+i-xm,285);
glVertex2f(-85+i-xm,285);
glVertex2f(-85+i-xm,175);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(285+i-xm,175); 
glVertex2f(285+i-xm,285);
glVertex2f(125+i-xm,285);
glVertex2f(125+i-xm,175);
glEnd();

//connecter

glColor3f(0.309804,0.184314,0.184314);
glBegin(GL_POLYGON);
glVertex2f(-100+i-xm,75); 
glVertex2f(-100+i-xm,95);
glVertex2f(-150+i-xm,95);
glVertex2f(-150+i-xm,75);
glEnd();

// carrier 1 Wheels

for(l=0;l<50;l++)
   {
	glColor3f(0.35,0.16,0.14);
	draw_circle(-25+i-xm,50,l);
	draw_circle(225+i-xm,50,l);
   }

//train base

glColor3f(0.196078,0.6,0.8);
glBegin(GL_POLYGON);
glVertex2f(350+i-xm,50); 
glVertex2f(350+i-xm,125);
glVertex2f(755+i-xm,125);
glVertex2f(820+i-xm,50);
glEnd();

//train control chamber

glColor3f(1.0,0.25,0.0);
glBegin(GL_POLYGON);
glVertex2f(360+i-xm,125); 
glVertex2f(360+i-xm,325);
glVertex2f(560+i-xm,325);
glVertex2f(560+i-xm,125);
glEnd();

//window

glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(375+i-xm,175); 
glVertex2f(375+i-xm,315);
glVertex2f(545+i-xm,315);
glVertex2f(545+i-xm,175);
glEnd();

//train top

glColor3f(0.1f, 0.0f, 0.0f);
glBegin(GL_POLYGON);
glVertex2f(350+i-xm,325); 
glVertex2f(350+i-xm,350);
glVertex2f(570+i-xm,350);
glVertex2f(570+i-xm,325);
glEnd();

//tain engine
glColor3f(1.0,0.5,0.0);
glBegin(GL_POLYGON);
glVertex2f(560+i-xm,125); 
glVertex2f(560+i-xm,225);
glVertex2f(755+i-xm,225);
glVertex2f(755+i-xm,125);
glEnd();

glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(580+i-xm,125); 
glVertex2f(580+i-xm,225);
glVertex2f(590+i-xm,225);
glVertex2f(590+i-xm,125);
glEnd();

glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(600+i-xm,125); 
glVertex2f(600+i-xm,225);
glVertex2f(610+i-xm,225);
glVertex2f(610+i-xm,125);
glEnd();

glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(735+i-xm,125); 
glVertex2f(735+i-xm,225);
glVertex2f(745+i-xm,225);
glVertex2f(745+i-xm,125);
glEnd();

//tain smoke

glColor3f(0.196078,0.6,0.9);
glBegin(GL_POLYGON);
glVertex2f(650+i-xm,225); 
glVertex2f(650+i-xm,275);
glVertex2f(700+i-xm,275);
glVertex2f(700+i-xm,225);
glEnd();

glColor3f(0.309804,0.184314,0.184314);
glBegin(GL_POLYGON);
glVertex2f(640+i-xm,275); 
glVertex2f(640+i-xm,300);
glVertex2f(710+i-xm,300);
glVertex2f(710+i-xm,275);
glEnd();

//train head-light

glColor3f(1.0,1.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(755+i-xm,225); 
glVertex2f(765+i-xm,225);
glVertex2f(765+i-xm,185);
glVertex2f(755+i-xm,185);
glEnd();

glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(755+i-xm,225); 
glVertex2f(785+i-xm,225);
glVertex2f(755+i-xm,205);

glEnd();

// train connector

glColor3f(0.309804,0.184314,0.184314);
glBegin(GL_POLYGON);
glVertex2f(350+i-xm,75); 
glVertex2f(350+i-xm,95);
glVertex2f(300+i-xm,95);
glVertex2f(300+i-xm,75);
glEnd();

//train wheels

for(l=0;l<50;l++)
   {
	glColor3f(0.35,0.16,0.14);
	draw_circle(425+i-xm,50,l);
	draw_circle(700+i-xm,50,l);
   }
}
   //Railway Station Board

glFlush();
}



void traffic_light()
{
	int l;
if(light==1)
	  {
for(l=0;l<=20;l++)
		{

glColor3f(0.0,0.0,0.0);
		draw_circle(1065,475,l);

		glColor3f(0.0,0.7,0.0);
		draw_circle(1065,375,l);
		}
	  }

	else
	  {

for(l=0;l<=20;l++)
		{
		glColor3f(1.0,0.0,0.0);
		draw_circle(1065,475,l);

		glColor3f(0.0,0.0,0.0);
		draw_circle(1065,375,l);
		}
	  }
}


void idle()
{
glClearColor(1.0,1.0,1.0,1.0);

if(light==0 && (i>=0 && i<=1150)) 
 {

	 i+=SPEED/10;
     m+=SPEED/150;
	n-=2;
	 o+=0.2;
	c+=2;

 }
 
 if(light==0 && (i>=2600 && i<=3000)) 
 {

	 i+=SPEED/10;
	 m+=SPEED/150;
	n-=2;
	 o+=0.2;
	c+=2;

 }

if(light==0)
 {
	 i=i;
	 m+=SPEED/150;
	n-=2;
	 o+=0.2;
	c+=2;

 }

else
 {

     i+=SPEED/10;
     m+=SPEED/150;
	n-=2;
	 o+=0.2;
	c+=2;
 }
if(i>3500)
	 i=0.0;
if(m>1100)
	 m=0.0;
if( o>75)
 {
	plane=0;
 }
if(c>500)
 {
	comet=0;
 }
glutPostRedisplay();

}

void mouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_UP)
exit(0);
}


void keyboardFunc( unsigned char key, int x, int y )
{
switch( key )
    {
case 'g':
case 'G':
light=1;
break;

	case 'r':
	case 'R':
		light=0;
		break;

case 'd':
	case 'D':
		day=1;
		break;

	case 'n':
case 'N':
		day=0;
		break;
		
	case 't':
case 'T':
		train=1;
		i=0;
	//	PlaySound(TEXT("HP.wav"),NULL,SND_SYNC);
	PlaySound(TEXT("hps.wav"),NULL,SND_FILENAME | SND_ASYNC);
//	sndPlaySound("TRAIN.wav",SND_ASYNC);
		break;

    };

}


void main_menu(int index)
{
	switch(index)
	{
	case 1:
	if(index==1)
	 {
	plane=1;
		 o=n=0.0;
	 }
	break;

	case 2:
	if(index==2)
	 {
		comet=1;
		 c=0.0;
	 }
	break;
	}
}



void myinit()
{
glClearColor(1.0,1.0,1.0,1.0);
glColor3f(0.0,0.0,1.0);
glPointSize(2.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,1100.0,0.0,700.0);
}



void display()
{

glClear(GL_COLOR_BUFFER_BIT);
draw_object();
traffic_light();
glFlush();
}


int main(int argc,char** argv)
{
int c_menu;

    printf("--------------------------------------------------------------------------------");
    printf("                    ARRIVAL AND DEPARTURE OF TRAIN                              ");
    printf("--------------------------------------------------------------------------------");
	printf("Press 'r' or 'R' to change the signal light to red. \n\n");
	printf("Press 'g' or 'G' to change the signal light to green. \n\n");
    printf("Press 'd' or 'D' to make it day. \n\n");
	printf("Press 'n' or 'N' to make it night. \n\n");
	printf("Press 't' or 'T' Train arrive at station.\n\n");
	printf("Press RIGHT MOUSE BUTTON to display menu. \n\n");
	printf("Press LEFT MOUSE BUTTON to quit the program. \n\n\n");
	printf("Press any key and Hit ENTER.\n");
	scanf("%s",&ch);

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1100.0,700.0);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Train to Hogwarts");
	glutDisplayFunc(display);
    glutIdleFunc(idle);
	glutKeyboardFunc(keyboardFunc);
	glutMouseFunc(mouse);
	myinit();
	c_menu=glutCreateMenu(main_menu);
	glutAddMenuEntry("Aeroplane",1);
	glutAddMenuEntry("Comet",2);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}



