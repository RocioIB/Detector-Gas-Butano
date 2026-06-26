#include <LiquidCrystal.h>

// RS, E, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int ZUMBADOR = 13;
int LED_ROJO = 10;
int LED_AMARILLO = 9;
int LED_VERDE = 8;
int sensor_MQ7 = A0;
int valor_sensor;

void setup()
{
  pinMode(ZUMBADOR, OUTPUT);
  pinMode(LED_ROJO, OUTPUT);
  pinMode(LED_AMARILLO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  
  lcd.begin(16, 2); // LCD de 16 columnas y 2 filas
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("<< SENSOR MQ7 >>");
  delay(3000);
}

void loop()
{
  valor_sensor = analogRead(sensor_MQ7);

  if (valor_sensor < 300)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("NO HAY GAS!!!");
    lcd.setCursor(0,1);
    lcd.print(">VALOR MQ-7: ");
    lcd.print(valor_sensor);
    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(LED_AMARILLO, LOW);
    digitalWrite(LED_ROJO, LOW);
    digitalWrite(ZUMBADOR, LOW);
  }

  else if (valor_sensor >= 300 && valor_sensor <= 400)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("ALERTA GAS!!!");
    lcd.setCursor(0,1);
    lcd.print(">VALOR MQ-7: ");
    lcd.print(valor_sensor);
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AMARILLO, HIGH);
    digitalWrite(LED_ROJO, LOW);
    digitalWrite(ZUMBADOR, LOW);
  }

  else if (valor_sensor > 400)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("PELIGRO GAS!!!");
    lcd.setCursor(0,1);
    lcd.print(">VALOR MQ-7: ");
    lcd.print(valor_sensor);
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AMARILLO, LOW);
    digitalWrite(LED_ROJO, HIGH);
    digitalWrite(ZUMBADOR, HIGH);
  }

  delay(200);
}
