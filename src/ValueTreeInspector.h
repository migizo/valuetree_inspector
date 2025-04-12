/*
  ==============================================================================

    ValueTreeInspector.h
    Author:  migizo

  ==============================================================================
*/

#pragma once

#include <juce_gui_basics/juce_gui_basics.h>
#include "ValueTreeInspectorComponent.h"

//==============================================================================
//! ValueTreeの状態を別ウインドウで確認するためのクラス
class ValueTreeInspector
: public juce::DocumentWindow
{
public:
    ValueTreeInspector(const juce::ValueTree& vt)
    : juce::DocumentWindow("ValueTree Inspcetor", juce::Colours::black, juce::DocumentWindow::allButtons, true)
    {
        setUsingNativeTitleBar (true);
        setContentOwned (new ValueTreeInspectorComponent(vt), true);
        setResizable (true, true);

        setVisible(true);
    }

    ~ValueTreeInspector() override
    {
    }

private:
    // juce::DocumentWindow
    void closeButtonPressed() override { setVisible(false); }
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ValueTreeInspector)
};
