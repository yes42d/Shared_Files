#include <LiquidCrystal.h>
const int RS=12, E=11, D4=5, D5=4, D6=3, D7=2;
LiquidCrystal lcd(RS, E, D4, D5, D6, D7);
const int T_pin= A0;

byte deg[8] = {
	0b00111,
	0b00101,
	0b00111,
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00000
};

void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
lcd.createChar(0, deg);
lcd.setCursor(0,0);
lcd.print("Orion Tech Tube");
}

void loop() {
  // put your main code here, to run repeatedly:
int L_o;
float V_o, T_degC;
L_o=analogRead(T_pin);
V_o=0.0048876*L_o;
T_degC=round(50-11*V_o);
lcd.setCursor(0,1);
lcd.print("R_Temp:");
lcd.setCursor(8,1);
lcd.print(T_degC);
lcd.setCursor(13,1);
lcd.write(byte(0));
lcd.setCursor(14,1);
lcd.print("C");
}
