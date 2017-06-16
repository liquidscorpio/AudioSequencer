#ifndef TRACKNOTE_H_INCLUDED
#define TRACKNOTE_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class TrackNote    : public Component
{
public:
    TrackNote();
    ~TrackNote();

    void paint (Graphics&) override;
    void resized() override;
    void renderChildren();
    
private:
    Label noteDisplay;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TrackNote)
};


#endif  // TRACKNOTE_H_INCLUDED
