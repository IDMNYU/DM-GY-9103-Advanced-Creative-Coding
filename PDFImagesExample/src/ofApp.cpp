#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	pdfRendering = false;
	ofBackground(225,225,225);
	ofSetVerticalSync(true);
	
	grabber.setup(ofGetWidth()/2, ofGetHeight()/2);
}

//--------------------------------------------------------------
void ofApp::update(){
	grabber.update();
	frame.setFromPixels(grabber.getPixels());
}

//--------------------------------------------------------------
void ofApp::draw(){
	
	ofSetRectMode(OF_RECTMODE_CENTER);
	//you need to draw the ofImage in order
	//for it to render in the PDF
	frame.draw(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth(), ofGetHeight());
	
	ofSetColor(54);
	if( pdfRendering ){
		
		ofDrawBitmapString("press r to stop pdf multipage rendering", 32, 92);
	}else{	
		ofDrawBitmapString("press r to start pdf multipage rendering", 32, 92);
		ofSetHexColor(0xffffff);
		
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


