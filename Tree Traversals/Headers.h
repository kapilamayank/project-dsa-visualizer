#ifndef HEADERS_H
#define HEADERS_H

#include<graphics.h>
#include<iostream>
#include<queue>
#include<vector>

extern int WINDOW_WIDTH;
extern int WINDOW_HEIGHT ;
extern int BG_COLOR ;
extern int BORDER_COLOR;   //nothing else can be this color
extern int r;
extern int nodeColor;
//int xOffset = 400;
//int yOffset = 100;


class TreeNode {
	public:
		int centerX;
		int centerY;
		int radius;  
		int color;
	public:
		std::string val;
		TreeNode *left;
		TreeNode *right;
		
		TreeNode (std::string val) ;
		TreeNode (std::string val, TreeNode *left, TreeNode *right) ;
		
		void renderCircle() ;
		
		void renderText() ;
		void renderTreeNode (int centerX, int centerY, int radius, int color) ;
		
		void changeColor (int newColor);
		void redrawNode () ;
		
		std::pair<int, int> getCenter () ;
		
		void connectChild (TreeNode *child) ;
};

class TextWindow {
	public:
		int font;
		int charsize;
		int x;  //the position of the text window
		int y;
		std::string innerText;
		
		TextWindow() ;
		
		TextWindow (int font, int charsize, std::string innerText) ;
		void displayText (std::string text) ;
		
		void addToText (std::string addThis) ;
};

// not a general line, but a line to connect the TreeNodes of a tree
class Line {
	int x1;
	int y1;
	int x2;
	int y2;
	
	public:
		Line() ;
		Line(int x1, int y1, int x2, int y2) ;
		
		void drawLine () ;
		
		void removeLine () ;
};

//helps renderTree()
TreeNode *helperToRenderTree(int i, int x, int y, int xOffset, int yOffset, std::vector<std::string> &Tree);

// this function will make it seem like the connecting lines are draw from the border instead of the center
// helps renderTree()
void fixRender (TreeNode *root) ; 

TreeNode* renderTree (std::vector<std::string> &Tree) ;

// takes input and forms the needed tree
std::vector<std::string> formTree() ;

void helperToPreOrderTraversal(TreeNode *root, TextWindow *text) ;
void preOrderTraversal(TreeNode *root);

void helperToInOrderTraversal(TreeNode *root, TextWindow *text) ;
void inOrderTraversal(TreeNode *root);

void helperToPostOrderTraversal(TreeNode *root, TextWindow *text);
void postOrderTraversal(TreeNode *root);

void helperToLevelOrderTraversal(TreeNode *root, TextWindow *text);
void levelOrderTraversal(TreeNode *root);
#endif
