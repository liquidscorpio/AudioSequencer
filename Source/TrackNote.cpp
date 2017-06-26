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
    g.fillAll(BACKGROUND_GREY);
    g.setColour(BACKGROUND_LIGHTGREY);
    g.drawLine(0, getHeight(), getWidth(), getHeight(), 1);
}

void TrackNote::renderChildren()
{
    Font font("Open Sans", "Light", 35.0f);
    std::string text = "C#";
    size_t labelWidth = font.getStringWidth(text) * 2;
    size_t labelHeight = font.getHeight();
    size_t gap = LABELBAR_PADDING * 2;
    addAndMakeVisible(noteDisplay);
    noteDisplay.setColour(Label::textColourId, Colour(0xBBFFFFFF));
    noteDisplay.setBounds(gap, gap, labelWidth, labelHeight);
    noteDisplay.setFont(font);
    noteDisplay.setText(text, NotificationType::dontSendNotification);
}

void TrackNote::resized()
{

}
