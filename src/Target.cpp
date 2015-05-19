#include "Target.h"


int Target::numActive = 0;
int Target::numComplete = 0;

//--------------------------------------------------------------
Target::Target(int level, vector<Entity*> *bullets) {
	this->level = level;
	size = 8 * level;
	this->bullets = bullets;
	pos.x = ofRandom(padding + size, Field::w - padding - size);
	pos.y = ofRandom(padding + size, Field::h - padding - size);
	
	numBullet = level * 3;
	signalInit = size * 2.5;
	signalSize = signalInit;
	active = false;
	fade = 0;
}


//--------------------------------------------------------------
void Target::update(double dt) {
	if(fade < 1) {
		fade += dt * fadeInRate;
	}
	else {
		fade = 1;
	}
	
	if(active) {
		numActive++;
		
		if(fadeSig < 1) {
			fadeSig += dt * fadeInRate;
		}
		else {
			fadeSig = 1;
		}
	
	
		if(signalSize > size) {
			signalSize = fmax(size, signalSize - decayRate * dt);
		}
		else {

			for(int i = 0; i < numBullet; i++) {
				double angle = ((double)i / (double)numBullet) * M_PI * 2;
				ofVec2f bDir;
				bDir.set(cos(angle), sin(angle));
				bullets->push_back(new Bullet(pos + bDir * size, bDir));
			}
			dead = true;
			numComplete++;
			Score::addPoints(level);
			Score::addTime(fmin(.5, .0625 * level + .1));
		}
	}
}

//--------------------------------------------------------------
void Target::draw() {
	ofPushMatrix();
	ofPushStyle();
		ofTranslate(pos);
		ofNoFill();
		double alpha = 255 * fade;
		double alphaSig = 255 * fadeSig;
		ofSetColor(Colors::B, alpha);
		ofCircle(0, 0, size);



		if(!active) {
		
			ofSetColor(Colors::E, alpha);
			VectorText::drawCenter(ofToString(level), 0, 0, size * .5);

		}

		if(active) {
			ofSetColor(Colors::C, alphaSig);
			ofCircle(0, 0, signalSize);
			ofSetColor(.5 * alpha * (signalSize / signalInit) * (signalSize / signalInit));
			VectorText::drawCenter(ofToString(level), 0, 0, size * .5);
		}


	ofPopStyle();
	ofPopMatrix();
}

//--------------------------------------------------------------
void Target::killAllActive(vector<Entity*> &e) {
	int s = e.size();
	for(int i = 0; i < s; i++) {
		Target *target = dynamic_cast<Target*>(e[i]);
		if(target->active) {
			target->dead = true;
		}
	}
}


//--------------------------------------------------------------
void Target::collision() {
	if(!active) {
		active = true;
	}
}


//--------------------------------------------------------------
Target::~Target() {

}
