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

    if (!allowTailOff || !adsr.isActive()) {
        clearCurrentNote();
    }
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

    adsrParams.attack = 0.8f;
    adsrParams.decay = 0.8f;
    adsrParams.sustain = 1.0f;
    adsrParams.release = 1.5f;
    adsr.setParameters(adsrParams);

    isPrepared = true;
}

void SynthVoice::renderNextBlock(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples) {

    jassert(isPrepared);

    if (!isVoiceActive()) {
        return;
    }

    juce::dsp::AudioBlock<float> audioBlock{ outputBuffer, (size_t)startSample };
    juce::dsp::ProcessContextReplacing<float> context(audioBlock);
    osc.process(context);
    gain.process(context);
    adsr.applyEnvelopeToBuffer(outputBuffer, startSample, numSamples);

    if (!adsr.isActive()) {
        clearCurrentNote();
    }

}