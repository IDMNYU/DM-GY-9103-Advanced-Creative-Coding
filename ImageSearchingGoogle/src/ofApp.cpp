#include "ofApp.h"

//Adapted from the Regular Expressions Example by @Kevin Siwoff

// we need to include the RegularExpression
// header file and say that we are using that
// name space
#include "Poco/RegularExpression.h"
using Poco::RegularExpression;

// Some explanation on regular expressions
// http://gnosis.cx/publish/programming/regular_expressions.html

// more info 
// http://www.regular-expressions.info/reference.html



//--------------------------------------------------------------
void ofApp::setup() {
    ofBackground(0);
    page = 0;
	searchPhrase = "storage unit";
	searchGoogleImages(searchPhrase);
	searchPhrase.clear();//clear our search phrase so we can type a new phrase
}


//--------------------------------------------------------------
void ofApp::searchGoogleImages( string term ) {
    
    // clear old imges    
    images.clear();
    urls.clear();
    
    // create the google url string
	ofStringReplace(term, " ", "%20");
	ofLogNotice() << term << endl;
	
	string googleImgURL = "http://www.google.com/search?q="+term+"&tbm=isch&sout=1&tbs=isz&&start="+ofToString(page);
    cout << "searching for " << googleImgURL << endl;
    
    ofHttpResponse res = ofLoadURL(googleImgURL);
    if(res.status > 0) {
        
        // copy over the response date fromt the url load
        rawData = res.data.getText();
        
        // first we want to get the search contents tag
        // in the webpage there is a table for all the images. we
        // want to get the content in the table using 
        // the <table> (.*?) </table> expression        
        RegularExpression regEx("<table class=\"images_table\" style=\"table-layout:fixed\" [^>]+>(.*?)</table>");
        RegularExpression::Match match;
        int found = regEx.match(rawData, match);
        
        
        // did we find the table tag with all the images
        // if so lets now start pulling out all the img tags
        if(found != 0) {
            
            // this is just the table content
            string contents = rawData.substr(match.offset, match.length);
            
            // setup the regex for img tags
            RegularExpression regEx("<img[^>]*src=\"([^\"]*)");
            RegularExpression::Match imgMatch;
            
            // now lets search for img tags in the content 
            // we keep search till we run out of img tags
            while(regEx.match(contents, imgMatch) != 0) {
                
                // we get the sub string from the content
                // and then trim the content so that we
                // can continue to search 
                string foundStr = contents.substr(imgMatch.offset, imgMatch.length);
                contents = contents.substr(imgMatch.offset + imgMatch.length);
                
                // setup the regex for src attribute in the img tag
                RegularExpression regImgEx("src=\"(.*?).$");
                RegularExpression::Match srcMatch;
                
                // if we found the src tag lets grab just
                // the url from the src attribute
                if (regImgEx.match(foundStr, srcMatch)!=0) {
                    
                    // save the img url
                    string url = foundStr.substr(srcMatch.offset+5, srcMatch.length);
                    urls.push_back(url);
                    
                }
                
            }
            // end while
            
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
	ofPushMatrix();
	
    // draw the images
    float x = 0;
    float y = 0;
    for(unsigned int i=0; i<images.size(); i++) {
        ofSetColor(255);
		ofTranslate(640+x, 20+y);
		ofRotateY(ofGetElapsedTimef());
        images[i].draw(0,0);
        
        y += images[i].getHeight()+2;
        if(y > ofGetHeight()-100) {
            y = 0;
            x += 200;
        }
    }
	ofPopMatrix();
    
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
		ofAppendUTF8(searchPhrase,key);
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
