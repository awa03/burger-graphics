#ifndef _CELL_H
#define _CELL_H

#include <stdio.h>
#include "color.c"  // Include color definitions
#include "user_settings.c"

#define false 0
#define true  1

// Define different block characters for finer pixel control
#define FULL_BLOCK  "\u2588"  // Full block
#define UPPER_BLOCK "\u2580"  // Upper half block
#define LOWER_BLOCK "\u2584"  // Lower half block
#define LEFT_BLOCK  "\u258C"  // Left half block
#define RIGHT_BLOCK "\u2590"  // Right half block
#define RESET_BLOCK "\u2591"  // Lighter block for "off"

// Define the Pixel struct with color and block type
typedef struct {
    Color color;  // ANSI color
    int isOn;     // Whether the pixel is on or off
    char* blockType;  // Type of block (full, half, etc.)
} Pixel;

// Define a 4x4 cell of Pixels
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

#endif

