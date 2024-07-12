#include<graphics.h>
#include<string>
#include<vector>
#include<algorithm>

int BOX_WIDTH = 75;
int BOX_HEIGHT = 75;

int SCREEN_WIDTH = 1200;
int SCREEN_HEIGHT = 1000;

std::string convertIntToString(int val){
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

class ArrayBox {
	public:
		int x;
		int y; // co-ordinates
		int width;
		int height;
		int color;
		int value;
		std::string content;
		
	ArrayBox(int x, int y, int w, int h, int val, int col=BLACK) {
		this->x = x; 
		this->y = y;
		this->width = w;
		this->height = h;
		
		this->value = val;
		this->content = convertIntToString(this->value);
		
		this->color = color;
	}
	
	void drawBox() {
		setcolor(WHITE);
		rectangle(this->x, this->y, this->x+this->width, this->y+this->height);
		
		settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
		char *textstring = convertStringToCharArray(this->content);
		outtextxy(this->x+10, this->y+BOX_HEIGHT/2-5, textstring);
	}
};

std::vector<ArrayBox *> drawArray(int *arr, int n){
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

main() {
	int *inputArray = new int [10];
	std::fill(inputArray, inputArray+10, 10);
	

	initwindow(1200, 1000);
	
	std::vector<ArrayBox *> arr = drawArray(inputArray, 10);
	
//	ArrayBox *box1 = new ArrayBox (200, 200, BOX_WIDTH, BOX_HEIGHT, 10);
//	box1->drawBox();
	
	getch();
}
