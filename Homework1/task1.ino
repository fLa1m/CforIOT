/*
Сделать “светофор” на трех светодиодах: красный, желтый, зеленый
Светофор работает в строгой последовательности цветов сигналов
1. Зеленый сигнал — разрешает движение в данном направлении.
2. Зеленый мигающий сигнал 3 раза — разрешает движение и предупреждает, что будет смена сигнала.
3. Желтый сигнал — запрещает движение и предупреждает, что будет красный сигнал.
4. Красный сигнал — запрещает движение в данном направлении
*/

int led_red = 13;
int led_yellow = 12;
int led_green = 11;
boolean ledOn = HIGH;
void setup()
{
  pinMode(led_red, OUTPUT);
  pinMode(led_yellow, OUTPUT);
  pinMode(led_green, OUTPUT);
}
void loop()
{
  digitalWrite(led_red, HIGH);
  delay(2000); // Wait for 10000 millisecond(s)
  digitalWrite(led_yellow, HIGH);
  delay(1000);
  digitalWrite(led_red, LOW);
  digitalWrite(led_yellow, LOW);
  digitalWrite(led_green, HIGH);
  delay(2000); // Wait for 1000 millisecond(s)
  for (int i = 0; i<6; i++)
  {
    ledOn = !ledOn;
    digitalWrite(led_green, ledOn);
    delay(500);
  }
  digitalWrite(led_green, LOW);
  digitalWrite(led_yellow, HIGH);
  delay(2000);
  digitalWrite(led_yellow, LOW);
}
