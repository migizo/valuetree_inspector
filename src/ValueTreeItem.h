/*
  ==============================================================================

    ValueTreeItem.h
    Author:  migizo

  ==============================================================================
*/

#pragma once
#include <juce_data_structures/juce_data_structures.h>
#include <juce_gui_basics/juce_gui_basics.h>
#include "PropertyItem.h"

//==============================================================================
//! ValueTreeを表すTreeViewItemで、入れ子構造で子にTreeViewItemもしくはPropertyItemを持ちうる
class ValueTreeItem final
: public juce::TreeViewItem
, private juce::ValueTree::Listener
{
public:
    ValueTreeItem (const juce::ValueTree& v);
    ~ValueTreeItem();

    bool mightContainSubItems() override;
    void paintItem (juce::Graphics& g, int width, int height) override;
    void itemOpennessChanged (bool isNowOpen) override;

private:
    void valueTreePropertyChanged (juce::ValueTree&vt, const juce::Identifier& ids) override;

    void valueTreeChildAdded (juce::ValueTree& parentTree, juce::ValueTree&) override         { treeChildrenChanged (parentTree); }
    void valueTreeChildRemoved (juce::ValueTree& parentTree, juce::ValueTree&, int) override  { treeChildrenChanged (parentTree); }
    void valueTreeChildOrderChanged (juce::ValueTree& parentTree, int, int) override    { treeChildrenChanged (parentTree); }
    void valueTreeParentChanged (juce::ValueTree&) override {}
    
    void treeChildrenChanged (const juce::ValueTree& parentTree);
    void refreshSubItems();

    juce::ValueTree state;
    int lastNumProperties = 0;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ValueTreeItem)
};
