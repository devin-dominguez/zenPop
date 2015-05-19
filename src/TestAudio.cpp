#include "TestAudio.h"


ofxOscSender TestAudio::oscOut;

void TestAudio::setup() {
	oscOut.setup("localhost", 6666);
	
	ofxOscBundle msgBundle;

	ofxOscMessage alertTime, bonusTime;

	alertTime.setAddress("/time/alert");
	alertTime.addFloatArg(Score::deathPenalty / Score::maxTime);
	msgBundle.addMessage(alertTime);

	bonusTime.setAddress("/time/bonus");
	bonusTime.addFloatArg(Score::bonusTime / Score::maxTime);
	msgBundle.addMessage(bonusTime);

	oscOut.sendBundle(msgBundle);

}

void TestAudio::gameplayUpdate() {
	ofxOscBundle msgBundle;
	
	ofxOscMessage timeLeft;
	timeLeft.setAddress("/time/remaining");
	timeLeft.addFloatArg(Score::timeLeft / Score::maxTime);
	msgBundle.addMessage(timeLeft);



	oscOut.sendBundle(msgBundle);

}
