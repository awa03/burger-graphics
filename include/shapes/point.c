#ifndef _POINT_C_
#define _POINT_C_

typedef struct {
  int x; 
  int y;
} Point;

#define Vec2 Point

Point makePoint(int x, int y){
  Point p;
  p.x = x;
  p.y = y;
  return p;
}

#endif
