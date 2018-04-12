#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	mImage.load("Jacksonstvshow.jpg");
	mShader.load("stretcher");
	mPlane.set(mImage.getWidth(),mImage.getHeight(),10,10);
	mPlane.mapTexCoordsFromTexture(mImage.getTexture());
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(255);
	mImage.getTexture().bind();
	mShader.begin();
	ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
	mShader.setUniform2f("stretch", sin(ofDegToRad(ofGetFrameNum() * 0.10f)), cos(ofDegToRad(ofGetFrameNum() * 0.10f)));
	mPlane.draw();
	mShader.end();
	mImage.getTexture().unbind();
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
