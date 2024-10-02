#include "include/cell.c"
#include "include/shapes/line.c"
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <stdio.h>
#include "include/color.c"

#define clrscr() printf("\e[1;1H\e[2J")

// Set terminal to non-canonical mode
void enableRawMode() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &term);

    // Make stdin non-blocking
    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
}

// Reset terminal back to normal mode
void disableRawMode() {
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= (ICANON | ECHO); // Re-enable canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

int main(void) {
    // Initialize cell
    cell myCell = {
    };
    initCell(myCell, createPixel(createColor(BLACK), FULL_BLOCK));
    drawCell(myCell);
    drawCell(myCell);

    int playerx = 2, playery = 4;
    // myCell[playery][playerx] = createPixel(createColor(RED), FULL_BLOCK);

    // Enable non-blocking keyboard input
    enableRawMode();

    char input;
    // game loop
    for (;;) {
        // myCell[playery][playerx] = createFullBlockPixel(createColor(YELLOW), false);

        // Safer Call -------------------------------------------------------------------- Bounded by size of arr
        // setPixel(myCell, makePoint(playerx, playery), createFullBlockPixel(createColor(YELLOW), false));
        // input = getchar(); // This will be non-blocking now

        if (input == 'q') { // Press 'q' to quit the loop
            break;
        } else if (input == 'w') { // Move player up
            // Logic to move player
            if(isValidY(playery - 1)){
              playery--;
            }
        } else if (input == 's') { // Move player down
            if(isValidY(playery + 1)){
              playery++;
            }
        } else if (input == 'a') { // Move player left
            if(isValidX(playery - 1)){
              playerx--;
            }
        } else if (input == 'd') { // Move player right
            if(isValidX(playery + 1)){
                playerx++;
              }
        }

        // myCell[playery][playerx] = createPixelBlock(createColor(RED_BG), true, " ");

        // Redraw the cell or update game logic here
        // Clear screen and draw updated cell
        clrscr();

        addTriangleFilled(myCell, 
          makeTriangle(
            makePoint(0, 0),
            makePoint(15, 20),
            makePoint(55, 25)
          ),
          createPixel(createColor(CYAN), FULL_BLOCK)
        );

        // ensure y is the same for proper usage, no checking incase on angle 
        // tech makes a square but is rendered as a rec due to res, 
        // make square will fix these issues 
        addRectangleFilled(myCell, 
          makeRectangle(
            makePoint(1, 1),
            makePoint(10, 1)
          ), 
          createPixel(createColor(YELLOW), FULL_BLOCK)
        );

        // AVOID USING EXPLICITLY -- ARTIFACTS CAUSED BY INCORRECT SETTING MAY OCCUR
        addRectangle4Filled(myCell, 
          makeRectangle4(
            makePoint(10, 10),
            makePoint(30, 10),
            makePoint(10, 20),
            makePoint(30, 20)
          ),
          createPixel(createColor(RED), FULL_BLOCK)
        );

        addRectangle4Filled(myCell, 
          makeRectangle4(
            makePoint(0, 20),
            makePoint(10, 20),
            makePoint(0, 40),
            makePoint(10, 40)
          ),
          createPixel(createColor(BLUE), FULL_BLOCK)
        );

        drawCell(myCell);
        usleep(2000000000); // Sleep for a short time to control loop speed
    }

    // Reset terminal to normal mode before exiting
    disableRawMode();
    return 0;
}



/*
 * NOTES -------------------------------------------------
 * Algorithm: Bresenham's Line Algorithm, REF: https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
 * G4G Algorithm Overview: https://www.geeksforgeeks.org/bresenhams-line-generation-algorithm/
*/

