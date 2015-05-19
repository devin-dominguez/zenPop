#include "Bullet.h"

int Bullet::numComplete = 0;

//--------------------------------------------------------------
Bullet::Bullet(ofVec2f pos, ofVec2f dir) {
	this->pos = pos;
	this->dir = dir;
	size = 3;
	timeLeft = 1;
	dying = false;
}


//--------------------------------------------------------------
void Bullet::update(double dt) {
	pos += dir * speed * dt;
	
	if(!dying && 
	(pos.x < 0 ||
	pos.x > Field::w ||
	pos.y < 0 ||
	pos.y > Field::h) ) {
		
		kill();
	}

	if(dying) {
		if(timeLeft > 0) {
			timeLeft -= decayRate * dt;
			size *= fmax(0, timeLeft);
		}
		else {
			dead = true;
		}
	}
}

//--------------------------------------------------------------
void Bullet::draw() {
	ofPushMatrix();
	ofPushStyle();
		ofTranslate(pos);
		if(!dying) {
			ofNoFill();
			ofSetColor(Colors::D);
		}
		else {
			ofFill();
			ofSetColor(Colors::A);
		}
		ofCircle(0, 0, size);
	ofPopStyle();
	ofPopMatrix();
}

//--------------------------------------------------------------
void Bullet::kill() {
	if(!dying) {
		numComplete++;
		Score::addPoints(1);
		Score::addTime(.06666666666);
		dying = true;
	}
}
