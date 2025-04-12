/*
  ==============================================================================

    ValueTreeInspectorComponent.cpp
    Author:  migizo

  ==============================================================================
*/

#include <JuceHeader.h>
#include "ValueTreeInspectorComponent.h"

//==============================================================================
ValueTreeInspectorComponent::ValueTreeInspectorComponent(const juce::ValueTree& vt)
{
    addAndMakeVisible(treeView);
    treeView.setDefaultOpenness(true);
    treeView.setRootItem(new ValueTreeItem(vt));
    
    setSize(400, 400);
}

ValueTreeInspectorComponent::~ValueTreeInspectorComponent()
{
    treeView.setRootItem(nullptr);
}

void ValueTreeInspectorComponent::paint (juce::Graphics& g)
{
}

void ValueTreeInspectorComponent::resized()
{
    auto area = getLocalBounds();
    treeView.setBounds(area);
}
