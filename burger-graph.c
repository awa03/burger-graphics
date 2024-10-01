#ifndef _BURGER_GRAPH_C
#define _BURGER_GRAPH_C

#include "include/cell.c"

// For Input Monitoring
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

// For Drawing Shapes
#include <stdio.h>
#include "shapes/line.c"

// TODO: Pixel Art to Custom file type, and Pixel Art to obj

#define moveCursor(x, y) printf("\033[%d;%dH", (y), (x))

void enableRawMode() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
}

void disableRawMode() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

// int main(void) {
//     // Initialize cell
//     cell myCell = {
//         {{createColor(BLACK), true, FULL_BLOCK}}, {{createColor(BLACK), true, FULL_BLOCK}}
//     };
//     drawCell(myCell);

//     int playerx = 2, playery = 4;
//     myCell[playery][playerx] = createPixel(createColor(RED), FULL_BLOCK);

//     enableRawMode();

//     int oldx = playerx, oldy = playery;
//     char input;

//     // Move cursor to the top-left and hide it to avoid flicker
//     printf("\033[?25l");  // Hide cursor
//     for (;;) {
//         input = getchar(); // Non-blocking input

//         // Process input
//         if (input == 'q') break;
//         else if (input == 'w') playery--;
//         else if (input == 's') playery++;
//         else if (input == 'a') playerx--;
//         else if (input == 'd') playerx++;

//         // Erase the old player position
//         moveCursor(oldx, oldy);
//         printf(" ");  // Empty space or background character

//         // Draw the player at the new position
//         moveCursor(playerx, playery);
//         printf("%c", *FULL_BLOCK);  // Draw player

//         // Update old positions for the next loop
//         oldx = playerx;
//         oldy = playery;

//         usleep(10000); // Small delay for smoother motion
//     }

//     // Show cursor and reset terminal
//     printf("\033[?25h");  // Show cursor
//     disableRawMode();
//     return 0;
// }


/*
 * NOTES -------------------------------------------------
 * Algorithm: Bresenham's Line Algorithm, REF: https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
 * G4G Algorithm Overview: https://www.geeksforgeeks.org/bresenhams-line-generation-algorithm/
*/

# endif
