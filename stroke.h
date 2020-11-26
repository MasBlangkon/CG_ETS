#ifndef H_STROKE
#define H_STROKE
#include "util.h"

void create_line();
void line_props();
void drawline(int xa, int ya, int xb, int yb, int color);

void rotate(int x1, int y1, int *x2, int *y2, int angle);
void rotate_p(int *x1, int *y1, int x0, int y0, int angle);

#endif

