/**
 ** VideoExampleSpeed by Kevin Siwoff
 ** @indefinit
**/

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	player.load("3.Mousetraps.mp4");
	player.play();
	buttonColor = ofColor(255, 255, 255, 255);
	ofSetRectMode(OF_RECTMODE_CENTER);
}

//--------------------------------------------------------------
void ofApp::update(){
	player.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	ofSetColor(255, 255, 255);
	if (player.isLoaded()) {
		//aspect ratio is the proportional relationship between width and height
		float aspectRatio = player.getWidth() / player.getHeight();
		ofPushMatrix();
		ofTranslate(-ofGetMouseX(), -ofGetMouseY());
		ofScale(zoomFactor,zoomFactor);
		if(player.isLoaded()){
		player.getTexture().drawSubsection(0, 0, ofGetHeight(), ofGetWidth(),ofGetMouseX(), ofGetMouseY(), ofGetWidth(), ofGetHeight());
		}
//		player.draw(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth(), ofGetWidth() / aspectRatio);
		ofPopMatrix();
	}
	//if the button color alpha is greater than 4
	//animate the button
	if(buttonColor.a >= 4){
		animatePlayPause();
	}
	
	ofSetColor(255, 0, 0, 255);
	ofFill();
	//draw our progress along the bottom of our screen
	ofDrawRectangle(0.0f, ofGetHeight() - 10.0f, player.getPosition() * ofGetWidth(), 10.0f);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	bool isPaused;
	switch (key) {
		case 'f':
			ofToggleFullscreen();
			break;
		case ' ':
			buttonColor.a = 255;
			//this is a ternary expression
			// if the player is paused, return false, otherwise return true
			isPaused = (player.isPaused()) ? false : true;
			player.setPaused(isPaused);
			break;
		case OF_KEY_LEFT:
			if (player.isPaused()) {
				player.previousFrame();
			}
			break;
		case OF_KEY_RIGHT:
			if (player.isPaused()) {
				player.nextFrame();
			}
			break;
		case '0':
			player.firstFrame();
			break;
		case OF_KEY_DOWN:
			if(zoomFactor >= 1.0f){
				zoomFactor -= 0.25f;
				
			}
			break;
		case OF_KEY_UP:
			if(zoomFactor >= 5.0f){
				zoomFactor = 1.0f;
				
			} else {
				zoomFactor += 0.25f;
			}
			break;
		default:
			break;
	}
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

//--------------------------------------------------------------
void ofApp::animatePlayPause(){
	ofSetColor(buttonColor);
	if(player.isPaused()){
		ofPushMatrix();
		ofFill();
		ofDrawRectangle(ofGetWidth()/2.0, ofGetHeight()/2.0, 10.0, 50.0);
		ofDrawRectangle(ofGetWidth()/2.0+25.0, ofGetHeight()/2.0, 10.0, 50.0);
		buttonColor.a-=4;
		ofPopMatrix();
	}
	else{
		ofPushMatrix();
		ofDrawTriangle(ofGetWidth()/2.0, ofGetHeight()/2.0, ofGetWidth()/2.0+50.0, ofGetHeight()/2.0+25.0, ofGetWidth()/2.0, ofGetHeight()/2.0+50.0);
		ofPopMatrix();
		buttonColor.a-=4;
	}
}
