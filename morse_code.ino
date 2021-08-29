#define SIZE 26
#define LED 8
#define TIME 300
#define SPACE 900

String to_translate = ""; // buffer
int string_length = 0;

char curr_char;
String char_to_string;

// entire alphabet
String alphabet[SIZE] = {
  "a", "b", "c", "d", "e",
  "f", "g", "h", "i", "j",
  "k", "l", "m", "n", "o",
  "p", "q", "r", "s", "t",
  "u", "v", "w", "x", "y",
  "z"
};

// morse alphabet
String morse_letters[SIZE]{
  ".-", "-...", "-.-.", "-..", ".",     // A B C D E
  "..-.", "--.", "....", "..", ".---",  // F G H I J
  "-.-", ".-..", "--", "-.", "---",     // K L M N O
  ".--.", "--.-", ".-.", "...", "-",    // P Q R S T 
  "..-", "...-", ".--", "-..-", "-.--", // U V W X Y
  "--.."                                // Z

};

// DEFINE MORSE CHARACTERS (., -, " ")
void dot(){
  // Serial.print("."); 
  
  digitalWrite(LED, HIGH);
  delay(TIME); 
  digitalWrite(LED, LOW);
  delay(TIME);
}

void dash(){
  // Serial.print("-");  

  digitalWrite(LED, HIGH);
  delay(TIME); 
  delay(TIME);
  digitalWrite(LED, LOW);
  delay(TIME);
}

void space(){
  delay(SPACE);
}

// LETTER FUNCTIONS FOR BLINKS
void letter_A()
{
  dot();
  dash();  
}

void letter_B()
{
  dash(); 
  dot();
  dot();
  dot(); 
}

void letter_C()
{
  dash(); 
  dot();
  dash(); 
  dot();    
}

void letter_D()
{
  dash();
  dot();
  dot();  
}

void letter_E()
{
  dot();  
}

void letter_F()
{
  dot();
  dot();
  dash();
  dot();  
}

void letter_G()
{
  dash();
  dash();
  dot();  
}

void letter_H()
{
  dot();
  dot();
  dot();
  dot();  
}

void letter_I()
{
  dot();
  dot();  
}

void letter_J()
{
  dot();
  dash();
  dash();
  dash();  
}

void letter_K()
{
  dash();
  dot();
  dash();  
}

void letter_L()
{
  dot();
  dash();
  dot();
  dot();  
}

void letter_M()
{
  dash();
  dash(); 
}

void letter_N()
{
  dash();
  dot();  
}

void letter_O()
{
  dash();
  dash();
  dash();  
}

void letter_P()
{
  dot();
  dash();
  dash();
  dot();  
}

void letter_Q()
{
  dash();
  dash();
  dot();
  dash();  
}

void letter_R()
{
  dot();
  dash();
  dot();  
}

void letter_S()
{
  dot();
  dot();
  dot();  
}

void letter_T()
{
  dash();  
}

void letter_U()
{
  dot();
  dot();
  dash();  
}

void letter_V()
{
  dot();
  dot();
  dot();
  dash();  
}

void letter_W()
{
  dot();
  dash();
  dash();  
}

void letter_X()
{
  dash();
  dot();
  dot();
  dash();  
}

void letter_Y()
{
  dash();
  dot();
  dash();
  dash();  
}

void letter_Z()
{
  dash();
  dash();
  dot();
  dot();  
}

// Create array of functions
typedef void(*morse_function)();

morse_function morse_blinkers[] =
{
  letter_A, letter_B, letter_C, letter_D, letter_E,
  letter_F, letter_G, letter_H, letter_I, letter_J,
  letter_K, letter_L, letter_M, letter_N, letter_O,
  letter_P, letter_Q, letter_R, letter_S, letter_T,
  letter_U, letter_V, letter_W, letter_X, letter_Y,
  letter_Z,
};

// Compare and output function
void morse(char curr_char) {
  
  char_to_string = String(curr_char); // char to string for compare
  
  if(char_to_string == " ")
  {
     Serial.print(" ");  
  }

  for(int i = 0; i < SIZE; i++){ 
      
      if(char_to_string == alphabet[i])
      {
        Serial.print(morse_letters[i]); // print morse to terminal
        morse_blinkers[i](); // follow up with LED morse blinks
        
      }
  }
 
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(Serial.available() > 0)
  {
    to_translate = Serial.readString(); // grab string from terminal
    Serial.print(to_translate);
    to_translate.toLowerCase(); // make string all lowercase; no diff between upper/lowercase in morse
    
    string_length = to_translate.length();

    // Identify the letter, output as morse code blinks
    for(int i = 0; i < string_length; i++)
    {
      curr_char = to_translate.charAt(i);
      morse(curr_char);
      space();
      Serial.print(" ");
    }
  
    Serial.println("");
      
  }
}
