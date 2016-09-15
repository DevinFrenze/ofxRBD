#pragma once

#ifndef TEXTURE_PLANE
#define TEXTURE_PLANE

#include "ofMain.h"

class texturePlane {
  ofVec2f transformPoint(ofVec2f anchor, ofVec2f point);

  public:
    void setup();
    void setup(float w, float h, int d);
    void update();
    void draw();

    float width = 256;
    float height = 256;

    ofMesh plane;
    float rotate = 0;
    float scale = 1;
    ofVec2f offset = ofVec2f(0, 0);
    int dimensions = 2;
};

#endif
