const int BOTON = 12; // Boton Conectado al pin 12
const int LEDR = 4; // Led Rojo conectado al pin 4
const int LEDA = 2; // Led Amarillo conectado al pin 2
const int LEDV = 15; // Led Verde conectado al pin 2

int UltimoEstadoBoton;    // the previous state of button
int ActualEstadoBoton; // the current state of button
void setup() {
  Serial.begin(9600);                // initialize serial
  pinMode(BOTON, INPUT_PULLUP); // Seteo el boton en modo entrada por pulsacion
  pinMode(LEDR, OUTPUT);    
  pinMode(LEDA, OUTPUT);  
  pinMode(LEDV, OUTPUT);        // Seteo los leds en modo salida
  ActualEstadoBoton = digitalRead(BOTON);
}
void loop(){
    
  UltimoEstadoBoton    = ActualEstadoBoton;      // Gaurdar el ultimo estado del boton
  ActualEstadoBoton = digitalRead(BOTON); // Actualizar el estado del boton
  if(UltimoEstadoBoton == HIGH && ActualEstadoBoton == LOW) {
    Serial.println("EL SEMAFORO SE HA PARADO");
    // Seteo la funcionalidad al pulsionar
    digitalWrite(LEDR, HIGH);
    digitalWrite(LEDA, LOW);
    digitalWrite(LEDV, LOW);
    delay(3000);
  }
  // Aca comienza el semaforo constantemente
    digitalWrite(LEDR, HIGH);
    digitalWrite(LEDA, LOW);
    digitalWrite(LEDV, LOW);
    delay(500);
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDA, HIGH);
    digitalWrite(LEDV, LOW);
    delay(500);
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDA, LOW);
    digitalWrite(LEDV, HIGH);
    delay(500);
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDA, HIGH);
    digitalWrite(LEDV, LOW);
    delay(500);
}