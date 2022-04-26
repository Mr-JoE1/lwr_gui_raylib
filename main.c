/*
Raylib example file.
This is an example main file for a simple raylib project.
Use this as a starting point or replace it with your code.

For a C++ project simply rename the file to .cpp and run premake 

*/

#include "raylib.h"
#include <math.h>

// global varibales

const  int len = 180;
const  int center_x = 415;
const  int center_y = 240;


// functions 

void display_information(int angle, int frequency, int elev);
double  deg2rad(int a);
void drawPointer(double angle);

int main ()
{
	int ang = 120; 
	// set up the window
	InitWindow(800, 480, "Hello Raylib");
	//Image background = LoadImage("resources/800x480_pg.png");
	Texture2D background = LoadTexture("resources/800x480_pg.png");
	
	// game loop
	while (!WindowShouldClose())
	{
		// drawing
		BeginDrawing();
		ClearBackground(BLACK);
		DrawTexture(background, 0, 0, WHITE);
		display_information(120, 10, 1);
		drawPointer(deg2rad(ang));
		
		EndDrawing();
	}

	// cleanup
	CloseWindow();
	return 0;
}

void display_information(int angle, int frequency, int elev){

	Font LoadFont(const char* fileName);
	//display angle value 

	DrawText(TextFormat("%i", angle), 45, 120, 30, RED);

	//display frequency value 

	DrawText(TextFormat("%i", frequency), 45, 190, 30, RED);

	//  Decode and display laser type
	if (frequency >= 1 && frequency <= 7)
		DrawText("LRF", 45, 265, 25, RED);
	else if (frequency > 7 && frequency <= 25)
		DrawText("LTD", 45, 265, 25, RED);
	else if (frequency > 1000)
		DrawText("BR", 45, 265, 25, RED);
	else
		DrawText("XXX", 45, 265, 25, RED);

	//display land or air
	if (elev == 1) {
		DrawText("AIR", 45, 340, 25, RED);
	}
	else {
		DrawText("GG", 45, 340, 25, RED);
	}
	DrawText("OK", 45, 410, 25, GREEN);
}

double  deg2rad(int a) {

	return ((a - 90) * 0.017453292519);
}


/*
 * Function to get the end point of
 * angle poiner and plot the pointer
 */
void drawPointer(double angle) {
	int end_x, end_y = 0;

	end_x = center_x + len * cos(angle);
	end_y = center_y + len * sin(angle);

	DrawLine(center_x, center_y, end_x, end_y, RED);
	DrawLine(center_x + 1, center_y +1 , end_x +1 , end_y +1, RED);
	DrawLine(center_x + 2, center_y + 2, end_x + 2, end_y + 2, RED);
	DrawLine(center_x + 3, center_y + 3, end_x + 3, end_y + 3, RED);
	DrawLine(center_x - 1, center_y - 1 , end_x - 1 , end_y - 1, RED);
	DrawLine(center_x - 2, center_y - 2, end_x - 2, end_y - 2, RED);
	DrawLine(center_x - 3, center_y - 3, end_x - 3, end_y - 3, RED);
}
