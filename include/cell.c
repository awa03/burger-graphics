#ifndef _CELL_H
#define _CELL_H

#include <stdio.h>
#include <stdlib.h>
#include "shapes/line.c"
#include "shapes/rectangle.c"
#include "shapes/triangle.c"
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
    Color bg_color;  // ANSI color, dont worry we have premade ones defined (RED, BLUE, etc)
    int isOn;     // Whether the pixel is on or off
    char* blockType;  // Type of block (full, half, etc.), this can help create cool effects
} Pixel;

// Define a NxN cell of Pixels -- If you want to adjust these refer to the user_settings file, or just manually change them
// (make sure to also change the for loops in the drawCell function if modified with literals)
typedef Pixel cell[SCREEN_HEIGHT][SCREEN_WIDTH];

// Function to draw a single pixel with partial blocks
void drawPixel(Pixel p) {
    if (p.isOn) {
        printf("%s%s%s", p.color.ansiCode, p.bg_color.ansiCode, p.blockType);  // Use the block type and color
    } else {
        printf(PIXEL_OFF BLACK_BG RESET_BLOCK );  // Default to a shaded block for "off" state
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

Pixel createPixelWithBG(Color c, Color bg, char* blocktype){
  Pixel p;
  p.blockType = FULL_BLOCK;
  p.color = c;
  p.color = bg;
  p.isOn = true;
  return p;
}


int isValid(Point point){
  if(point.x < SCREEN_WIDTH && point.x >= 0 && point.y < SCREEN_HEIGHT && point.y >= 0 ){
    return true;
  }
  return false;
}

int isValidExplicit(int x, int y){
  Point p;
  p.x = x;
  p.y = y;
  return isValid(p);
}

int isValidY(int y){
  return y < SCREEN_HEIGHT;
}
int isValidX(int x){
  return x < SCREEN_WIDTH;
}

void setPixel(cell c, Point point, Pixel pix){
  if(isValid(point)){
    c[point.y][point.x] = pix;
  }
}

void addLine(cell c, Line l, Pixel pix) {
  // Check for valid starting and ending coordinates
  if (l.start.x < 0 || l.start.x >= SCREEN_WIDTH || l.start.y < 0 || l.start.y >= SCREEN_HEIGHT ||
    l.end.x < 0 || l.end.x >= SCREEN_WIDTH || l.end.y < 0 || l.end.y >= SCREEN_HEIGHT) {
    // Handle the error appropriately (e.g., print an error message)
    fprintf(stderr, "Error: Line coordinates out of bounds.\n");
    return; // Exit the function if the coordinates are invalid
  }

  // Bresenham's Line Algorithm to fill in pixels between two points
  int x0 = l.start.x;
  int y0 = l.start.y;
  int x1 = l.end.x;
  int y1 = l.end.y;

  // Find the difference in the vals
  int dx = abs(x1 - x0);
  int dy = abs(y1 - y0);
  int sx = (x0 < x1) ? 1 : -1; // Step in the x direction
  int sy = (y0 < y1) ? 1 : -1; // Step in the y direction
  int err = dx - dy;

  while (true) {
    // Set the pixel at (x0, y0)
    if (x0 >= 0 && x0 < SCREEN_WIDTH && y0 >= 0 && y0 < SCREEN_HEIGHT) {
      c[y0][x0] = pix; 
    }

    // Check if we've reached the end point
    if (x0 == x1 && y0 == y1) break;

    int err2 = err * 2;
    if (err2 > -dy) { // Move horizontally
      err -= dy;
      x0 += sx;
    }
    if (err2 < dx) {  // Move vertically
      err += dx;
      y0 += sy;
    }
  }
}

void addTriangle(cell c, Triangle t, Pixel pix){
  addLine(c, makeLine(t.p1, t.p2), pix);
  addLine(c, makeLine(t.p2, t.p3), pix);
  addLine(c, makeLine(t.p3, t.p1), pix);
}

void addTriangleFilled(cell c, Triangle t, Pixel pix){
  addLine(c, makeLine(t.p1, t.p2), pix);
  addLine(c, makeLine(t.p2, t.p3), pix);
  addLine(c, makeLine(t.p3, t.p1), pix);

  // #TODO: IMPLEMENT
}

void addRectangle(cell c, Rectangle s, Pixel pix) {
    // Vector from p1 to p2
    int dx = s.p2.x - s.p1.x;
    int dy = s.p2.y - s.p1.y;

    // Calculate the perpendicular vector (rotate by 90 degrees)
    int perp_dx = -dy;
    int perp_dy = dx;

    // Calculate p3 and p4
    Point p3 = makePoint(s.p1.x + perp_dx, s.p1.y + perp_dy);
    Point p4 = makePoint(s.p2.x + perp_dx, s.p2.y + perp_dy);

    // Draw the four sides of the Rectangle
    addLine(c, makeLine(s.p1, s.p2), pix);  // Side 1: p1 -> p2
    addLine(c, makeLine(s.p2, p4), pix);    // Side 2: p2 -> p4
    addLine(c, makeLine(p4, p3), pix);      // Side 3: p4 -> p3
    addLine(c, makeLine(p3, s.p1), pix);    // Side 4: p3 -> p1
}



#endif

