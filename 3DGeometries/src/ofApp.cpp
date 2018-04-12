#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	mSphere.set(100,12);
	//be careful with IcoSphere subdivisions
	//numbers greater than 4 tend to slow down
	//computer dramatically!
	mIcoSphere.set(100,1);
	
	mPlane.set(100.0f, 100.0f,4,4);
	mCylinder.set(100.0f, 100.0f,4,4);
	mCone.set(100.0f, 100.0f,4,4);
	mBox.set(100.0f, 100.0f, 100.0f,4,4,4);
	
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofTranslate(100.0f, ofGetHeight()/2);
	//try other ofPolyRenderModes
	//ofPolyRenderMode::OF_MESH_WIREFRAME
	//ofPolyRenderMode::OF_MESH_FILL
	//ofPolyRenderMode::OF_MESH_POINTS
	
	mSphere.draw(ofPolyRenderMode::OF_MESH_FILL);
	ofTranslate(200.0f, 0.0f);
	mIcoSphere.draw(ofPolyRenderMode::OF_MESH_FILL);
	ofTranslate(200.0f, 0.0f);
	mPlane.draw(ofPolyRenderMode::OF_MESH_FILL);
	ofTranslate(200.0f, 0.0f);
	mCylinder.draw(ofPolyRenderMode::OF_MESH_FILL);
	ofTranslate(200.0f, 0.0f);
	mCone.draw(ofPolyRenderMode::OF_MESH_FILL);
	ofTranslate(200.0f, 0.0f);
	mBox.draw(ofPolyRenderMode::OF_MESH_FILL);

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
