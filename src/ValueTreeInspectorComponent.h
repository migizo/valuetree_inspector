/*
  ==============================================================================

    ValueTreeInspectorComponent.h
    Author:  migizo

  ==============================================================================
*/

#pragma once

#include <juce_gui_basics/juce_gui_basics.h>
#include "ValueTreeItem.h"

//==============================================================================
//! ValueTreeInspectorウインドウのコンテンツを表すコンポーネント
//! ウインドウのコンテンツとしてtreeViewをそのまま持たせる実装もありうるが,機能追加などを考慮してこのコンポーネントの子としてtreeViewを持たせる実装になっている
class ValueTreeInspectorComponent  : public juce::Component
{
public:
    ValueTreeInspectorComponent(const juce::ValueTree& vt);
    ~ValueTreeInspectorComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:    
    juce::TreeView treeView;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ValueTreeInspectorComponent)
};
