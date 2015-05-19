#include "VectorText.h"


map<char, vector<ofPoint> > VectorText::characters;
void VectorText::setup() {

	characters['0'].push_back(ofPoint( 1, -1));
	characters['0'].push_back(ofPoint( 1,  1));
	characters['0'].push_back(ofPoint(-1,  1));
	characters['0'].push_back(ofPoint(-1, -1));
	characters['0'].push_back(ofPoint( 1, -1));
	characters['0'].push_back(ofPoint(-1,  1));

	characters['1'].push_back(ofPoint( 0, -1));
	characters['1'].push_back(ofPoint( 0,  1));
	
	characters['2'].push_back(ofPoint(-1, -1));
	characters['2'].push_back(ofPoint( 1, -1));
	characters['2'].push_back(ofPoint( 1,  0));
	characters['2'].push_back(ofPoint(-1,  0));
	characters['2'].push_back(ofPoint(-1,  1));
	characters['2'].push_back(ofPoint( 1,  1));

	characters['3'].push_back(ofPoint(-1, -1));
	characters['3'].push_back(ofPoint( 1, -1));
	characters['3'].push_back(ofPoint( 1,  0));
	characters['3'].push_back(ofPoint( 0,  0));
	characters['3'].push_back(ofPoint( 1,  0));
	characters['3'].push_back(ofPoint( 1,  1));
	characters['3'].push_back(ofPoint(-1,  1));

	characters['4'].push_back(ofPoint(-1, -1));
	characters['4'].push_back(ofPoint(-1,  0));
	characters['4'].push_back(ofPoint( 1,  0));
	characters['4'].push_back(ofPoint( 1, -1));
	characters['4'].push_back(ofPoint( 1,  1));

	characters['5'].push_back(ofPoint( 1, -1));
	characters['5'].push_back(ofPoint(-1, -1));
	characters['5'].push_back(ofPoint(-1,  0));
	characters['5'].push_back(ofPoint( 1,  0));
	characters['5'].push_back(ofPoint( 1,  1));
	characters['5'].push_back(ofPoint(-1,  1));

	characters['6'].push_back(ofPoint( 1, -1));
	characters['6'].push_back(ofPoint(-1, -1));
	characters['6'].push_back(ofPoint(-1,  1));
	characters['6'].push_back(ofPoint( 1,  1));
	characters['6'].push_back(ofPoint( 1,  0));
	characters['6'].push_back(ofPoint(-1,  0));

	characters['7'].push_back(ofPoint(-1, -1));
	characters['7'].push_back(ofPoint( 1, -1));
	characters['7'].push_back(ofPoint( 0,  1));

	characters['8'].push_back(ofPoint(-1,  0));
	characters['8'].push_back(ofPoint( 1,  0));
	characters['8'].push_back(ofPoint( 1,  1));
	characters['8'].push_back(ofPoint(-1,  1));
	characters['8'].push_back(ofPoint(-1, -1));
	characters['8'].push_back(ofPoint( 1, -1));
	characters['8'].push_back(ofPoint( 1,  1));

	characters['9'].push_back(ofPoint( 1,  1));
	characters['9'].push_back(ofPoint( 1, -1));
	characters['9'].push_back(ofPoint(-1, -1));
	characters['9'].push_back(ofPoint(-1,  0));
	characters['9'].push_back(ofPoint( 1,  0));

	characters['A'].push_back(ofPoint(-1,  1));
	characters['A'].push_back(ofPoint(-1, -1));
	characters['A'].push_back(ofPoint( 1, -1));
	characters['A'].push_back(ofPoint( 1,  1));
	characters['A'].push_back(ofPoint( 1,  0));
	characters['A'].push_back(ofPoint(-1,  0));

	characters['B'].push_back(ofPoint(-1,  0));
	characters['B'].push_back(ofPoint( 1,  0));
	characters['B'].push_back(ofPoint( 0, -1));
	characters['B'].push_back(ofPoint(-1, -1));
	characters['B'].push_back(ofPoint(-1,  1));
	characters['B'].push_back(ofPoint( 1,  1));
	characters['B'].push_back(ofPoint( 1,  0));

	characters['C'].push_back(ofPoint( 1, -1));
	characters['C'].push_back(ofPoint(-1, -1));
	characters['C'].push_back(ofPoint(-1,  1));
	characters['C'].push_back(ofPoint( 1,  1));

	characters['D'].push_back(ofPoint( 1,  0));
	characters['D'].push_back(ofPoint( 1,  1));
	characters['D'].push_back(ofPoint(-1,  1));
	characters['D'].push_back(ofPoint(-1, -1));
	characters['D'].push_back(ofPoint( 0, -1));
	characters['D'].push_back(ofPoint( 1,  0));

	characters['E'].push_back(ofPoint( 1, -1));
	characters['E'].push_back(ofPoint(-1, -1));
	characters['E'].push_back(ofPoint(-1,  0));
	characters['E'].push_back(ofPoint( 0,  0));
	characters['E'].push_back(ofPoint(-1,  0));
	characters['E'].push_back(ofPoint(-1,  1));
	characters['E'].push_back(ofPoint( 1,  1));

	characters['F'].push_back(ofPoint( 1, -1));
	characters['F'].push_back(ofPoint(-1, -1));
	characters['F'].push_back(ofPoint(-1,  0));
	characters['F'].push_back(ofPoint( 0,  0));
	characters['F'].push_back(ofPoint(-1,  0));
	characters['F'].push_back(ofPoint(-1,  1));

	characters['G'].push_back(ofPoint( 1, -1));
	characters['G'].push_back(ofPoint(-1, -1));
	characters['G'].push_back(ofPoint(-1,  1));
	characters['G'].push_back(ofPoint( 1,  1));
	characters['G'].push_back(ofPoint( 1,  0));
	characters['G'].push_back(ofPoint( 0,  0));
	
	characters['H'].push_back(ofPoint(-1, -1));
	characters['H'].push_back(ofPoint(-1,  1));
	characters['H'].push_back(ofPoint(-1,  0));
	characters['H'].push_back(ofPoint( 1,  0));
	characters['H'].push_back(ofPoint( 1, -1));
	characters['H'].push_back(ofPoint( 1,  1));

	characters['I'].push_back(ofPoint(-1, -1));
	characters['I'].push_back(ofPoint( 1, -1));
	characters['I'].push_back(ofPoint( 0, -1));
	characters['I'].push_back(ofPoint( 0,  1));
	characters['I'].push_back(ofPoint(-1,  1));
	characters['I'].push_back(ofPoint( 1,  1));

	characters['J'].push_back(ofPoint(-1, -1));
	characters['J'].push_back(ofPoint( 1, -1));
	characters['J'].push_back(ofPoint( 1,  1));
	characters['J'].push_back(ofPoint(-1,  1));
	characters['J'].push_back(ofPoint(-1,  0));

	characters['K'].push_back(ofPoint(-1, -1));
	characters['K'].push_back(ofPoint(-1,  1));
	characters['K'].push_back(ofPoint(-1,  0));
	characters['K'].push_back(ofPoint( 0,  0));
	characters['K'].push_back(ofPoint( 1, -1));
	characters['K'].push_back(ofPoint( 0,  0));
	characters['K'].push_back(ofPoint( 1,  1));

	characters['L'].push_back(ofPoint(-1, -1));
	characters['L'].push_back(ofPoint(-1,  1));
	characters['L'].push_back(ofPoint( 1,  1));
	
	characters['M'].push_back(ofPoint(-1,  1));
	characters['M'].push_back(ofPoint(-1, -1));
	characters['M'].push_back(ofPoint( 0,  0));
	characters['M'].push_back(ofPoint( 1, -1));
	characters['M'].push_back(ofPoint( 1,  1));
	
	characters['N'].push_back(ofPoint(-1,  1));
	characters['N'].push_back(ofPoint(-1, -1));
	characters['N'].push_back(ofPoint( 1,  1));
	characters['N'].push_back(ofPoint( 1, -1));

	characters['O'].push_back(ofPoint(-1, -1));
	characters['O'].push_back(ofPoint( 1, -1));
	characters['O'].push_back(ofPoint( 1,  1));
	characters['O'].push_back(ofPoint(-1,  1));
	characters['O'].push_back(ofPoint(-1, -1));

	characters['P'].push_back(ofPoint(-1,  1));
	characters['P'].push_back(ofPoint(-1, -1));
	characters['P'].push_back(ofPoint( 1, -1));
	characters['P'].push_back(ofPoint( 1,  0));
	characters['P'].push_back(ofPoint(-1,  0));

	characters['Q'].push_back(ofPoint( 0,  0));
	characters['Q'].push_back(ofPoint( 1,  1));
	characters['Q'].push_back(ofPoint(-1,  1));
	characters['Q'].push_back(ofPoint(-1, -1));
	characters['Q'].push_back(ofPoint( 1, -1));
	characters['Q'].push_back(ofPoint( 1,  1));

	characters['R'].push_back(ofPoint(-1,  1));
	characters['R'].push_back(ofPoint(-1, -1));
	characters['R'].push_back(ofPoint( 1, -1));
	characters['R'].push_back(ofPoint( 1,  0));
	characters['R'].push_back(ofPoint(-1,  0));
	characters['R'].push_back(ofPoint( 0,  0));
	characters['R'].push_back(ofPoint( 1,  1));

	characters['S'].push_back(ofPoint( 1, -1));
	characters['S'].push_back(ofPoint(-1, -1));
	characters['S'].push_back(ofPoint(-1,  0));
	characters['S'].push_back(ofPoint( 1,  0));
	characters['S'].push_back(ofPoint( 1,  1));
	characters['S'].push_back(ofPoint(-1,  1));

	characters['T'].push_back(ofPoint(-1, -1));
	characters['T'].push_back(ofPoint( 1, -1));
	characters['T'].push_back(ofPoint( 0, -1));
	characters['T'].push_back(ofPoint( 0,  1));

	characters['U'].push_back(ofPoint(-1, -1));
	characters['U'].push_back(ofPoint(-1,  1));
	characters['U'].push_back(ofPoint( 1,  1));
	characters['U'].push_back(ofPoint( 1, -1));

	characters['V'].push_back(ofPoint(-1, -1));
	characters['V'].push_back(ofPoint( 0,  1));
	characters['V'].push_back(ofPoint( 1, -1));

	characters['W'].push_back(ofPoint(-1, -1));
	characters['W'].push_back(ofPoint(-1,  1));
	characters['W'].push_back(ofPoint( 0,  0));
	characters['W'].push_back(ofPoint( 1,  1));
	characters['W'].push_back(ofPoint( 1, -1));

	characters['X'].push_back(ofPoint(-1, -1));
	characters['X'].push_back(ofPoint( 1,  1));
	characters['X'].push_back(ofPoint( 0,  0));
	characters['X'].push_back(ofPoint(-1,  1));
	characters['X'].push_back(ofPoint( 1, -1));

	characters['Y'].push_back(ofPoint(-1, -1));
	characters['Y'].push_back(ofPoint( 0,  0));
	characters['Y'].push_back(ofPoint( 0,  1));
	characters['Y'].push_back(ofPoint( 0,  0));
	characters['Y'].push_back(ofPoint( 1, -1));

	characters['Z'].push_back(ofPoint(-1, -1));
	characters['Z'].push_back(ofPoint( 1, -1));
	characters['Z'].push_back(ofPoint(-1,  1));
	characters['Z'].push_back(ofPoint( 1,  1));

	characters['-'].push_back(ofPoint(-1,  0));	
	characters['-'].push_back(ofPoint( 1,  0));	

	characters['_'].push_back(ofPoint(-1,  1));	
	characters['_'].push_back(ofPoint( 1,  1));	
	
	characters['a'] = characters['A'];
	characters['b'] = characters['B'];
	characters['c'] = characters['C'];
	characters['d'] = characters['D'];
	characters['e'] = characters['E'];
	characters['f'] = characters['F'];
	characters['g'] = characters['G'];
	characters['h'] = characters['H'];
	characters['i'] = characters['I'];
	characters['j'] = characters['J'];
	characters['k'] = characters['K'];
	characters['l'] = characters['L'];
	characters['m'] = characters['M'];
	characters['n'] = characters['N'];
	characters['o'] = characters['O'];
	characters['p'] = characters['P'];
	characters['q'] = characters['Q'];
	characters['r'] = characters['R'];
	characters['s'] = characters['S'];
	characters['t'] = characters['T'];
	characters['u'] = characters['U'];
	characters['v'] = characters['V'];
	characters['w'] = characters['W'];
	characters['x'] = characters['X'];
	characters['y'] = characters['J'];
	characters['z'] = characters['Z'];
}


void VectorText::drawChar(unsigned char c, int x, int y, double size) {
ofPushMatrix();
ofPushStyle();
	ofTranslate(x, y);
	ofScale(size, size);
	ofNoFill();
	ofBeginShape();
		int length = characters[c].size();
		for(int i = 0; i < length; i++) {
			ofVertex(characters[c][i]);
		}
	ofEndShape();
ofPopStyle();
ofPopMatrix();
}

void VectorText::drawCenter(string str, int x, int y, double size) {
	int l = str.length();
	double offset = (l - 1) * .5;
	offset *= size * 2;
	ofPushMatrix();
		ofTranslate(x - offset, y);
		for(int i = 0; i < l; i++) {
			drawChar(str[i], i * size * 2, y, size * .75);
		}
	ofPopMatrix();
}

void VectorText::drawLeft(string str, int x, int y, double size) {
	int l = str.length();
	ofPushMatrix();
		ofTranslate(x, y);
		for(int i = 0; i < l; i++) {
			drawChar(str[i], i * size * 2, y, size * .65);
		}
	ofPopMatrix();
}



