/*
  ==============================================================================

    ValueTreeItem.cpp
    Author:  migizo

  ==============================================================================
*/

#include "ValueTreeItem.h"

ValueTreeItem::ValueTreeItem (const juce::ValueTree& v)
: state (v)
{
    state.addListener (this);
}

ValueTreeItem::~ValueTreeItem()
{
    state.removeListener(this);
}

bool ValueTreeItem::mightContainSubItems()
{
    return state.getNumChildren() > 0;
}

void ValueTreeItem::paintItem (juce::Graphics& g, int width, int height)
{
    g.setColour(juce::Colours::lightgrey);
    g.drawLine(0, height/2, 2, height/2);
    
    g.setColour(juce::Colours::lightgrey);
    g.setFont (15.0f);

    g.drawText (state.getType().toString(),
                4, 0, width - 4, height,
                juce::Justification::centredLeft, true);
}

void ValueTreeItem::itemOpennessChanged (bool isNowOpen)
{
    if (isNowOpen && getNumSubItems() == 0)
        refreshSubItems();
    else
        clearSubItems();
}

void ValueTreeItem::valueTreePropertyChanged (juce::ValueTree&vt, const juce::Identifier& ids)
{
    // propertiesの数が変わった場合のみ更新
    if (vt == state && lastNumProperties != state.getNumProperties())
    {
        treeChildrenChanged(state);
    }
}

void ValueTreeItem::refreshSubItems()
{
    clearSubItems();

    lastNumProperties = state.getNumProperties();
    for (int i = 0; i < lastNumProperties; ++i)
    {
        auto propName = state.getPropertyName(i);
        addSubItem (new PropertyItem(state, propName));
    }
    
    for (int i = 0; i < state.getNumChildren(); ++i)
        addSubItem (new ValueTreeItem (state.getChild (i)));
}

void ValueTreeItem::treeChildrenChanged (const juce::ValueTree& parentTree)
{
    if (parentTree == state)
    {
        refreshSubItems();
        treeHasChanged();
        setOpen (true);
    }
}
