//================================================
//                     BACA ABJAD HURUF DAN ANGKA
//=================================================
#define kolom1 29 
#define kolom2 28
#define kolom3 27
#define kolom4 26
#define baris1 25
#define baris2 24
#define baris3 23
#define baris4 22
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

char numpressed = "",
char timespressed = "",
char letter = "",
char simpanNamaModel = ""


void bacaAbjad()
{
  int loop=1;
  while(loop) {
  numpressed=255; //reset 
  if (readKeypad()){ //scan keypad
    timespressed=0; //reset 
    if (numpressed==0){ //ditekan 0
      dozero(); //print zero
      letter='0'; // 
      textstorage(1); //simpan huruf
    }
    if (numpressed=='D'){ //ditekan D / shift
      textstorage(2); //simpan spasi
      dospace(); //do a space
    }
    if (numpressed=='C'){ //ditekan C/ backspace
      textstorage(3); //simpan backspace
      dobackspace(); //do a backspace
    }
    if (numpressed=='#'){ //ditekan  # / enter 
     // simpanModelKeRegister();    //selesai simpan string
      simpanNamaModel(19);
     resetAbjad();
     lcd.setCursor(12,1);
     displayString(19);
      loop=0;
    }
    if (numpressed=='*'){ //ditekan * 
    lcd.clear();
     resetAbjad();
      loop=0;
    }

    
    if ((numpressed<10&&numpressed>0)||numpressed==11){ 
      lastnumpressed=numpressed; 
      basetime=millis(); 
      while (elapsed<wait){ //selama tombol ditekan cepat 
        if(readKeypad()){ //scan keypad
          if (numpressed==lastnumpressed){ //if it was the same as before,
            incrementtimespressed(); //increment "timespressed"
            basetime=basetime+(wait-(wait-elapsed)); //roll up the base time, to allow another wait period until next press of the same button
            definepress(); //use "numpressed" and "timespressed" to define "letter"

            lcd.print(letter); //print the letter that was defined
            lcd.setCursor(cursorx,cursory); //maintain cursor position
            delay(preventholddelay); 
          }
          else{ 
            disablespacedelay=true; 
            break; 
          }
        }
        elapsed=millis()-basetime; //refresh the while loop
      }
      elapsed=0; //reset 
      textstorage(1); //store character
      dospace(); 
    }
  }
  
  if (positionintypedtext==(jumlahMaxHuruf+1))
  { 
    resetAbjad();
    loop=0;
  }


  } // while looop 
}



bool readKeypad(){
  bool pressfound=false;
digitalWrite(kolom1, LOW);
digitalWrite(kolom2, HIGH);
digitalWrite(kolom3, HIGH);
digitalWrite(kolom4, HIGH);
 if(digitalRead(baris1) == 0){delay(100);pressfound=true; tone(buzzer, 3000, durasi);numpressed = 'D' ; } 
 if(digitalRead(baris2) == 0){delay(100);pressfound=true;tone(buzzer, 3000, durasi); numpressed = '#' ;}//'#'
 if(digitalRead(baris3) == 0){delay(100);pressfound=true;tone(buzzer, 3000, durasi); numpressed = 0 ; }
 if(digitalRead(baris4) == 0){delay(100);pressfound=true; tone(buzzer, 3000, durasi);numpressed = '*' ; }   
      
        //==========================================
digitalWrite(kolom1, HIGH);
digitalWrite(kolom2, LOW);
digitalWrite(kolom3, HIGH);
digitalWrite(kolom4, HIGH);

if(digitalRead(baris1) == 0){ delay(100);pressfound=true; tone(buzzer, 3000, durasi);numpressed = 'C' ;      } 
if(digitalRead(baris2) == 0){delay(100);pressfound=true; tone(buzzer, 3000, durasi);numpressed = 9 ; } 
if(digitalRead(baris3) == 0){delay(100);pressfound=true; tone(buzzer, 3000, durasi);numpressed = 8 ; } 
if(digitalRead(baris4) == 0){delay(100);pressfound=true; tone(buzzer, 3000, durasi);numpressed = 7 ; }        
        //==========================================
      
digitalWrite(kolom1, HIGH);
digitalWrite(kolom2, HIGH);
digitalWrite(kolom3, LOW);
digitalWrite(kolom4, HIGH);
       if(digitalRead(baris1) == 0){delay(100);pressfound=true; tone(buzzer, 3000, durasi);numpressed = 'B' ; } 
        if(digitalRead(baris2) == 0){delay(100);pressfound=true;tone(buzzer, 3000, durasi); numpressed = 6 ; } 
        if(digitalRead(baris3) == 0){delay(100);pressfound=true; tone(buzzer, 3000, durasi);numpressed = 5 ; }
        if(digitalRead(baris4) == 0){delay(100);pressfound=true; tone(buzzer, 3000, durasi);numpressed = 4 ; }      
        //==========================================        
        //==========================================
   
digitalWrite(kolom1, HIGH);
digitalWrite(kolom2, HIGH);
digitalWrite(kolom3, HIGH);
digitalWrite(kolom4, LOW);

        if(digitalRead(baris1) == 0){delay(100);pressfound=true; tone(buzzer, 3000, durasi);numpressed = 'A' ; } //a=10
        if(digitalRead(baris2) == 0){delay(100);pressfound=true; tone(buzzer, 3000, durasi);numpressed = 3 ; } 
        if(digitalRead(baris3) == 0){delay(100);pressfound=true; tone(buzzer, 3000, durasi);numpressed = 2 ; }
        if(digitalRead(baris4) == 0){delay(100);pressfound=true;tone(buzzer, 3000, durasi); numpressed = 1; }  

    return pressfound; 
}

void definepress(){ //uses "lastnumpressed" and "timespressed" to define "letter"
  if (lastnumpressed==1){
    if (timespressed==1){
      letter='Q';
    }
    if (timespressed==2){
      letter='Z';
    }
    if (timespressed==3){
      letter='1';
    }
  }
  if (lastnumpressed==2){
    if (timespressed==1){
      letter='A';
    }
    if (timespressed==2){
      letter='B';
    }
    if (timespressed==3){
      letter='C';
    }
    if (timespressed==4){
      letter='2';
    }
  }
  if (lastnumpressed==3){
    if (timespressed==1){
      letter='D';
    }
    if (timespressed==2){
      letter='E';
    }
    if (timespressed==3){
      letter='F';
    }
    if (timespressed==4){
      letter='3';
    }
  }
  if (lastnumpressed==4){
    if (timespressed==1){
      letter='G';
    }
    if (timespressed==2){
      letter='H';
    }
    if (timespressed==3){
      letter='I';
    }
    if (timespressed==4){
      letter='4';
    }
  }
  if (lastnumpressed==5){
    if (timespressed==1){
      letter='J';
    }
    if (timespressed==2){
      letter='K';
    }
    if (timespressed==3){
      letter='L';
    }
    if (timespressed==4){
      letter='5';
    }
  }
  if (lastnumpressed==6){
    if (timespressed==1){
      letter='M';
    }
    if (timespressed==2){
      letter='N';
    }
    if (timespressed==3){
      letter='O';
    }
    if (timespressed==4){
      letter='6';
    }
  }
  if (lastnumpressed==7){
    if (timespressed==1){
      letter='P';
    }
    if (timespressed==2){
      letter='R';
    }
    if (timespressed==3){
      letter='S';
    }
    if (timespressed==4){
      letter='7';
    }
  }
  if (lastnumpressed==8){
    if (timespressed==1){
      letter='T';
    }
    if (timespressed==2){
      letter='U';
    }
    if (timespressed==3){
      letter='V';
    }
    if (timespressed==4){
      letter='8';
    }
  }
  if (lastnumpressed==9){
    if (timespressed==1){
      letter='W';
    }
    if (timespressed==2){
      letter='X';
    }
    if (timespressed==3){
      letter='Y';
    }
    if (timespressed==4){
      letter='9';
    }
  }
  if (lastnumpressed==11){
    if (timespressed==1){
      letter='.';
    }
    if (timespressed==2){
      letter='?';
    }
    if (timespressed==3){
      letter='!';
    }
    if (timespressed==4){
      letter=',';
    }
    if (timespressed==5){
      letter='\'';
    }
    if (timespressed==6){
      letter='"';
    }
    if (timespressed==7){
      letter='-';
    }
  }
}

void incrementtimespressed(){ 
  if (timespressed==maxtimespressed[lastnumpressed]){ //if at the maximum,
    timespressed=1; //roll over timespressed to one
  }
  else{ //otherwise,
    timespressed++;
  }
}

void dozero(){ //prints zero
  lcd.print('0'); //print 0
  lcd.setCursor(cursorx,cursory); 
  dospace(); //space
}

void dospace(){ 
  if (cursory==3){
    if (cursorx==19){ 
      cursorx=0; corner
      cursory=0;
      lcd.clear(); //clear the lcd
    }
    else{ //otherwise,
      cursorx++; 
    }
  }
  else{ 
    if (cursorx==19){ 
      cursorx=0;corner
      cursory=3;
    }
    else{ //otherwise,
      cursorx++; 
    }
  }
  lcd.setCursor(cursorx,cursory); 
  if (disablespacedelay){
    disablespacedelay=false; 
  }
  else{ //otherwise,
    delay(preventholddelay); //delay a bit
  }
}

void doclear(){ //clears and returns to top-left of display
  cursorx=0;
  cursory=0;
  lcd.clear();
  lcd.setCursor(cursorx,cursory);
  delay(preventholddelay);
}

void dobackspace(){ 
  if (cursory==3){
    if (cursorx==0){
      cursorx=19;
      cursory=0;
    }
    else{
      cursorx--;
    }
  }
  else{
    if (cursorx==0){
      cursorx=0;
      cursory=0;
    }
    else{
      cursorx--;
    }
  }
  lcd.setCursor(cursorx,cursory);
  lcd.print(" ");
  lcd.setCursor(cursorx,cursory);
  delay(preventholddelay);
}

void textstorage(byte mode){ 
  if (mode==1){ 
    typedtext[positionintypedtext]=letter; 
    positionintypedtext++; 
  }
  if (mode==2){ 
    typedtext[positionintypedtext]=' '; 
    positionintypedtext++; 
  }
  if (mode==3){
    positionintypedtext--;
    typedtext[positionintypedtext]=' '; 
  }
}


void resetAbjad()
{
positionintypedtext=0;      
promptreadKeypadpress=false;
elapsed=0;
cursory=0;
cursorx=0;
numpressed=255;
 timespressed=0;

  
}//

void hapusbuffer()
{
  for(int i=0;i<jumlahMaxHuruf;i++)
  typedtext[i]=0x00;
}
