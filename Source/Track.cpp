#include <vector>

#include "../JuceLibraryCode/JuceHeader.h"
#include "Track.h"
#include "TrackNote.h"
#include "SharedMacros.h"

Track::Track()
{
    backgroundColour = new BACKGROUND_GREY;
    setColour(ColourSelector::backgroundColourId, *backgroundColour);
}


Track::~Track()
{

}

void Track::fitToView()
{
    uint32_t yPos = PLAYERBAR_HEIGHT;
    uint32_t height = (int) getParentHeight() - PLAYERBAR_HEIGHT;
    uint32_t width = (int) getParentWidth() * TRACK_WIDTH_RATIO;
    setBounds(0, yPos, width, height);
}

void Track::renderChildren()
{
    labelBar = new LabelBar("Track 1");
    addAndMakeVisible(labelBar);
    uint16_t width = getWidth();
    labelBar->setBounds(0, 0, width, LABELBAR_HEIGHT);
    uint8_t i = 0;
    for (auto &note : notesList) {
        addAndMakeVisible(note);
        uint16_t noteY = i * TRACKNOTE_HEIGHT + LABELBAR_HEIGHT;
        note.setBounds(0, noteY, width, TRACKNOTE_HEIGHT);
        note.setColour(ColourSelector::backgroundColourId,
                       BACKGROUND_GREY);
        note.renderChildren();
        i++;
    }
}

void Track::paint (Graphics& g)
{
    g.fillAll (*backgroundColour);
    g.setColour (*backgroundColour);
    g.drawRect (getLocalBounds(), 1);
}

void Track::resized()
{
    
}
