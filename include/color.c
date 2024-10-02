#ifndef _COLOR_C_
#define _COLOR_C_

#define BLACK       "\x1b[38;5;0m"
#define RED         "\x1b[38;5;196m"
#define GREEN       "\x1b[38;5;46m"
#define YELLOW      "\x1b[38;5;226m"
#define BLUE        "\x1b[38;5;21m"
#define MAGENTA     "\x1b[38;5;201m"
#define CYAN        "\x1b[38;5;51m"
#define WHITE       "\x1b[38;5;15m"
#define ORANGE      "\x1b[38;5;214m"
#define PURPLE      "\x1b[38;5;93m"
#define PINK        "\x1b[38;5;213m"
#define LIGHT_BLUE  "\x1b[38;5;81m"
#define LIGHT_GREEN "\x1b[38;5;119m"
#define GRAY        "\x1b[38;5;244m"
#define LIGHT_GRAY  "\x1b[38;5;250m"
#define BROWN       "\x1b[38;5;94m"
#define GOLD        "\x1b[38;5;220m"
#define TEAL        "\x1b[38;5;30m"
#define VIOLET      "\x1b[38;5;135m"
#define RESET       "\x1b[0m"   // Reset to default
#define PIXEL_OFF   BLACK  // Background "off" color (black)
#define RED_BG      "\x1b[48;5;196m"
#define GREEN_BG    "\x1b[48;5;46m"
#define BLUE_BG     "\x1b[48;5;21m"
#define YELLOW_BG   "\x1b[48;5;226m"
#define CYAN_BG     "\x1b[48;5;51m"
#define MAGENTA_BG  "\x1b[48;5;201m"
#define WHITE_BG    "\x1b[48;5;15m"
#define BLACK_BG    "\x1b[48;5;0m"

typedef struct {
  const char* ansiCode;
} Color;

Color createColor(const char* ansiCode) {
    Color color;
    color.ansiCode = ansiCode;
    return color;
}

#endif
