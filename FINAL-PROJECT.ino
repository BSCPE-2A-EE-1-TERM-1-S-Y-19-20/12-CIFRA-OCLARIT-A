#include "CAPACITANCE.h"
#include "INDUCTANCE.h"
void setup() {
  Serial.begin(9600);  
}

char rx_byte = 0;
void loop() {
                                     //PROMPT USER TO CHOOSE BETWEEN CAPACITANCE AND INDUCTANCE
  Serial.println ("A. Inductance");
  Serial.println ("B. Capacitance");
  if (Serial.available () > 0) {  //is a character available?
    rx_byte= Serial.read();       //get the character
  }
  

  capacitance CAPACITANCE;
  inductance INDUCTANCE;
  if ((rx_byte == 'A')||(rx_byte == 'a'))

    {
       CAPACITANCE.capsetup ();
       CAPACITANCE.caploop ();
      
    }
  else if ((rx_byte == 'B') || (rx_byte == 'b'))
    {
      INDUCTANCE.inductsetup ();
      INDUCTANCE.inductloop ();
    }

}
