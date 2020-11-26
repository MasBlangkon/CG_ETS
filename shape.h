#ifndef H_SHAPE
#define H_SHAPE
#include "util.h"

void persegi(int sisikiri, int sisiatas, int panjangsisi, int warna);
void persegi_panjang(int sisikiri, int sisiatas, int panjang, int lebar, int warna);
void jajar_genjang(int sisi_kiriatas, int sisi_kiribawah, int sisiatas, int panjang, int lebar, int warna);
void trapesium(int sisi_kiriatas, int sisi_kiribawah, int sisiatas, int panjangsisiatas, int panjangsisibawah, int lebar, int warna);
void segitiga_siku(int x0alas, int y0alas, int tinggi, int panjangalas, int warna);
void segitiga_samasisi(int x0alas, int y0alas, int panjangsisi, int warna);
void segitiga(int x0, int y0, int tinggi, int panjangalas, int warna);

void create_persegi();
void create_persegipanjang();
void create_jajargenjang();
void create_trapesium();
void create_segitiga();
void create_segitiga_samasisi();

void lingkaran(int xCenter, int yCenter, int radius, int arc, int color);
void circlePlotPoints(int xCenter, int yCenter, int x, int y, int color);
void fixedPlotPoints1(int xCenter, int yCenter, int x, int y, int color);

void set_lingkaran(int xCenter, int yCenter, int radius, int color, int angle);
void semiCirclePlotPoints(int xCenter, int yCenter, int x, int y, int color, int angle, int radius);

void ellips(int rx, int ry, int xc, int yc);

void create_lingkaran();
void create_ellips();

#endif
