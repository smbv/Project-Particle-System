#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetVerticalSync(true);
	
	int num = 1500;
	cycling = false;
	currentColor = 2;

	p.assign(num, Particle());
	currentMode = PARTICLE_MODE_ATTRACT;
	currentModeStr = "1 - PARTICLE_MODE_ATTRACT: attracts to mouse"; 

	resetParticles();
}

//--------------------------------------------------------------
void ofApp::resetParticles(){

	//these are the attraction points used in the fourth demo 
	attractPoints.clear();
	for(int i = 0; i < 4; i++){
		attractPoints.push_back( glm::vec3( ofMap(i, 0, 4, 100, ofGetWidth()-100) , ofRandom(100, ofGetHeight()-100) , 0) );
	}
	
	attractPointsWithMovement = attractPoints;
	cycling = false;

	for(unsigned int i = 0; i < p.size(); i++){
		p[i].setMode(currentMode);		
		p[i].setAttractPoints(&attractPointsWithMovement);
		p[i].reset();
	}	
}

//--------------------------------------------------------------
void ofApp::update(){

//plays recorded keys by going through the list
	counter1 += 1;
	if(replaying && counter1 > 120){
		keyPressed(recordKey[counter2] + 100);
		if(counter2 > recordKey.size()){
			replaying = false;
			counter2 = 0;
		}
		counter1 = 0;
		counter2 ++;
	}

	for(unsigned int i = 0; i < p.size(); i++){
		p[i].setMode(currentMode);
		p[i].setColor(cycling, currentColor);
		p[i].update(stop, halfSpeed, doubleSpeed);
	}
	
	//lets add a bit of movement to the attract points
	for(unsigned int i = 0; i < attractPointsWithMovement.size(); i++){
		attractPointsWithMovement[i].x = attractPoints[i].x + ofSignedNoise(i * 10, ofGetElapsedTimef() * 0.7) * 12.0;
		attractPointsWithMovement[i].y = attractPoints[i].y + ofSignedNoise(i * -10, ofGetElapsedTimef() * 0.7) * 12.0;
	}	
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor(60,60,60), ofColor(10,10,10));

	//*EXTRA* changed the position of where the mode is displayed
	ofDrawBitmapString(currentModeStr, 10,10);

	//*EXTRA* added a line with the command to open/close the menu
	ofDrawBitmapString("Press 'm' to open/close the menu", 10,30);

	//*EXTRA* displays and hides the button and mouse commands for a cleaner view of the particles
	if(menu == true){
		ofDrawBitmapString("\nSpacebar to reset. \nKeys 1-4 to change mode. \nPress 't' to change colors. \nPress 's' to stop particles. \nPress 'd' to double the speed. \nPress 'a' to halve the speed. \nPress 'r' to start/stop recording. \nPress 'p' to replay the recording. \nPress 'c' to cancel the replay. \nClick and drag the mouse to make a magnifying rectangle. \nRight click inside to remove it.", 10,30);
	}
	
	//displays program recording
	if(record){
        ofDrawBitmapString("Recording...", 10,200);
    }

	//display program replaying
	if(replaying){
        ofDrawBitmapString("Replaying...", 10,200);
    }

	for(unsigned int i = 0; i < p.size(); i++){
		if(p[i].pos.x > pointx1 && p[i].pos.y > pointy1 && p[i].pos.x < pointx2 && p[i].pos.y < pointy2){
			p[i].zoom(4);
		}
		else{
		p[i].draw();
		}
	}
	
	ofSetColor(190);
	if( currentMode == PARTICLE_MODE_NEAREST_POINTS ){
		for(unsigned int i = 0; i < attractPoints.size(); i++){
			ofNoFill();
			ofDrawCircle(attractPointsWithMovement[i], 10);
			ofFill();
			ofDrawCircle(attractPointsWithMovement[i], 4);
		}
	}

	ofSetColor(230);	
	// By making a menu and for aesthetic, this code below is moved above
	// ofDrawBitmapString(currentModeStr + "\n\nSpacebar to reset. \nKeys 1-4 to change mode.", 10, 20);

	ofNoFill();
	ofDrawRectangle(pointx1, pointy1, pointx2 - pointx1, pointy2 - pointy1);
	ofFill();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	//cancel replay key
	if(key == 'c'){
		replaying = false;
	}

	//makes every key inactive
	if(replaying && key < 'z' && key != 'p'){
		return;
	}
	
	//activates the replay key
	else if(replaying && key != 'p'){
		key -= 100;
	}

	//adds the recorded keys to the vector(list)
	if(record && key != 'r'){
        recordKey.push_back(key);
    }

	if( key == '1'){
		currentMode = PARTICLE_MODE_ATTRACT;
		currentModeStr = "1 - PARTICLE_MODE_ATTRACT: attracts to mouse"; 		
	}
	if( key == '2'){
		currentMode = PARTICLE_MODE_REPEL;
		currentModeStr = "2 - PARTICLE_MODE_REPEL: repels from mouse"; 				
	}
	if( key == '3'){
		currentMode = PARTICLE_MODE_NEAREST_POINTS;
		currentModeStr = "3 - PARTICLE_MODE_NEAREST_POINTS:"; 						
	}
	if( key == '4'){
		currentMode = PARTICLE_MODE_NOISE;
		currentModeStr = "4 - PARTICLE_MODE_NOISE: snow particle simulation"; 						
		resetParticles();
	}	
	if( key == ' ' ){
		resetParticles();
		currentColor = 2;
	}
	//key creation to enable color changing
	if(key == 't'){
		cycling = true;
		currentColor = (currentColor+1)%3;
	}
	//key creation to stop the particles
	if(key == 's'){
		stop = !stop;
	}
	//key creation to double velocity
	if(key == 'd'){
		doubleSpeed = !doubleSpeed;
	}
	//key creation to half velocity
	if(key == 'a'){
		halfSpeed = !halfSpeed;
	}
	//key creation to record
	if(key == 'r'){
        if(!record){
            recordKey.clear();
        }
        record = !record;
    }
	//key creation to replay
	if(key == 'p'){
		replaying =! replaying;
	}
	//*EXTRA* key creation to make a menu
	if(key == 'm'){
		menu = !menu;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
//starting points 
int ofApp::pointx1 = 0;
int ofApp::pointy1 = 0;

//dragging points 
int ofApp::pointx2 = 0;
int ofApp::pointy2 = 0;

//saves left-click position
int ofApp::mposx1 = 0;
int ofApp::mposy1 = 0;

void ofApp::mouseDragged(int x, int y, int button){
	if(button == 0){
		pointx2 = x;
		pointy2 = y;
	}
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if(button == 0){
		pointx1 = x;
		pointy1 = y;
		pointx2 = x;
		pointy2 = y;
	
	}

	else if(button == 2){
		mposx1 = x;
		mposy1 = y;
	
		if(mposx1 < pointx2 and mposx1 > pointx1 and mposy1 < pointy2 and mposy1 > pointy1){ //area inside the shape
			pointx1 = 0;
			pointy1 = 0;
			pointx2 = 0;
			pointy2 = 0;
		}
	}
	
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
