/*
    This file is part of Helio Workstation.

    Helio is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Helio is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Helio. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

class PianoRoll;

#include "MidiEventComponent.h"
#include "Note.h"

class NoteComponent : public MidiEventComponent
{
public:

    NoteComponent(PianoRoll &gridRef, const Note &eventRef);
    ~NoteComponent() override;

    enum State
    {
        None,
        ResizingRight,
        ResizingLeft,
        GroupScalingRight,
        GroupScalingLeft,
        Tuning,
        Dragging
    };
    
    void setGhostMode();

    const Note &getNote() const;
    PianoRoll &getRoll() const;

    void updateBounds(const Rectangle<float> &b) override;
    void setSelected(const bool selected) override;

    //===------------------------------------------------------------------===//
    // Accessors
    //===------------------------------------------------------------------===//

    //bool isNoteToggled(const int note, const float beat);
    int getKey() const;
    float getLength() const;
    float getVelocity() const;

    //===------------------------------------------------------------------===//
    // Component
    //===------------------------------------------------------------------===//

    bool keyStateChanged(bool isKeyDown) override;
    void modifierKeysChanged(const ModifierKeys &modifiers) override;
    void mouseMove(const MouseEvent &e) override;
    void mouseDown(const MouseEvent &e) override;
    void mouseDrag(const MouseEvent &e) override;
    void mouseUp(const MouseEvent &e) override;
    void mouseDoubleClick(const MouseEvent &e) override;
    void paint(Graphics &g) override;

protected:

    inline void paintNewLook(Graphics &g);
    inline void paintLegacyLook(Graphics &g);
    
    Note anchor;
    Note groupScalingAnchor;

    void setNoCheckpointNeededForNextAction();
    bool isResizing() const;
    
    void startResizingRight(bool sendMidiMessage);
    bool getResizingRightDelta(const MouseEvent &e, float &deltaLength) const;
    Note continueResizingRight(float deltaLength);
    void endResizingRight();
    
    void startResizingLeft(bool sendMidiMessage);
    bool getResizingLeftDelta(const MouseEvent &e, float &deltaLength) const;
    Note continueResizingLeft(float deltaLength);
    void endResizingLeft();
    
    void startTuning();
    Note continueTuning(const MouseEvent &e);
    Note continueTuningLinear(float delta);
    Note continueTuningMultiplied(float factor);
    Note continueTuningSine(float factor, float midline, float phase);
    void endTuning();
    
    void startGroupScalingRight(float groupStartBeat);
    bool getGroupScaleRightFactor(const MouseEvent &e, float &absScaleFactor) const;
    Note continueGroupScalingRight(float absScaleFactor);
    void endGroupScalingRight();
    
    void startGroupScalingLeft(float groupEndBeat);
    bool getGroupScaleLeftFactor(const MouseEvent &e, float &absScaleFactor) const;
    Note continueGroupScalingLeft(float absScaleFactor);
    void endGroupScalingLeft();
    
    void startDragging(bool sendMidiMessage);
    bool getDraggingDelta(const MouseEvent &e, float &deltaBeat, int &deltaKey);
    Note continueDragging(float deltaBeat, int deltaKey, bool sendMidiMessage);
    void endDragging(bool sendMidiMessage = true);
    
    bool canResize() const;

    State state;

    Rectangle<float> realLocalBounds;
    
    bool ghostMode;
    
    friend class PianoRoll;
    friend class MidiRollToolbox;
    friend class NoteResizerLeft;
    friend class NoteResizerRight;
    
    bool firstChangeDone;
    void checkpointIfNeeded();

    bool shouldGoQuickSelectLayerMode(const ModifierKeys &modifiers) const;
    void setQuickSelectLayerMode(bool value);
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(NoteComponent)
    
};
