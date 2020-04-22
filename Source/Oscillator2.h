/*
  ==============================================================================

    Oscillator2.h
    Created: 15 Feb 2020 9:30:02am
    Author:  Rishikesh Daoo

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/*
 */
class Oscillator2    : public Component
{
public:
    Oscillator2(JuceSynthFrameworkAudioProcessor&);
    ~Oscillator2();

    void paint (Graphics&) override;
    void resized() override;

private:
    ComboBox osc2Menu;
    Slider Blendslider;

    ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment> waveSelection2;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> blendVal;

    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    JuceSynthFrameworkAudioProcessor& processor;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Oscillator2)
};
