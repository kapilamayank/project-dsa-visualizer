#include "header.h"
#include<vector>

void selectionSort(std::vector<ArrayBox *> arr) {
	int n = arr.size();
	
	for (int i = 0; i < n; i++) {
		int mini = i;	
		for (int j = i; j < n; j++) {
			arr[j]->highlightBox(YELLOW);
			delay(350);
			
			if (arr[j]->value < arr[mini]->value) {
				mini = j;
			}
			
			arr[j]->unHighlightBox();
		}
		
		arr[mini]->highlightBox(GREEN);
		delay(1000);
		
		int temp = arr[i]->value;
		arr[i]->value = arr[mini]->value;
		arr[mini]->value = temp;
		
		arr[i]->clearBox();
		arr[mini]->clearBox();
		arr[i]->drawBox();
		arr[mini]->drawBox();
		
		arr[i]->highlightBox(GREEN);
		
		if (i != mini) {
			arr[mini]->unHighlightBox();
			delay(1000);
		}
		else{
			delay(500);
		}
		
		arr[i]->colorBox(BLUE);
		
		delay(300);
	}	
}

void insertionSort(std::vector<ArrayBox *> arr) {
	int n = arr.size();
	
	//arr[0]->highlightBox(BLUE);
	
	for (int i=0; i < n; i++) {
		int j;
		for (j=i; j>0; j--) {
			arr[j]->highlightBox(GREEN);
			delay(500);
			if (arr[j]->value <= arr[j-1]->value) {
				
				int temp = arr[j-1]->value;
				arr[j-1]->value = arr[j]->value;
				arr[j]->value = temp;
				
				arr[j-1]->clearBox();
				arr[j]->clearBox();
				
				arr[j-1]->drawBox();
				arr[j]->drawBox();
				
				
				arr[j]->highlightBox(BLUE);
				arr[j-1]->highlightBox(GREEN);
				
				delay(500);
			}
			else {
				break;
			}
		}
		delay(250);
		arr[j]->highlightBox(BLUE);
		delay(250);
	}
}

void bubbleSort(std::vector<ArrayBox *> arr) {
	int n = arr.size();
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-1-i; j++) {
			arr[j]->highlightBox(YELLOW);
			arr[j+1]->highlightBox(YELLOW);
			delay(1000);
			if (arr[j]->value > arr[j+1]->value) {
				int temp = arr[j]->value;
				arr[j]->value = arr[j+1]->value;
				arr[j+1]->value = temp;
				
				arr[j]->clearBox();
				arr[j+1]->clearBox();
				
				arr[j]->drawBox();
				arr[j+1]->drawBox();
				
				arr[j]->highlightBox(GREEN);
				arr[j+1]->highlightBox(GREEN);
				delay(500);
			}
			else{
				arr[j]->highlightBox(RED);
				arr[j+1]->highlightBox(RED);
				delay(500);
			}
			
			arr[j]->unHighlightBox();
			arr[j+1]->unHighlightBox();
			delay(250);
		}
		
		arr[n-1-i]->colorBox(BLUE);
		delay(500);
	}
}
