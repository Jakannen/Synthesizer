/*
  ==============================================================================

    SynthSound.h
    Created: 1 Dec 2024 8:03:11pm
    Author:  Jack

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>

class SynthSound : public juce::SynthesiserSound {
public:
    bool appliesToNote(int midiNoteNum) override {
        return true;
    }

    bool appliesToChannel(int midiChannel) override {
        return true;
    }

};