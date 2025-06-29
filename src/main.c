/*******************************************************************************************
*
*
*   File Name: main.c 
*   Description: *A reworked Raylib example modified for my projects
*   	Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   	BSD-like license that allows static linking with closed source software
*   Author: @Dedra-Termai
*   Date: 06-28-2025
*   Update: 06-28-2025
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
	Texture wabbit = LoadTexture("wabbit_alpha.png");

	//Set the Current Screen to LOGO
	GameScreen currentScreen = LOGO;

	//Frame counter
	int framesCounter = 0;          // Useful to count frames

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
		
			framesCounter++;    // Count frames
		
			// Wait for 2 seconds (120 frames) before jumping to TITLE screen
			if (framesCounter > 120)
			{
			    currentScreen = TITLE;
			}
		    } break;
		    case TITLE:
		    {
			// TODO: Update TITLE screen variables here!
		
			// Press enter to change to GAMEPLAY screen
			if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
			{
			    currentScreen = GAMEPLAY;
			}
		    } break;
		    case GAMEPLAY:
		    {
			// TODO: Update GAMEPLAY screen variables here!
		
			// Press enter to change to ENDING screen
			if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
			{
			    currentScreen = ENDING;
			}
		    } break;
		    case ENDING:
		    {
			// TODO: Update ENDING screen variables here!
		
			// Press enter to return to TITLE screen
			if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
			{
			    currentScreen = TITLE;
			}
		    } break;
		    default: break;
		}
		//----------------------------------------------------------------------------------
		
		// drawing
		BeginDrawing();
		
		// Setup the back buffer for drawing (clear color and depth buffers)
		ClearBackground(RAYWHITE);
		
		switch(currentScreen)
		{
		case LOGO:
		{
			// TODO: Draw LOGO screen here!
			DrawText("LOGO SCREEN", 20, 20, 40, LIGHTGRAY);
			DrawText("WAIT for 2 SECONDS...", 290, 220, 20, GRAY);
		
		} break;
		case TITLE:
		{
			// TODO: Draw TITLE screen here!
			DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, GREEN);
			DrawText("TITLE SCREEN", 20, 20, 40, DARKGREEN);
			DrawText("PRESS ENTER or TAP to JUMP to GAMEPLAY SCREEN", 120, 220, 20, DARKGREEN);
		
		} break;
		case GAMEPLAY:
		{
			// TODO: Draw GAMEPLAY screen here!
			DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, PURPLE);
			DrawText("GAMEPLAY SCREEN", 20, 20, 40, MAROON);
			DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 130, 220, 20, MAROON);
			// draw our texture to the screen
			DrawTexture(wabbit, 400, 200, WHITE);
			// draw some text using the default font
			DrawText("Hello Raylib", 200,200,20,WHITE);
		
		} break;
		case ENDING:
		{
			// TODO: Draw ENDING screen here!
			DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, BLUE);
			DrawText("ENDING SCREEN", 20, 20, 40, DARKBLUE);
			DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, DARKBLUE);
		
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
	UnloadTexture(wabbit);

	// destroy the window and cleanup the OpenGL context
	CloseWindow();
	return 0;
}
