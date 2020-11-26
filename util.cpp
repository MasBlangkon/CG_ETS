#include "util.h"

void header(){
	printf("===============ETS CG================\n");
	printf("======....Dibuat Oleh: FBS ....======\n\n");
}

void show_graph(int width, int height){	
	int size, page = 0, angle = 0, time = 0, wf, hf, scale=1, scale_up=1;
	int xcq1 = (width/2) + (width/4), ycq1 = (height/2) - (height/4), //Koordinat Tengah Kuadran 1
		xcq2 = width/2 + width/4, ycq2 = height/2 + height/4, //Koordinat Tengah Kuadran 2
		xcq3 = width/2 - width/4, ycq3 = height/2 + height/4, //Koordinat Tengah Kuadran 3
		xcq4 = width/2 - width/4, ycq4 = height/2 - height/4; //Koordinat Tengah Kuadran 4
	
	initwindow(width+10, height+15, "ETS CG 181511013", (1200-width)/2, 50);
	
	if(width==height){
		size=width;
		wf = -1;
		hf = -1;
	} else if(width<height){
		size=width;
		wf = -1;
		hf = 1;
	}else{
		size=height;
		wf = 1;
		hf = -1;
	}
		
	create_frame(1, 1, width, height, 1);
	delay(300);
	scandinavian_pattern(width/16+(wf*width/32), height/16+(hf*height/32), size/2-50, size/2-50);
	delay(300);
	japanese_crest(xcq1, ycq1+10, size/4, angle, YELLOW);
	delay(300);
	japanese_crest(xcq3, ycq3+10, size/4, angle, YELLOW);
	delay(300);
	scandinavian_pattern(width/2+width/16+(wf*width/32), height/2+height/16+(hf*height/32), size/2-50, size/2-50);
	
	delay(1000);
	cleardevice();
	
	while(1){
		setbkcolor(LIGHTGRAY);
		create_frame(1, 1, width, height, 0);
		
		if (angle >= 360){
			angle = 0;
		}
		
		if (scale <= 3 && scale_up){
			if (scale == 3){
				scale_up = 0;
			}
			scale++;
		} else if (scale==1){
			scale_up = 1;
		} else {
			scale--;
		}
		
		japanese_crest(xcq1, ycq1-height/8, width/8, angle, YELLOW);
		japanese_crest(xcq2, ycq2+height/8, width/8, angle, YELLOW);
		japanese_crest(xcq3, ycq3+height/8, width/8, angle, YELLOW);
		japanese_crest(xcq4, ycq4-height/8, width/8, angle, YELLOW);
		
		japanese_crest(xcq1+width/8, height/2, scale*width/32, angle, YELLOW);
		japanese_crest(xcq3-width/8, height/2, scale*width/32, angle, YELLOW);
	
		scandinavian_pattern(width/4+width/16+(wf*width/32), height/4+height/16+(hf*height/32), (size/2)-50, (size/2)-50);

		angle+=10;
		delay(300);
		setactivepage(page);        
		setvisualpage(1-page);
        page = 1 - page;
		cleardevice();
	}
	
	getch();
	closegraph();
}

void create_frame(int xstart, int ystart, int w, int h, int type){
	//MENYEBUTKAN KOORDINAT TITIK PADA SUDUT FRAME
	int x0 = w/2 + xstart, 	y0 = h/2 + ystart,	//TENGAH
		x1 = xstart, 		y1 = ystart, 		//KIRI ATAS 
		x2 = w + xstart, 	y2 = ystart, 		//KANAN ATAS
		x3 = w + xstart, 	y3 = h + ystart,	//KANAN BAWAH
		x4 = xstart, 		y4 = h + ystart;	//KIRI BAWAH

	//MENGGAMBAR FRAME
	drawline(x1, y1, x2, y2, RED);
	drawline(x2, y2, x3, y3, RED);
	drawline(x3, y3, x4, y4, RED);
	drawline(x4, y4, x1, y1, RED);
	
	if(type == 1){
		drawline(x0, y1, x0, y3, RED);
		drawline(x1, y0, x3, y0, RED);
	}
}

void filled_circle(int x0, int y0, int radius, int color){
	setfillstyle(SOLID_FILL, YELLOW);
	setcolor(YELLOW);
	circle(x0, y0, radius);
	//lingkaran(x0, y0, radius, 0, YELLOW);
	floodfill(x0, y0, YELLOW);
}

void scandinavian_pattern(int xstart, int ystart, int w, int h){
	int y = ystart;
	int idxy = 0;
	
	while(idxy < 4){
		int x = xstart; 
		int idxx = 0;
		
		while(idxx < 4){
			persegi(x+2, y, w/4-2, WHITE);
			drawline(x+w/8, y, x+w/8, (y+h/4)-2, DARKGRAY);
			if((idxx+idxy)%2 == 0){
				int color1 = BLUE, color2 = YELLOW;
				if(idxx%2==0){
					//setfillstyle(SOLID_FILL, YELLOW);
					lingkaran(x+w/16, y+h/16+h/8, w/100, 0, YELLOW);
					//floodfill(x+w/16, y+h/16, YELLOW);
					color1 = DARKGRAY;
					color2 = BLUE;
				}
				
				set_lingkaran(x+w/8+1, y+1, w/8-2, color1, 0);
				set_lingkaran(x+w/8+1, y+1, w/8-2, color2, 180);
			}else {
				set_lingkaran(x+w/8+3, y+1, w/8-2, RED, 90);
				set_lingkaran(x+w/8+1, y+1, w/8-2, DARKGRAY, 270);
				
				//if(idxx%2==1){
					//setfillstyle(SOLID_FILL, YELLOW);
					lingkaran(x+w/16, y+h/8, w/100, 0, WHITE);
					//floodfill(x+w/16, y+h/8, YELLOW);
				//}
			}
			x+=w/4;
			idxx++;
		}
		y+=h/4;
		idxy++;
	}
}


void japanese_crest(int centerX, int centerY, int radius, int start_angle, int color) {
	int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6, x7, y7, x8, y8, x9, y9, x10, y10;
	int cur_x, cur_y, cur_x2, cur_y2, cur_x3, cur_y3, cur_x4, cur_y4, cur_x5, cur_y5;
	int xk1, yk1, xk2, yk2, cur_xk, cur_yk;
	
	filled_circle(centerX, centerY, radius/8, YELLOW);
	
	cur_x = centerX;
	cur_y = centerY-radius; 
	for(int count=1; count<=5; count++){
		if(count == 1) {
			rotate(centerX, centerY, &cur_x, &cur_y, start_angle);
			x1 = cur_x;
			y1 = cur_y;
		} 
		
		rotate(centerX, centerY, &cur_x, &cur_y, 360/5);
		x2 = cur_x;
		y2 = cur_y;
		
		drawline(x1, y1, x2, y2, color);	
		
		x1 = x2;
		y1 = y2;
	}
	
	cur_xk = centerX; 	cur_yk = centerY-radius+radius*5/8; 
	cur_x = centerX; 	cur_y = centerY-radius+radius/7; 
	cur_x2 = centerX; 	cur_y2 = centerY-radius+radius*7/8; 
	cur_x3 = centerX; 	cur_y3 = centerY-radius+radius*3/8;	
	cur_x4 = centerX; 	cur_y4 = centerY-radius+radius/2;
	cur_x5 = centerX; 	cur_y5 = centerY-radius+radius/4;
		
	for(int count=1; count<=20; count++){
		if(count == 1) {
			rotate(centerX, centerY, &cur_x, &cur_y, start_angle-9);
			x1 = cur_x;
			y1 = cur_y;
			
			rotate(centerX, centerY, &cur_x2, &cur_y2, start_angle-27);
			x3 = cur_x2;
			y3 = cur_y2;
			
			rotate(centerX, centerY, &cur_x3, &cur_y3, start_angle-18);
			x5 = cur_x3;
			y5 = cur_y3;
			
			rotate(centerX, centerY, &cur_x4, &cur_y4, start_angle-9);
			x7 = cur_x4;
			y7 = cur_y2;
			
			rotate(centerX, centerY, &cur_x5, &cur_y5, start_angle-9);
			x9 = cur_x3;
			y9 = cur_y3;
			
			rotate(centerX, centerY, &cur_xk, &cur_yk, start_angle-18);
			xk1 = cur_xk;
			yk1 = cur_yk;
		} 
		
		rotate(centerX, centerY, &cur_xk, &cur_yk, 360/20);
		xk2 = cur_xk; yk2 = cur_yk;
		
		rotate(centerX, centerY, &cur_x, &cur_y, 360/20);
		x2 = cur_x; y2 = cur_y;
		
		rotate(centerX, centerY, &cur_x2, &cur_y2, 360/20);
		rotate(centerX, centerY, &cur_x3, &cur_y3, 360/20);
		x4 = cur_x2; y4 = cur_y2;
		x6 = cur_x3; y6 = cur_y3;
		
		rotate(centerX, centerY, &cur_x4, &cur_y4, 360/20);
		rotate(centerX, centerY, &cur_x5, &cur_y5, 360/20);
		x8 = cur_x4;  y8 = cur_y4;
		x10 = cur_x5; y10 = cur_y5;
			
		if (count%4==1){
			drawline(x4, y4, x1, y1, YELLOW);
			drawline(x4, y4, x2, y2, YELLOW);
			drawline(x6, y6, x1, y1, YELLOW);
			drawline(x6, y6, x2, y2, YELLOW);
		} else if (count%4==3){
			drawline(x4, y4, x7, y7, YELLOW);
			drawline(x4, y4, x8, y8, YELLOW);
			drawline(xk2, yk2, x7, y7, YELLOW);
			drawline(xk2, yk2, x8, y8, YELLOW);
		} else {
			drawline(x4, y4, x9, y9, YELLOW);
			drawline(x4, y4, x10, y10, YELLOW);
			drawline(x6, y6, x9, y9, YELLOW);
			drawline(x6, y6, x10, y10, YELLOW);
		}
		
		xk1 = xk2; yk1 = yk2;
		x1 = x2; y1 = y2;
		x3 = x4; y3 = y4;
		x5 = x6; y5 = y6;
		x7 = x8; y7 = y8;
		x9 = x10; y9 = y10;
	}
}
