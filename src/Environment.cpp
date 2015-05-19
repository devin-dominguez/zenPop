#include "Environment.h"

void Field::draw() {
	ofSetColor(Colors::A);
	ofNoFill();
	ofRect(x, y, w, h);
}



//--------------------------------------------------------------



ofColor Colors::A;		//red
ofColor Colors::B;		//blue
ofColor Colors::C;		//green
ofColor Colors::D;		//white
ofColor Colors::E;		//gray?
ofColor Colors::bg;		//black
ofColor Colors::flash;	//white

void Colors::setup() {
	A.set(255, 0, 64);
	B.set(0, 64, 255);
	C.set(64, 255, 0);
	D.set(255);
	E.set(48);
	bg.set(0);
	flash.set(255);
}



//--------------------------------------------------------------


int Score::score;
int Score::multi;
int Score::level;
double Score::timeLeft;
double Score::rate;
double Score::baseRate;
bool Score::blink = false;

void Score::init() {
	score = 0;
	timeLeft = bonusTime;
	rate = baseRate;
	level = 1;
	multi = 1;
	baseRate = 1.0;
}

void Score::update(double dt) {
	baseRate = 1.0 + ((level - 1) / 15.0);
	
	if(timeLeft > 0) {
		timeLeft -= baseRate * rate * dt;
		timeLeft = fmin(timeLeft, maxTime);
	}

	if(timeLeft > bonusTime) {
		multi = fmax(2.0, level * .5 + .5);
	}
	else {
		multi = 1;
	}

	blink = !blink;

}

void Score::deathStuff() {
	if(timeLeft > bonusTime) {
		timeLeft = bonusTime - deathPenalty;
	}
	else {
		timeLeft -= deathPenalty;
	}

}

void Score::addPoints(int p) {
	score += p * multi;
}

void Score::addTime(double t) {
	t /= rate;
	timeLeft += t;

}


void Score::draw() {
	double timeLeftY = -Field::h * timeLeft / maxTime;
	double timeBonusY = (1 - (bonusTime / maxTime)) * Field::h;
	double deathPenaltyY = (1 - (deathPenalty / maxTime)) * Field::h;
	ofPushStyle();
		ofFill();
		if( (timeLeft >= bonusTime) && blink) {
			ofSetColor(Colors::D);
		}
		else {
			ofSetColor(Colors::A);
		}
		ofRect(-10, Field::h, -20, timeLeftY); 
		
		ofSetColor(Colors::D);
		ofRect(-10, timeBonusY, -20, 1); 
		ofRect(-10, deathPenaltyY, -20, 1); 
		
		ofSetColor(Colors::D);
		ofNoFill();
		ofRect(-10, 0, -20, Field::h);
	ofPopStyle();




}
