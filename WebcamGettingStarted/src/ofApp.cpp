#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	mVidGrabber.setVerbose(true);
	mVidGrabber.setup(320,240);
}

//--------------------------------------------------------------
void ofApp::update(){
	mVidGrabber.update();
	if(mVidGrabber.isFrameNew()){
		ofLogNotice() << "frame new" << endl;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetHexColor(0xffffff);
	mVidGrabber.draw(ofGetWidth()/2 - mVidGrabber.getWidth()/2, ofGetHeight()/2 - mVidGrabber.getHeight()/2);
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
