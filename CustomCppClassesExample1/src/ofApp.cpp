#include "ofApp.h"

MyCustomClass::MyCustomClass(string _name){
	name = _name;
}

MyCustomClass::~MyCustomClass(){
	
	//in a destructor  you might want to clean up any
	//dynamic memory allocated
}

void MyCustomClass::sayHello(){
	ofLog() << "hello my name is: " << name << endl;
}

//--------------------------------------------------------------
void ofApp::setup(){
	//one way of initializing our custom class
	MyCustomClass myInstance("kevin");
	
	//uncomment these for other ways of initializing
	//	MyCustomClass myInstance = MyCustomClass("kevin");
	
	myInstance.sayHello();
	
	//this is a shared pointer.
	//shared pointers allocate memory on the Heap instead
	//of on the stack
	//	std::shared_ptr<MyCustomClass> pMyInstance = std::make_shared<MyCustomClass>("kevin");
	//	pMyInstance->sayHello();
	
	
	
	
	
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
