#include "texturePlane.h"

//--------------------------------------------------------------
void texturePlane::setup(float w, float h, int d){
  width = w;
  height = h;
  dimensions = d;
  setup();
}

//--------------------------------------------------------------
void texturePlane::setup(){
  for (float i = 0; i < dimensions; i++) {
    for (float j = 0; j < dimensions; j++) {
      plane.addVertex(
        ofVec3f(
          width * i / (dimensions - 1),
          height * j / (dimensions - 1),
          0
        )
      );

      // texture coordinates are updated in update method anyway
      plane.addTexCoord(ofVec2f(0,0));
    }
  }

  for (float i = 0; i < dimensions - 1; i++) {
    for (float j = 0; j < dimensions - 1; j++) {
      plane.addIndex(i * dimensions + j);
      plane.addIndex((i + 1) * dimensions + j);
      plane.addIndex(i * dimensions + j + 1);

      plane.addIndex((i + 1) * dimensions + j + 1);
      plane.addIndex((i + 1) * dimensions + j);
      plane.addIndex(i * dimensions + j + 1);
    }
  }
}

//--------------------------------------------------------------
void texturePlane::update(){
  ofVec2f anchor = ofVec2f(width / 2, height / 2);
  ofVec2f normal = ofVec2f(width, height);

  for (float i = 0; i < dimensions; i++) {
    for (float j = 0; j < dimensions; j++) {
      ofVec2f coord = ofVec2f(
        width * i / (dimensions - 1),
        height * j / (dimensions - 1)
      );

      coord = transformPoint(anchor, coord) / normal;

      plane.setTexCoord((i * dimensions) + j, coord);
    }
  }
}

//--------------------------------------------------------------
ofVec2f texturePlane::transformPoint(ofVec2f anchor, ofVec2f point){
  ofVec2f v = point - anchor;
  v *= scale;
  v = v.getRotated(rotate);
  return v + anchor + offset;
}

//--------------------------------------------------------------
void texturePlane::draw(){
  plane.draw();
}
