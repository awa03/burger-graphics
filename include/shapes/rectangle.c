#ifndef _Rectangle_H_
#define _Rectangle_H_

#include "point.c"

typedef struct {
  Point p1;
  Point p2;
} Rectangle;

Rectangle makeRectangle(Point p1, Point p2){
  Rectangle s;   
  s.p1 = p1;
  s.p2 = p2;
  return s;
}




#endif
