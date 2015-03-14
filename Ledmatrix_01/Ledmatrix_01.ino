/*
 * Conway's "Life"
 * 
 * Adapted from the Life example
 * on the Processing.org site
 *
 * Needs FrequencyTimer2 library
 */

#include <FrequencyTimer2.h>

byte col = 0;
byte leds[8][8];

// pin[xx] on led matrix connected to nn on Arduino (-1 is dummy to make array start at pos 1)
int pins[17]= {-1, 22,24, 26, 28, 30, 32,34,36,38,40,42,44,46,48,50,52}; 

// col[xx] of leds = pin yy on led matrix
int cols[8] = {13, 3, 4, 10, 6, 11, 15, 16};

// row[xx] of leds = pin yy on led matrix
int rows[8] = {9, 14, 8, 12, 1, 7, 2, 5};

#define DELAY 0
#define SIZE 8
extern byte leds[SIZE][SIZE];
byte world[SIZE][SIZE][2];
long density = 50;

void setup() {
  setupLeds();
  randomSeed(analogRead(5));
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      if (random(100) < density) {
        world[i][j][0] = 1;
      }
      else {
        world[i][j][0] = 0;
      }
      world[i][j][1] = 0;
    }
  }
}

void loop() {
  // Display current generation
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      leds[i][j] = world[i][j][0];
    }
  }
  delay(DELAY);

  // Birth and death cycle 
  for (int x = 0; x < SIZE; x++) { 
    for (int y = 0; y < SIZE; y++) {
      // Default is for cell to stay the same
      world[x][y][1] = world[x][y][0];
      int count = neighbours(x, y); 
      if (count == 3 && world[x][y][0] == 0) {
        // A new cell is born
        world[x][y][1] = 1; 
      } 
      if ((count < 2 || count > 3) && world[x][y][0] == 1) {
        // Cell dies
        world[x][y][1] = 0; 
      }
    }
  }

  // Copy next generation into place
  for (int x = 0; x < SIZE; x++) { 
    for (int y = 0; y < SIZE; y++) {
      world[x][y][0] = world[x][y][1];
    }
  }
}

int neighbours(int x, int y) {
 return world[(x + 1) % SIZE][y][0] + 
         world[x][(y + 1) % SIZE][0] + 
         world[(x + SIZE - 1) % SIZE][y][0] + 
         world[x][(y + SIZE - 1) % SIZE][0] + 
         world[(x + 1) % SIZE][(y + 1) % SIZE][0] + 
         world[(x + SIZE - 1) % SIZE][(y + 1) % SIZE][0] + 
         world[(x + SIZE - 1) % SIZE][(y + SIZE - 1) % SIZE][0] + 
         world[(x + 1) % SIZE][(y + SIZE - 1) % SIZE][0]; 
}

void setupLeds() {
  // sets the pins as output
  for (int i = 1; i <= 16; i++) {
    pinMode(pins[i], OUTPUT);
  }

  // set up cols and rows
  for (int i = 1; i <= 8; i++) {
    digitalWrite(pins[cols[i]-1], LOW);
  }

  for (int i = 1; i <= 8; i++) {
    digitalWrite(pins[rows[i]-1], LOW);
  }

  clearLeds();

  // Turn off toggling of pin 11 and 3
  FrequencyTimer2::disable();
  // Set refresh rate (interrupt timeout period)
  FrequencyTimer2::setPeriod(2000);
  // Set interrupt routine to be called
  FrequencyTimer2::setOnOverflow(display);

}

void clearLeds() {
  // Clear display array
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      leds[i][j] = 0;
    }
  }
}

// Interrupt routine
void display() {
  digitalWrite(pins[cols[col]-1], LOW);  // Turn whole previous column off
  col++;
  if (col == 8) {
    col = 0;
  }
  for (int row = 0; row < 8; row++) {
    if (leds[col][7 - row] == 1) {
      digitalWrite(pins[rows[row]-1], LOW);  // Turn on this led
    }
    else {
      digitalWrite(pins[rows[row]-1], HIGH); // Turn off this led
    }
  }
  digitalWrite(pins[cols[col]-1], HIGH); // Turn whole column on at once (for equal lighting times)
}
