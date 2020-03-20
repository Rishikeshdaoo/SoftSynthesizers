/*
  ==============================================================================

    SynthSound.h
    Created: 17 Mar 2020 2:40:16pm
    Author:  Rishikesh Daoo

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class SynthSound : public SynthesiserSound {

public:
    SynthSound();

    bool appliesToNote(int) override;

    bool appliesToChannel(int) override;

};