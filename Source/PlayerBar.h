#ifndef PLAYERBAR_H_INCLUDED
#define PLAYERBAR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class PlayerBar    : public Component
{
public:
    PlayerBar();
    ~PlayerBar();

    void paint (Graphics&) override;
    void resized() override;
    void fitToView();

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PlayerBar)
    ScopedPointer<Colour> backgroundColour;
};


#endif  // PLAYERBAR_H_INCLUDED
