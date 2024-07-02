#include "Headers.h"
#include<graphics.h>
#include<iostream>
#include<vector>

int WINDOW_WIDTH = 1000;
int WINDOW_HEIGHT = 1000;
int BG_COLOR = BLACK;
int BORDER_COLOR = MAGENTA;   //nothing else can be this color
int r = 50;
int nodeColor = 1;
//int xOffset = 400;
//int yOffset = 100;

// class definitions V
		
TreeNode::TreeNode (std::string val) {
	this->val = val;
	this->right = NULL;
	this->left = NULL;
}
TreeNode::TreeNode (std::string val, TreeNode *left, TreeNode *right){
	this->val = val;
	this->left = left;
	this->right = right;
}

void TreeNode::renderCircle() {
	setfillstyle(SOLID_FILL, this->color);
	setcolor(BORDER_COLOR);
	circle(this->centerX, this->centerY, this->radius);
	floodfill(centerX, centerY, BORDER_COLOR);
}

void TreeNode::renderText() {
	char convertedString[this->val.length()+1];
	int i;
	for (i = 0; i < this->val.length(); i++) {
		convertedString[i] = this->val[i];
	}
	convertedString[i] = '\0';
	
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 5);
	setcolor(WHITE);
	outtextxy(this->centerX-20, this->centerY-20, convertedString);
}

void TreeNode::renderTreeNode (int centerX, int centerY, int radius, int color) {
	this->centerX = centerX;
	this->centerY = centerY;
	this->radius = radius;
	this->color = color;
	
	renderCircle();
	renderText();
}

void TreeNode::changeColor (int newColor) {
	this->color = newColor;
	
	setfillstyle(SOLID_FILL, newColor);
	setcolor(BORDER_COLOR);
	circle(this->centerX, this->centerY, this->radius);
	floodfill(this->centerX, this->centerY, BORDER_COLOR);
	
	renderText();
	
	/*
		the flood fill works in a weird way due to which we have to re-draw the circle
		after the fill, we re-render the inner text
	*/ 
}

void TreeNode::redrawNode () {
	changeColor (this->color);
}

std::pair<int, int> TreeNode::getCenter () {
	std::pair<int, int> p;
	p.first = centerX;
	p.second = centerY;
	return p;
}

void TreeNode::connectChild (TreeNode *child) {
	setfillstyle(SOLID_FILL, GREEN);
	setcolor(GREEN);
	line(this->centerX, this->centerY, child->getCenter().first, child->getCenter().second);  
}


//helps renderTree()
TreeNode *helperToRenderTree(int i, int x, int y, int xOffset, int yOffset, std::vector<std::string> &Tree){
	if (i >= Tree.size() || Tree[i] == "null"){
		return NULL;
	}
	
	TreeNode *node = new TreeNode(Tree[i]);
	node->renderTreeNode (x, y, r, nodeColor);
	
	xOffset = xOffset/2;
	node->left = helperToRenderTree(2*i+1, x-xOffset, y+yOffset, xOffset, yOffset, Tree);
	node->right = helperToRenderTree(2*i+2, x+xOffset, y+yOffset, xOffset, yOffset, Tree);
	
	if (node->left)     node->connectChild(node->left);
	if (node->right)    node->connectChild(node->right);
	
	return node;
}

// this function will make it seem like the connecting lines are draw from the border instead of the center
// helps renderTree()
void fixRender (TreeNode *root) {
	if (root == NULL) {
		return;
	}
	
	root->changeColor(root->color);
	fixRender(root->left);
	fixRender(root->right);
} 

TreeNode* renderTree (std::vector<std::string> &Tree){
	if (Tree.size() == 0) {
		return NULL;
	}
	
	int i = 0;
	int x = WINDOW_WIDTH/2;
	int y = 100;
	int xOffset = WINDOW_WIDTH/2;
	int yOffset = 100;
	
	TreeNode *root =helperToRenderTree(0, x, y, xOffset, yOffset, Tree);
	fixRender(root);
	return root;
}

// takes input and forms the needed tree
std::vector<std::string> formTree() {
	int size;
	std::cout << "ENTER TREE SIZE (LESS than 16 | inclusive of null nodes): ";   
	std::cin >> size;
	
	
	if (size > 15) {
		std::cout << "ERROR: Too many nodes... try again";
		exit(1);
	}
	
	
	std::vector<std::string> Tree(size);
	std::cout << "ENTER NODES: ";
	for (int i = 0; i < size; i++){
		std::cin >> Tree[i];
	}
	
	return Tree;
}



