#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetWindowShape(400,400);
	angle = 0;
	oneShot = false;
	pdfRendering = false;

	ofBackground(225,225,225);
	ofSetVerticalSync(true);
	//load a custom font
	//the ttf file must be inside your bin/data directory
	font.load("frabk.ttf", 24, true, false, true);
}

//--------------------------------------------------------------
void ofApp::update(){
	angle++;
}

//--------------------------------------------------------------
void ofApp::draw(){
	if( oneShot ){
		ofBeginSaveScreenAsPDF("screenshot-"+ofGetTimestampString()+".pdf", false);
	}
	
	ofSetColor(54);
	if( pdfRendering ){
		ofDrawBitmapString("press r to stop pdf multipage rendering", 32, 92);
	}else{	
		ofDrawBitmapString("press r to start pdf multipage rendering\npress s to save a single screenshot as pdf to disk", 32, 92);
	}
		
		
	ofFill();		
	ofSetColor(54,54,54);
	ofDrawBitmapString("TTF Font embdedded into pdf as vector shapes", 32, 460);
	
	if( oneShot || pdfRendering ){
		//important if we want our font to draw
		//as a shape
		font.drawStringAsShapes("Current Frame: ",  32, 500);
		ofSetColor(245, 58, 135);
		font.drawStringAsShapes( ofToString(ofGetFrameNum()), 32 + font.getStringBoundingBox("Current Frame: ", 0, 0).width + 9, 500);
	}else{
		font.drawString("Current Frame: ",  32, 500);	
		ofSetColor(245, 58, 135);		
		font.drawString( ofToString(ofGetFrameNum()), 32 + font.getStringBoundingBox("Current Frame: ", 0, 0).width + 9, 500);		
	}
	
	
	ofSetColor(54,54,54);
	ofSetRectMode(OF_RECTMODE_CORNER);
	ofNoFill();


	//lets draw a box with a trail
	ofSetColor(245, 58, 135);
	
	ofRectangle boxBounds(32, 500, ofGetWidth()-32, 250);
	
	//lets get a noise value based on the current frame
	float noiseX = ofNoise(float(ofGetFrameNum())/600.f, 200.0f);
	float noiseY = ofNoise(float(ofGetFrameNum())/800.f, -900.0f);

	ofNoFill();
	ofBeginShape();
		//instead of using a for loop
		// we can pass a vector of ofPoints to our shape
		ofVertices(boxTrail);
	ofEndShape(false);
	
	ofFill();
	ofSetRectMode(OF_RECTMODE_CENTER);

	ofPushMatrix();
		float x = ofMap( noiseX, 0, 1, boxBounds.x, boxBounds.x + boxBounds.width, true);
		float y = ofMap( noiseY, 0, 1, boxBounds.y, boxBounds.y + boxBounds.height, true);

		ofTranslate(x, y, 0);
		ofRotate(angle);
		ofDrawRectangle(0, 0, 30, 30);
	ofPopMatrix();	
	
	if( boxTrail.size() == 0 || ( boxTrail.back() - ofPoint(x, y) ).length() > 1.5 ){
		boxTrail.push_back(ofPoint(x, y));
	}
	
	if(boxTrail.size() > 800 ){
		boxTrail.erase(boxTrail.begin(), boxTrail.begin()+1);
	}
	
	if( oneShot ){
		ofEndSaveScreenAsPDF();
		oneShot = false;
	}	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	
	if( key=='r'){
		pdfRendering = !pdfRendering;	
		if( pdfRendering ){
			ofSetFrameRate(12);  // so it doesn't generate tons of pages
			ofBeginSaveScreenAsPDF("recording-"+ofGetTimestampString()+".pdf", true);
		}else{
			ofSetFrameRate(60);
			ofEndSaveScreenAsPDF();		
		}
	}
	
	if( !pdfRendering && key == 's' ){
		oneShot = true;
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


