int Vin = 5;
int Pin1 = 0;
int Pin2 = 0;
int Pin3 = 0;

float Vin1 = 0;
float Vin2 = 0;
float Vin3 = 0;

float R0 = 390 ; //given resistor value
float R1 = 0;
float R2 = 0;
float R3 = 0;

float OutputR1 = 0;
float OutputR2 = 0;
float OutputR3 = 0;
float numerator;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Pin1 = analogRead( A0 );
  Pin2 = analogRead( A1 );
  Pin3 = analogRead( A2 );

  Vin1 = (Pin1*Vin)/1024.0;
  Vin2 = (Pin2*Vin)/1024.0;
  Vin3 = (Pin3*Vin)/1024.0;

  R1 = R0 * ( ( Vin2/Vin1 ) - 1 );
  R2 = R0 * ( ( Vin3/Vin1 ) - 1) - R1;
  R3 = R0 * ( ( Vin/Vin1) - 1) - R1 - R2;

  numerator = ( R1*R2 ) + ( R1*R3 ) + ( R2*R3 );

  OutputR1 = numerator/R3;
  OutputR2 = numerator/R2;
  OutputR3 = numerator/R1;

  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();

  Serial.print( "R1 = " );
  Serial.println( R1 );
  Serial.print( "R2 = " );
  Serial.println( R2 );
  Serial.print( "R3 = " );
  Serial.println( R3 );

  Serial.println();
  Serial.print( "New Values: " );
  Serial.println();
  Serial.print( "R1 = " );
  Serial.println( OutputR1 );
  Serial.print( "R2 = " );
  Serial.println( OutputR2 );
  Serial.print( "R3 = " );
  Serial.println( OutputR3 );

  delay(3000);
  
}