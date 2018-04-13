#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	mShader.load("shader");
	mImage.load("macrame_loungechair_cat.jpg");
	
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	if(mImage.isAllocated()){
		mShader.begin();
		ofClear(255, 255, 255);
		ofPushStyle();
		ofPushMatrix();
		//we pass in a time variable to shader for lerping
		mShader.setUniform1f("u_time", ofGetElapsedTimef());
		//we pass in a texture uniform so we can
		//manipulate that texture in the shader
		mShader.setUniformTexture("tex0", mImage.getTexture(), 1);
		//now we use the image's bounding rectangle
		//as a frame for our image
		mImage.draw(0,0);
		ofPopStyle();
		ofPopMatrix();
		mShader.end();
	}
	//this image is drawn outside our shader
	mImage.draw(ofGetMouseX(),ofGetMouseY(),mImage.getWidth(), mImage.getHeight());

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
