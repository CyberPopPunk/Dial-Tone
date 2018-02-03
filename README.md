# Dial-Tone
Office Pager MIDI Controller
[COMPLETE]

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
Top Left Knob:
Top Right Knob:
Left Switch:
Right Switch:
Phone NumPad:
Big Button:
Side Touch Fader:

After Thoughts:
---In future MIDI projects, don't assign notes and hard code values such as octave and scales. Use generic MIDI messages and program them inside of the software like Ableton.
--Reduce delay as much as possible, should only need 100ms max for processes otherwise it starts to impede on note succeession and use.
--find a better way to attach the keypad to case besides superglue/hotglue. Epoxy maybe? or create a support from uderneath that can withstand pressure on the buttons over time.
