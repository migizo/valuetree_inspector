#pragma once

#include <JuceHeader.h>
#include <valuetree_inspector/valuetree_inspector.h>

#define USE_INSPECTOR_WINDOW 1 // 0: inspector component, 1: inspector window

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  : public juce::Component
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    bool keyPressed (const juce::KeyPress& key) override;

private:
    juce::UndoManager undoManager;
    juce::ValueTree valueTree;
    
#if USE_INSPECTOR_WINDOW
    ValueTreeInspector vtInspectorWindow;
#else
    ValueTreeInspectorComponent vtInspector;
#endif
    
    juce::TextButton addButton;
    juce::TextButton removeButton;
    
    //==============================================================================
    // Your private member variables go here...


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
