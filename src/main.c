/*******************************************************************************************
*
*
*   File Name: main.c 
*   Description: *A reworked Raylib example modified for my projects
*   	Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   	BSD-like license that allows static linking with closed source software
*   Author: @Dedra-Termai
*   Date: 06-28-2025
*   Update: 07-06-2025
*
*
********************************************************************************************/


#include "raylib.h"
#include "resource_dir.h"	// utility header for SearchAndSetResourceDir
#include "stdio.h"

//------------------------------------------------------------------------------------------
// Types and Structures Definition
//------------------------------------------------------------------------------------------
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

typedef enum GameScreen { LOGO = 0, TITLE, GAMEPLAY, ENDING } GameScreen;

//------------------------------------------------------------------------------------
// Global Variables Declaration
//------------------------------------------------------------------------------------
Texture2D RaylibLogo;
Vector2 RaylibLogoPosition = {(SCREEN_WIDTH*.6),(SCREEN_HEIGHT*.75)};
Texture2D YourLogoHere;
Vector2 YourLogoHerePosition = {(SCREEN_WIDTH/2-50),(SCREEN_HEIGHT/4)};
GameScreen currentScreen;
int framesCounter = 0;          // Useful to count frames

//------------------------------------------------------------------------------------
// Module Functions Declaration
//------------------------------------------------------------------------------------
//Update Functions
void UpdateLogoScreen();//LOGO
void UpdateTitleScreen();//TITLE
void UpdateGamePlayScreen();//GAMEPLAY
void UpdateEndingScreen();//ENDING 

//Draw Functions
void DrawLogoScreen(); //LOGO
void DrawTitleScreen();//TITLE
void DrawGamePlayScreen();//GAMEPLAY
void DrawEndingScreen();//ENDING


//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main ()
{
	// Tell the window to use vsync and work on high DPI displays
	SetConfigFlags(FLAG_VSYNC_HINT | FLAG_WINDOW_HIGHDPI);

	// Create the window and OpenGL context
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Hello Raylib");

	// Utility function from resource_dir.h to find the resources folder and set it as the current working directory so we can load from it
	SearchAndSetResourceDir("resources");

	// Load a texture from the resources directory
	RaylibLogo = LoadTexture("Raylib_logo.png");
	YourLogoHere = LoadTexture("yourlogohere.png");

	//Set the Current Screen to LOGO
	currentScreen = LOGO;

	SetTargetFPS(60);               // Set desired framerate (frames-per-second)
	
	// game loop
	while (!WindowShouldClose())		// run the loop untill the user presses ESCAPE or presses the Close button on the window
	{
		// update
		//----------------------------------------------------------------------------------
		switch (currentScreen)
		{
		    case LOGO:
		    {
				// TODO: Update LOGO screen variables here!
				UpdateLogoScreen();				

		    } break;
		    case TITLE:
		    {
				// TODO: Update TITLE screen variables here!
				UpdateTitleScreen();
				
		    } break;
		    case GAMEPLAY:
		    {
				// TODO: Update GAMEPLAY screen variables here!
				UpdateGamePlayScreen();
				
		    } break;
		    case ENDING:
		    {
				// TODO: Update ENDING screen variables here!				
				UpdateEndingScreen();
			
		    } break;
		    default: break;
		}
		//----------------------------------------------------------------------------------
		
		// drawing
		BeginDrawing();
		
		// Setup the back buffer for drawing (clear color and depth buffers)
		ClearBackground(GRAY);
		
		switch(currentScreen)
		{
			case LOGO:
			{
				// TODO: Draw LOGO screen here!
				DrawLogoScreen();		
			} break;
			case TITLE:
			{
				// TODO: Draw TITLE screen here!
				DrawTitleScreen();
				
			
			} break;
			case GAMEPLAY:
			{
				// TODO: Draw GAMEPLAY screen here!
				DrawGamePlayScreen();
			
			} break;
			case ENDING:
			{
				// TODO: Draw ENDING screen here!
				DrawEndingScreen();
			
			} break;
			default: break;
		}
		// end the frame and get ready for the next one  (display frame, poll input, etc...)
		EndDrawing();
        	//----------------------------------------------------------------------------------

	}

	// De-Initialization
    //--------------------------------------------------------------------------------------
	// cleanup
	// unload our texture so it can be cleaned up
	UnloadTexture(RaylibLogo);

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}


//--------------------------------------------------------------------------------------
//Update Functions
//--------------------------------------------------------------------------------------
//LOGO
void UpdateLogoScreen(){
	framesCounter++;    // Count frames
			
	// Wait for 2 seconds (120 frames) before jumping to TITLE screen
	if (framesCounter > 240)
	{
		currentScreen = TITLE;
	}
}

//TITLE
void UpdateTitleScreen(){
	// Press enter to change to GAMEPLAY screen
	if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
	{
		currentScreen = GAMEPLAY;
	}
}

//GAMEPLAY
void UpdateGamePlayScreen(){
	// Press enter to change to ENDING screen
	if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
	{
		currentScreen = ENDING;
	}
}

//ENDING
void UpdateEndingScreen(){
	// Press enter to return to TITLE screen
	if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
	{
		currentScreen = TITLE;
	}
}

//--------------------------------------------------------------------------------------
//Draw Functions
//--------------------------------------------------------------------------------------
//LOGO
void DrawLogoScreen(){
	DrawText("LOGO SCREEN", 20, 20, 40, LIGHTGRAY);
	DrawText("A PLACEHOLDER game", SCREEN_WIDTH/4, SCREEN_HEIGHT/2,40, BLACK);
	DrawTextureEx(YourLogoHere, YourLogoHerePosition, 0.0f, .25f, WHITE);
	DrawText("WAIT for 2 SECONDS...", 290, 550, 20, BLACK);
	DrawText("Powered by ...", SCREEN_WIDTH/4, 650, 40, BLACK); 
	DrawTextureEx(RaylibLogo, RaylibLogoPosition, 0.0f, .5f, WHITE);
};

//TITLE
void DrawTitleScreen(){
	DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, GREEN);
	DrawText("TITLE SCREEN", 20, 20, 40, DARKGREEN);
	DrawText("PRESS ENTER or TAP to JUMP to GAMEPLAY SCREEN", 120, 220, 20, DARKGREEN);
};

//GAMEPLAY
void DrawGamePlayScreen(){
	DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, PURPLE);
	DrawText("GAMEPLAY SCREEN", 20, 20, 40, MAROON);
	DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, MAROON);
	// draw our texture to the screen
	// draw some text using the default font
	//DrawText("Hello Raylib", 200,200,20,WHITE);
};

//ENDING
void DrawEndingScreen(){
	DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, BLUE);
	DrawText("ENDING SCREEN", 20, 20, 40, DARKBLUE);
	DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, DARKBLUE);
}