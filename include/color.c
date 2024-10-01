#define RED     "\x1b[48;5;196m"
#define GREEN   "\x1b[48;5;46m"
#define BLUE    "\x1b[48;5;21m"
#define YELLOW  "\x1b[48;5;226m"
#define CYAN    "\x1b[48;5;51m"
#define MAGENTA "\x1b[48;5;201m"
#define WHITE   "\x1b[48;5;15m"
#define BLACK   "\x1b[48;5;0m"
#define PIXEL_OFF   "\x1b[48;5;0m"
#define RESET   "\x1b[0m"

typedef struct {
  const char* ansiCode;
} Color;

Color createColor(const char* ansiCode) {
    Color color;
    color.ansiCode = ansiCode;
    return color;
}



