/*
  ==============================================================================

    SynthAudioSource.cpp
    Created: 18 Mar 2020 9:00:01pm
    Author:  Rishikesh Daoo

  ==============================================================================
*/

#include "SynthAudioSource.h"
#include "SynthVoice.h"
#include "SynthSound.h"

SynthAudioSource::SynthAudioSource(MidiKeyboardState& keyState) : m_keyboardState (keyState)
        {
            for (auto i = 0; i < 4; ++i) {
                m_synth.addVoice(new SynthVoice());
            }

            m_synth.addSound (new SynthSound());
        }

void SynthAudioSource::setUsingSineWaveSound() {
    m_synth.clearSounds();
}

void SynthAudioSource::prepareToPlay(int samplesPerBlockExpected, double sampleRate) {
    m_synth.setCurrentPlaybackSampleRate(sampleRate);
}

void SynthAudioSource::releaseResources() {}

void SynthAudioSource::getNextAudioBlock(const AudioSourceChannelInfo &bufferToFill) {

    bufferToFill.clearActiveBufferRegion();

    MidiBuffer incomingMidi;
    m_keyboardState.processNextMidiBuffer(incomingMidi, bufferToFill.startSample, bufferToFill.numSamples, true);

    m_synth.renderNextBlock(*bufferToFill.buffer, incomingMidi, bufferToFill.startSample, bufferToFill.numSamples);
}