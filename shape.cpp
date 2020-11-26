#include "shape.h"

void create_persegi(){
	int x, y, s, color;
	printf("Rekomendasi Input (100, 100, 50, 1)\n");
	printf("Masukkan Sisi Kiri = "); scanf("%d", &x);
	printf("Masukkan Sisi Atas = "); scanf("%d", &y);
	printf("Masukkan Panjang Sisi = "); scanf("%d", &s);
	printf("Pilih Warna = "); scanf("%d", &color);
	if(color>15 || color <1){
		ulang:
		printf("\nHanya dapat memasukkan angka 1-15\n");
		printf("Pilih Warna = "); scanf("%d", &color);
		if(color>15 || color <1) goto ulang;
	}
	persegi(x, y, s, color);
}

void create_persegipanjang(){
	int x, y, p, l, color;
	printf("Rekomendasi Input (10, 100, 100, 75, 2)\n");
	printf("Masukkan Sisi Kiri = "); scanf("%d", &x);
	printf("Masukkan Sisi Atas = "); scanf("%d", &y);
	printf("Masukkan Panjang = "); scanf("%d", &p);
	printf("Masukkan Lebar = "); scanf("%d", &l);
	printf("Pilih Warna = "); scanf("%d", &color);
	if(color>15 || color <1){
		ulang:
		printf("\nHanya dapat memasukkan angka 1-15\n");
		printf("Pilih Warna = "); scanf("%d", &color);
		if(color>15 || color <1) goto ulang;
	}
	persegi_panjang(x, y, p, l, color);
}

void create_jajargenjang(){
	int x1, x2, y, p, l, color;
	printf("Rekomendasi Input (10, 150, 200, 100, 75, 3)\n");
	printf("Masukkan Sisi Kiri Atas = "); scanf("%d", &x1);
	printf("Masukkan Sisi Kiri Bawah = "); scanf("%d", &x2);
	printf("Masukkan Sisi Atas = "); scanf("%d", &y);
	printf("Masukkan Panjang = "); scanf("%d", &p);
	printf("Masukkan Lebar = "); scanf("%d", &l);
	printf("Pilih Warna = "); scanf("%d", &color);
	if(color>15 || color <1){
		ulang:
		printf("\nHanya dapat memasukkan angka 1-15\n");
		printf("Pilih Warna = "); scanf("%d", &color);
		if(color>15 || color <1) goto ulang;
	}
	jajar_genjang(x1, x2, y, p, l, color);
}

void create_trapesium(){
	int x1, x2, y, px1, px2, l, color;
	printf("Rekomendasi Input (10, 100, 100, 75, 100, 100, 4)\n");
	printf("Masukkan Sisi Kiri Atas = "); scanf("%d", &x1);
	printf("Masukkan Sisi Kiri Bawah = "); scanf("%d", &x2);
	printf("Masukkan Sisi Atas = "); scanf("%d", &y);
	printf("Masukkan Panjang Sisi Atas = "); scanf("%d", &px1);
	printf("Masukkan Panjang Sisi Bawah = "); scanf("%d", &px2);
	printf("Masukkan Lebar = "); scanf("%d", &l);
	printf("Pilih Warna = "); scanf("%d", &color);
	if(color>15 || color <1){
		ulang:
		printf("\nHanya dapat memasukkan angka 1-15\n");
		printf("Pilih Warna = "); scanf("%d", &color);
		if(color>15 || color <1) goto ulang;
	}
	trapesium(x1, x2, y, px1, px2, l, color);
}

void create_segitiga_siku(){
	int x, y, a, t, color;
	printf("Rekomendasi Input (50, 120, 100, 100, 5)\n");
	printf("Masukkan X0 Alas = "); scanf("%d", &x);
	printf("Masukkan Y0 Alas = "); scanf("%d", &y);
	printf("Masukkan Panjang Alas = "); scanf("%d", &a);
	printf("Masukkan Tinggi = "); scanf("%d", &t);
	printf("Pilih Warna = "); scanf("%d", &color);
	if(color>15 || color <1){
		ulang:
		printf("\nHanya dapat memasukkan angka 1-15\n");
		printf("Pilih Warna = "); scanf("%d", &color);
		if(color>15 || color <1) goto ulang;
	}
	segitiga_siku(x, y, t, a, color);
}

void create_segitiga_samasisi(){
	int x, y, a, color;
	printf("Rekomendasi Input (150, 400, 200, 3)\n");
	printf("Masukkan X0 Alas = "); scanf("%d", &x);
	printf("Masukkan Y0 Alas = "); scanf("%d", &y);
	printf("Masukkan Panjang Sisi = "); scanf("%d", &a);
	printf("Pilih Warna = "); scanf("%d", &color);
	if(color>15 || color <1){
		ulang:
		printf("\nHanya dapat memasukkan angka 1-15\n");
		printf("Pilih Warna = "); scanf("%d", &color);
		if(color>15 || color <1) goto ulang;
	}
	segitiga_samasisi(x, y, a, color);
}

void segitiga_samasisi(int x0alas, int y0alas, int panjangsisi, int warna){
	int tinggi = sqrt((panjangsisi * panjangsisi) - (1/4 * panjangsisi * panjangsisi));
	segitiga_siku(x0alas+(panjangsisi/2), y0alas, tinggi, panjangsisi, warna);
	segitiga_siku(x0alas-(panjangsisi/2), y0alas, tinggi, -panjangsisi, warna);
}

void rotated_segitiga_samasisi(int x0alas, int y0alas, int panjangsisi, int warna){
	int tinggi = sqrt((panjangsisi * panjangsisi) - (1/4 * panjangsisi * panjangsisi));
	segitiga_siku(x0alas+(panjangsisi/2), y0alas, tinggi, panjangsisi, warna);
	segitiga_siku(x0alas-(panjangsisi/2), y0alas, tinggi, -panjangsisi, warna);
}

void segitiga_siku(int x0alas, int y0alas, int tinggi, int panjangalas, int warna){
	if (panjangalas > 0){
		drawline(x0alas, y0alas-tinggi, x0alas+panjangalas, y0alas, warna);
		drawline(x0alas, y0alas-tinggi, x0alas, y0alas, warna);
		drawline(x0alas, y0alas, x0alas+panjangalas, y0alas, warna);
	} else {
		drawline(x0alas-panjangalas, y0alas-tinggi, x0alas-panjangalas, y0alas, warna);
		drawline(x0alas-panjangalas, y0alas-tinggi, x0alas, y0alas, warna);
		drawline(x0alas, y0alas, x0alas-panjangalas, y0alas, warna);
	}
}

void segitiga(int x0, int y0, int radius, int angle, int warna){
	int x1, x2, y1, y2;
	int cur_x, cur_y;
	
	cur_x = x0;
	cur_y = y0+radius; 
	
	for(int count=1; count<=3; count++){
		if(count == 1) {
			//initial point
			rotate(x0, y0, &cur_x, &cur_y, angle);
			x1 = cur_x;
			y1 = cur_y;
		} 
	
		rotate(x0, y0, &cur_x, &cur_y, 360/3);
		x2 = cur_x;
		y2 = cur_y;
		
		drawline(x1, y1, x2, y2, warna);	
		
		x1 = x2;
		y1 = y2;
	}
}

void persegi(int sisikiri, int sisiatas, int panjangsisi, int warna){
	drawline(sisikiri, sisiatas, sisikiri, sisiatas+panjangsisi, warna);
	drawline(sisikiri, sisiatas, sisikiri+panjangsisi, sisiatas, warna);
	drawline(sisikiri+panjangsisi, sisiatas, sisikiri+panjangsisi, sisiatas+panjangsisi, warna);
	drawline(sisikiri, sisiatas+panjangsisi, sisikiri+panjangsisi, sisiatas+panjangsisi, warna);
}

void persegi_panjang(int sisikiri, int sisiatas, int panjang, int lebar, int warna){
	drawline(sisikiri, sisiatas, sisikiri, sisiatas+lebar, warna);
	drawline(sisikiri, sisiatas, sisikiri+panjang, sisiatas, warna);
	drawline(sisikiri+panjang, sisiatas, sisikiri+panjang, sisiatas+lebar, warna);
	drawline(sisikiri, sisiatas+lebar, sisikiri+panjang, sisiatas+lebar, warna);
}

void jajar_genjang(int sisi_kiriatas, int sisi_kiribawah, int sisiatas, int panjang, int lebar, int warna){
	drawline(sisi_kiriatas, sisiatas, sisi_kiriatas+panjang, sisiatas, warna);
	drawline(sisi_kiriatas, sisiatas, sisi_kiribawah, sisiatas+lebar, warna);
	drawline(sisi_kiriatas+panjang, sisiatas, sisi_kiribawah+panjang, sisiatas+lebar, warna);
	drawline(sisi_kiribawah, sisiatas+lebar, sisi_kiribawah+panjang, sisiatas+lebar, warna);
}

void trapesium(int sisi_kiriatas, int sisi_kiribawah, int sisiatas, int panjangsisiatas, int panjangsisibawah, int lebar, int warna){
	drawline(sisi_kiriatas, sisiatas, sisi_kiriatas+panjangsisiatas, sisiatas, warna);
	drawline(sisi_kiriatas, sisiatas, sisi_kiribawah, sisiatas+lebar, warna);
	drawline(sisi_kiriatas+panjangsisiatas, sisiatas, sisi_kiribawah+panjangsisibawah, sisiatas+lebar, warna);
	drawline(sisi_kiribawah, sisiatas+lebar, sisi_kiribawah+panjangsisibawah, sisiatas+lebar, warna);
}

void lingkaran(int xCenter, int yCenter, int radius, int arc, int color){
	int x = 0;
	int y = radius;
	int p = 1 - radius;
	int curx, cury;
	
	while (x < y) {
	 	x++;
	 	if (p < 0){
	  		p += 2 * x + 1;
		}else { 
	   		y--;
	   		p += 2 * (x - y) + 1;
	  	}
	  	
		if(arc==1){
			fixedPlotPoints1(xCenter, yCenter, x, y, color);
	  	}else{
	  		circlePlotPoints(xCenter, yCenter, x, y, color);
	  	}
	}
}

void fixedPlotPoints1(int xCenter, int yCenter, int x, int y, int color){
 putpixel (xCenter + x, yCenter + y, (color==15 ? 15 : 7));
 putpixel (xCenter - x, yCenter + y, (color==15 ? 15 : 8));
}

void circlePlotPoints(int xCenter, int yCenter, int x, int y, int color)
{
 putpixel (xCenter + x, yCenter + y, 15);
 putpixel (xCenter - x, yCenter + y, (color==15 ? 15 : color));
 
 putpixel (xCenter + x, yCenter - y, (color==15 ? 15 : color));
 putpixel (xCenter - x, yCenter - y, (color==15 ? 15 : color));
 
 putpixel (xCenter + y, yCenter + x, (color==15 ? 15 : color));
 putpixel (xCenter - y, yCenter + x, (color==15 ? 15 : color));
 
 putpixel (xCenter + y, yCenter - x, (color==15 ? 15 : color));
 putpixel (xCenter - y, yCenter - x, (color==15 ? 15 : color));
}

void set_lingkaran(int xCenter, int yCenter, int radius, int color, int angle){
	int x = 0;
	int y = radius;
	int p = 1 - radius;
	int curx, cury;
	
	while (x < y) {
	 	x++;
	 	if (p < 0){
	  		p += 2 * x + 1;
		}else { 
	   		y--;
	   		p += 2 * (x - y) + 1;
	  	}
	  	
	  	semiCirclePlotPoints(xCenter, yCenter, x, y, color, angle, radius);
	}
}

void semiCirclePlotPoints(int xCenter, int yCenter, int x, int y, int color, int angle, int radius){
 int curx, cury;
 
 curx=xCenter+y; cury=yCenter+x;
 rotate_p(&curx, &cury, xCenter, yCenter+radius, angle);	
 putpixel (curx, cury, (color==15 ? 15 : color));
 
 curx=xCenter-y; cury=yCenter+x;
 rotate_p(&curx, &cury, xCenter, yCenter+radius, angle);	
 putpixel (curx, cury, (color==15 ? 15 : color));
 
 curx=xCenter+x; cury=yCenter+y;
 rotate_p(&curx, &cury, xCenter, yCenter+radius, angle);
 putpixel (curx, cury, (color==15 ? 15 : color));
 
 curx=xCenter-x; cury=yCenter+y;
 rotate_p(&curx, &cury, xCenter, yCenter+radius, angle);
 putpixel (curx, cury, (color==15 ? 15 : color));
}

void create_lingkaran(){
	int x0, y0, r;
	printf("Rekomendasi Input (100, 100, 50)\n");
	printf("Masukkan X0 = "); scanf("%d", &x0);
	printf("Masukkan Y0 = "); scanf("%d", &y0);
	printf("Masukkan Radius = "); scanf("%d", &r);
	lingkaran(x0, y0, r, 0, 0);
}

void ellips(int rx, int ry, int xc, int yc){ 
    float dx, dy, d1, d2, x, y; 
    x = 0; 
    y = ry; 
  
    d1 = (ry * ry) 
         - (rx * rx * ry) 
         + (0.25 * rx * rx); 
    dx = 2 * ry * ry * x; 
    dy = 2 * rx * rx * y; 
  
    while (dx < dy) { 
        putpixel(x + xc, y + yc, 1);
        putpixel(-x + xc, y + yc, 2);
        putpixel(x + xc, -y + yc, 3);
        putpixel(-x + xc, -y + yc, 4);
  
        if (d1 < 0) { 
            x++; 
            dx = dx + (2 * ry * ry); 
            d1 = d1 + dx + (ry * ry); 
        } 
        else { 
            x++; 
            y--; 
            dx = dx + (2 * ry * ry); 
            dy = dy - (2 * rx * rx); 
            d1 = d1 + dx - dy + (ry * ry); 
        } 
    } 
  
    d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) 
         + ((rx * rx) * ((y - 1) * (y - 1))) 
         - (rx * rx * ry * ry); 
  
    while (y >= 0) { 
      	putpixel(x + xc, y + yc, 5);
        putpixel(-x + xc, y + yc, 6);
        putpixel(x + xc, -y + yc, 7);
        putpixel(-x + xc, -y + yc, 8);
  
        if (d2 > 0) { 
            y--; 
            dy = dy - (2 * rx * rx); 
            d2 = d2 + (rx * rx) - dy; 
        } 
        else { 
            y--; 
            x++; 
            dx = dx + (2 * ry * ry); 
            dy = dy - (2 * rx * rx); 
            d2 = d2 + dx - dy + (rx * rx); 
        } 
    } 
} 

void create_ellips(){
	int x0, y0, rx, ry;
	printf("Rekomendasi Input (250, 250, 100, 150)\n");
	printf("Masukkan X0 = "); scanf("%d", &x0);
	printf("Masukkan Y0 = "); scanf("%d", &y0);
	printf("Masukkan Radius Major = "); scanf("%d", &ry);
	printf("Masukkan Radius Minor = "); scanf("%d", &rx);
	ellips(rx, ry, x0, y0);
}
