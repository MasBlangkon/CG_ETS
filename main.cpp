#include "util.h"

int main(int argc, char** argv)
{	
	int width, height;
	
	header();
	printf("Rekomendasi (Width = 700, Height = 700) atau (Width = 1000, Height = 700)\n\n");
	printf("Masukan width : ");
	scanf("%d", &width);
	printf("Masukan height : ");
	scanf("%d", &height);
	
	show_graph(width, height);
	
	return 0;
}
