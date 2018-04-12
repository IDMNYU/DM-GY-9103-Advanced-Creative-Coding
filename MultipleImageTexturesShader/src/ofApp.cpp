#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	mShader.load("shader");
	mImage1.load("macrame_loungechair_cat.jpg");
	mImage2.load("https://vignette.wikia.nocookie.net/warriorcatsclanroleplay/images/f/fc/Placeholder-pet.png/revision/latest?cb=20130716185616");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	//we make sure both of our images have loaded and allocated data in their textures
	if(mImage1.isAllocated() && mImage2.isAllocated()){
		mShader.begin();
		ofClear(255, 255, 255);
		ofPushStyle();
		ofPushMatrix();
		//we pass in a time variable to shader for lerping
		mShader.setUniform1f("u_time", ofGetElapsedTimef());
		//we pass in a texture uniform so we can
		//manipulate that texture in the shader
		mShader.setUniformTexture("tex0", mImage1.getTexture(), 1);
		mShader.setUniformTexture("tex1", mImage2.getTexture(), 2);
		//now we use the image's bounding rectangle
		//as a frame for our image
		//we can replace this image draw call with a
		//geometry primitive
		mImage1.draw(0,0);
		ofPopStyle();
		ofPopMatrix();
		mShader.end();
	}
	//this image is drawn outside our shader
	mImage1.draw(ofGetMouseX(),ofGetMouseY(),mImage1.getWidth(), mImage1.getHeight());

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
