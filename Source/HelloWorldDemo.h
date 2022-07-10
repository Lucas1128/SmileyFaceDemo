/*
  ==============================================================================

   This file is part of the JUCE examples.
   Copyright (c) 2020 - Raw Material Software Limited

   The code included in this file is provided under the terms of the ISC license
   http://www.isc.org/downloads/software-support-policy/isc-license. Permission
   To use, copy, modify, and/or distribute this software for any purpose with or
   without fee is hereby granted provided that the above copyright notice and
   this permission notice appear in all copies.

   THE SOFTWARE IS PROVIDED "AS IS" WITHOUT ANY WARRANTY, AND ALL WARRANTIES,
   WHETHER EXPRESSED OR IMPLIED, INCLUDING MERCHANTABILITY AND FITNESS FOR
   PURPOSE, ARE DISCLAIMED.

  ==============================================================================
*/

/*******************************************************************************
 The block below describes the properties of this PIP. A PIP is a short snippet
 of code that can be read by the Projucer and used to generate a JUCE project.

 BEGIN_JUCE_PIP_METADATA

 name:             HelloWorldDemo
 version:          1.0.0
 vendor:           JUCE
 website:          http://juce.com
 description:      Simple HelloWorld application.

 dependencies:     juce_core, juce_data_structures, juce_events, juce_graphics,
                   juce_gui_basics
 exporters:        xcode_mac, vs2019, linux_make, xcode_iphone

 moduleFlags:      JUCE_STRICT_REFCOUNTEDPOINTER=1

 type:             Component
 mainClass:        HelloWorldDemo

 useLocalCopy:     1

 END_JUCE_PIP_METADATA

*******************************************************************************/

#pragma once


//==============================================================================
class HelloWorldDemo  : public Component
{
public:
    //==============================================================================
    HelloWorldDemo()
    {
        addAndMakeVisible (quitButton);
        quitButton.onClick = [] { JUCEApplication::quit(); };

        setSize (600, 300);
    }

    //==============================================================================
    void paint (Graphics& g) override
    {
        /* Background Color */
        g.fillAll (Colour (0xffc1d0ff));

        g.fillPath (internalPath);

        
        g.strokePath (internalPath, PathStrokeType (5.200f));



        g.setColour(juce::Colours::yellow);

        /* Draw Yellow Face */
        int circlediamater = 200;
        g.fillEllipse ((getWidth() - circlediamater) / 2, (getHeight() - circlediamater) / 2, circlediamater, circlediamater);

        g.setColour(Colours::black);

        /* Draw Mouth */
        g.setColour(juce::Colours::black);
        g.fillEllipse((getWidth() - 100) / 2, (getHeight() + 80) / 2, 100, 10);

        /* Draw Eyes */
        g.setColour(juce::Colours::black);
        g.fillEllipse((getWidth() - 100) / 2, (getHeight() - 125) / 2, 20, 50);
        g.fillEllipse((getWidth() + 50) / 2, (getHeight() - 125) / 2, 20, 50);



        /*internalPath.clear();
        internalPath.startNewSubPath(136.0f, 80.0f);
        internalPath.quadraticTo(176.0f, 24.0f, 328.0f, 32.0f);
        internalPath.quadraticTo(472.0f, 40.0f, 472.0f, 104.0f);
        internalPath.quadraticTo(472.0f, 192.0f, 232.0f, 176.0f);
        internalPath.closeSubPath();*/
    }

    void resized() override
    {
        quitButton.setBounds(getWidth() - 176, getHeight() - 60, 120, 32);
        
    }

private:
    //==============================================================================
    TextButton quitButton { TRANS("Quit") };
    Path internalPath;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HelloWorldDemo)
};
