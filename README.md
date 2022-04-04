# blender-arduino-controller
Arduino Leonardo controller for Blender, using rotary encoders. Make a desktop shortcut box. This essentially acts as a second keyboard for Blender specific functions. 

* Blender doesn't have all these functions mapped to keyboard shortcuts out of the box. You need to install AnimationController.py as an add-on for this to work.*

## Uses add-ons:
* [Animation Extras](https://blendermarket.com/products/animation-extras)
* [ShotDial](https://blendermarket.com/products/shotdial)
* Animation Controller (AnimationController.py, see above)
* Stored Views (comes with Blender by default, optional)

## Functions
### Rotary Encoder 1 (0,1, switch A0)
* Rotate forward to move camera views forward - i.e., set the camera preview in the viewport to the next camera in the Outliner List
* Rotate backward to move camera views backward
* Click to toggle Camera View

### Rotary Encoder 2 (2,3, switch A1)
* Rotate to change the active Blender window editor. An RGB LED on pins 6,9,10 has one color for each editor.
* Click to return to the 3D Viewport

### Rotary Encoder 3 (4,5, switch A2)
* Rotate to change media volume
* Press to play/pause media
* Long press to skip to the next song

### Rotary Encoder 4 (A3, 7, switch A4)
* Rotate to move the active frame by the frame amount. This is 10 by default. The frame amount is indicated by a second RGB LED, specifically the RED and GREEN, on pins 11,12,13
* Press to toggle between 10 and 1 for the frame amount
* Long press to toggle between 2 and 1 for the frame amount

### Button 1 (A5)
* Press to set Onion Skinning for the selected object, start drawing, and update the onion skin. While pressed, the BLUE light on the second RGB LED will be on, otherwise it will be off. 

You can change any of these functions, any of these pins, etc. This is just how I have mine set up. 
