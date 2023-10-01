#pragma once

#include "ofMain.h"
#include "Particle.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void resetParticles();

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

		particleMode currentMode;
		string currentModeStr;

		bool stop; //makes the particles stop in place
		bool halfSpeed; //halves the speed of the particles
		bool doubleSpeed; //increases the velocity of the particles
		bool cycling; //enables color changes
		bool record = false; //toggles(on/off) recordings
		int currentColor; //saves the color changes
		bool replaying = false; //toggles(on/off) replays
		bool menu = false; //*EXTRA* creates a menu with all the commands

		static int pointx1;
		static int pointy1;
		static int pointx2;
		static int pointy2;
		static int mposx1;
		static int mposy1;

		//replay counters
		int counter1 = 0;
		int counter2 = 0;
		
		vector <char> recordKey; //list that records characters used
		vector <Particle> p;
		vector <glm::vec3> attractPoints;
		vector <glm::vec3> attractPointsWithMovement;
};