#include "ofApp.h"

//Adapted from the Regular Expressions Example by @Kevin Siwoff

// we need to include the standard regex library
#include <regex>

// Some explanation on regular expressions
// http://gnosis.cx/publish/programming/regular_expressions.html

// more info 
// http://www.regular-expressions.info/reference.html



//--------------------------------------------------------------
void ofApp::setup() {
    ofBackground(250);
    page = 0;
	searchPhrase = "storage unit";
	searchGoogleImages(searchPhrase);
	searchPhrase.clear();//clear our search phrase so we can type a new phrase
	ofSetRectMode(OF_RECTMODE_CENTER);
}


//--------------------------------------------------------------
void ofApp::searchGoogleImages( string term ) {
    
    // clear old imges    
    images.clear();
    urls.clear();
    
    // create the google url string
	ofStringReplace(term, " ", "%20");
	ofLogNotice() << term << endl;
	
	string googleImgURL = "http://www.google.com/search?q="+term+"&tbm=isch&oq="+term+"&tbs=isz&&start="+ofToString(page);
	cout << "searching for " << googleImgURL << endl;
    
    ofHttpResponse res = ofLoadURL(googleImgURL);
	
    if(res.status > 0) {
		ofLogNotice() << "success response" << endl;
        // copy over the response date fromt the url load
        rawData = res.data.getText();
		//uncomment to see raw data response from google images
		//ofLogNotice() << rawData << endl;
		
		// We start our scrape by matching all content within the div#ires
        // want to get the content in the div using
        // a regular expression match and subgroup
		string imgResultsPattern = ".*\"ires\">(.*)<div id=\"foot\">.*";
		regex regEx(imgResultsPattern, std::regex::extended);
		smatch m;
		
		if( regex_match(rawData, m, regEx) ){
			//we want the second element in m because it contains our subgroup
			string imageResultsStr = m[1];
			smatch img;
			regex imgPattern("src=\"([^> | ^\"]*)\"");
			//once we've matched our outer content, we can
			//search for all of the image tags containg src attributes
			while(regex_search(imageResultsStr, img, imgPattern)){
				//push the image src onto our urls vector
				urls.push_back(img[1].str());
				//regex_search will return one result at a time. To iterate our regex_search
				//replace the string we are searching with the unsearched content
				imageResultsStr = img.suffix().str();
			}
		}
    }

    
    // load all the images
    for (unsigned int i=0; i<urls.size(); i++) {
        images.push_back(URLImage());
        images.back().url = urls[i];
        images.back().bDoneLoading = false;
    }
    
    
    // just clean up for rendering to screen
    ofStringReplace(rawData, "\n", "");
    ofStringReplace(rawData, " ", "");
    ofStringReplace(rawData, "\t", "");
    string str;
    for (unsigned int i=0; i<rawData.size(); i++) {
        str += rawData[i];
        if(i%40==39) str+="\n";
    }
    rawData = str.substr(0, 2000)+"...";
}

//--------------------------------------------------------------
void ofApp::update(){
    for(unsigned int i=0; i<images.size(); i++) {
        if(!images[i].bDoneLoading) {
            images[i].load(images[i].url);
            images[i].bDoneLoading = true;
            break;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
	//draw our search phrase in the top left corner
	ofDrawBitmapString(searchPhrase, 20.0f, 20.0f);
	//ofPushMatrix();
	
    // draw the images
	ofTranslate(ofGetWidth()*0.5f, ofGetHeight()*0.5f);
	ofScale(4.0);
    for(unsigned int i=0; i<images.size(); i++) {
        ofSetColor(255);
		//check that the image is done loading
		//so we don't draw an unallocated texture
		if(images[i].bDoneLoading){
			images[i].draw(0,0);
		}
    }
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	if(key == OF_KEY_DEL || key == OF_KEY_BACKSPACE){
		searchPhrase = searchPhrase.substr(0, searchPhrase.length()-1);
	}
	else if(key == OF_KEY_RETURN){
		page += 22;
		searchGoogleImages(searchPhrase);
		searchPhrase.clear();
	} else {
		//we append our key character to the string searchPhrase
		ofUTF8Append(searchPhrase,key);
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
