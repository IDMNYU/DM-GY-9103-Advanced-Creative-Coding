#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	bgVideo.load("Aurora_Police_Department_Recruitment_Video.mp4");
	videoPanel.load("presto-pizza-south-beach2_512kb.mp4");
	windows95.load("Windows_95_Launch-lAkuJXGldrM.mp4");
	ofSetRectMode(OF_RECTMODE_CENTER);
	//need to call play before we can update the videos and draw to screen
	bgVideo.play();
	videoPanel.play();
	windows95.play();
	
	//sets the name of our Window
	ofSetWindowTitle("Presto Pizza");
}

//--------------------------------------------------------------
void ofApp::update(){
	ofBackground(255, 255, 255);
	//remember to update your videos to next frame
	bgVideo.update();
	videoPanel.update();
	windows95.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	//if both videos are loaded, then draw
	if(bgVideo.isLoaded() && videoPanel.isLoaded()){
		//fmod() is a way of doing modulus with floating point numbers in C++
		if(fmod(ofGetElapsedTimeMillis() *0.125, 360.0) < 180.0){
			windows95.draw(ofGetWidth()/2, ofGetHeight()/2);
		} else {
			bgVideo.draw(ofGetWidth()/2, ofGetHeight()/2);
		}

		//isolate our translation matrix
		ofPushMatrix();
			ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
			ofRotateY(ofGetElapsedTimeMillis() *0.125);
			ofRotateX(15.0f);
			videoPanel.draw(0,0);
		ofPopMatrix();
	}

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
