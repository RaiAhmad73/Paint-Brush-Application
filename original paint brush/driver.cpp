#include "GP142.h"
#include <stdio.h>
#include <math.h>
#include<cmath>
#define PI 3.1415926535
#define ANIMATE_MSG "Select \"Animate\"\nOn the \"Run\" Menu"
#define TEXT_SIZE 20
struct points
	{
		double x;
		double y;
	};
class shapes{
private:

public:
	void draw_line(int x1, int y1, int x2, int y2, int color=RED, int width=1)
	{
	GP142_lineXY (color,x1,y1,x2,y2,width);
	}
	void draw_circle(int x, int y, int radius, int color=WHITE)
	{
	 GP142_circleXY(color, x, y, radius);
    }
	virtual void draw(int )=0; 
};
class circle:public shapes{

	public:

	void draw(int color)
	{
		int radius=0;
		int quit = 0;           
		int mouse_x, mouse_y;
		char key_pressed;

		int pcount=0;
		points arr[1000];
		while (!quit) 
		{

			switch (GP142_await_event(&mouse_x, &mouse_y, &key_pressed)) 
			{
			case GP142_QUIT:
				quit = 1;   
				break;

			case GP142_MOUSE:

				arr[pcount].x=mouse_x;
				arr[pcount].y=mouse_y;
				pcount++;

				if(pcount==2)
				{
					radius=sqrt(pow(arr[0].x-arr[1].x,2)+pow(arr[0].y-arr[1].y,2));
					GP142_circleXY(color, arr[0].x,arr[0].y , radius);
	                GP142_circleXY(BLACK, arr[0].x, arr[0].y, radius-1);

					//draw_circle(arr[0].x,arr[0].x,radius,color);
					//draw_circle(arr[0].x,arr[0].y,radius-1,BLACK);
					return;
				}
				break;
			}
		}
	}


};
class openshape:public shapes{};
class line:public openshape{
public:
	 
	void draw(int color)
	{
		int quit = 0;           
		int mouse_x, mouse_y;
		char key_pressed;

		int pcount=0;
		points arr[1000];
		while (!quit) 
		{

			switch (GP142_await_event(&mouse_x, &mouse_y, &key_pressed)) 
			{
			case GP142_QUIT:
				quit = 1;   
				break;

			case GP142_MOUSE:

				arr[pcount].x=mouse_x;
				arr[pcount].y=mouse_y;
				pcount++;

				if(pcount==2)
				{
					pcount=0;
					draw_line(arr[0].x,arr[0].y,arr[1].x,arr[1].y,color);
					return;
				}
				break;
			}
		}
	}
};
class curve :public shapes{
	public:
		//03238400638 syed kashif
	void draw(int color)
	{
		int quit = 0;           
		int mouse_x, mouse_y;
		char key_pressed;

		int pcount=0;
		points arr[1000];
		while (!quit) 
		{

			switch (GP142_await_event(&mouse_x, &mouse_y, &key_pressed)) 
			{
			case GP142_QUIT:
				quit = 1;   
				break;

			case GP142_MOUSE:

				arr[pcount].x=mouse_x;
				arr[pcount].y=mouse_y;
				pcount++;
			case GP142_KBD:
				if(key_pressed=='a' )
				{
					
					for(int i=0,j=1;i<pcount;i++,j++)
					{
						draw_line(arr[i].x,arr[i].y,arr[j].x,arr[j].y,color);

					}
					//draw_line(arr[pcount-1].x,arr[pcount-1].y,arr[0].x,arr[0].y,color);
					return;
				}
				break;
			}
		}
	}
};
class polygon:public shapes{
public:
	void draw(int color)
	{
		int quit = 0;           
		int mouse_x, mouse_y;
		char key_pressed;

		int pcount=0;
		points arr[1000];
		while (!quit) 
		{

			switch (GP142_await_event(&mouse_x, &mouse_y, &key_pressed)) 
			{
			case GP142_QUIT:
				quit = 1;   
				break;

			case GP142_MOUSE:

				arr[pcount].x=mouse_x;
				arr[pcount].y=mouse_y;
				pcount++;
			case GP142_KBD:
				if(key_pressed=='a')
				{
					
					for(int i=0,j=1;i<pcount;i++,j++)
					{
						draw_line(arr[i].x,arr[i].y,arr[j].x,arr[j].y,color);

					}
					draw_line(arr[pcount-1].x,arr[pcount-1].y,arr[0].x,arr[0].y,color);
					return;
				}
				break;
			}
		}
	}
};
class triangle:public polygon{
public:
	void draw(int color)
	{
		{
		int quit = 0;           
		int mouse_x, mouse_y;
		char key_pressed;

		int pcount=0;
		points arr[1000];
		while (!quit) 
		{

			switch (GP142_await_event(&mouse_x, &mouse_y, &key_pressed)) 
			{
			case GP142_QUIT:
				quit = 1;   
				break;

			case GP142_MOUSE:

				arr[pcount].x=mouse_x;
				arr[pcount].y=mouse_y;
				pcount++;

				if(pcount==3)
				{
					pcount=0;
					draw_line(arr[0].x,arr[0].y,arr[1].x,arr[1].y,color);
					draw_line(arr[0].x,arr[0].y,arr[2].x,arr[2].y,color);
					draw_line(arr[1].x,arr[1].y,arr[2].x,arr[2].y,color);

					return;
				}
				break;
			}
		}
	}
	}
};
class rectangle:public polygon{
public:
	void draw(int color)
	{
		{
		int quit = 0;           
		int mouse_x, mouse_y;
		char key_pressed;

		int pcount=0;
		points arr[1000];
		while (!quit) 
		{

			switch (GP142_await_event(&mouse_x, &mouse_y, &key_pressed)) 
			{
			case GP142_QUIT:
				quit = 1;   
				break;

			case GP142_MOUSE:

				arr[pcount].x=mouse_x;
				arr[pcount].y=mouse_y;
				pcount++;

				if(pcount==2)
				{
					pcount=0;
					draw_line(arr[0].x,arr[0].y,arr[1].x,arr[0].y,color);
					draw_line(arr[1].x,arr[0].y,arr[1].x,arr[1].y,color);
					draw_line(arr[1].x,arr[1].y,arr[0].x,arr[1].y,color);
					draw_line(arr[0].x,arr[1].y,arr[0].x,arr[0].y,color);

					return;
				}
				break;
			}
		}
	}
	}

};
class quadrilateral:public polygon{
public:
	void draw(int color)
	{
		int quit = 0;           
		int mouse_x, mouse_y;
		char key_pressed;

		int pcount=0;
		points arr[1000];
		while (!quit) 
		{

			switch (GP142_await_event(&mouse_x, &mouse_y, &key_pressed)) 
			{
			case GP142_QUIT:
				quit = 1;   
				break;

			case GP142_MOUSE:

				arr[pcount].x=mouse_x;
				arr[pcount].y=mouse_y;
				pcount++;

				if(pcount==4)
				{
					pcount=0;
					draw_line(arr[0].x,arr[0].y,arr[1].x,arr[1].y,color);
					draw_line(arr[1].x,arr[1].y,arr[3].x,arr[3].y,color);
					draw_line(arr[3].x,arr[3].y,arr[2].x,arr[2].y,color);
					draw_line(arr[2].x,arr[2].y,arr[0].x,arr[0].y,color);

					return;
				}
				break;
			}
		}
	 

   }
};

void draw_circle(int x, int y, int radius, int color=WHITE){
	 GP142_circleXY(color, x, y, radius);
}

void demo_handle_mouse(int x, int y){
    GP142_printfXY(YELLOW,x,y,9,"Mouse at (%d,%d)", x, y);
}

void demo_handle_kbd(char c)
{
	GP142_printfXY(WHITE, 0, 0,   TEXT_SIZE, "%c", c);
}

void demo_handle_periodic(void){};
void draw_line(int x1, int y1, int x2, int y2, int color=RED, int width=1){
	GP142_lineXY (color,x1,y1,x2,y2,width);
}


int main(void)
{           
	shapes * allshapes[1000];
	allshapes[0]=new line;
	allshapes[1]=new triangle;
	allshapes[2]=new rectangle;
	allshapes[3]=new quadrilateral;
    allshapes[4]=new polygon;
	allshapes[5]=new curve;
	allshapes[6]=new circle;

    GP142_open(); 
	draw_line(400,400,400,-350);
	
	draw_line(400,308,1000,308);
	GP142_printfXY(RED,400,308,20,"%Delete");
	draw_line(400,280,1000,280);
	GP142_printfXY(PINK,400,280,18,"save");
	draw_line(400,252,1000,252);
	GP142_printfXY(PURPLE,400,252,18,"load");
    draw_line(400,225,1000,225);
	GP142_printfXY(OLIVE,400,225,18,"%Draw line");
	draw_line(400,196,1000,196);
	GP142_printfXY(OLIVE,400,196,18,"%Draw circle");
	draw_line(400,168,1000,168);
	GP142_printfXY(OLIVE,400,168,18,"%Triangle");
	draw_line(400,140,1000,140);
	GP142_printfXY(OLIVE,400,140,18,"%Rectangle");
	draw_line(400,112,1000,112);
	GP142_printfXY(OLIVE,400,112,15,"%Quadrilateral");
	draw_line(400,84,1000,84);
	GP142_printfXY(OLIVE,400,84,18,"%Polygon");
	draw_line(400,56,1000,56);
	GP142_printfXY(OLIVE,400,56,17,"%Draw Curve");
	draw_line(400,28,1000,28);
	GP142_printfXY(OLIVE,400,28,18,"%TEXT");
	draw_line(400,0,1000,0);
	GP142_printfXY(RED,400,0,18,"%RED");
	draw_line(400,-28,1000,-28);
	GP142_printfXY(GREEN,400,-28,14,"% KARO GREEN");
	draw_line(400,-56,1000,-56);
	GP142_printfXY(BLUE,400,-56,18,"%BLUE");
	draw_line(400,-84,1000,-84);
	GP142_printfXY(YELLOW,400,-84,18,"%YELLOW");
	draw_line(400,-112,1000,-112);
	GP142_printfXY(ORANGE,400,-112,18,"%ORANGE");
	draw_line(400,-140,1000,-140);
	GP142_printfXY(WHITE,400,-140,18,"WHITE");
	draw_line(400,-168,1000,-168);
	GP142_printfXY(OLIVE,400,-168,18,"%BLACK");
	draw_line(400,-192,1000,-192);
	GP142_printfXY(BROWN,400,-192,18,"%BUCKET");
	bool red_flag=false;
	bool green_flag=false;
	bool blue_flag=false;
	bool yellow_flag=false;
	bool orange_flag=false;
	bool white_flag=false;
	bool black_flag=false;

	 
	int quit = 0;           
	int mouse_x, mouse_y;
	char key_pressed;

	int pcount=0;
	
	points arr[1000];
	while (!quit) 
	{

		switch (GP142_await_event(&mouse_x, &mouse_y, &key_pressed)) 
		{
		case GP142_QUIT:
			quit = 1;   
			break;

		case GP142_MOUSE:

			arr[2*pcount].x=mouse_x;
			arr[2*pcount].y=mouse_y;
			if(arr[0].x<=1000 && arr[0].x>=400  && arr[0].y>=308 && arr[0].y<=430)
			{
				//delete
			}
			if(arr[0].x<=1000 && arr[0].x>=400  && arr[0].y>=280 && arr[0].y<=308)
			{
				//save
			}
			if(arr[0].x<=1000 && arr[0].x>=400  && arr[0].y>=252 && arr[0].y<=280)
			{
			//load

			}
			//if(arr[0].x<=1000 && arr[0].x>=400 && arr[0].y>= && arr[0].y<=)
			//{
			//	//bucket
			//}
			if(arr[0].x<=1000 && arr[0].x>=400  && arr[0].y>=225 && arr[0].y<=252)
			{
				//LINE
				GP142_await_event(&mouse_x, &mouse_y, &key_pressed); 
				if(mouse_x<=1000 && mouse_x>=400  && mouse_y>=56 && mouse_y<=84)
				{
					GP142_printfXY(RED,0,0,10,"%RED COLOR");
					red_flag=true;
					allshapes[0]->draw(2);
				}
				
				else if(mouse_x<=1000 && mouse_x>=400  && mouse_y>=-28 && mouse_y<=0)
				{
					GP142_printfXY(RED,0,0,10,"%GREEN COLOR");
					green_flag=true;
					allshapes[0]->draw(3);

				}
				else if(mouse_x<=1000 && mouse_x>=400  && mouse_y>=-56 && mouse_y<=-28)
				{
					GP142_printfXY(RED,0,0,10,"%BLUE COLOR");

					blue_flag=true;
					allshapes[0]->draw(4);

				}
				else if(mouse_x<=1000 && mouse_x>=400  && mouse_y>=-84 &&mouse_y<=-56)
				{
					GP142_printfXY(RED,0,0,10,"%YELLoW COLOR");

					yellow_flag=true;
					allshapes[0]->draw(5);

				}
				else if(mouse_x<=1000 && mouse_x>=400  && mouse_y>=-112 && mouse_y<=-84)
				{
					GP142_printfXY(RED,0,0,10,"%ORANGE COLOR");

					orange_flag=true;
					allshapes[0]->draw(13);

				}
				else if (mouse_x<=500 && mouse_x>=400  && mouse_y>=-140 && mouse_y<=-112)
				{
					GP142_printfXY(RED,0,0,10,"%White COLOR");

					white_flag=true;
					allshapes[0]->draw(1);

				}
				else if (mouse_x<=1000 && mouse_x>=400  && mouse_y>=-168 && mouse_y<=-140)
				{
					GP142_printfXY(RED,0,0,10,"%Black COLOR");

					black_flag=true;
					allshapes[0]->draw(0);

				}

			}
		
			if(arr[0].x<=1000 && arr[0].x>=400  && arr[0].y>=196 && arr[0].y<=225)
			{
				//circle
				//GP142_printfXY(RED,0,0,10,"%CIRCLE");
				GP142_await_event(&mouse_x, &mouse_y, &key_pressed); 
				if(mouse_x<=1000 && mouse_x>=400  && mouse_y>=56 && mouse_y<=84)
				{
					red_flag=true;
					allshapes[6]->draw(2);
				}
				else if(mouse_x<=1000 && mouse_x>=400  && mouse_y>=-28 && mouse_y<=0)
				{
					green_flag=true;
					allshapes[6]->draw(3);

				}
				else if(mouse_x<=1000 && mouse_x>=400  && mouse_y>=-56 && mouse_y<=-28)
				{
					blue_flag=true;
					allshapes[6]->draw(4);

				}
				else if(mouse_x<=1000 && mouse_x>=400  && mouse_y>=-84 &&mouse_y<=-56)
				{
					yellow_flag=true;
					allshapes[6]->draw(5);

				}
				else if(mouse_x<=1000 && mouse_x>=400  && mouse_y>=-112 && mouse_y<=-84)
				{
					orange_flag=true;
					allshapes[6]->draw(13);

				}
				else if (mouse_x<=500 && mouse_x>=400  && mouse_y>=-140 && mouse_y<=-112)
				{
					white_flag=true;
					allshapes[6]->draw(1);

				}
				else if (mouse_x<=1000 && mouse_x>=400  && mouse_y>=-168 && mouse_y<=-140)
				{
					black_flag=true;
					allshapes[6]->draw(0);

				}

			}
			if(arr[0].x<=1000 && arr[0].x>=400  && arr[0].y>=168 && arr[0].y<=196)
			{
				//triangle
				GP142_await_event(&mouse_x, &mouse_y, &key_pressed); 
				if(mouse_x<=1000 && mouse_x>=400  && mouse_y>=56 && mouse_y<=84)
				{
					red_flag=true;
					allshapes[1]->draw(2);
				}
				else if(mouse_x<=1000 && mouse_x>=400  && mouse_y>=-28 && mouse_y<=0)
				{
					green_flag=true;
					allshapes[1]->draw(3);

				}
				else if(mouse_x<=1000 && mouse_x>=400  && mouse_y>=-56 && mouse_y<=-28)
				{
					blue_flag=true;
					allshapes[1]->draw(4);

				}
				else if(mouse_x<=1000 && mouse_x>=400  && mouse_y>=-84 &&mouse_y<=-56)
				{
					yellow_flag=true;
					allshapes[1]->draw(5);

				}
				else if(mouse_x<=1000 && mouse_x>=400  && mouse_y>=-112 && mouse_y<=-84)
				{
					orange_flag=true;
					allshapes[1]->draw(13);

				}
				else if (mouse_x<=500 && mouse_x>=400  && mouse_y>=-140 && mouse_y<=-112)
				{
					white_flag=true;
					allshapes[1]->draw(1);

				}
				else if (mouse_x<=1000 && mouse_x>=400  && mouse_y>=-168 && mouse_y<=-140)
				{
					black_flag=true;
					allshapes[1]->draw(0);

				}
			}
			if(arr[0].x<=1000 && arr[0].x>=400  && arr[0].y>=140 && arr[0].y<=168)
			{
				GP142_printfXY(RED,0,0,10,"%RECTANGLE");
				GP142_await_event(&mouse_x, &mouse_y, &key_pressed); 
				if(mouse_x<=1000 && mouse_x>=400  && mouse_y>=56 && mouse_y<=84)
				{
					red_flag=true;
					allshapes[2]->draw(2);
				}
				else if(mouse_x<=1000 && mouse_x>=400  && mouse_y>=-28 && mouse_y<=0)
				{
					green_flag=true;
					allshapes[2]->draw(3);

				}
				else if(mouse_x<=1000 && mouse_x>=400  && mouse_y>=-56 && mouse_y<=-28)
				{
					blue_flag=true;
					allshapes[2]->draw(4);

				}
				else if(mouse_x<=1000 && mouse_x>=400  && mouse_y>=-84 &&mouse_y<=-56)
				{
					yellow_flag=true;
					allshapes[2]->draw(5);

				}
				else if(mouse_x<=1000 && mouse_x>=400  && mouse_y>=-112 && mouse_y<=-84)
				{
					orange_flag=true;
					allshapes[2]->draw(13);

				}
				else if (mouse_x<=500 && mouse_x>=400  && mouse_y>=-140 && mouse_y<=-112)
				{
					white_flag=true;
					allshapes[2]->draw(1);

				}
				else if (mouse_x<=1000 && mouse_x>=400  && mouse_y>=-168 && mouse_y<=-140)
				{
					black_flag=true;
					allshapes[2]->draw(0);

				}
			}
			if(arr[0].x<=1000 && arr[0].x>=400  && arr[0].y>=112 && arr[0].y<=140)
			{
				GP142_printfXY(RED,0,0,10,"%QUAD");
				GP142_await_event(&mouse_x, &mouse_y, &key_pressed); 
				if(mouse_x<=1000 && mouse_x>=400  && mouse_y>=56 && mouse_y<=84)
				{
					red_flag=true;
					allshapes[3]->draw(2);
				}
				else if(mouse_x<=1000 && mouse_x>=400  && mouse_y>=-28 && mouse_y<=0)
				{
					green_flag=true;
					allshapes[3]->draw(3);

				}
				else if(mouse_x<=1000 && mouse_x>=400  && mouse_y>=-56 && mouse_y<=-28)
				{
					blue_flag=true;
					allshapes[3]->draw(4);

				}
				else if(mouse_x<=1000 && mouse_x>=400  && mouse_y>=-84 &&mouse_y<=-56)
				{
					yellow_flag=true;
					allshapes[3]->draw(5);

				}
				else if(mouse_x<=1000 && mouse_x>=400  && mouse_y>=-112 && mouse_y<=-84)
				{
					orange_flag=true;
					allshapes[3]->draw(13);

				}
				else if (mouse_x<=500 && mouse_x>=400  && mouse_y>=-140 && mouse_y<=-112)
				{
					white_flag=true;
					allshapes[3]->draw(1);

				}
				else if (mouse_x<=1000 && mouse_x>=400  && mouse_y>=-168 && mouse_y<=-140)
				{
					black_flag=true;
					allshapes[3]->draw(0);

				}
			}
			if(arr[0].x<=1000 && arr[0].x>=400  && arr[0].y>=84 && arr[0].y<=112)
			{
				GP142_printfXY(RED,0,0,10,"%POL");
				GP142_await_event(&mouse_x, &mouse_y, &key_pressed); 
				if(mouse_x<=1000 && mouse_x>=400  && mouse_y>=56 && mouse_y<=84)
				{
					red_flag=true;
					allshapes[4]->draw(2);
				}
				else if(mouse_x<=1000 && mouse_x>=400  && mouse_y>=-28 && mouse_y<=0)
				{
					green_flag=true;
					allshapes[4]->draw(3);

				}
				else if(mouse_x<=1000 && mouse_x>=400  && mouse_y>=-56 && mouse_y<=-28)
				{
					blue_flag=true;
					allshapes[4]->draw(4);

				}
				else if(mouse_x<=1000 && mouse_x>=400  && mouse_y>=-84 &&mouse_y<=-56)
				{
					yellow_flag=true;
					allshapes[4]->draw(5);

				}
				else if(mouse_x<=1000 && mouse_x>=400  && mouse_y>=-112 && mouse_y<=-84)
				{
					orange_flag=true;
					allshapes[4]->draw(13);

				}
				else if (mouse_x<=500 && mouse_x>=400  && mouse_y>=-140 && mouse_y<=-112)
				{
					white_flag=true;
					allshapes[4]->draw(1);

				}
				else if (mouse_x<=1000 && mouse_x>=400  && mouse_y>=-168 && mouse_y<=-140)
				{
					black_flag=true;
					allshapes[4]->draw(0);

				}
			}
		    if(arr[0].x<=1000 && arr[0].x>=400  && arr[0].y>=56 && arr[0].y<=84)
			{
				GP142_printfXY(RED,0,0,10,"%CURVE");
					GP142_await_event(&mouse_x, &mouse_y, &key_pressed); 
				if(mouse_x<=1000 && mouse_x>=400  && mouse_y>=56 && mouse_y<=84)
				{
					red_flag=true;
					allshapes[5]->draw(2);
				}
				else if(mouse_x<=1000 && mouse_x>=400  && mouse_y>=-28 && mouse_y<=0)
				{
					green_flag=true;
					allshapes[5]->draw(3);

				}
				else if(mouse_x<=1000 && mouse_x>=400  && mouse_y>=-56 && mouse_y<=-28)
				{
					blue_flag=true;
					allshapes[5]->draw(4);

				}
				else if(mouse_x<=1000 && mouse_x>=400  && mouse_y>=-84 &&mouse_y<=-56)
				{
					yellow_flag=true;
					allshapes[5]->draw(5);

				}
				else if(mouse_x<=1000 && mouse_x>=400  && mouse_y>=-112 && mouse_y<=-84)
				{
					orange_flag=true;
					allshapes[5]->draw(13);

				}
				else if (mouse_x<=500 && mouse_x>=400  && mouse_y>=-140 && mouse_y<=-112)
				{
					white_flag=true;
					allshapes[5]->draw(1);

				}
				else if (mouse_x<=1000 && mouse_x>=400  && mouse_y>=-168 && mouse_y<=-140)
				{
					black_flag=true;
					allshapes[5]->draw(0);

				}

			}
			if(arr[0].x<=1000 && arr[0].x>=400  && arr[0].y>=28 && arr[0].y<=56)
			{
				GP142_printfXY(RED,0,0,10,"%text");

			}
			//if(arr[0].x<=1000 && arr[0].x>=400  && arr[0].y>=0 && arr[0].y<=28)
			//{
			//	GP142_printfXY(RED,0,0,10,"%RED");

			//}
			//if(arr[0].x<=1000 && arr[0].x>=400  && arr[0].y>=-28 && arr[0].y<=0)
			//{
			//	GP142_printfXY(RED,0,0,10,"%GREEEN");

			//}
			//if(arr[0].x<=1000 && arr[0].x>=400  && arr[0].y>=-56 && arr[0].y<=-28)
			//{
			//	GP142_printfXY(RED,0,0,10,"%BLUE");

			//}
			//if(arr[0].x<=1000 && arr[0].x>=400  && arr[0].y>=-84 && arr[0].y<=-56)
			//{
			//	GP142_printfXY(RED,0,0,10,"%yellow");

			//}
			//if(arr[0].x<=1000 && arr[0].x>=400  && arr[0].y>=-112 && arr[0].y<=-84)
			//{
			//	GP142_printfXY(RED,0,0,10,"%orange");

			//}
			//if(arr[0].x<=1000 && arr[0].x>=400  && arr[0].y>=-140 && arr[0].y<=-112)
			//{
			//	GP142_printfXY(RED,0,0,10,"%white");

			//}
			//if(arr[0].x<=1000 && arr[0].x>=400  && arr[0].y>=-168 && arr[0].y<=-140)
			//{
			//	GP142_printfXY(RED,0,0,10,"%black");

			//}
			
			/*if(arr[0].x<=1000 && arr[0].x>=400  && arr[0].y>=196 && arr[0].y<=252)
			{
				
			}
		*/
	

			
			//demo_handle_mouse(mouse_x,mouse_y);
			
		}
	//	break;
	}


	   
        
    GP142_close();         
    
    return 0;
}




