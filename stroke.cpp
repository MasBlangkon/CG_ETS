#include "stroke.h"

void create_line(){
	int x0, y0, x1, y1, color, width, type;
	printf("Masukkan x0 = "); scanf("%d", &x0);
	printf("Masukkan y0 = "); scanf("%d", &y0);
	printf("Masukkan x1 = "); scanf("%d", &x1);
	printf("Masukkan y1 = "); scanf("%d", &y1);
	printf("Pilih Color = "); scanf("%d", &color);
	if(color>15 || color <1){
		ulang:
		printf("\nHanya dapat memasukkan angka 1-15\n");
		printf("Pilih Color = "); scanf("%d", &color);
		if(color>15 || color <1) goto ulang;
	}
	drawline(x0, y0, x1, y1, color);
}

//MEMBUAT GARIS DENGAN ALGORITMA DDA
void drawline (int xa, int ya, int xb, int yb, int color){
	int dx = xb-xa,
		dy = yb-ya,
		steps, dk;
	float xIncrement, yIncrement,
		x = xa,
		y = ya;
	
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	
	xIncrement = dx / (float) steps;
	yIncrement = dy / (float) steps;
	
	putpixel(ROUND(x), ROUND(y), color);
	for(int k=0; k < steps; k++){
		x += xIncrement;
		y += yIncrement;
		putpixel(ROUND(x), ROUND(y), color);
	}
}

//TRANSFORMASI
void translation(int figure[], int edges, int dx, int dy){
	for (int i=0; i < edges; i++) {
		figure[2*i] += dx;
		figure[2*i+1] += dy;
	}
}

void scale(int figure[], int edges, int dx, int dy, int cx, int cy){
	for (int i=0; i < edges; i++) {
		figure[2*i] = (figure[2*i] - cx) * dx + cx;
		figure[2*i+1] = (figure[2*i+1] - cy) * dy + cy;
	}
}

void rotate(int x1, int y1, int *x2, int *y2, int angle){ 
   int Tx, Ty, rotX, rotY, rotX2, rotY2;
   
   Tx = *x2 - x1;
   Ty = *y2 - y1; 
   
   rotX = (Tx*COS(angle)) - (Ty*SIN(angle)) + x1;
   rotY = (Tx*SIN(angle)) + (Ty*COS(angle)) + y1;
   
   *x2 = rotX;
   *y2 = rotY; 
} 

void rotate_p(int *x1, int *y1, int x0, int y0, int angle){ 
   int Tx, Ty, rotX, rotY;
   
   Tx = *x1 - x0;
   Ty = *y1 - y0; 
   
   rotX = (Tx*COS(angle)) - (Ty*SIN(angle)) + x0;
   rotY = (Tx*SIN(angle)) + (Ty*COS(angle)) + y0;
   
   *x1 = rotX;
   *y1 = rotY; 
} 
