#pragma once

#include "ofxOsc.h"
#include "Environment.h"

class TestAudio {
	public:
		static void setup();
		static void gameplayUpdate();

	private:
		static ofxOscSender oscOut;

};
