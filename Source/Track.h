#ifndef TRACK_H_INCLUDED
#define TRACK_H_INCLUDED

#include <vector>

#include "../JuceLibraryCode/JuceHeader.h"
#include "SharedMacros.h"
#include "TrackNote.h"

class Track    : public Component
{
public:
    Track();
    ~Track();

    void paint (Graphics&) override;
    void resized() override;
    void fitToView();
    void renderChildren();
    
    class LabelBar : public Component
    {
    public:
        LabelBar(std::string name) {
            trackName = new TextEditor();
            trackName->setText(name);
            addAndMakeVisible(trackName);
            trackName->setColour(trackName->textColourId, Colours::white);
            trackName->setFont(18.0f);
            // TextEditor does not support vertical alignment
            trackName->setBounds(LABELBAR_PADDING, LABELBAR_PADDING,
                                 getParentWidth(), getParentHeight());
            trackName->setColour(trackName->backgroundColourId,
                                 Colour(0x00000000u));
            trackName->setColour(trackName->focusedOutlineColourId,
                                 Colour(0x00000000u));
        }
        
        void paint(Graphics& g) override {
            g.fillAll (Colours::orange);
            g.setColour (Colours::orange);
            g.drawRect (getLocalBounds(), 1);
        }

    private:
        ScopedPointer<TextEditor> trackName;
    };

private:
    ScopedPointer<Colour> backgroundColour;
    ScopedPointer<LabelBar> labelBar;
    std::vector<TrackNote> notesList = std::vector<TrackNote>(6);
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Track)
};



#endif  // TRACK_H_INCLUDED
