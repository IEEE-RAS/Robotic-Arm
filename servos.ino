#include <Servo.h>

Servo servo_0; // Declaração do objeto para controlar o primeiro servo
Servo servo_1; // Declaração do objeto para controlar o segundo servo
Servo servo_2; // Declaração do objeto para controlar o terceiro servo
Servo servo_3; // Declaração do objeto para controlar o quarto servo
Servo servo_4; // Declaração do objeto para controlar o quinto servo
Servo servo_5; // Declaração do objeto para controlar o sexto servo
Servo servo_6; // Declaração do objeto para controlar o sexto servo

void setup() {
  Serial.begin(9600); // Inicializar a comunicação serial
  servo_0.attach(2); // Associa o servo_0 ao pino 2
  servo_1.attach(3); // Associa o servo_1 ao pino 3
  servo_2.attach(4); // Associa o servo_2 ao pino 4
  servo_3.attach(5); // Associa o servo_3 ao pino 5
  servo_4.attach(6); // Associa o servo_4 ao pino 6
  servo_5.attach(7); // Associa o servo_5 ao pino 7
  servo_6.attach(8); // Associa o servo_5 ao pino 8
}

void loop() {
  if (Serial.available() > 0) { // Se houver dados disponíveis para ler
    String input = Serial.readStringUntil('\n'); // Ler a cadeia de dados até a quebra de linha
    int servoIndex = input.substring(0, 1).toInt(); // Obter o índice do servo
    int servoValue = input.substring(2).toInt(); // Obter o valor do servo
    
    switch (servoIndex) {
      case 1:
        servo_0.write(servoValue);
        break;
      case 2:
        servo_1.write(servoValue);
        break;
      case 3:
        servo_2.write(servoValue);
        break;
      case 4:
        servo_3.write(servoValue);
        break;
      case 5:
        servo_4.write(servoValue);
        servo_6.write(180 - servoValue);
        break;
      case 6:
        servo_5.write(servoValue);
        
        break;
      default:
        // Índice de servo inválido
        break;
    }
  }
}
