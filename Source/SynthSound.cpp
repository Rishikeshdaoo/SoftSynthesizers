/*
  ==============================================================================

    SynthSound.cpp
    Created: 17 Mar 2020 2:40:30pm
    Author:  Rishikesh Daoo

  ==============================================================================
*/

#include "SynthSound.h"

SynthSound::SynthSound(){}

bool SynthSound::appliesToChannel(int) {
    return true;
}

bool SynthSound::appliesToNote(int) {
    return true;
}