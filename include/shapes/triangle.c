#ifndef _TRIANGLE_C_
#define _TRIANGLE_C_

#include "point.c"

typedef struct {
  Point p1;
  Point p2;
  Point p3;
} Triangle;


Triangle makeTriangle(Point p1, Point p2, Point p3){
  Triangle t; 
  t.p1 = p1;
  t.p2 = p2;
  t.p3 = p3;
  return t;
}

Triangle makeTriangleExplicit(int pone1, int pone2, int ptwo1, int ptwo2, int pthree1, int pthree2){
  Triangle t; 
  t.p1 = makePoint(pone1, pone2);
  t.p2 = makePoint(ptwo1, ptwo2);
  t.p3 = makePoint(pthree1, pthree2);
  return t;
}


#endif

