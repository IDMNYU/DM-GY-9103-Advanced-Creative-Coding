#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	receiver.setup(PORT);
	ofSetWindowTitle("Receiver App");
}

//--------------------------------------------------------------
void ofApp::update(){
	while(receiver.hasWaitingMessages()){
		ofxOscMessage m;
		if(receiver.getNextMessage(m)){
			if(m.getAddress() == "/accxyz"){
				
				auto x = m.getArgAsFloat(0);
				auto y = m.getArgAsFloat(1);
				auto z = m.getArgAsFloat(2);
				glm::vec3 point = glm::vec3(x,y,z);
				points.push_back(point);
			}
			
		}
		
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBeginShape();
	for(auto &point : points){
//		auto x = point.x  * 100.0;
//		auto y = point.y  * 100.0;
//		auto z = point.z * 100.0;
		ofVertex(point);
	}
	ofEndShape();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if(key == 'c'){
		
		points.clear();
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
