#define a 2
#define b 3
#define c 4
#define d 5
#define e 6
#define f 7
#define g 8
#define dp 9
#define com1 10
#define com2 11
#define com3 12
#define com4 13

void setup() {
  // put your setup code here, to run once:
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(dp, OUTPUT);
  pinMode(com1, OUTPUT);
  pinMode(com2, OUTPUT);
  pinMode(com3, OUTPUT);
  pinMode(com4, OUTPUT);  
}
void decoder(int number){
  switch (number) {
  case 0:
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, LOW);
    digitalWrite(dp, LOW);
    break;    
  case 1:
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    digitalWrite(dp, LOW);
    break;
  case 2:
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, LOW);
    digitalWrite(g, HIGH);
    digitalWrite(dp, LOW);  
    break;
  case 3:
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, HIGH);
    digitalWrite(dp, LOW);
    break;
  case 4:
    digitalWrite(a, LOW);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    digitalWrite(dp, LOW);
    break;
  case 5:
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    digitalWrite(dp, LOW);
    break;
  case 6:
    digitalWrite(a, HIGH);
    digitalWrite(b, LOW);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    digitalWrite(dp, LOW);
    break;  
  case 7:
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    digitalWrite(dp, LOW);
    break;  
  case 8:
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    digitalWrite(dp, LOW);
    break;  
  case 9:
    digitalWrite(a, HIGH);
    digitalWrite(b, HIGH);
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    digitalWrite(dp, LOW);
    break;
  case 10:
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    digitalWrite(dp, HIGH);
    break;    
  default:
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(d, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, LOW);
    digitalWrite(dp, LOW);
    break;
  }
}

void digit_enable(int digit){
  switch(digit){
  case 1:
    digitalWrite(com1, LOW);
    digitalWrite(com2, HIGH);
    digitalWrite(com3, HIGH);
    digitalWrite(com4, HIGH);
    break;
  case 2: 
    digitalWrite(com1, HIGH);
    digitalWrite(com2, LOW);
    digitalWrite(com3, HIGH);
    digitalWrite(com4, HIGH);
    break;
  case 3:
    digitalWrite(com1, HIGH);
    digitalWrite(com2, HIGH);
    digitalWrite(com3, LOW);
    digitalWrite(com4, HIGH);
    break;
  case 4:
    digitalWrite(com1, HIGH);
    digitalWrite(com2, HIGH);
    digitalWrite(com3, HIGH);
    digitalWrite(com4, LOW);
    break;
  default:
    digitalWrite(com1, HIGH);
    digitalWrite(com2, HIGH);
    digitalWrite(com3, HIGH);
    digitalWrite(com4, HIGH);
    break;
  }
}


int get_digit1(int number){
  int digit1;
  digit1 = number/1000;
  return digit1;
}


int get_digit2(int number){
  int digit2;
  digit2 = (number/100)%10;
  return digit2;
}


int get_digit3(int number){
  int digit3;
  digit3 = (number/10)%10;
  return digit3;  
}


int get_digit4(int number){
  int digit4;
  digit4 = number%10;
  return digit4;  
}

void display4digit(int number){
  int dig1;
  int dig2;
  int dig3;
  int dig4;
  
  dig1 = get_digit1(number);
  dig2 = get_digit2(number);
  dig3 = get_digit3(number);
  dig4 = get_digit4(number);

  digit_enable(1);
  decoder(dig1);
  delay(3);
  digit_enable(2);
  decoder(dig2);
  delay(3);
  digit_enable(3);
  decoder(dig3);
  delay(3);
  digit_enable(4);
  decoder(dig4);
  delay(3);
}


void loop() {
  // put your main code here, to run repeatedly:
  int number = 0;
  int wait = 0;
 
  for(number=0; number<10000; number++){
    for(wait = 0; wait < 20; wait++){
      display4digit(number);
    }
  }
 
}
