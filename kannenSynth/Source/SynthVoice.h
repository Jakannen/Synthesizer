/*
  ==============================================================================

    SynthVoice.h
    Created: 1 Dec 2024 8:02:27pm
    Author:  Jack

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "SynthSound.h"

class SynthVoice : public juce::SynthesiserVoice {
public:

    bool canPlaySound(juce::SynthesiserSound* sound) override;
    void startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition) override;
    void stopNote(float velocity, bool allowTailOff) override;
    void controllerMoved(int controllerNumber, int newControllerValue) override;
    void pitchWheelMoved(int newPitchWheelValue) override;
    void prepareToPlay(double sampleRate, int samplesPerBlock, int outputChannels);
    void renderNextBlock(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples) override;
private:
    // Saw wave -> x / juce::MathConstants<float>::pi
    // Square wave -> x < 0.0f ? -1.0f : 1.0f
    // Sine wave -> std::sin(x)

    juce::ADSR adsr;
    juce::ADSR::Parameters adsrParams;
    juce::dsp::Oscillator<float> osc{ [](float x) { return std::sin(x); }, 200 };
    juce::dsp::Gain<float> gain;
    bool isPrepared = false;
};