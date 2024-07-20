#include "header.h"

#include<graphics.h>
#include<string>
#include<vector>
#include<algorithm>

int BOX_WIDTH = 75;
int BOX_HEIGHT = 75;

int SCREEN_WIDTH = 1200;
int SCREEN_HEIGHT = 1000;

std::string convertIntToString(int val){
	if (val == 0)	return "0";
	
	std::string helperString = "";
	while(val > 0) {
		char endChar = val%10 + (int)'0';
		helperString += endChar;
		val = val/10;
	} 
	
	std::string returnString = "";
	
	for(int i = helperString.length()-1; i >= 0; i--) {
		returnString += helperString[i];
	}
	
	return returnString;
}

char *convertStringToCharArray(std::string str) {
	char *arr = new char[str.length()+1] ;
	
	int i;
	for (i = 0; i < str.length(); i++) {
		arr[i] = str[i];
	}
	
	arr[i] = '\0';
	return arr;
}


ArrayBox::ArrayBox(int x, int y, int w, int h, int val, int col=WHITE) {
	this->x = x; 
	this->y = y;
	this->width = w;
	this->height = h;
	
	this->value = val;
	this->content = convertIntToString(this->value);
	
	this->borderColor = col;
}

void ArrayBox::drawBoxOutline() {
	setcolor(this->borderColor);
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
	rectangle(this->x, this->y, this->x+this->width, this->y+this->height);
}

void ArrayBox::drawInnerText() {
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
	this->content = convertIntToString(this->value);
	char *textstring = convertStringToCharArray(this->content);
	outtextxy(this->x+10, this->y+BOX_HEIGHT/2-5, textstring);
}

void ArrayBox::drawBox() {
	drawBoxOutline();
	drawInnerText();
}

void ArrayBox::highlightBox(int color) {
	setcolor(color);
	rectangle(this->x, this->y, this->x+this->width, this->y+this->height);
}

void ArrayBox::unHighlightBox() {
	setcolor(this->borderColor);
	rectangle(this->x, this->y, this->x+this->width, this->y+this->height);
}

void ArrayBox::colorBox(int color) {
	this->borderColor = color;
	highlightBox(this->borderColor);
}

void ArrayBox::innerColorBox(int color) {
	this->drawBoxOutline();
	
	setfillstyle(SOLID_FILL, color);
	floodfill(this->x+5, this->y+5, this->borderColor);
	
	this->drawInnerText();
}

void ArrayBox::clearBox() {
	//this->drawBoxOutline();
	
	setfillstyle(SOLID_FILL, BLACK);
	bar(this->x+5, this->y+5, this->x+this->width-5, this->x+this->height-5);
}


std::vector<ArrayBox *> drawArray(int *arr, int n) {
	int totalWidthOfArray = (BOX_WIDTH) * n + 5 * (n-1); // padding of 5px
	int remainingScreen = SCREEN_WIDTH - totalWidthOfArray;
	
	int x = remainingScreen/2;
	int y = 400;
	
	std::vector<ArrayBox *> boxVector;
	for (int i=0; i<n; i++) {
		boxVector.push_back(new ArrayBox(x, y, BOX_WIDTH, BOX_HEIGHT, arr[i]));
		x = x + BOX_WIDTH + 5; // with padding
	}
	
	for (int i = 0; i < boxVector.size(); i++) {
		boxVector[i]->drawBox();
	}
	
	return boxVector;
}
