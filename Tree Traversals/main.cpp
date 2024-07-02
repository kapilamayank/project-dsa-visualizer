#include "Headers.h"
#include<iostream>
main(){
	std::cout << " =================== WELCOME ================== " << std::endl;
	std::cout << " |                                             |" << std::endl;
	std::cout << " |       To Tree-Traversal DSA Visualizer      |" << std::endl;
	std::cout << " |                                             |" << std::endl;
	std::cout << " =============================================== " << std::endl << std::endl << std::endl;
	
	 
	std::vector<std::string> Tree = formTree();
	
	std::cout << "CHOOSE THE TYPE OF TRAVERSAL: \n\t--> Pre-Order Traversal  [0]\n\t--> In-Order Traversal   [1] \n\t--> Post-Order Traversal [2] \n\t--> Level-Order Traversal[3]" << std::endl;
	std::cout << "Your choice:  ";
	int choice;
	std::cin >> choice;
	
	std::cout << Tree.size();
	
	
	initwindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Window");
	
	TreeNode *root = renderTree(Tree);
	/*
	std::vector<std::string> Tree;
	Tree.push_back("1");
	Tree.push_back("2");
	TreeNode *root = renderTree(Tree);
	
	std::cout << root->centerX << " " << root->centerY << " " << root->radius << " " << root->color;
	
	*/
	
//	setfillstyle(SOLID_FILL, 4);
//	setcolor(WHITE);
//	circle(root->centerX, root->centerY, root->radius);
//	floodfill(root->centerX, root->centerY, BLACK);
	
	//root->changeColor(RED);
	
	delay(1000);
	switch (choice) {
		case 0:
			preOrderTraversal(root);
			break;
		case 1:
			inOrderTraversal(root);
			break;
		case 2:
			postOrderTraversal(root);
			break;
		case 3:
			levelOrderTraversal(root);
			break;
		default: 
			std::cout << "ERROR: Not a correct choice!" << std::endl;
	}
	
	
	getch();
}
