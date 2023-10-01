#pragma once
#include "ofMain.h"

enum particleMode{
	PARTICLE_MODE_ATTRACT = 0,
	PARTICLE_MODE_REPEL,
	PARTICLE_MODE_NEAREST_POINTS,
	PARTICLE_MODE_NOISE
};

class Particle{

	public:
		Particle();

		void zoom(int num);
		void setMode(particleMode newMode);	
		void setAttractPoints( vector <glm::vec3> * attract );
		void attractToPoint(int, int);
		void repelFromPoint(int, int);
		void reset();
		void update(bool stop, bool halfSpeed, bool doubleSpeed);
		void draw();
		void keyPressed(int key);
		void setColor(bool cycling, int color);

		glm::vec3 pos;
		glm::vec3 vel;
		glm::vec3 frc;
		float drag; 
		float uniqueVal;
		float scale;
		bool stop;
		int currentColor;
		bool cycling; 
		particleMode mode;
		vector <glm::vec3> * attractPoints; 
};