#include <LiquidCrystal.h>
#include <Keypad.h>

LiquidCrystal lcd(13,12,3,2,1,0);

String senha = "4002";
String buf = ""; 
const byte LINHAS = 4;
const byte COLUNAS = 4;
int i = 0;
char keys [LINHAS] [COLUNAS] =
{
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[LINHAS] = {11,10,9,8};
byte colPins[COLUNAS] = {7,6,5,4};

Keypad teclado = Keypad (makeKeymap(keys), rowPins, colPins, LINHAS, COLUNAS);
                         
//

int pos=7;

void password() {
  while (i<4){
  lcd.setCursor (0,0);
  lcd.print ("SENHA:");
    
  char key = teclado.getKey();
  if (key != NO_KEY){
  buf+= key;
  lcd.setCursor(pos,0);
  lcd.print("*");
  i++;
    pos++;
   }
  }
   if (buf == senha){
  lcd.setCursor(0,1);
  lcd.print("SENHA OK");
  digitalWrite(A2,HIGH);
  delay(3000);
  lcd.clear();
  lcd.print ("SENHA:");
  i=0;
     pos=7;
  buf = "";
   }
  if (buf != senha){ 
  lcd.setCursor(0,1);
  lcd.print("SENHA INCORRETA");
  delay(1000);
  lcd.clear();
  lcd.print("SENHA:");
  i=0;
    pos=7;
  buf = "";
  }  
}

//
                         
void setup(){
  
  lcd.begin(16,2);
  lcd.print("INICIANDO");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("SENHA:");
  } 

void loop(){
  
  digitalWrite(A2,LOW);
  char key = teclado.getKey();
  if (key != NO_KEY){  
  password();
    }
  } 
