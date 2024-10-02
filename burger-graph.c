#include "include/cell.c"
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <stdio.h>

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
        {{createColor(BLACK), true, FULL_BLOCK}}, {{createColor(BLACK), true, FULL_BLOCK}}
    };
    drawCell(myCell);

    int playerx = 2, playery = 4;
    myCell[playery][playerx] = createPixel(createColor(RED), FULL_BLOCK);

    // Enable non-blocking keyboard input
    enableRawMode();

    char input;
    for (;;) {

        myCell[playery][playerx] = createFullBlockPixel(createColor(RED), false);
        input = getchar(); // This will be non-blocking now

        if (input == 'q') { // Press 'q' to quit the loop
            break;
        } else if (input == 'w') { // Move player up
            // Logic to move player
            playery--;
        } else if (input == 's') { // Move player down
            playery++;
        } else if (input == 'a') { // Move player left
            playerx--;
        } else if (input == 'd') { // Move player right
            playerx++;
        }

        myCell[playery][playerx] = createFullBlockPixel(createColor(RED), true);
        // Redraw the cell or update game logic here
        // Clear screen and draw updated cell
        clrscr();
        drawCell(myCell);
        usleep(15000); // Sleep for a short time to control loop speed
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

