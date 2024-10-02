#ifndef _Rectangle_H_
#define _Rectangle_H_

#include "point.c"

typedef struct {
  Point p1;
  Point p2;
} Rectangle;

// TODO Make a conversion constructor from Rectangle to Rectangle 4

typedef struct {
  Point p1;
  Point p2;
  Point p3;
  Point p4;
} Rectangle4;

Rectangle makeRectangle(Point p1, Point p2){
  Rectangle s;   
  s.p1 = p1;
  s.p2 = p2;
  return s;
}

Rectangle4 makeRectangle4(Point p1, Point p2, Point p3, Point p4){
  Rectangle4 s;   
  s.p1 = p1;
  s.p2 = p2;
  s.p3 = p3;
  s.p4 = p4;
  return s;
}




#endif
