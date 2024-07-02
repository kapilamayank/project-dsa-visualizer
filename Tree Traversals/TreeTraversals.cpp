#include "Headers.h"
#include<queue>
//class TextWindow : to display the result of traversal	
TextWindow::TextWindow() {
	this->innerText = "";
	this->font = DEFAULT_FONT;
	this->charsize = 3;
	this->y = 700;
	this->x = 300;
}

TextWindow::TextWindow (int font, int charsize, std::string innerText) {
	this->font = font;
	this->charsize = charsize;
	this->innerText = innerText;
	this->y = WINDOW_HEIGHT-150;
	this->x = 250;
	
	displayText(this->innerText);
}

void TextWindow::displayText (std::string text) {
	this->innerText = text;
	char textConverted[text.length()+1];
	for (int i = 0; i < text.length(); i++){
		textConverted[i] = text[i];
	}
	textConverted[text.length()] = '\0';
	
	settextstyle(this->font, HORIZ_DIR, this->charsize);
	outtextxy(this->x, this->y, textConverted);
}

void TextWindow::addToText (std::string addThis) {
	this->innerText += addThis;
	
	displayText(this->innerText);
}

// class Line : to connect the TreeNodes during traversal

Line::Line() {
	
}
Line::Line(int x1, int y1, int x2, int y2) {
	this->x1 = x1+10;
	this->x2 = x2+10;
	this->y1 = y1+10;
	this->y2 = y2+10;
}

void Line::drawLine () {
	setlinestyle(CENTER_LINE, 0, THICK_WIDTH);
	setcolor(RED);
	line(x1, y1, x2, y2);
}

void Line::removeLine () {
	setlinestyle(CENTER_LINE, 0, THICK_WIDTH);
	setcolor(BLACK);
	line(x1, y1, x2, y2);
}

void helperToPreOrderTraversal (TreeNode *root, TextWindow *text) {
	if (root == NULL) {
		return;
	}
	
	Line *lineToLeft = NULL;
	Line *lineToRight = NULL;
	
	root->changeColor(CYAN);
	text->addToText(root->val);
	delay(1500);
	
	if (root->left){
		lineToLeft = new Line(root->centerX, root->centerY, root->left->centerX, root->left->centerY);
		delay(500);
		lineToLeft->drawLine();
	}
	
	helperToPreOrderTraversal (root->left, text);
	
	if (lineToLeft) {
		delay(250);
		lineToLeft->removeLine();
		root->redrawNode();
		root->left->redrawNode();
	}
	
	if (root->right) {
		lineToRight = new Line(root->centerX, root->centerY, root->right->centerX, root->right->centerY);
		delay(500);
		lineToRight->drawLine();
	}
	
	helperToPreOrderTraversal (root->right, text);
	
	if (lineToRight) {
		delay(250);
		lineToRight->removeLine();
		root->redrawNode();
		root->right->redrawNode();
	}
}

void preOrderTraversal (TreeNode *root) {
	TextWindow *text = new TextWindow();
	
	helperToPreOrderTraversal(root, text);
}

void helperToInOrderTraversal (TreeNode *root, TextWindow *text) {
	if (root == NULL) {
		return;
	}
	
	Line *lineToLeft = NULL;
	Line *lineToRight = NULL;
	
	if (root->left){
		lineToLeft = new Line(root->centerX, root->centerY, root->left->centerX, root->left->centerY);
		delay(500);
		lineToLeft->drawLine();
	}
	
	helperToInOrderTraversal (root->left, text);
	
	if (lineToLeft) {
		delay(250);
		lineToLeft->removeLine();
		root->redrawNode();
		root->left->redrawNode();
	}
	
	root->changeColor(CYAN);
	text->addToText(root->val);
	delay(1500);
	
	if (root->right) {
		lineToRight = new Line(root->centerX, root->centerY, root->right->centerX, root->right->centerY);
		delay(500);
		lineToRight->drawLine();
	}
	
	helperToInOrderTraversal (root->right, text);
	
	if (lineToRight) {
		delay(250);
		lineToRight->removeLine();
		root->redrawNode();
		root->right->redrawNode();
	}
}

void inOrderTraversal (TreeNode *root) {
	TextWindow *text = new TextWindow();
	
	helperToInOrderTraversal(root, text);
}

void helperToPostOrderTraversal (TreeNode *root, TextWindow *text) {
	if (root == NULL) {
		return;
	}
	
	Line *lineToLeft = NULL;
	Line *lineToRight = NULL;
	
	if (root->left){
		lineToLeft = new Line(root->centerX, root->centerY, root->left->centerX, root->left->centerY);
		delay(500);
		lineToLeft->drawLine();
	}
	
	helperToPostOrderTraversal (root->left, text);
	
	if (lineToLeft) {
		delay(250);
		lineToLeft->removeLine();
		root->redrawNode();
		root->left->redrawNode();
	}
	
	if (root->right) {
		lineToRight = new Line(root->centerX, root->centerY, root->right->centerX, root->right->centerY);
		delay(500);
		lineToRight->drawLine();
	}
	
	helperToPostOrderTraversal (root->right, text);
	
	if (lineToRight) {
		delay(250);
		lineToRight->removeLine();
		root->redrawNode();
		root->right->redrawNode();
	}
	
	root->changeColor(CYAN);
	text->addToText(root->val);
	delay(1500);
}

void postOrderTraversal (TreeNode *root) {
	TextWindow *text = new TextWindow();
	
	helperToPostOrderTraversal(root, text);
}

void levelOrderTraversal (TreeNode *root) {
	TextWindow *text = new TextWindow();
	
	helperToLevelOrderTraversal(root, text);
}

void helperToLevelOrderTraversal(TreeNode *root, TextWindow *text) {
	std::queue<TreeNode *> q;
	q.push(root);
	
	while(!q.empty()) {
		TreeNode *front = q.front();
		q.pop();
		
		delay(1000);
		front->changeColor(CYAN);
		text->addToText(front->val);
		
		if (front->left)  {
			delay(250);
			Line *lineToLeft = new Line (front->centerX, front->centerY, front->left->centerX, front->left->centerY);
			lineToLeft->drawLine();
			q.push(front->left);
		}
		if (front->right){
			delay(250);
			Line *lineToRight = new Line (front->centerX, front->centerY, front->right->centerX, front->right->centerY);
			lineToRight->drawLine();
			q.push(front->right);
		}
	}
}
