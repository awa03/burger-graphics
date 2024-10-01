#ifndef _CELL_H
#define _CELL_H

#include <stdio.h>
#include "color.c"  
#include "user_settings.c"

#define false 0
#define true  1

// These will be our blocks -- Basis of our "Pixels"
#define FULL_BLOCK  "\u2588"  // Full block
#define UPPER_BLOCK "\u2580"  // Upper half block
#define LOWER_BLOCK "\u2584"  // Lower half block
#define LEFT_BLOCK  "\u258C"  // Left half block
#define RIGHT_BLOCK "\u2590"  // Right half block
#define RESET_BLOCK "\u2591"  // Lighter block for "off"

// Define the Pixel struct with color and block type
typedef struct {
    Color color;  // ANSI color, dont worry we have premade ones defined (RED, BLUE, etc)
    int isOn;     // Whether the pixel is on or off
    char* blockType;  // Type of block (full, half, etc.), this can help create cool effects
} Pixel;

// Define a NxN cell of Pixels -- If you want to adjust these refer to the user_settings file, or just manually change them
// (make sure to also change the for loops in the drawCell function if modified with literals)
typedef Pixel cell[SCREEN_HEIGHT][SCREEN_WIDTH];

// Function to draw a single pixel with partial blocks
void drawPixel(Pixel p) {
    if (p.isOn) {
        printf("%s%s", p.color.ansiCode, p.blockType);  // Use the block type and color
    } else {
        printf(PIXEL_OFF RESET_BLOCK);  // Default to a shaded block for "off" state
    }
}

// Function to draw the entire cell
void drawCell(cell c) {
    for (int i = 0; i < SCREEN_HEIGHT; i++) {  // Loop through rows
        for (int j = 0; j < SCREEN_WIDTH; j++) {  // Loop through columns
            drawPixel(c[i][j]);  // Draw each pixel in the cell
        }
        printf(RESET "\n");  // Reset colors and move to the next row
    }
}



// constructors so we dont have to define every element of the pixel
Pixel createFullBlockPixel(Color c, int isOn){
  Pixel p;
  p.isOn = isOn;
  p.color = c;
  p.blockType = FULL_BLOCK;
  return p;
}

Pixel createPixelBlock(Color c, int isOn, char* blocktype){
  Pixel p;
  p.blockType = blocktype;
  p.color = c;
  p.isOn = isOn;
  return p;
}

Pixel createPixel(Color c, char* blocktype){
  Pixel p;
  p.blockType = FULL_BLOCK;
  p.color = c;
  p.isOn = true;
  return p;
}



#endif

