#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowTitle("Syphon Client Example");
	//setup our syphon client to receive texture output from a syphon server
	mClient.setup();
	//you must set the server name to match your server application
	mClient.setServerName("Syphon Server Output");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofPushStyle();
		ofSetColor(ofColor::hotPink);
		//this text will be overwritten by our syphon input
		//once we connect to a syphon server
		ofDrawBitmapString("waiting for syphon input...", ofGetWidth()/2.0 - 50.0f, ofGetHeight()/2.0, 0.0f);
	ofPopStyle();
	//draw the syphon input in its entirety
	mClient.draw(0.0f,0.0f);
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
