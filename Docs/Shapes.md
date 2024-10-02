# Shapes

Lets first start by showcasing the needed components in order to construct a shape. 

## Points

```c
Point makePoint(int x, int y);
```

Through the `makePoint` function we can create a point structure. This struct contains a x and a y value. You can consider this "point" to represent a pixel
within the Pixel array. You can also manually construct a point through the following method: 

```c
typedef struct {
  int x; 
  int y;
} Point;
```

A points values can be set through manually changing the values encapsulated within the point structure. An example of this being:

```c
Point p;
p.x = 2;
p.y = 3;
```

Points can also be created using the alias `Vec2`, this may help with readability especially when using the variable in cases where the name point may not be appropriate. 

<br>

The other type of point is the `Point3`. The a point 3 is not currently used within the implementation, however it will be extremely useful in creating 3d programs. These can also
be refrenced through the name `Vec3`. Values can be set in the same manner as the `Point`, however, with the addition of a new `z`.

```c
Point3 p;
p.x = 1;
p.y = 2;
p.z = 3;
```

****

## Lines

Lines can be useful in creating practically any visual application. A line can be created through the following method:

```c
Line makeLine(Point start, Point end);
```

Additionally we the `makeLineExplicit` function will allow us to create a line without needing to first create points. 

```c
Line makeLineExplicit(int x, int y, int x1, int y1);
```


The start and end poisitions both being created through the aforementioned line points. A line is only defined through two points since the points inbetween can be assumed. This is also 
helpful in allowing us to implement out [Bresenham line algorithm](Bresenham-Line-Algorithm.md). 

<br>
The line structure can be seen below.

```c
typedef struct {
  Point start;
  Point end;
} Line;
```

Lines can then be implemented within our pixel array using the `addLine` function. This function implements [Bresenham line algorithm](Bresenham-Line-Algorithm.md) in order to 
calculate where each pixel should be placed. The add line function takes the following parameters:

```c
void addLine(cell c, Line l, Pixel pix);
```

## Triangles

Triangles operate very similarly to lines. Triangles are infact made up of 3 lines. A triangle may be created through the following:

```c
Triangle makeTriangle(Point p1, Point p2, Point p3);
```

A triangle can also be created manually, the structure of which is the following:

```c
typedef struct {
  Point p1;
  Point p2;
  Point p3;
} Triangle;
```

We can use similar functions to contruct our triangle points as well.

```c
Triangle makeTriangle(Point p1, Point p2, Point p3);
Triangle makeTriangleExplicit(int pone1, int pone2,
                              int ptwo1, int ptwo2, int pthree1, int pthree2);
```

I would stray away from using the explicit function because it is ironically more verbose than using:

```c
makeTriangle(makePoint(1, 2), makePoint(3, 3), makePoint(5, 10));
```









