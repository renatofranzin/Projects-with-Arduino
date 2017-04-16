#include <LiquidCrystal.h>

// Pino analogico para ligacao do LM35
int sensor = 0;
int motor = 6;

// Variaveis que armazenam a temperatura
int temp = 0;

// Variaveis que armazenam PWM
int pwm = 0;
int potencia = 0;

//Define os pinos que serão ligados ao LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
  lcd.begin(16, 2); //Inicializa
  lcd.print("TEMP: ");
  lcd.setCursor(10, 0);
  lcd.print("C");

  lcd.setCursor(0, 1);
  lcd.print("PWM: ");
  lcd.setCursor(11, 1);
  lcd.print("%");

  pinMode (motor, OUTPUT);
}

void loop()
{
  temp = ( 5.0 * analogRead(sensor) * 100.0) / 1024.0;
  delay(100);
  lcd.setCursor(7, 0);
  lcd.print(temp, DEC); //Escreve no display o valor da temperatura

  if (temp < 20)
  {
    pwm = 0;
    potencia = (pwm * 255) / 100;
    analogWrite(motor, potencia);
    lcd.setCursor(7, 1);
    lcd.print("   "); //Apaga o valor do PWM anterior: 4 espaços
    lcd.setCursor(7, 1);
    lcd.print(pwm, DEC); //Escreve no display o valor do PWM

  }
  if (temp >= 20 && temp < 30)
  {
    pwm = 25;
    potencia = (pwm * 255) / 100;
    analogWrite(motor, potencia);
    lcd.setCursor(7, 1);
    lcd.print("    "); //Apaga o valor do PWM anterior: 4 espaços
    lcd.setCursor(7, 1);
    lcd.print(pwm, DEC); //Escreve no display o valor do PWM
  }
}
