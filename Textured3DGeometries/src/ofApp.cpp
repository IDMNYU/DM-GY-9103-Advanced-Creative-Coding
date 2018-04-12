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
	
	mImage1.load("macrame_loungechair_cat.jpg");
	mImage2.load("https://vignette.wikia.nocookie.net/warriorcatsclanroleplay/images/f/fc/Placeholder-pet.png/revision/latest?cb=20130716185616");
	mShader.load("shader");
	
	mPlane.mapTexCoordsFromTexture(mImage1.getTexture());
	mSphere.mapTexCoordsFromTexture(mImage1.getTexture());
	mIcoSphere.mapTexCoordsFromTexture(mImage1.getTexture());
	mCylinder.mapTexCoordsFromTexture(mImage1.getTexture());
	mCone.mapTexCoordsFromTexture(mImage1.getTexture());
	mBox.mapTexCoordsFromTexture(mImage1.getTexture());
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
	mShader.begin();
	
	//we pass in a time variable to shader for lerping
	mShader.setUniform1f("u_time", ofGetElapsedTimef());
	mShader.setUniformTexture("tex0", mImage1.getTexture(), 1);
	mShader.setUniformTexture("tex1", mImage2.getTexture(), 2);
	
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
	mShader.end();

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
