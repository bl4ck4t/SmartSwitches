//Constants
const int buttonPin = 2;     
const int ledPin =  13;     

//Variables
int buttonState = 0;
int flag=0;

void setup() {
  //Input or output?
  pinMode(ledPin, OUTPUT);      
  pinMode(buttonPin, INPUT_PULLUP);  
  Serial.begin(9600); 
}

void loop(){
   if (Serial.available() > 0) {
   int state = Serial.read();
   if (state == '1') {
     digitalWrite(ledPin, HIGH);
   }
   if (state == '0') {
     digitalWrite(ledPin, LOW);
     }
   }
  //Read button state (pressed or not pressed?)
  buttonState = digitalRead(buttonPin);

  //If button pressed...
  if (buttonState == LOW) { 
    //...ones, turn led on!
    if ( flag == 0){
      digitalWrite(ledPin, HIGH);
      flag=1; //change flag variable
    }
    //...twice, turn led off!
    else if ( flag == 1){
      digitalWrite(ledPin, LOW);
      flag=0; //change flag variable again 
    }    
  }
  delay(200); //Small delay
   
}
