#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "PlayerBar.h"
#include "Track.h"

class MainContentComponent   : public AudioAppComponent
{
public:

    MainContentComponent()
    {
        setSize (800, 600);
        setAudioChannels (2, 2);
        
        playerBar = new PlayerBar();
        addAndMakeVisible(playerBar);
        playerBar->fitToView();
        
        track = new Track();
        addAndMakeVisible(track);
        track->fitToView();
    }

    ~MainContentComponent()
    {
        shutdownAudio();
    }

    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override
    {
    }

    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override
    {
        bufferToFill.clearActiveBufferRegion();
    }

    void releaseResources() override
    {
    }

    void paint (Graphics& g) override
    {
        g.fillAll (Colours::black);

    }

    void resized() override
    {
        if (track) {
            track->fitToView();
        }
        
        if (playerBar) {
            playerBar->fitToView();
        }
    }

private:
    ScopedPointer<PlayerBar> playerBar;
    ScopedPointer<Track> track;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


// (This function is called by the app startup code to create our main component)
Component* createMainContentComponent() { return new MainContentComponent(); }


#endif  // MAINCOMPONENT_H_INCLUDED
