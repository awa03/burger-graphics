#ifndef _POINT_C_
#define _POINT_C_

typedef struct {
  int x; 
  int y;
} Point;

// TODO: IMPLEMENT
typedef struct {
  int x; 
  int y;
  int z;
} Point3;

#define Vec2 Point
#define Vec3 Point3

Point makePoint(int x, int y){
  Point p;
  p.x = x;
  p.y = y;
  return p;
}

#endif
