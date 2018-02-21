#include "ofApp.h"
using namespace ofxCv;
using namespace cv;

//--------------------------------------------------------------
void ofApp::setup(){
	cam.setup(480,360);
}

//--------------------------------------------------------------
void ofApp::update(){
	cam.update();
	if(cam.isFrameNew()) {
		contourFinder.setMinAreaRadius(5);
		contourFinder.setMaxAreaRadius(500);
		contourFinder.setThreshold(75);
		contourFinder.findContours(cam);
		contourFinder.setFindHoles(false);
	}
	vector<ofPolyline> polylines = contourFinder.getPolylines();
	for(auto &polyline : polylines){
		//gets the points from each polyline
		vector<ofPoint> points = polyline.getVertices();
		for(auto &point: points){
			//log the x and y positions of each point along our polylines
			ofLog() << point.x << "," << point.y << endl;
		}
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	cam.draw(0, 0);
	contourFinder.draw();
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
