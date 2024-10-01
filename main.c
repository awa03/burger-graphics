#include <stdio.h>
#include "include/cell.c"


int main(void) {
  cell myCell = {
    {{createColor(BLACK), true, FULL_BLOCK}}
  };

  // Draw the cell
  drawCell(myCell);
}
/*
 * NOTES -------------------------------------------------
 * Algorithm: Bresenham's Line Algorithm, REF: https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
 * G4G Algorithm Overview: https://www.geeksforgeeks.org/bresenhams-line-generation-algorithm/
*/

