# Dial-Tone
Office Pager MIDI Controller
[COMPLETE]

YouTube Video: https://youtu.be/quUnFeOX6tg

The Dial-Tone is a repurposed office pager that has been turned into a Class Compliant USB MIDI controller for playing music of cueing lights etc. on any USB MIDI supported computer (almost all of them).

Software used:
AVR DUDE
HIDUINO
Arduino IDE

Hardware Used:
Pager (salvaged, origin unknown)
Arduino Uno (Inland brand replica)
Various Sensors (btns, pots, faders, LDR, phone numpad)
AVRISP mkII programmer (recommended, but basically essential if you don't wanna lose you mind)
rubber feet


MIDI Messages:
Top Left Knob: MIDI CC 85
Top Right Knob: MIDI CC 86
Left Switch: Octave (adds +12 to midi note number bringing it up 1 octave)
Right Switch:  Scale control (chromatic or major blues)
Phone NumPad:   C4-B4 while on chromatic scale.........C-D-Eb-E-G-A-C-D-Eb when on Maj Blues
Big Button:  MIDI CC 88
Side Touch Fader: MIDI CC 87

After Thoughts:
---In future MIDI projects, don't assign notes and hard code values such as octave and scales. Use generic MIDI messages and map them inside of the software like Ableton, creating a more fluid overall project.
--Reduce delay as much as possible, should only need 200ms max for processes otherwise it starts to impede on note succeession and musical use.
--find a better way to attach the keypad to case besides superglue/hotglue. Epoxy maybe? or create a support from uderneath that can withstand pressure on the buttons over time.
