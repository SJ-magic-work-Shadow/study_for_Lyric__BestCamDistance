/************************************************************
description
	for Lyric app used with yourShadow(unity) = moCap demo app.
	
purpose
	check the optimum parameter(distance etc) of camera.
	
environment
	1280 x 720
	
	cam
		angle = 60 deg

result(best distance)
	623
************************************************************/
#pragma once

/************************************************************
************************************************************/
#include "ofMain.h"
#include "ofxGui.h"

/************************************************************
************************************************************/
class ofApp : public ofBaseApp{
private:
	/****************************************
	****************************************/
	enum{
		WIDTH = 1280,
		HEIGHT = 720,
	};
	
	/****************************************
	****************************************/
	ofEasyCam EasyCam;
	ofCamera cam;
	
	ofImage img;
	ofFbo fbo;
	
	/********************
	********************/
	ofxPanel gui;
	
	ofxGuiGroup GG_Cam;
	ofxVec3Slider CamPosition;
	ofxVec3Slider CamLookAt;
	ofxVec3Slider CamUpper;
	ofxFloatSlider CamAngle;
	
	
public:
	/****************************************
	****************************************/
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
		
};
