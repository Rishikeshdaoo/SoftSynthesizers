/*
  ==============================================================================

    SynthAudioSource.h
    Created: 18 Mar 2020 9:00:01pm
    Author:  Rishikesh Daoo

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "SynthSound.h"
#include "SynthVoice.h"

class SynthAudioSource : public AudioSource {

public:
    SynthAudioSource(MidiKeyboardState& keyState);

    void setUsingSineWaveSound();

    void prepareToPlay(int samplesPerBlockExpected, double sampleRate) override;

    void getNextAudioBlock(const AudioSourceChannelInfo& bufferToFill) override;

    void releaseResources() override;

private:
    MidiKeyboardState& m_keyboardState;
    Synthesiser m_synth;
};