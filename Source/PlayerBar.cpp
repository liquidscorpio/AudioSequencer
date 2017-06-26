#include "../JuceLibraryCode/JuceHeader.h"
#include "PlayerBar.h"
#include "SharedMacros.h"

PlayerBar::PlayerBar()
{
    backgroundColour = new BACKGROUND_GREY;
}

PlayerBar::~PlayerBar()
{

}

void PlayerBar::renderChildren() {
    playButton = new ImageComponent();
    playButton->setBounds(12, 12, 24, 24);
    playButton->setImage(ImageCache::getFromHashCode(100),
                         RectanglePlacement::centred);
    playButton->setMouseCursor(MouseCursor::PointingHandCursor);
    addAndMakeVisible(playButton);
}

void PlayerBar::paint (Graphics& g)
{
    g.fillAll(*backgroundColour);
    g.setColour(*backgroundColour);
    g.drawRect(getLocalBounds(), 1);
    g.setFont(14.0f);
}

void PlayerBar::fitToView()
{
    setBounds(0, 0, getParentWidth(), PLAYERBAR_HEIGHT);
}

void PlayerBar::resized()
{

}
