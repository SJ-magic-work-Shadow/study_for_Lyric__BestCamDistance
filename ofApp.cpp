/************************************************************
************************************************************/
#include "ofApp.h"

/************************************************************
************************************************************/

//--------------------------------------------------------------
void ofApp::setup(){
	/********************
	********************/
	ofSetWindowTitle( "CHECK CAM PARAM" );
	ofSetWindowShape( WIDTH, HEIGHT );
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofSetEscapeQuitsApp(false);

	/********************
	********************/
	gui.setup();
	
	{
		GG_Cam.setup("camera");
		
		{
			float _pos_max = 1000;
			
			ofVec3f PosMax = ofVec3f(_pos_max, _pos_max, _pos_max);
			ofVec3f PosMin = ofVec3f(-_pos_max, -_pos_max, -_pos_max);
			ofVec3f PosInit = ofVec3f(0, 0, 1000);
	
			GG_Cam.add(CamPosition.setup("pos", PosInit, PosMin, PosMax));
		}
		{
			float _pos_max = 1000;
			
			ofVec3f PosMax = ofVec3f(_pos_max, _pos_max, _pos_max);
			ofVec3f PosMin = ofVec3f(-_pos_max, -_pos_max, -_pos_max);
			ofVec3f PosInit = ofVec3f(0, 0, 0);

			GG_Cam.add(CamLookAt.setup("LookAt", PosInit, PosMin, PosMax));
		}
		{
			ofVec3f DirMax = ofVec3f(1, 1, 1);
			ofVec3f DirMin = ofVec3f(-1, -1, -1);
			ofVec3f DirInit = ofVec3f(0, 1, 0);
	
			GG_Cam.add(CamUpper.setup("Upper", DirInit, DirMin, DirMax));
		}
		{
			GG_Cam.add(CamAngle.setup("angle", 60, 10, 120));
		}
		
		gui.add(&GG_Cam);
	}

	/********************
	********************/
	img.load("check_surface.png");
	
	fbo.allocate(WIDTH, HEIGHT, GL_RGBA);
}

//--------------------------------------------------------------
void ofApp::update(){
	/********************
	********************/
	glDisable(GL_CULL_FACE);
	
	/********************
	********************/
	cam.setPosition(CamPosition);
	cam.lookAt( CamLookAt, CamUpper);
	cam.setFov(CamAngle);
	
	cam.setNearClip(1);
	cam.setFarClip(2000);

}

//--------------------------------------------------------------
void ofApp::draw(){
	/********************
	********************/
	fbo.begin();
	ofClear(0, 0, 0, 0);
	ofSetColor(255);
	img.draw(0, 0, ofGetWidth(), ofGetHeight());
	fbo.end();
	
	
	/********************
	********************/
	ofBackground(0);
	ofPushStyle();

	/********************
	Z-buffering and blemding mode do not work together properly in a simple way.
	(oF Essentials. p98)
	
	参考URL
		https://www.sjbaker.org/steve/omniv/alpha_sorting.html
	********************/
	// z buffering
	ofDisableAlphaBlending();
	ofEnableDepthTest();
	
	/*
	// Alpha
	ofEnableAlphaBlending();
	// ofEnableBlendMode(OF_BLENDMODE_ADD);
	ofEnableBlendMode(OF_BLENDMODE_ALPHA);
	*/
	
	/********************
	********************/
	ofSetColor(255);
	
	/********************
	ofVboにtexture貼って使用する場合 : ofVboにすれば、各頂点をDynamicに揺らすなどが可能になる
		https://github.com/SJ-magic-study-oF/study__study__Vbo_x_texture__ofCamera/blob/master/ofApp.cpp
	********************/
	// EasyCam.begin();
	cam.begin();
	
	fbo.setAnchorPercent(0.5, 0.5);
	fbo.draw(0, 0);
	
	cam.end();
	// EasyCam.end();
	
	ofPopStyle();
	
	ofDisableDepthTest();
	
	/********************
	********************/
	gui.draw();
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
