#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofImage myImage;
	myImage.load("Jacksonstvshow.jpg");
	
	
	mImages.push_back(myImage);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(ofColor::bisque);
	ofPushMatrix();
	ofTranslate(ofGetWidth() /4, ofGetMouseY());
	float rotationAngle = ofMap(
								ofGetElapsedTimef(),
								0,
								20,
								0,
								360);
	ofRotateX(rotationAngle);
	
	for(auto image : mImages){
		
		image.draw(0,0);
	}
	
	
	ofPopMatrix();
	
	ofDrawRectangle(100,100,200,200);
	ofDrawBitmapString("This is really important text", 20,20);
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
