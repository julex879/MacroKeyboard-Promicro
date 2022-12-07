//nuevo commit 
//https://www.sparkfun.com/products/12640
//https://learn.sparkfun.com/tutorials/pro-micro--fio-v3-hookup-guide/all#installing-windows
#define KEY_LEFT_CTRL     0x80
#define KEY_LEFT_SHIFT    0x81
#define KEY_LEFT_ALT      0x82
#define KEY_LEFT_GUI      0x83
#define KEY_RIGHT_CTRL    0x84
#define KEY_RIGHT_SHIFT   0x85
#define KEY_RIGHT_ALT     0x86
#define KEY_RIGHT_GUI     0x87

// Misc keys
#define KEY_UP_ARROW      0xDA
#define KEY_DOWN_ARROW    0xD9
#define KEY_LEFT_ARROW    0xD8
#define KEY_RIGHT_ARROW   0xD7
#define KEY_BACKSPACE     0xB2
#define KEY_TAB           0xB3
#define KEY_RETURN        0xB0
#define KEY_MENU          0xED // "Keyboard Application" in USB standard
#define KEY_ESC           0xB1
#define KEY_INSERT        0xD1
#define KEY_DELETE        0xD4
#define KEY_PAGE_UP       0xD3
#define KEY_PAGE_DOWN     0xD6
#define KEY_HOME          0xD2
#define KEY_END           0xD5
#define KEY_CAPS_LOCK     0xC1
#define KEY_PRINT_SCREEN  0xCE // Print Screen / SysRq
#define KEY_SCROLL_LOCK   0xCF
#define KEY_PAUSE         0xD0 // Pause / Break

// Numeric keypad
#define KEY_NUM_LOCK      0xDB
#define KEY_KP_SLASH      0xDC
#define KEY_KP_ASTERISK   0xDD
#define KEY_KP_MINUS      0xDE
#define KEY_KP_PLUS       0xDF
#define KEY_KP_ENTER      0xE0
#define KEY_KP_1          0xE1
#define KEY_KP_2          0xE2
#define KEY_KP_3          0xE3
#define KEY_KP_4          0xE4
#define KEY_KP_5          0xE5
#define KEY_KP_6          0xE6
#define KEY_KP_7          0xE7
#define KEY_KP_8          0xE8
#define KEY_KP_9          0xE9
#define KEY_KP_0          0xEA
#define KEY_KP_DOT        0xEB

// Function keys
#define KEY_F1            0xC2
#define KEY_F2            0xC3
#define KEY_F3            0xC4
#define KEY_F4            0xC5
#define KEY_F5            0xC6
#define KEY_F6            0xC7
#define KEY_F7            0xC8
#define KEY_F8            0xC9
#define KEY_F9            0xCA
#define KEY_F10           0xCB
#define KEY_F11           0xCC
#define KEY_F12           0xCD
#define KEY_F13           0xF0
#define KEY_F14           0xF1
#define KEY_F15           0xF2
#define KEY_F16           0xF3
#define KEY_F17           0xF4
#define KEY_F18           0xF5
#define KEY_F19           0xF6
#define KEY_F20           0xF7
#define KEY_F21           0xF8
#define KEY_F22           0xF9
#define KEY_F23           0xFA
#define KEY_F24           0xFB
#include "Keypad.h"
#include "Keyboard.h"
#include <Mouse.h>



#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library. 
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define NUMFLAKES     10 // Number of snowflakes in the animation example

#define buzzer  A3
boolean entrada =0;
const byte ROWS = 4;
const byte COLS = 4; 

char hexaKeys[ROWS][COLS] = {
  {'1', '4', '7', '*'},
  {'2', '5', '8', '0'},
  {'3', '6', '9', '#'},
  {'A', 'B', 'C', 'D'}
};
byte rowPins[ROWS] = {9,8,7,6};
byte colPins[COLS] = { 5, 4,14,15}; 
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
void setup() {
    pinMode(buzzer, OUTPUT); 

    sonido_buzzer();
    
    Keyboard.begin();
    Mouse.begin();
    Wire.begin();          // inicializa bus I2C
    oled.begin(SSD1306_SWITCHCAPVCC, 0x3C); // inicializa pantalla con direccion 0x3C
    oled.clearDisplay();      // limpia pantalla
    oled.setTextColor(WHITE);   // establece color al unico disponible (pantalla monocromo)
    oled.setCursor (0, 10);    // ubica cursor en coordenas 10,30
    oled.setTextSize(2);      // establece tamano de texto en 2
    oled.clearDisplay(); 
    oled.print("ACTIVO"); 
    oled.display(); 
    oled.setCursor (0, 10); 
    

}
void loop() {
  char customKey = customKeypad.getKey();
  oled.clearDisplay();      // limpia pantalla
  if (customKey) {
    sonido_buzzer();
    casos(customKey);
    oled.setCursor (0, 10);    // ubica cursor en coordenas 10,30  
    oled.display();      // muestra en pantalla todo lo establecido anteriormente
  }
}


void casos (char customKey){
  switch( customKey ){

          case'':
                  break;
          
           default :
                  break; 
  }

}

void explosion(){
   for(int i=0;i<=4;i++){
      digitalWrite(buzzer, HIGH); // sets the digital pin 13 onHola buenos dias 
      delay(200);            // waits for a second
      digitalWrite(buzzer, LOW);  // sets the digital pin 13 off
      delay(200);            // waits for a second
    }
}
void efecto_terminator(String datos, int tiempo ){
    int largo =datos.length();
    for(int i=0;i<=largo;i++){
      Keyboard.print(datos[i]);
      delay(tiempo);
    }
}
void cambio_de_pagina(){
    Keyboard.press(KEY_LEFT_CTRL);      // emila presion de tecla c
    Keyboard.press(KEY_TAB);      // emula presion de tecla Control
    delay(10);         // demora de 100 mseg.
    Keyboard.releaseAll();      // deja de presionar las teclas anteriores
    delay(10);        // demora de 1 seg.
}
void cambio_de_ventana(){
    Keyboard.press(KEY_LEFT_ALT);      // emula presion de tecla Control
    Keyboard.press(KEY_TAB);      // emila presion de tecla c
    delay(10);         // demora de 100 mseg.
    Keyboard.releaseAll();      // deja de presionar las teclas anteriores
    delay(10);        // demora de 1 seg
}
void seleccionar(){
    Keyboard.press(KEY_END);      // emila presion de tecla c
    Keyboard.press(KEY_LEFT_SHIFT);      // emula presion de tecla Control
    Keyboard.press(KEY_HOME);      // emila presion de tecla c
    delay(10);         // demora de 100 mseg.
    Keyboard.releaseAll();      // deja de presionar las teclas anteriores
    delay(10);        // demora de 1 seg.
}
void copiar(){
    Keyboard.press(KEY_LEFT_CTRL);      // emula presion de tecla Control
    Keyboard.press('c');      // emila presion de tecla c
    delay(10);         // demora de 100 mseg.
    Keyboard.releaseAll();      // deja de presionar las teclas anteriores
    delay(10);        // demora de 1 seg.
  }
void pegar(){
    Keyboard.press(KEY_LEFT_CTRL);      // emula presion de tecla Control
    Keyboard.press('v');      // emula presion de tecla v
    delay(10);         // demora de 100 mseg.
    Keyboard.releaseAll();      // deja de presionar las teclas anteriores
    delay(10);        // demora de 1 seg.
  }
void sonido_buzzer(){
    digitalWrite(buzzer, HIGH); // sets the digital pin 13 on
    delay(200);            // waits for a second
    digitalWrite(buzzer, LOW);  // sets the digital pin 13 off
    delay(200);            // waits for a second  
}
