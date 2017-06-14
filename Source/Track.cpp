#include <vector>

#include "../JuceLibraryCode/JuceHeader.h"
#include "Track.h"
#include "TrackNote.h"
#include "SharedMacros.h"

Track::Track()
{
    backgroundColour = new BACKGROUND_GREY;
    labelBar = new LabelBar("Track 1");
    addAndMakeVisible(labelBar);
    labelBar->setBounds(0, 0, getParentWidth(), 30);
    notesList = std::vector<TrackNote>(32);
}


Track::~Track()
{
    
}

void Track::fitToView()
{
    uint32_t yPos = PLAYERBAR_HEIGHT + UI_PADDING;
    uint32_t height = getParentHeight() - (PLAYERBAR_HEIGHT + (2 * UI_PADDING));
    uint32_t width = (int) getParentWidth() * TRACK_WIDTH_RATIO;
    setBounds(UI_PADDING, yPos, width, height);
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
