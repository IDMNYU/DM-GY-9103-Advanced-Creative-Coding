#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetWindowShape(100, 100);
    
    eliza.load();
    eliza.start();
	//get Eliza's response and copy the value to a
	//new string variable
	string resp = eliza.getResponse();
	//escape all quotation marks
	findAndReplace(resp, "\'", "\\'");
	speak(resp);
}


void testApp::findAndReplace(string& source, string const& find, string const& replace)
{
	for(string::size_type i = 0; (i = source.find(find, i)) != string::npos;)
	{
		source.replace(i, find.length(), replace);
		i += replace.length();
	}
}

//--------------------------------------------------------------
void testApp::update(){
    
    string userSays;
    std::getline(std::cin, userSays);
    cout << eliza.ask(userSays);
	//get Eliza's response and copy the value to a
	//new string variable
	string resp = eliza.getResponse();
	//escape all quotation marks
	findAndReplace(resp, "\'", "\\'");
	speak(resp);
	
}

//--------------------------------------------------------------
void testApp::draw(){

}

void testApp::exit(){
    eliza.save();
}

void testApp::speak(string phrase){
	//system speak here
#ifdef TARGET_OSX
	string cmd = "say -v Alex " + phrase;   // create the command
	ofLog() << "exact sequence: " << phrase << endl;
	system(cmd.c_str());
#endif
#ifdef TARGET_WIN32
	string cmd = "data\\SayStatic.exe "+phrase;   // create the command
	cout << cmd << endl;
	system(cmd.c_str());
#endif
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
