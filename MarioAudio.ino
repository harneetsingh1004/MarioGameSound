#define BUZZER_PIN 8  // Buzzer connected to digital pin 8

// Define musical notes (frequencies in Hz)
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_G5  784
#define NOTE_A5  880
#define NOTE_B5  988

// Super Mario melody
int melody[] = {
  NOTE_E5, NOTE_E5, 0, NOTE_E5,
  0, NOTE_C5, NOTE_E5, 0,
  NOTE_G5, 0, 0,  0,
  NOTE_G4, 0, 0, 0,
  
  NOTE_C5, 0, 0, NOTE_G4,
  0, 0, NOTE_E4, 0,
  0, NOTE_A4, 0, NOTE_B4,
  0, NOTE_A4, NOTE_G4, 0,
  
  NOTE_E5, NOTE_G5, NOTE_A5,
  0, NOTE_F5, NOTE_G5, 0,
  NOTE_E5, 0, NOTE_C5, NOTE_D5, NOTE_B4,
  0, 0, NOTE_C5, 0, 0, NOTE_G4, 0, 0, NOTE_E4
};

// Note durations (4 = quarter note, 8 = eighth note, etc.)
int durations[] = {
  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8,

  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8,

  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8,
  8, 8, 8, 8, 8, 8, 8, 8, 8
};

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  playSong();
}

void loop() {
  delay(2000);  // Delay before replaying the song
  playSong();
}

void playSong() {
  for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
    int noteDuration = 1000 / durations[i]; // Convert to milliseconds
    if (melody[i] == 0) {
      delay(noteDuration); // Rest (pause)
    } else {
      tone(BUZZER_PIN, melody[i], noteDuration);
    }
    delay(noteDuration + 50);  // Small pause between notes
  }
  noTone(BUZZER_PIN);
}