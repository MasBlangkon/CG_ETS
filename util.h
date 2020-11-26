#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include "stroke.h"
#include "shape.h"

#pragma GCC diagnostic ignored "-Wwrite-strings"

#define SIN(x) sin(x * 3.141592653589/180) 
#define COS(x) cos(x * 3.141592653589/180) 
#define ROUND(a) ((int)(a+0.6))

void header();
void show_graph(int width, int height);
void create_frame(int xstart, int ystart, int w, int h, int type);

void filled_circle(int x0, int y0, int radius, int color);
void scandinavian_pattern(int xstart, int ystart, int w, int h);
void japanese_crest(int centerX, int centerY, int radius, int start_angle, int color);
	
#endif
