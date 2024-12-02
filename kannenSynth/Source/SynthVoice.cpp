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
    // Set freq for oscillator
    osc.setFrequency(juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber));
    adsr.noteOn();
}

void SynthVoice::stopNote(float velocity, bool allowTailOff) {
    adsr.noteOff();
}

void SynthVoice::controllerMoved(int controllerNumber, int newControllerValue) {

}

void SynthVoice::pitchWheelMoved(int newPitchWheelValue) {

}

void SynthVoice::prepareToPlay(double sampleRate, int samplesPerBlock, int outputChannels) {

    adsr.setSampleRate(sampleRate);

    // Initialize Spec
    juce::dsp::ProcessSpec spec;
    spec.maximumBlockSize = samplesPerBlock;
    spec.sampleRate = sampleRate;
    spec.numChannels = outputChannels;
    // Init oscillator
    osc.prepare(spec);
    // Init gain
    gain.prepare(spec);

    // Prep gain (between 0 and 1)
    gain.setGainLinear(0.01f);

    isPrepared = true;
}

void SynthVoice::renderNextBlock(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples) {

    jassert(isPrepared);

    juce::dsp::AudioBlock<float> audioBlock{ outputBuffer };

    // Pass audio through the oscillator then through gain
    // Context replacing: result of process method overwrites audio buffer

    // Process audio through oscillator
    osc.process(juce::dsp::ProcessContextReplacing<float>(audioBlock));

    // Process audio through gain
    gain.process(juce::dsp::ProcessContextReplacing<float>(audioBlock));

    adsr.applyEnvelopeToBuffer(outputBuffer, startSample, numSamples);
}