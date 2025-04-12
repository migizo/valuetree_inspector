/*******************************************************************************

 BEGIN_JUCE_MODULE_DECLARATION

  ID:                 valuetree_inspector
  vendor:             migizo
  version:            1.0.0
  name:               ValueTree Inspector
  description:        A valuetree inspcetor window/component for JUCE.
  website:            https://twitter.com/migizo

  dependencies:       juce_data_structures juce_gui_basics

 END_JUCE_MODULE_DECLARATION

*******************************************************************************/

#pragma once

#define VALUETREE_INSPECTOR_H_INCLUDED

#include <juce_data_structures/juce_data_structures.h>
#include <juce_gui_basics/juce_gui_basics.h>
#include "src/PropertyItem.h"
#include "src/ValueTreeItem.h"
#include "src/ValueTreeInspectorComponent.h"
#include "src/ValueTreeInspector.h"
