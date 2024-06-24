/* Добавить кнопку перехода пешехода в светофор
Алгоритм работы:
1. Пешеход нажимает кнопку.
2. Через определенное программно время (например, 5 сек) светофор для машин переходит в режим
мигающий-желтый 3 раза.
3. Красный для перехода пешеходов горит строго определенное время, сколько бы раз кнопку не
нажимали
4. После "зеленого" с установленным временем задержки (5 сек) происходит разрешение нажатия
кнопки (до этого кнопка не реагирует)
Светофор готов к новому циклу. */

int button = 2;
int red_led = 11;
int yellow_led = 12;
int green_led = 13;
boolean ledOn = HIGH;

void setup()
{
  pinMode(red_led, OUTPUT);
  pinMode(yellow_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(button, INPUT);
  Serial.begin(9600);
}

void loop()
{
  //digitalWrite(green_led, HIGH);
  if (digitalRead(button))
  {
    delay(5000);
    digitalWrite(green_led, LOW);
    for (int i = 0; i<6; i++)
    {
      ledOn = !ledOn;
      digitalWrite(yellow_led, ledOn);
      delay(500);
    }
    digitalWrite(yellow_led, LOW);
    digitalWrite(red_led, HIGH);
    delay(5000);
    digitalWrite(red_led, LOW);
    digitalWrite(green_led, HIGH);
    delay(5000);
    Serial.println("Ready!");
  }
  else
  {
    digitalWrite(green_led, HIGH);
  }
}
