/*
  ==============================================================================

    SynthVoice.cpp
    Created: 1 Dec 2024 8:02:27pm
    Author:  Jack

  ==============================================================================
*/

#include "SynthVoice.h"

bool SynthVoice::canPlaySound(juce::SynthesiserSound* sound) {
    // Check that sound can be casted
    return dynamic_cast<juce::SynthesiserSound*>(sound) != nullptr;

}

void SynthVoice::startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition) {

}

void SynthVoice::stopNote(float velocity, bool allowTailOff) {

}

void SynthVoice::controllerMoved(int controllerNumber, int newControllerValue) {

}

void SynthVoice::pitchWheelMoved(int newPitchWheelValue) {

}

void SynthVoice::renderNextBlock(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples) {

}