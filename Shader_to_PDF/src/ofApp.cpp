#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
#ifdef TARGET_OPENGLES
	shader.load("shadersES2/shader");
#else
	if(ofIsGLProgrammableRenderer()){
		shader.load("shadersGL3/shader");
	}else{
		shader.load("shadersGL2/shader");
	}
#endif
	fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
}

//--------------------------------------------------------------
void ofApp::update(){
	
	
}

//--------------------------------------------------------------
void ofApp::draw(){
	//
	fbo.begin();
	ofSetColor(255);
	
	shader.begin();
	
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
	
	shader.end();
	fbo.end();
	
	ofPixels pix;
	fbo.getTexture().readToPixels(pix);
	ofImage img(pix);
	img.draw(0, 0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'r'){
		
		bRecording = !bRecording;
		if(bRecording){
			ofBeginSaveScreenAsPDF("test.pdf", true);
			ofLog() << "recording screen" << endl;
			ofSetFrameRate(16);
			
		}
		else {
			ofEndSaveScreenAsPDF();
			ofLog() << "ended screen to PDF" << endl;
			ofSetFrameRate(60);
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
