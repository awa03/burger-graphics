
#ifndef _LINE_C_
#define _LINE_C_

#include "point.c"
#include "../cell.c"

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

// TODO: Implement
void addLine(cell* c, Line l){
  return;
}

#endif
