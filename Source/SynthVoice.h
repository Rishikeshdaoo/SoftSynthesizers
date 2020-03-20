/*
  ==============================================================================

    SynthVoice.h
    Created: 17 Mar 2020 2:22:57pm
    Author:  Rishikesh Daoo

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class SynthVoice : public SynthesiserVoice {

public:
    SynthVoice();
    ~SynthVoice();

    bool canPlaySound(SynthesiserSound* synthSound) override;

    void startNote(int midiNoteNumber, float velocity, SynthesiserSound*, int currentPitchWheelPosition) override;

    void stopNote(float velocity, bool allowTailOff) override;

    void pitchWheelMoved (int) override;
    void controllerMoved (int, int) override;

    void renderNextBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples) override;

private:
    double  m_currentAngle = 0.0,
            m_angleDelta = 0.0,
            m_level = 0.0,
            m_tailOff = 0.0;
};