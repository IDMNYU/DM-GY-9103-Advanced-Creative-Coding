#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//first load our image
	img.load("Jacksonstvshow.jpg");
	
	
	//now we add lines to our path
	path.lineTo(ofGetWidth()/4, ofGetHeight());
	path.lineTo(ofGetWidth()/2, ofGetHeight()/ 2);
	path.lineTo(ofGetWidth(), 0);
	//path.lineTo(0,0);
	path.close();
	
	//next we allocate memory to our fbo object
	//notice how we use GL_RGBA as our last parameter.
	//this means that our fbo will have an ALPHA channel.
	//VERY IMPORTANT!
	fbo.allocate(img.getWidth(),img.getHeight(), GL_RGBA);
	
	//next we begin our fbo and draw the path inside it
	fbo.begin();
	//we call ofClear 0 because we want to start with a black mask
	ofClear(0,0,0,0);
	//then we set our path color to white because we will use the
	//white pixels to guide our mask
	ofSetColor(255, 255, 255, 255);
	path.draw();
	fbo.end();
	
	//very important last step before we draw
	//there are 3 steps happening at once here:
	// 1. we get the texture from our img
	// 2. we get the texture from our fbo, which is acting as our mask
	// 3. we set our alpha mask ON the image texture
	img.getTexture().setAlphaMask(fbo.getTexture());
	
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	//ofScale(0.5f, 0.5f);
	img.draw(ofGetWidth()/4,0);
	path.draw(ofGetMouseX(),ofGetMouseY());
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
