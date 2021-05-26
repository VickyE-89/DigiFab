//Definerer alle lampene til pin og setter som variabler for senere bruk
#define yellowLED 3
#define blueLED 4
#define redLED 5
#define greenLED 6 
#define whiteLED 7

// Tilfeldig tider lysene kan lyse i
int timesOn[] = {400, 600, 800, 1000, 1200}; 

// Tilfeldig forsinkelse mellom lysene
int delayTimes[] = {500, 700, 900, 1100, 1300};

//Variabler for å sjekke om lysene er på eller ikke  
volatile boolean yellowLight = false;
volatile boolean blueLight = false;
volatile boolean redLight = false;
volatile boolean greenLight = false;
volatile boolean whiteLight = false;

// For å sjekke om man har vunnet.
volatile boolean isWinner = false; 


void setup() {
  pinMode(yellowLED, OUTPUT); //Gult lys
  pinMode(blueLED, OUTPUT); // Blått lys
  pinMode(redLED, OUTPUT); // Rødt lys
  pinMode(greenLED, OUTPUT); // Grønt lys 
  pinMode(whiteLED, OUTPUT); // Hvitt lys

  attachInterrupt(digitalPinToInterrupt(2), checkWinnerYellow, CHANGE); // Gul knapp
  attachInterrupt(digitalPinToInterrupt(18), checkWinnerBlue, CHANGE); // Blå knapp
  attachInterrupt(digitalPinToInterrupt(19), checkWinnerRed, CHANGE); // Rød knapp
  attachInterrupt(digitalPinToInterrupt(20), checkWinnerGreen, CHANGE); // Grønn knapp
  attachInterrupt(digitalPinToInterrupt(21), checkWinnerWhite, CHANGE); // Hvit knapp 
  turnOffLEDs();

}

void loop() {
  //Velger et tilfeldig lys
  int randomLED = random(1,6);
  //Velger en tilfeldig tid lyset skal være tent fra listen(array) definert over
  int timeLEDIsLit = timesOn[random(5)];
  //Skrur på det valgte lyset
  lightLED(randomLED, timeLEDIsLit);
  //Skrur av alle lys
  turnOffLEDs();
  //pauser i tilfeldig valgt tid fra listen definert over
  int delayTime = delayTimes[random(5)];
  //Sjekker om vinner variabelen er sann
  if (isWinner) {
    //Hvis det er en vinner, setter vinner variabelen tilbake til falsk
    //og deretter utfører vinner sekvensen
    isWinner = false;
    winner();
  }
}

//Metode for å skru på tilfeldig lys
//Bruker switch-case for å skille de forskjellige mulighetene 
//Hvert tilfelle skrur på hvert sitt lys og setter tilhørende variabel til sann
void lightLED(int led, int duration) {
  switch (led) {
    case 1: // Gul
      digitalWrite(yellowLED, HIGH);
      yellowLight = true;
      break;
     case 2: //Blå
      digitalWrite(blueLED, HIGH);
      blueLight = true;
      break;
     case 3: // Rød
      digitalWrite(redLED, HIGH);
      redLight = true;
      break;
     case 4: // Grønn
      digitalWrite(greenLED, HIGH);
      greenLight = true;
      break;
     case 5: // Hvit
      digitalWrite(whiteLED, HIGH);
      whiteLight = true;
      break;
     default:
      break;
     }
     //vent forsinkelses tiden
     delay(duration);
     // Nullstiller alle variabler for påskrudd lys
     yellowLight = false;
     blueLight = false;
     redLight = false;
     greenLight = false; 
     whiteLight = false; 
   }

//Metode for å skru alle lys av
void turnOffLEDs() {
  digitalWrite(yellowLED, LOW);
  digitalWrite(blueLED, LOW);
  digitalWrite(redLED, LOW);
  digitalWrite(greenLED, LOW);
  digitalWrite(whiteLED, LOW);
  }

//Metode for å indikere et vinn
void winner() {
  // Alle lys blinker 3 ganger hver gang man trykker på riktig knapp til riktig tid 
  for (int i=0; i<3; i++) {
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    delay(250);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    delay(250);
  }
  delay(2000);
}

//Metode kalt når gul knapp trykkes
void checkWinnerYellow() {
  //Hvis variabel for gult lys er sann
  if(yellowLight) {
    // Sett variabel for vinner til sann
    isWinner = true;
  }
}

//Metode kalt når blå knapp trykkes
void checkWinnerBlue() {
  //Hvis variabel for blått lys er sann
  if(blueLight) {
    //Sett variabel for vinner til sann
    isWinner = true;
  }
}

//Metode kalt når rød knapp trykkes
void checkWinnerRed() {
  //Hvis variabel for rødt lys er sann
  if(redLight) {
    //Sett variabel for vinner til sann
    isWinner = true;
  }
}

//Metode kalt når grønn knapp trykkes
void checkWinnerGreen() {
  //Hvis variabel for grønt lys er sann
  if(greenLight) {
    //Sett variabel for vinner til sann
    isWinner = true; 
   }
}

//Metode kalt når hvit knapp trykkes
void checkWinnerWhite() {
  //Hvis variabel for hvitt lys er sann
  if(whiteLight) {
    //Sett variabel for vinner til sann
    isWinner = true; 
  }
}
