#include "../JuceLibraryCode/JuceHeader.h"
#include "TrackNote.h"
#include "SharedMacros.h"

TrackNote::TrackNote()
{

}

TrackNote::~TrackNote()
{
}

void TrackNote::paint (Graphics& g)
{
    g.fillAll (Colours::black);
    g.setColour (BACKGROUND_LIGHTGREY);
    g.drawLine(0, getHeight(), getWidth(), getHeight(), 2);
//    g.drawLine(0, 0, 0, getHeight(), 2);
//    g.drawLine(getWidth(), 0, getWidth(), getHeight(), 2);
}

void TrackNote::renderChildren()
{
    addAndMakeVisible(noteDisplay);
    noteDisplay.setColour(Label::textColourId, Colour(0xBBFFFFFF));
    noteDisplay.setBounds(LABELBAR_PADDING, LABELBAR_PADDING,
                          getWidth() * 0.3, getHeight());
    noteDisplay.setText("C#", NotificationType::dontSendNotification);
    noteDisplay.setFont(Font("Gill Sans", "Light", 36.0f));
}

void TrackNote::resized()
{

}
