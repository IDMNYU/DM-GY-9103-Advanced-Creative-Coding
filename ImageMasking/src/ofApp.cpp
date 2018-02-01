#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//first load our image
	img.load("Jacksonstvshow.jpg");
	
	
	//now we add lines to our path
	path.lineTo(ofGetWidth()/4, ofGetHeight());
	path.lineTo(ofGetWidth()/2, ofGetHeight()/ 2);
	path.lineTo(ofGetWidth(), 0);
	path.lineTo(0,0);
	
	//next we allocate memory to our fbo object
	fbo.allocate(img.getWidth(),img.getHeight());
	
	//next we begin our fbo and draw the path inside it
	fbo.begin();
	ofClear(255,255,255, 255);
	path.draw();
	fbo.end();
	
	//very important last step before we draw
	img.getTexture().setAlphaMask(fbo.getTexture());
	
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	img.draw(ofGetWidth()/4,0);
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
