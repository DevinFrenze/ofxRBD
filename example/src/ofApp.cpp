#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofDisableArbTex();
  plane.setup();
  plane.rotate = 45;
  plane.scale = 4;
  setupStripe();
}

//--------------------------------------------------------------
void ofApp::setupStripe(){ 
  stripe.allocate( STRIPE_WIDTH, STRIPE_HEIGHT, GL_RGB );
  stripe.begin();
    ofClear(255,255,255,0);
    ofSetColor(ofColor::white);
    ofDrawRectangle(0, 0, STRIPE_WIDTH, 0.5 * STRIPE_HEIGHT);
    ofSetColor(ofColor::black);
    ofDrawRectangle(0, 0.5 * STRIPE_HEIGHT, STRIPE_WIDTH, 0.5 * STRIPE_HEIGHT);
  stripe.end();
}

//--------------------------------------------------------------
void ofApp::update(){
  plane.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
  ofBackground(100);
  ofSetColor(255);
  ofTexture texture = stripe.getTexture();
  texture.setTextureWrap(GL_REPEAT, GL_REPEAT);
  texture.bind();

  plane.draw();

  texture.unbind();
}
