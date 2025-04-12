/*
  ==============================================================================

    PropertyItem.cpp
    Author:  migizo

  ==============================================================================
*/

#include "PropertyItem.h"

PropertyItem::PropertyItem(const juce::ValueTree& v, const juce::Identifier& ids)
: state(v)
, propId(ids)
{
    state.addListener(this);
}

PropertyItem::~PropertyItem()
{
    state.removeListener(this);
}

void PropertyItem::paintItem (juce::Graphics& g, int width, int height)
{
    g.setColour(juce::Colours::lightgrey);
    g.drawLine(0, height/2, 2, height/2);
    
    g.setColour(juce::Colours::lightgrey);
    g.setFont (15.0f);
    g.drawText (propId.toString() + " : " + state[propId].toString(),
                4, 0, width - 4, height,
                juce::Justification::centredLeft, true);
}
