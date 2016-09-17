#pragma once

#include "ofMain.h"
#include "ofxRBD.h"

class ofApp : public ofBaseApp{

  public:
    void setup();
    void update();
    void draw();

    texturePlane plane;

    ofFbo stripe;
    int STRIPE_WIDTH = 512;
    int STRIPE_HEIGHT = 512;
    void setupStripe();

};
