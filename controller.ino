#include <HID-Project.h>

#include <HID-Settings.h>

#include <EncoderButton.h>

EncoderButton camera(0, 1, A0);
EncoderButton editor(2, 3, A1);
EncoderButton media(4, 5, A2);
EncoderButton frames(A3, 7, A4);
const int onionButton = A5;
const int resetButton = 8;
const int Red1 = 6;
const int Green1 = 9;
const int Blue1 = 10;
const int Red2 = 11;
const int Green2 = 12;
const int Blue2 = 13;
int pos = 0;
int frame_value = 10;
int buttonState = 0;
int resetState = 0;

void onMediaClicked(EncoderButton & eb) {
  Consumer.press(MEDIA_PLAY_PAUSE);
  Consumer.release(MEDIA_PLAY_PAUSE);
}

void onMediaLongClicked(EncoderButton & eb) {
  Consumer.write(MEDIA_NEXT);
}
void onCameraClicked(EncoderButton & eb) {
  Keyboard.press(KEYPAD_0);
  Keyboard.release(KEYPAD_0);

}

void onEditorClicked(EncoderButton & eb) {
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_F5);
  Keyboard.release(KEY_LEFT_SHIFT);
  Keyboard.release(KEY_F5);
}

void onFramesClicked(EncoderButton & eb) {
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_F3);
  Keyboard.release(KEY_LEFT_SHIFT);
  Keyboard.release(KEY_LEFT_CTRL);
  Keyboard.release(KEY_LEFT_ALT);
  Keyboard.release(KEY_F3);
  if (frame_value == 10) {
    frame_value = 1;
  } else {
    frame_value = 10;
  }
}

void onFramesLongClicked(EncoderButton & eb) {
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(KEY_F4);
  Keyboard.release(KEY_LEFT_SHIFT);
  Keyboard.release(KEY_LEFT_CTRL);
  Keyboard.release(KEY_LEFT_ALT);
  Keyboard.release(KEY_F4);
  if (frame_value == 2) {
    frame_value = 1;
  } else {
    frame_value = 2;
  }
}

void onFramesEncoder(EncoderButton & eb) {
  if (eb.increment() > 0) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_F1);
    Keyboard.release(KEY_LEFT_SHIFT);
    Keyboard.release(KEY_LEFT_CTRL);
    Keyboard.release(KEY_LEFT_ALT);
    Keyboard.release(KEY_F1);
  } else {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_F2);
    Keyboard.release(KEY_LEFT_SHIFT);
    Keyboard.release(KEY_LEFT_CTRL);
    Keyboard.release(KEY_LEFT_ALT);
    Keyboard.release(KEY_F2);
  }
}

void onCameraEncoder(EncoderButton & eb) {
  if (eb.increment() > 0) {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_W);
    Keyboard.release(KEY_W);
    Keyboard.release(KEY_LEFT_CTRL);
  } else {
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_W);
    Keyboard.release(KEY_W);
    Keyboard.release(KEY_LEFT_CTRL);
    Keyboard.release(KEY_LEFT_SHIFT);
  }

}

void onMediaEncoder(EncoderButton & eb) {
  if (eb.increment() > 0) {
    Consumer.press(MEDIA_VOLUME_UP);
    Consumer.release(MEDIA_VOLUME_UP);
  } else {
    Consumer.press(MEDIA_VOLUME_DOWN);
    Consumer.release(MEDIA_VOLUME_DOWN);
  }

}

void onEditorEncoder(EncoderButton & eb) {
  pos += eb.increment();
  if (pos > 7) {
    pos = 0;
  }
  if (pos < 0) {
    pos = 7;
  }
  if (pos == 0) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_F5);
    Keyboard.release(KEY_F5);
    Keyboard.release(KEY_LEFT_SHIFT);
  } else if (pos == 1) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_F10);
    Keyboard.release(KEY_F10);
    Keyboard.release(KEY_LEFT_SHIFT);
  } else if (pos == 2) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_F3);
    Keyboard.release(KEY_F3);
    Keyboard.release(KEY_LEFT_SHIFT);
  } else if (pos == 3) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_F8);
    Keyboard.release(KEY_F8);
    Keyboard.release(KEY_LEFT_SHIFT);
  } else if (pos == 4) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_F12);
    Keyboard.release(KEY_F12);
    Keyboard.release(KEY_LEFT_SHIFT);
  } else if (pos == 5) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_F6);
    Keyboard.release(KEY_F6);
    Keyboard.release(KEY_LEFT_SHIFT);
  } else if (pos == 6) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_F9);
    Keyboard.release(KEY_F9);
    Keyboard.release(KEY_LEFT_SHIFT);
  } else if (pos == 7) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_F7);
    Keyboard.release(KEY_F7);
    Keyboard.release(KEY_LEFT_SHIFT);
  }

}

void RGB_color1(int red_light_value, int green_light_value, int blue_light_value) {
  analogWrite(Red1, red_light_value);
  analogWrite(Green1, green_light_value);
  analogWrite(Blue1, blue_light_value);
}

void setup() {
  Keyboard.begin();
  // put your setup code here, to run once:

  pinMode(Red1, OUTPUT);
  pinMode(Red2, OUTPUT);
  pinMode(Green1, OUTPUT);
  pinMode(Green2, OUTPUT);
  pinMode(Blue1, OUTPUT);
  pinMode(Blue2, OUTPUT);
  pinMode(onionButton, INPUT_PULLUP);
  pinMode(resetButton, INPUT_PULLUP);
  //Link the event(s) to your function
  camera.setClickHandler(onCameraClicked);
  editor.setClickHandler(onEditorClicked);
  camera.setEncoderHandler(onCameraEncoder);
  editor.setEncoderHandler(onEditorEncoder);

  media.setClickHandler(onMediaClicked);
  media.setEncoderHandler(onMediaEncoder);
  media.setLongClickHandler(onMediaLongClicked);

  frames.setClickHandler(onFramesClicked);
  frames.setLongClickHandler(onFramesLongClicked);
  frames.setEncoderHandler(onFramesEncoder);
}

void loop() {
  // put your main code here, to run repeatedly:
  // You must call update() for every defined EncoderButton.
  // This will update the state of the encoder & button and 
  // fire the appropriat events.
  camera.update();
  editor.update();
  media.update();
  frames.update();

  if (frame_value == 10) {
    analogWrite(Red2, 255);
    analogWrite(Green2, 0);
  } else if (frame_value - 1) {
    analogWrite(Red2, 150);
    analogWrite(Green2, 150);
  } else {
    analogWrite(Red2, 0);
    analogWrite(Green2, 255);
  }

  if (pos == 7) {
    RGB_color1(77, 255, 0);
  } else if (pos == 0) {
    RGB_color1(0, 255, 140);
  } else if (pos == 1) {
    RGB_color1(0, 221, 255);
  } else if (pos == 2) {
    RGB_color1(0, 4, 255);
  } else if (pos == 3) {
    RGB_color1(212, 0, 255);
  } else if (pos == 4) {
    RGB_color1(255, 0, 85);
  } else if (pos == 5) {
    RGB_color1(255, 0, 0);
  } else if (pos == 6) {
    RGB_color1(255, 217, 0);
  }

  buttonState = analogRead(onionButton);
  //resetState = analogRead(resetButton);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState > 1000) {
    analogWrite(Blue2, 0);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_F9);
    Keyboard.release(KEY_LEFT_SHIFT);
    Keyboard.release(KEY_LEFT_CTRL);
    Keyboard.release(KEY_LEFT_ALT);
    Keyboard.release(KEY_F9);
    delay(400);
  } else {
    analogWrite(Blue2, 255);
  }

  if (resetState > 1000){
    frame_value = 10;
    pos = 0;
    }

}
