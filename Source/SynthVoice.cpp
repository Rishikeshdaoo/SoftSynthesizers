/*
  ==============================================================================

    SynthVoice.cpp
    Created: 17 Mar 2020 2:30:58pm
    Author:  Rishikesh Daoo

  ==============================================================================
*/

#include "SynthVoice.h"

SynthVoice::SynthVoice(){}

SynthVoice::~SynthVoice() {}


bool SynthVoice::canPlaySound(SynthesiserSound *synthSound) {
    return dynamic_cast<SynthesiserSound*> (synthSound) != nullptr;
}

void SynthVoice::startNote(int midiNoteNumber, float velocity, SynthesiserSound* synthesiserSound, int currentPitchWheelPosition) {
    m_currentAngle = 0.f;
    m_level = velocity * 0.15;
    m_tailOff = 0.f;

    auto cyclesPerSecond = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
    auto cyclesPerSample = cyclesPerSecond / getSampleRate();

    m_angleDelta = cyclesPerSample * 2.0 * MathConstants<double>::pi;
}

void SynthVoice::stopNote(float velocity, bool allowTailOff) {
    if(allowTailOff){
        if(m_tailOff == 0.0){
            m_tailOff = 1.0;
        }
        else{
            clearCurrentNote();
            m_angleDelta = 0.0;
        }
    }
}

void SynthVoice::pitchWheelMoved (int)       {}
void SynthVoice::controllerMoved (int, int)  {}

void SynthVoice::renderNextBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples){
    if (m_angleDelta != 0.0){
        if (m_tailOff > 0.0)
        {
            while (--numSamples >= 0)
            {
                auto currentSample = (float) (std::sin (m_currentAngle) * m_level * m_tailOff);

                for (auto i = outputBuffer.getNumChannels(); --i >= 0;)
                    outputBuffer.addSample (i, startSample, currentSample);

                m_currentAngle += m_angleDelta;
                ++startSample;

                m_tailOff *= 0.99;

                if (m_tailOff <= 0.005){
                clearCurrentNote();

                m_angleDelta = 0.0;
                break;
                }
            }
        }
        else{
            while (--numSamples >= 0){
                auto currentSample = (float) (std::sin (m_currentAngle) * m_level);

                for (auto i = outputBuffer.getNumChannels(); --i >= 0;)
                outputBuffer.addSample (i, startSample, currentSample);

                m_currentAngle += m_angleDelta;
                ++startSample;
            }
        }
    }
}



