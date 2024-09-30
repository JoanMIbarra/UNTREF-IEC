const int BOTON = 9; // Boton Conectado al pin 9
const int LEDR = 0; // Led Rojo conectado al pin 0
const int LEDA = 3; // Led Amarillo conectado al pin 3
const int LEDV = 4; // Led Verde conectado al pin 4

int UltimoEstadoBoton;    // El anterior estado del botón
int ActualEstadoBoton; // El actual estado del botón
void setup() {
  Serial.begin(9600);                // initialize serial
  pinMode(BOTON, INPUT); // Seteo el boton en modo entrada 
  pinMode(LEDR, OUTPUT);    
  pinMode(LEDA, OUTPUT);  
  pinMode(LEDV, OUTPUT);        // Seteo los leds en modo salida
  ActualEstadoBoton = digitalRead(BOTON); // Leo el estado del botón
}

void loop(){
    
  UltimoEstadoBoton    = ActualEstadoBoton;      // Gaurdar el ultimo estado del boton
  ActualEstadoBoton = digitalRead(BOTON); // Lee el estado actual del boton
  if(UltimoEstadoBoton == HIGH && ActualEstadoBoton == LOW) { //Pregunta si el botón se está pulsado
    Serial.println("EL SEMAFORO SE HA PARADO"); //Mensaje
    // Seteo la funcionalidad al pulsionar, primero amarillo unos segundos, luego rojo.
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDA, HIGH);
    digitalWrite(LEDV, LOW);
    delay(500);
    digitalWrite(LEDR, HIGH);
    digitalWrite(LEDA, LOW);
    digitalWrite(LEDV, LOW);
    delay(1000);
  }
  else{
  // Aca comienza el semaforo constantemente entre amarillo y verde
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDA, HIGH);
    digitalWrite(LEDV, LOW);
    delay(500);
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDA, LOW);
    digitalWrite(LEDV, HIGH);
    delay(500);
    }
}