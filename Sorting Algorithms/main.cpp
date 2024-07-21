#include "header.h"
#include<iostream>
#include<graphics.h>
#include<vector>


main() {
	std::cout << "Welcome to Sorting Algorithm Visualizer!" << std::endl << std::endl;
	
	int n; int *inputArray;
	std::cout << "Enter the array size (<=12): ";
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
	
	std::cout << std::endl;
	std::cout << "Choose Algorithm: " << std::endl;
	std::cout << "\t" << "[1] Bubble Sort" << std::endl;
	std::cout << "\t" << "[2] Insertion Sort" << std::endl;
	std::cout << "\t" << "[3] Selection Sort" << std::endl;
	std::cout << "Enter Code: ";
	int code;
	std::cin >> code;
	
	initwindow(1200, 1000);
	
	
	std::vector<ArrayBox *> arr = drawArray(inputArray, n);
	delay(500);
	
	switch(code) {
		case 1: 
			bubbleSort(arr);
			break;
		case 2:
			insertionSort(arr);
			break;
		case 3:
			selectionSort(arr);
			break;
		default:
			std::cout << "Wrong code !" << std::endl;
			exit(1);
	}
	
	getch();
}
