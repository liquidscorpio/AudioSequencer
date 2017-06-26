#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include <string>
#include <vector>

#include "../JuceLibraryCode/JuceHeader.h"
#include "PlayerBar.h"
#include "Track.h"
#include "Sine.h"

class MainContentComponent   : public AudioAppComponent
{
public:

    MainContentComponent()
    {
        loadAssets();
        Rectangle<int> scr = Desktop::getInstance()
            .getDisplays()
            .getMainDisplay()
            .userArea;

        setSize (scr.getWidth(), scr.getHeight());
        setAudioChannels (2, 2);
        
        playerBar = new PlayerBar();
        addAndMakeVisible(playerBar);
        playerBar->fitToView();
        playerBar->renderChildren();
        
        track = new Track();
        addAndMakeVisible(track);
        track->fitToView();
        track->renderChildren();
    }

    ~MainContentComponent()
    {
        shutdownAudio();
    }

    void loadAssets() {
        std::vector<juce::StringRef> assets = {
            "Assets/play_btn.png"
        };

        for (auto const path : assets) {
            // TODO: Patch for relative path
            File fp = File("Assets/play_btn.png");
            Image img = ImageFileFormat::loadFrom(fp);
            ImageCache::addImageToCache(img, 100);
        }

    }

    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override
    {
    }

    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override
    {
        Sine wave;
        const float level = 0.125f;
        double currentAngle = wave.getAngleDelta();
        float* const buffer = bufferToFill.buffer->getWritePointer(0, bufferToFill.startSample);

        for (int sample = 0; sample < bufferToFill.numSamples; ++sample)
        {
            const float currentSample = (float) std::sin (currentAngle);
            wave.updateAngleDelta();
            currentAngle += wave.getAngleDelta();
            buffer[sample] = currentSample * level;
        }
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

    }


private:
    ScopedPointer<PlayerBar> playerBar;
    ScopedPointer<Track> track;
    ScopedPointer<PluginDescription> plugDesc;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


// (This function is called by the app startup code to create our main component)
Component* createMainContentComponent() { return new MainContentComponent(); }


#endif  // MAINCOMPONENT_H_INCLUDED
