#include <vector>

#include "../JuceLibraryCode/JuceHeader.h"
#include "Track.h"
#include "TrackNote.h"
#include "SharedMacros.h"

Track::Track()
{
    
}


Track::~Track()
{

}

void Track::fitToView()
{
    uint32_t yPos = PLAYERBAR_HEIGHT + UI_PADDING;
    uint32_t height = notesList.size() * TRACKNOTE_HEIGHT + LABELBAR_HEIGHT;
    uint32_t width = (int) getParentWidth() * TRACK_WIDTH_RATIO;
    setBounds(UI_PADDING, yPos, width, height);
}

void Track::renderChildren()
{
    backgroundColour = new BACKGROUND_GREY;
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
