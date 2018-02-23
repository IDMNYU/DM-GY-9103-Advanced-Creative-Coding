#pragma once

#include "ofMain.h"

//a custom c++ class without inheritance
//see ofApp.cpp for MyCustomClass implementation
class MyCustomClass {
//public means all methods and members are accessible outside
//the class definition
public:
	MyCustomClass(string _name);//constructor
	~MyCustomClass();//destructor
	string name;
	void sayHello();
	int getId();
	void setId(int id);
//private means all methods and members are accessible
//from within the class only!
private:
	int prId;
};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);		
};
