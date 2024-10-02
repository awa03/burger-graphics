
#ifndef _LINE_C_
#define _LINE_C_

#include "point.c"

// Either value can represent one another, just need them to both be set
typedef struct {
  Point start;
  Point end;
} Line;


// constructors
Line makeLine(Point start, Point end){
  Line l;
  l.start = start;
  l.end = end;
  return l;
}
Line makeLineExplicit(int x, int y, int x1, int y1){
  Line l;
  l.start = makePoint(x, y);
  l.end = makePoint(x1, y1);
  return l;
}

#endif
