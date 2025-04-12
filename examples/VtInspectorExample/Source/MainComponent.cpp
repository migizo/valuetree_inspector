#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
: valueTree("ROOT")
#if USE_INSPECTOR_WINDOW
, vtInspectorWindow(valueTree)
#else
, vtInspector(valueTree)
#endif
{
    addAndMakeVisible(addButton);
    addButton.setButtonText("Add");
    addButton.onClick = [this]
    {
        undoManager.beginNewTransaction();
        valueTree.appendChild({ "Item", {{ "uuid", juce::Uuid().toDashedString() }},{}}, &undoManager);
    };
    for (int i = 0; i < 3; i++)
    {
        addButton.triggerClick();
    }
    
    addAndMakeVisible(removeButton);
    removeButton.setButtonText("Remove");
    removeButton.onClick = [this]
    {
        undoManager.beginNewTransaction();
        valueTree.removeChild(valueTree.getNumChildren() - 1, &undoManager);
    };
    
#if !USE_INSPECTOR_WINDOW
    addAndMakeVisible(vtInspector);
#endif

    setSize (600, 400);
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
    
    g.setColour (juce::Colours::white);
    g.setFont (juce::FontOptions (15.0f));
    g.drawFittedText ("Let's Click 'Add / Remove' Button, and undo/redo by cmd+z or cmd+shift+z.", getLocalBounds().removeFromTop(64), juce::Justification::centred, 1);
}

void MainComponent::resized()
{
    auto area = getLocalBounds();
    area.removeFromTop(64); // remove text area
    auto topArea = area.removeFromTop(32).reduced(2);
    addButton.setBounds(topArea.removeFromLeft(topArea.getWidth()/2));
    removeButton.setBounds(topArea);
    
#if !USE_INSPECTOR_WINDOW
    vtInspector.setBounds(area);
#endif
}

bool MainComponent::keyPressed (const juce::KeyPress& key)
{    
    if (key == juce::KeyPress('z', juce::ModifierKeys::commandModifier, 0))
    {
        undoManager.undo();
        return true;
    }

    if (key == juce::KeyPress('z', juce::ModifierKeys::commandModifier | juce::ModifierKeys::shiftModifier, 0))
    {
        undoManager.redo();
        return true;
    }

    return juce::Component::keyPressed(key);
}
