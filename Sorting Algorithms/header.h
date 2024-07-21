#ifndef HEADER_H
#define HEADER_H

#include<string>
#include<vector>
#include<graphics.h>


extern int BOX_WIDTH;
extern int BOX_HEIGHT;

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;

std::string convertIntToString(int val);

char *convertStringToCharArray(std::string str) ;

class ArrayBox {
	public:
		int x;
		int y; // co-ordinates
		int width;
		int height;
		int borderColor;
		int value;
		std::string content;
		
	ArrayBox(int x, int y, int w, int h, int val, int col) ;
	void drawBoxOutline() ;
	void drawInnerText() ;
	void drawBox() ;
	
	void highlightBox(int color) ;
	void unHighlightBox();
	
	void colorBox(int color);
	void innerColorBox(int color);
	void clearBox();
};

std::vector<ArrayBox *> drawArray(int *arr, int n) ;

void selectionSort(std::vector<ArrayBox *> arr) ;
void insertionSort(std::vector<ArrayBox *> arr) ;
void bubbleSort(std::vector<ArrayBox *> arr);

#endif
