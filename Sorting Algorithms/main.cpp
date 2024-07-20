#include "header.h"
#include<iostream>
#include<graphics.h>
#include<vector>


main() {
	
	int n; int *inputArray;
	std::cout << "Enter the box size (<=12): ";
	std::cin >> n;
	
	if (n > 12) {
		std::cout << "Input too large!";
		exit(1);
	}
	
	inputArray = new int[n];
	std::cout << "Enter the array values: ";
	for (int i=0; i<n; i++){
		std::cin >> inputArray[i];
	}
	
	initwindow(1200, 1000);
	
	
	std::vector<ArrayBox *> arr = drawArray(inputArray, n);
	delay(500);
	bubbleSort(arr);
//	std::cout << arr[0]->value << std::endl;
	
	
	getch();
}
