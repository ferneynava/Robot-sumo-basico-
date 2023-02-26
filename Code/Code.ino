// Definir los pines de los sensores
int sensorIzquierdo = A0;
int sensorDerecho = A1;

// Definir los pines de los motores
int motorIzquierdoA = 2;
int motorIzquierdoB = 3;
int motorDerechoA = 4;
int motorDerechoB = 5;

// Definir la velocidad de los motores
int velocidad = 200;

void setup() {
  // Configurar los pines de los sensores como entradas
  pinMode(sensorIzquierdo, INPUT);
  pinMode(sensorDerecho, INPUT);

  // Configurar los pines de los motores como salidas
  pinMode(motorIzquierdoA, OUTPUT);
  pinMode(motorIzquierdoB, OUTPUT);
  pinMode(motorDerechoA, OUTPUT);
  pinMode(motorDerechoB, OUTPUT);
}

void loop() {
  // Leer los valores de los sensores
  int valorIzquierdo = analogRead(sensorIzquierdo);
  int valorDerecho = analogRead(sensorDerecho);

  // Si ambos sensores detectan una línea, avanzar
  if (valorIzquierdo > 800 && valorDerecho > 800) {
    avanzar();
  }
  // Si solo el sensor izquierdo detecta una línea, girar a la derecha
  else if (valorIzquierdo > 800) {
    girarDerecha();
  }
  // Si solo el sensor derecho detecta una línea, girar a la izquierda
  else if (valorDerecho > 800) {
    girarIzquierda();
  }
  // Si ningún sensor detecta una línea, dar marcha atrás y girar aleatoriamente
  else {
    marchaAtras();
    delay(500);
    detener();
    delay(500);
    int aleatorio = random(0, 2);
    if (aleatorio == 0) {
      girarDerecha();
    }
    else {
      girarIzquierda();
    }
  }
}

// Función para avanzar
void avanzar() {
  digitalWrite(motorIzquierdoA, HIGH);
  digitalWrite(motorIzquierdoB, LOW);
  digitalWrite(motorDerechoA, HIGH);
  digitalWrite(motorDerechoB, LOW);
}

// Función para girar a la derecha
void girarDerecha() {
  digitalWrite(motorIzquierdoA, LOW);
  digitalWrite(motorIzquierdoB, HIGH);
  digitalWrite(motorDerechoA, HIGH);
  digitalWrite(motorDerechoB, LOW);
  delay(400);
}

// Función para girar a la izquierda
void girarIzquierda() {
  digitalWrite(motorIzquierdoA, HIGH);
  digitalWrite(motorIzquierdoB, LOW);
  digitalWrite(motorDerechoA, LOW);
  digitalWrite(motorDerechoB, HIGH);
  delay(400);
}

// Función para dar marcha atrás
void marchaAtras() {
  digitalWrite(motorIzquierdoA, LOW);
  digitalWrite(motorIzquierdoB, HIGH);
  digitalWrite(motorDerechoA, LOW);
  digitalWrite(motorDerechoB, HIGH);
}

// Función para detener el robot
void detener()
