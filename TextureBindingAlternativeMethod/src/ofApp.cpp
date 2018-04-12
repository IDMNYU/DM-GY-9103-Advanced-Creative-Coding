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
	ofDisableArbTex();
	ofLoadImage(mTex1, "macrame_loungechair_cat.jpg");
	ofLoadImage(mTex2, "https://vignette.wikia.nocookie.net/warriorcatsclanroleplay/images/f/fc/Placeholder-pet.png/revision/latest?cb=20130716185616");
	
	//this is a technique for determining the texture mapping
	mTex1.setTextureWrap(GL_REPEAT, GL_REPEAT);
	mTex1.setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
	
	mTex2.setTextureWrap(GL_REPEAT, GL_REPEAT);
	mTex2.setTextureMinMagFilter(GL_NEAREST, GL_NEAREST);
	
	
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
	
	//textures can bind to geometries
	//you must always unbind before binding again
	mTex1.bind();
	mSphere.draw(ofPolyRenderMode::OF_MESH_FILL);
	mTex1.unbind();
	
	ofTranslate(200.0f, 0.0f);
	mTex2.bind();
	mIcoSphere.draw(ofPolyRenderMode::OF_MESH_FILL);
	mTex2.unbind();
	ofTranslate(200.0f, 0.0f);
	
	mTex1.bind();
	mPlane.draw(ofPolyRenderMode::OF_MESH_FILL);
	mTex1.unbind();
	
	ofTranslate(200.0f, 0.0f);
	mTex2.bind();
	mCylinder.draw(ofPolyRenderMode::OF_MESH_FILL);
	mTex2.unbind();
	
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
