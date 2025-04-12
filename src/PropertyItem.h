/*
  ==============================================================================

    PropertyItem.h
    Author:  migizo

  ==============================================================================
*/

#pragma once
#include <juce_data_structures/juce_data_structures.h>
#include <juce_gui_basics/juce_gui_basics.h>

//==============================================================================
// ValueTreeItemを親に持ち、そのValueTreeのpropertyの内の一つを表すTreeViewItem
class PropertyItem final
: public juce::TreeViewItem
, private juce::ValueTree::Listener
{
public:
    PropertyItem(const juce::ValueTree& v, const juce::Identifier& ids);
    ~PropertyItem();
    bool mightContainSubItems() override { return false; }
    void paintItem (juce::Graphics& g, int width, int height) override;

private:
    void valueTreePropertyChanged (juce::ValueTree&, const juce::Identifier&) override { repaintItem(); }
    
    juce::ValueTree state;
    const juce::Identifier propId;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PropertyItem)
};
