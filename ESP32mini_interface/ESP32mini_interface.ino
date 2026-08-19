#include <TFT_eSPI.h>
#include "BluetoothSerial.h"
#include <WiFi.h>
#include <FS.h>
#include <LittleFS.h>
using fs::FS;
#include <WebServer.h>
BluetoothSerial BT;
TFT_eSPI tft=TFT_eSPI();
int buttonk=32;
int buttondurumuk=0;
int button=12;
int buttondurumu=0;
int button2=33;
int buttondurumu2=0;
//
int menu=0;
int menu2=0;
//
int buttoncooldown=0;
int buttoncooldown2=0;
int buttocooldownk=0;
//
int osdeger=0;
int baudrate=0;
int osx=0;
int gpio=0;
int gpior=5;
//
int pincool=0;
int pincool2=0;
int togglepin=0;
//
int builtinled=2;
//
int menuyaazdirmacooldown=0;
static const unsigned char PROGMEM image_arrow_curved_right_up_bits[] = {0x00,0x00,0xff,0xff,0x00,0x00,0xff,0xff,0x00,0x00,0xff,0xff,0x00,0x00,0xff,0xff,0x00,0x00,0x0f,0xff,0x00,0x00,0x0f,0xff,0x00,0x00,0x0f,0xff,0x00,0x00,0x0f,0xff,0xf0,0x00,0xff,0xff,0xf0,0x00,0xff,0xff,0xf0,0x00,0xff,0xff,0xf0,0x00,0xff,0xff,0x0f,0xff,0xff,0x0f,0x0f,0xff,0xff,0x0f,0x0f,0xff,0xff,0x0f,0x0f,0xff,0xff,0x0f,0x00,0x0f,0xf0,0x00,0x00,0x0f,0xf0,0x00,0x00,0x0f,0xf0,0x00,0x00,0x0f,0xf0,0x00};
static const unsigned char PROGMEM image_ButtonDown_bits[] = {0xff,0xff,0xff,0xff,0xe0,0xff,0xff,0xff,0xff,0xe0,0xff,0xff,0xff,0xff,0xe0,0xff,0xff,0xff,0xff,0xe0,0xff,0xff,0xff,0xff,0xe0,0x07,0xff,0xff,0xfc,0x00,0x07,0xff,0xff,0xfc,0x00,0x07,0xff,0xff,0xfc,0x00,0x07,0xff,0xff,0xfc,0x00,0x07,0xff,0xff,0xfc,0x00,0x00,0x3f,0xff,0x80,0x00,0x00,0x3f,0xff,0x80,0x00,0x00,0x3f,0xff,0x80,0x00,0x00,0x3f,0xff,0x80,0x00,0x00,0x3f,0xff,0x80,0x00,0x00,0x01,0xf0,0x00,0x00,0x00,0x01,0xf0,0x00,0x00,0x00,0x01,0xf0,0x00,0x00,0x00,0x01,0xf0,0x00,0x00,0x00,0x01,0xf0,0x00,0x00};
static const unsigned char PROGMEM image_ButtonUp_bits[] = {0x00,0x01,0xf0,0x00,0x00,0x00,0x01,0xf0,0x00,0x00,0x00,0x01,0xf0,0x00,0x00,0x00,0x01,0xf0,0x00,0x00,0x00,0x01,0xf0,0x00,0x00,0x00,0x3f,0xff,0x80,0x00,0x00,0x3f,0xff,0x80,0x00,0x00,0x3f,0xff,0x80,0x00,0x00,0x3f,0xff,0x80,0x00,0x00,0x3f,0xff,0x80,0x00,0x07,0xff,0xff,0xfc,0x00,0x07,0xff,0xff,0xfc,0x00,0x07,0xff,0xff,0xfc,0x00,0x07,0xff,0xff,0xfc,0x00,0x07,0xff,0xff,0xfc,0x00,0xff,0xff,0xff,0xff,0xe0,0xff,0xff,0xff,0xff,0xe0,0xff,0xff,0xff,0xff,0xe0,0xff,0xff,0xff,0xff,0xe0,0xff,0xff,0xff,0xff,0xe0};
void drawScreen(void) {
    tft.fillScreen(0x0);
    // rect 1
    tft.drawRect(8, 3, 61, 120, 0xFFFF);
    // ellipse 2
    tft.drawEllipse(135, 24, 22, 22, 0xFFFF);
    // rect 3
    tft.drawRect(5, -1, 67, 127, 0xFFFF);
    // ButtonUp
    tft.drawBitmap(78, 71, image_ButtonUp_bits, 35, 20, 0xFFFF);
    // ButtonDown
    tft.drawBitmap(78, 98, image_ButtonDown_bits, 35, 20, 0xFFFF);
    // arrow_curved_right_up
    tft.drawBitmap(77, 17, image_arrow_curved_right_up_bits, 32, 20, 0xFFFF);

}
int ziplamatoggle=0;
int kareyartma=0;
int kareyazalma=0;
int kareysilme=0;
int kareysilmeust;
//
int engelx=0;
int engelxazalma=0;
int engelxsilme=0;
int kaybetme=0;
int karey=1;
//
void drawBTmenu(void) {
    tft.fillScreen(0x0);
    // rect 1
    tft.drawRect(3, 2, 154, 38, 0xFFFF);
    // string 2
    tft.setTextColor(0xFFFF);
    tft.setTextSize(1);
    tft.drawString("CPU frequency", 7, 17);
    // line 3
    tft.drawLine(91, 3, 91, 39, 0xFFFF);
    // rect 4
    tft.drawRect(98, 47, 55, 78, 0xFFFF);
    // line 5
    tft.drawLine(99, 64, 152, 64, 0xFFFF);
    // string 6
    tft.setCursor(110,50);
       tft.setTextSize(2);
    tft.print("WIP");
  
 
}
int cpu=240;
int cpup=0;
int cpum=0;
int ekrannumbersilem=0;
//
void drawBLE(void) {
    tft.fillScreen(0x0);
    // rect 1
    tft.drawRect(26, 5, 112, 18, 0xFFFF);
    // string 2
    tft.setTextColor(0xFFFF);
    tft.setTextSize(1);
    tft.drawString("BLE TERMINAL", 48, 11);
    // line 3
    tft.drawLine(123, 6, 123, 21, 0xFFFF);
    // line 4
    tft.drawLine(43, 5, 43, 21, 0xFFFF);

}
int y=30;
int yazalma=0;
String komut;
void drawWifi(void) {
    tft.fillScreen(0x0);
    // rect 1
    tft.drawRect(16, 0, 124, 22, 0xFFFF);
    // string 2
    tft.setTextColor(0xFFFF);
    tft.setTextSize(1);
    tft.drawString("Wifi Terminal", 41, 8);
    // line 3
    tft.drawLine(120, 1, 120, 20, 0xFFFF);
    // line 4
    tft.drawLine(36, 20, 36, 1, 0xFFFF);
    // rect 7
    tft.drawRect(12, 33, 139, 90, 0xFFFF);
    // rect 8
    tft.drawRect(10, 30, 144, 95, 0xFFFF);
    tft.drawRect(137, 34, 1, 1, 0xFFFF);
}
int wifisayisi;
String wifiad;
//
int wifiy=39;
int wifiycooldown=0;
int wifitarama=1;
int wifiyazmac=0;
//
void drawMath(void) {
    tft.fillScreen(0x0);
    // rect 1
    tft.drawRect(29, 4, 97, 36, 0xFFFF);
    // string 2
    tft.setTextColor(0xFFFF);
    tft.setTextSize(1);
    tft.drawString("Soru:", 33, 18);
    // rect 3
    tft.drawRect(16, 78, 45, 37, 0xFFFF);
    // rect 3 copy 1
    tft.drawRect(93, 79, 45, 37, 0xFFFF);
    // string 5
    tft.drawString("A", 35, 81);
    // string 5 copy 1
    tft.drawString("B", 113, 81);
    // line 7
    tft.drawLine(17, 89, 59, 89, 0xFFFF);
    // line 8
    tft.drawLine(94, 89, 136, 89, 0xFFFF);

}
//
int randomsecme=0;
int sayisecmecooldown=0;
int sayi=0;
int sayi2=0;
int sonuc;
int randomcevap=0;
int randomcevapc=0;
//
int A=0;
int B=0;
int randomsik=0;
int randomsik2=0;
void drawLogic(void) {
    tft.fillScreen(0x0);
    // rect 1
    tft.drawRect(19, 3, 112, 28, 0xFFFF);
    // rect 1 copy 1
    tft.drawRect(17, 1, 116, 32, 0xFFFF);
    // string 3
    tft.setTextColor(0xFFFF);
    tft.setTextSize(1);
    tft.drawString("BASIC LOGIC ANALYZ", 22, 12);
    // ellipse 4
    tft.drawEllipse(138, 53, 19, 17, 0xFFFF);
    // rect 5
    tft.drawRect(88, 38, 28, 15, 0xFFFF);
    // rect 6
    tft.drawRect(86, 36, 32, 19, 0xFFFF);
    // string 7
    tft.drawString("GPIO", 91, 42);
    // rect 8
    tft.drawRect(4, 87, 152, 33, 0xFFFF);
    // rect 9
    tft.drawRect(2, 85, 156, 37, 0xFFFF);
    // rect 10
    tft.drawRect(15, 67, 39, 15, 0xFFFF);
    // string 11
    tft.drawString("OUTPUT", 17, 71);
    // rect 12
    tft.drawRect(13, 65, 43, 19, 0xFFFF);

}
int gpiopin=0;
int gpionumber=0;
int baudrat=0;
int logicx=8;//+9
//
void drawSort(void) {
    tft.fillScreen(0x0);
    // rect 1
    tft.drawRect(7, 5, 144, 51, 0xFFFF);
    // ellipse 2
    tft.drawEllipse(133, 108, 15, 16, 0xFFFF);

}
int pinartmacooldown=0;
int pinazalmacooldown=0;
int silmekonum;
int sifirsilme;
//
int karaktery=70;
int karaktersilmey=0;
int karakterartma;
int karakterazalma;
int karaktersilmey2;
//
int eny[2]={random(10,100),random(10,100)};
int enx[2]={160,160};
int ensil[2]={enx[1]+6,enx[0]+6};
int enxazalma;
int hitbox;
int hitboxarka;
int collisionpoint;
//
int blokx=110;
int bloky=108;
bool bloksaso=false;
int blokstate[3]={110,128,144};
int currentstate=0;
int blokazalma;
int eskixbakma;
int eskixbak=-1;
int eskix;
int eskic;
//
int resimdelay=0;
int frame=0;
void drawBench(void) {
    tft.fillScreen(0x0);
    tft.drawRect(17, 3, 127, 28, 0xFFFF);
    tft.drawRect(15, 1, 131, 32, 0xFFFF);
    tft.setTextColor(0xFFFF);
    tft.setTextSize(2);
    tft.drawString("BENCHMARK", 26, 9);
    tft.drawRect(136, 68, 18, 17, 0xFFFF);
    tft.drawRect(134, 66, 22, 21, 0xFFFF);
    tft.drawRect(3, 95, 154, 30, 0xFFFF);
    tft.drawRect(1, 93, 158, 34, 0xFFFF);
    tft.drawRect(4, 75, 33, 14, 0xFFFF);
    tft.drawRect(2, 73, 37, 18, 0xFFFF);
    tft.setTextSize(1);
    tft.drawString("SCORE", 6, 78);
       tft.drawRect(59, 36, 45, 34, 0xFFFF);
    tft.drawRect(57, 34, 49, 38, 0xFFFF);
    tft.drawString("0-100", 63, 38);
    tft.drawString("250-500", 61, 59);
    tft.drawString("100-250", 60, 49);
    }
    bool togglebenchmark=false;
int silmeon;
int toggle;
//
int forbench;
int skor;
int zaman;
static const unsigned char PROGMEM image_bluetooth_connected_bits[] = {0x01,0x00,0x02,0x80,0x02,0x40,0x22,0x20,0x12,0x20,0x4a,0x48,0x26,0x90,0x33,0x30,0x26,0x90,0x4a,0x48,0x12,0x20,0x22,0x20,0x02,0x40,0x02,0x80,0x01,0x00,0x00,0x00};
static const unsigned char PROGMEM image_paint_10_bits[] = {0x00,0x00,0x00,0xc0,0x00,0x00,0x01,0x80,0x00,0x00,0x06,0x00,0x00,0x00,0x0c,0x00,0x00,0x00,0x18,0x00,0x00,0x00,0x30,0x00,0x00,0x00,0x60,0x00,0x00,0x00,0xc0,0x00,0x00,0x01,0x80,0x00,0x80,0x01,0x00,0x00,0xc0,0x03,0x00,0x00,0x40,0x02,0x00,0x00,0x30,0x06,0x00,0x00,0x18,0x04,0x00,0x00,0x0c,0x04,0x00,0x00,0x03,0x08,0x00,0x00,0x01,0xc8,0x00,0x00,0x00,0x78,0x00,0x00};
static const unsigned char PROGMEM image_paint_11_bits[] = {0x80,0x00,0x00,0xc0,0x00,0x0c,0x60,0x00,0x18,0x30,0x00,0x30,0x10,0x00,0x60,0x0c,0x00,0xc0,0x06,0x01,0x00,0x03,0x02,0x00,0x01,0x84,0x00,0x00,0xcc,0x00,0x00,0x30,0x00,0x00,0x38,0x00,0x00,0x4c,0x00,0x00,0xc6,0x00,0x03,0x03,0x00,0x06,0x00,0xc0,0x0c,0x00,0x60,0x18,0x00,0x30,0x30,0x00,0x1c,0x60,0x00,0x04};
void drawScreen2(void) {
    tft.fillScreen(0x0);
    tft.drawRect(6, 3, 153, 80, 0xFFFF);
    tft.drawEllipse(142, 105, 14, 14, 0xFFFF);
    tft.setTextColor(0xFFFF);
    tft.setTextSize(1);
    tft.drawString("10", 137, 102);
    tft.drawRect(3, 90, 60, 28, 0xFFFF);
    tft.drawBitmap(8, 96, image_bluetooth_connected_bits, 14, 16, 0xFFFF);
    tft.drawLine(27, 91, 27, 116, 0xFFFF);

}
int ble;
//
int birdartmac;
int birdazalmac;
int birdy=110;
int birdys;
int motion=20;
//
int towerx=170;
int towersizes[5]={34,59,66,50,20};
int towersizepick=random(0,5);
int towerxgelme;
bool tg=false;
//
int dvdx=30;
int dvdy=20;
int vx=2;
int vy=1;
int dvdcooldown;
int randomrenk=random(0,6);
//

int cizgix=60;
int cizgiy=50;
int cizgix2=80;
int cizgiy2=60;
//
int cizgicooldown=0;
int cizgimods=0;

int boxx=1;
int boxx2=101;
//
int boxv=2;
int box2v=1;
int boxvartma;
//
int pongx=44;
int pongartma;
int pongazalma;
//
int pongtopx=50;
int pongtopy=50;
int pongxv=1;
int pongyv=1;
int pongartma2=0;
//
void drawos(void) {
    tft.fillScreen(0x0);
    tft.drawRect(10, 3, 45, 51, 0xFFFF);
    tft.setTextColor(0xFFFF);
    tft.setTextSize(1);
    tft.drawString("Pinler", 16, 7);
    tft.drawLine(11, 15, 53, 15, 0xFFFF);
    tft.drawString("GPIO 34", 12, 20);
    tft.drawString("GPIO 14", 12, 32);
    tft.drawString("GPIO 27", 12, 42);
    tft.drawRect(8, 1, 49, 55, 0xFFFF);
    tft.drawEllipse(127, 28, 21, 23, 0xFFFF);
    tft.drawRect(18, 89, 122, 20, 0xFFFF);
    tft.setTextSize(2);
    tft.drawString("Ossiloskop", 20, 91);
    tft.drawRect(16, 87, 126, 24, 0xFFFF);
    tft.drawLine(79, 0, 79, 86, 0xFFFF);
    tft.drawLine(0, 64, 31, 86, 0xFFFF);
    tft.drawLine(159, 63, 127, 86, 0xFFFF);
    tft.drawLine(79, 66, 61, 86, 0xFFFF);
    tft.drawLine(80, 67, 95, 86, 0xFFFF);
}
int gpio1[3]={34,14,27};
int gpiosecilen=0;
int gpiosecilengorme=0;
int ostoggle=0;
//
int oc=0;
int oc2=0;
//
int degismecooldown=0;
//
int yenilenmerate=0;
//
int baudrate2;
int buzzer=26;
void drawos2(void) {
    tft.fillScreen(0x0);
    tft.drawEllipse(132, 25, 24, 22, 0xFFFF);
    tft.drawLine(106, 0, 106, 127, 0xFFFF);
    tft.drawEllipse(132, 25, 24, 22, 0xFFFF);
    tft.drawEllipse(132, 103, 24, 22, 0xFFFF);
       tft.drawRect(110, 50, 47, 30, 0xFFFF);
    tft.setTextColor(0xFFFF);
    tft.setTextSize(1);
    tft.drawString("GPIO", 121, 53);
    tft.drawString("ANALOG", 115, 70);
    tft.drawString("  &", 119, 61);
}
int cooldown1=0;
int cooldown2=0;
int gpioreadd;
int gpioreada;
int oldx;
int oldy;
int newy;
int newx=105;
void drawChat(void) {
    tft.fillScreen(0x0);
    tft.drawRect(1, 1, 81, 11, 0xFFFF);
    tft.setTextColor(0xFFFF);
    tft.setTextSize(1);
    tft.drawString("BT TERMINAL++", 3, 3);
    tft.drawRect(83, 1, 21, 11, 0xFFFF);
    tft.drawRect(106, 1, 52, 11, 0xFFFF);
}
int chatyartma=0;
int chaty=19;
int basicdelay=0;
int spamtime;
int dotcooldown=0;
int beepcooldown=0;
int saniye=0;
int saat=0;
int dakika=0;
int saniyecooldown=0;
int silbiya=0;
int silbiya2=0;
//
void menupopo(void) {
    tft.fillScreen(0x0);
    tft.drawRect(2, 1, 127, 126, 0xFFFF);
    tft.drawEllipse(144, 15, 13, 13, 0xFFFF);

}
int menuyirmicooldown=0;
int menyirmicooldown2=0;
//
int shotdurum=0;
int shotx=51;
int idbullet=2;
int bulletvcooldown=0;
//
int enemyshotx=130;
int enemyshotspeed=70;
int enemyshotid=0;
int cooldo=0;
//
int boty=60;
int botengely=random(1,127);
int botengelx=165;
int botazalma=0;
int botalaz=0;
int ayrılma=0;
const unsigned char fastfetch[] PROGMEM = {
  0x00, 0x00, 0x0F, 0xC0, 0x00, 0x00, 0x00, 0x0F, 0xF8, 0x00, 0x00, 0x0E, 0x03, 0xFE, 0x00, 0x02,
  0x1F, 0xE0, 0xFF, 0x00, 0x06, 0x3F, 0xF8, 0x3F, 0xC0, 0x0C, 0x7F, 0xFE, 0x1F, 0xE0, 0x1C, 0x7F,
  0xFF, 0x87, 0xF0, 0x18, 0x7F, 0xFF, 0xC3, 0xF0, 0x30, 0x01, 0xFF, 0xE1, 0xF8, 0x30, 0x00, 0x3F,
  0xF8, 0xFC, 0x60, 0xF8, 0x0F, 0xFC, 0x7C, 0x63, 0xFF, 0x83, 0xFE, 0x3E, 0x67, 0xFF, 0xE1, 0xFE,
  0x3E, 0x4F, 0xFF, 0xF0, 0xFF, 0x1E, 0xCF, 0xFF, 0xFC, 0x7F, 0x8F, 0xCF, 0xFF, 0xFE, 0x3F, 0xCF,
  0xDF, 0x87, 0xFF, 0x1F, 0xC7, 0xDF, 0x81, 0xFF, 0x8F, 0xE7, 0xDF, 0xE0, 0x7F, 0xCF, 0xE3, 0xCF,
  0xFC, 0x3F, 0xC7, 0xF3, 0xCF, 0xFF, 0x0F, 0xE3, 0xF0, 0xC7, 0xFF, 0x8F, 0xF3, 0xF0, 0xC3, 0xFF,
  0xC7, 0xF1, 0xF8, 0x41, 0xFF, 0xE3, 0xF1, 0xF8, 0x60, 0x1F, 0xF3, 0xF9, 0xF8, 0x60, 0x07, 0xF1,
  0xF9, 0xFC, 0x20, 0x03, 0xF9, 0xF8, 0xFC, 0x30, 0x71, 0xF9, 0xF8, 0xF8, 0x10, 0xF9, 0xF8, 0xFC,
  0xF8, 0x18, 0xF9, 0xF8, 0xFC, 0xF0, 0x0C, 0xF8, 0xFC, 0xFC, 0xE0, 0x06, 0xF8, 0xFC, 0xFC, 0x00,
  0x06, 0x21, 0xF8, 0xFC, 0x00, 0x03, 0x81, 0xF8, 0xFC, 0x18, 0x01, 0xC1, 0xF9, 0xF8, 0x38, 0x00,
  0x60, 0xF8, 0x70, 0x60, 0x00, 0x38, 0x00, 0x01, 0xC0, 0x00, 0x0E, 0x00, 0x0F, 0x00, 0x00, 0x03,
  0xF0, 0xFC, 0x00, 0x00, 0x00, 0x7F, 0xE0, 0x00
};
void setup(){
BT.begin("ble TERMINAL");
pinMode(button,INPUT_PULLUP);
pinMode(button2,INPUT_PULLUP);
pinMode(buttonk,INPUT_PULLUP);
pinMode(builtinled,OUTPUT);
tft.init();
tft.fillScreen(TFT_BLACK);
tft.setRotation(3);
 drawScreen(); 
 WiFi.begin("yourwifiname","yourpasswordwifi");
 sayi=random(0,50);
sayi2=random(0,50);
pinMode(34, INPUT);
pinMode(14, INPUT);
pinMode(27, INPUT);
pinMode(buzzer,OUTPUT);
}
void loop() {

  if(BT.hasClient()){
    digitalWrite(builtinled,HIGH);
  }else{
    digitalWrite(builtinled,LOW);
  }
buttondurumu=digitalRead(button);
buttondurumu2=digitalRead(button2);
buttondurumuk=digitalRead(buttonk);
if(menu==0){
 tft.fillEllipse(142, 105, 11, 12, 0x0);
   ekrannumbersilem++;
   if(ekrannumbersilem==5){

}
if(ekrannumbersilem>=15){
ekrannumbersilem=15;
}
  tft.setCursor(10,10);
tft.setTextSize(0);
tft.print("1.Osikop");
  tft.setCursor(10,20);
  tft.print("2.CBG");
    tft.setCursor(10,30);
    tft.print("3.System");
        tft.setCursor(10,40);
    tft.print("4.BTS");
                tft.setCursor(10,50);
    tft.print("5.WFT");
            tft.setCursor(10,60);
    tft.print("6.MTQ");
                tft.setCursor(10,70);
    tft.print("7.BLA");
                    tft.setCursor(10,80);
    tft.print("8.DGG");
                        tft.setCursor(10,90);
    tft.print("9.BG");
                            tft.setCursor(10,100);
    tft.print("10.??");
                                tft.setCursor(10,110);
    tft.print("11.BENCH");
tft.setTextSize(2);
tft.setCursor(121,16);
tft.print(menu2);
if(buttondurumu==LOW){
buttoncooldown++;
if(buttoncooldown==3){
  tft.fillCircle(135, 24, 20,TFT_BLACK);
menu2++;
}
}else{
buttoncooldown=0;  
}
//
if(buttondurumu2==LOW){
buttoncooldown2++;
if(buttoncooldown2==3){
  tft.fillCircle(135, 24, 20,TFT_BLACK);
menu2--;
}
}else{
buttoncooldown2=0;  
}
if(buttondurumuk==LOW){
  if(menu2==1){
    menu=1;
          tft.fillScreen(TFT_WHITE);
  }
  if(menu2==2){
  tft.fillScreen(TFT_BLACK);
menu=2;
menu2=0;
}
if(menu2==3){
menu=3;
menu2=0;
drawBTmenu();
}
if(menu2==4){
menu2=0;
menu=4;
drawBLE();
}
if(menu2==5){
menu2=0;
menu=5;
drawWifi();
}
if(menu2==6){
menu=6;
menu2=0;
drawMath();
}
if(menu2==7){
menu=7;
menu2=0;
drawLogic();
}
if(menu2==8){
menu=8;
menu2=0;
tft.fillScreen(TFT_BLACK);
}
if(menu2==9){
menu=9;
menu2=0;
tft.fillScreen(TFT_BLACK);
}
if(menu2==10){
menu=10;
menu2=0;
tft.fillScreen(TFT_BLACK);
}
if(menu2==11){
menu=11;
menu2=0;
tft.fillScreen(TFT_BLACK);
drawBench();
}
if(menu2>11){
menu=12;
menu2=12;

}
}
if(menu2<0){
menu2=0;
}
if(menu2>11){ 
menu=12;
drawScreen2();
tft.fillEllipse(142, 105, 11, 12, 0x0);
}

}else{
ekrannumbersilem=0;
}
if(menu==1){
  baudrate++;
  if(baudrate>200){
baudrate=0;
osx++;
  }
  tft.drawPixel(osx,gpior,TFT_GREEN);
  if(osx>=160){
    osx=0;
    tft.fillScreen(TFT_WHITE);
  }
tft.setRotation(1);
if(buttondurumu==LOW&&buttondurumu2==LOW){
   tft.fillScreen(TFT_BLACK);
menu=0;
menu2=0;
osx=0;
  tft.setRotation(3);
 drawScreen();
}
if(togglepin==0){
  pincool++;
  if(pincool>random(10,150)){
    pincool=0;
    gpior++;
  }
  if(gpior>128){
    togglepin=1;
  }
}else{
   pincool2++;
  if(pincool2>random(10,150)){
    pincool2=0;
    gpior--;
  }
    if(gpior<0){
    togglepin=0;
  }
}
}
if(menu==2){
   tft.setRotation(1);
  if(kaybetme==0){ 
  kareysilme=karey-25;
  kareysilmeust=karey+25;
tft.fillRect(64,karey,25,25,TFT_YELLOW);
tft.fillRect(64,kareysilmeust,25,25,TFT_BLACK);
if(buttondurumu==LOW){
buttoncooldown++;
if(buttoncooldown==5){
  ziplamatoggle=1;
}
}else{
  if(karey==1){
    buttoncooldown=0;
  }
}

//
if(ziplamatoggle==1){
  if(karey<40){
    kareyazalma++;
    if(kareyazalma>10){
      kareyazalma=0;
      karey++;
    }
  }else{
  ziplamatoggle=0;
  }
}else{
  if(karey<1){
  karey=1;
  }
  if(karey>1){
    kareyartma++;
    if(kareyartma>10){
      kareyartma=0;
      karey--;
    }
  }
}
engelxazalma++;
if(engelxazalma>10){
  engelxazalma=0;
  engelx++;
}
engelxsilme=engelx-3;
if(engelx>180){
engelx=0;
}
tft.fillCircle(engelx,6,3,TFT_RED);
tft.fillCircle(engelxsilme,6,3,TFT_BLACK);
  }else{
  engelx=0;
tft.fillScreen(TFT_GREEN);
if(buttondurumuk==LOW){
tft.fillScreen(TFT_BLACK);
kaybetme=0;
}
  }
if(buttondurumu2==LOW){
menu=0;
menu2=0;
tft.setRotation(3);
tft.fillScreen(TFT_BLACK);
drawScreen();
engelx=0;
kaybetme=0;
}
if(engelx>63){
if(engelx<89){
  if(karey<20){
    kaybetme=1;
  }
}
}else{
   tft.fillRect(64,kareysilme,25,21,TFT_BLACK);
}
}
if(menu==3){
setCpuFrequencyMhz(cpu);
tft.setCursor(106,20);
tft.setTextSize(2);
tft.print(cpu);
tft.setCursor(10,68);
tft.setTextSize(1);
tft.print(WiFi.localIP());
if(buttondurumu2==LOW&&buttondurumu==LOW){
 tft.setRotation(3);
menu=0;
menu2=0;
drawScreen();
}
if(buttondurumu==LOW){
cpup++;
if(cpup==3){
if(cpu<240){
cpu=cpu+10;
}
tft.fillRect(97, 5, 55, 31, TFT_BLACK);
}
}else{
cpup=0;
}
if(buttondurumu2==LOW){
cpum++;
if(cpum==3){
if(cpu>0){
cpu=cpu-10;
}
tft.fillRect(97, 5, 55, 31, TFT_BLACK);
}
}else{
cpum=0;
}
}
if(menu==4){
if(buttondurumu==LOW&&buttondurumu2==LOW){
menu=0;
drawScreen();
y=30;
}
if(BT.available()){
komut=BT.readString();
yazalma++;
if(yazalma==1){
y=y+10;
}
tft.setCursor(8,y);
tft.print(komut);
}else{
yazalma=0;
}
if(y>115){
y=30;
drawBLE();
}
}
if(menu==5){
wifisayisi=WiFi.scanNetworks();
wifiad=WiFi.SSID(wifitarama);
if(wifisayisi>0){
wifiycooldown++;
if(wifiycooldown>3){
wifiycooldown=0;
if(wifiy<119){
wifiy=wifiy+7;
}
}
wifiyazmac++;
if(wifiyazmac>5){
wifiyazmac=0;
if(wifiy<119){
wifitarama++;
}
tft.setCursor(20,wifiy);
tft.print(wifiad);
}
}
if(wifiy>119){
menu=0;
tft.fillScreen(TFT_BLACK);
drawScreen();
wifiy=39;
}
}
if(menu==6){

randomsecme++;
if(randomsecme==3){
drawMath();
sayisecmecooldown++;
if(sayisecmecooldown==3){
sayi=random(0,50);
sayi2=random(0,50);
}
randomcevap=random(1,3);
sonuc=sayi+sayi2;
if(randomcevap==1){
B=sonuc;
A=random(100,0);
}
if(randomcevap==2){
A=sonuc;
B=random(0,100);
}
tft.setCursor(30,92);
tft.print(A);
tft.setCursor(107,92);
tft.print(B);
tft.setCursor(64,11);
tft.setTextSize(2);
tft.print(sayi);
tft.setCursor(92,11);
tft.print(sayi2);
}
if(buttondurumu==LOW){
if(A==sonuc){
sayisecmecooldown=0;
randomcevapc=0;
randomsecme=0;
sayi=random(0,50);
sayi2=random(0,50);

}else{
menu=0;
sayisecmecooldown=0;
randomcevapc=0;
randomsecme=0;
drawScreen();
}
}
if(buttondurumu2==LOW){
if(B==sonuc){
sayisecmecooldown=0;
randomcevapc=0;
randomsecme=0;
sayi=random(0,50);
sayi2=random(0,50);

}else{
menu=0;
sayisecmecooldown=0;
randomcevapc=0;
randomsecme=0;
drawScreen();
}
}
}
if(menu==7){
if(buttondurumu==LOW){
pinartmacooldown++;
if(pinartmacooldown==3){
logicx=8;
 tft.fillRect(5, 88, 150, 31, 0x0);
     tft.fillEllipse(138, 53, 16, 15, 0x0);
if(gpionumber<31){
gpionumber++;
}
}
}else{
pinartmacooldown=0;
}
if(buttondurumu2==LOW){
pinazalmacooldown++;
if(pinazalmacooldown==3){
logicx=8;
 tft.fillRect(5, 88, 150, 31, 0x0);
   tft.fillEllipse(138, 53, 16, 15, 0x0);
if(gpionumber>0){
gpionumber--;
}
}
}else{
pinazalmacooldown=0;
}
tft.setCursor(128,45);
tft.setTextSize(2);
tft.print(gpionumber);
silmekonum=(logicx+11)-2;

baudrat++;
if(baudrat>500){
baudrat=0;
logicx=logicx+11;
tft.fillRect(silmekonum, 94, 12, 17,TFT_BLACK);
sifirsilme=logicx+2;
 tft.fillRect(sifirsilme, 97, 6, 11, TFT_BLACK);
}
gpiopin=digitalRead(gpionumber);
tft.setCursor(logicx,96);
tft.print(gpiopin);
if(logicx>=140){
logicx=8;
 tft.fillRect(5, 88, 150, 31, 0x0);
}
}
if(menu==8){
karaktersilmey=karaktery+1;
karaktersilmey2=karaktery-1;
if(buttondurumu==LOW){
   tft.drawRect(54, karaktersilmey, 26, 26, TFT_BLACK);
karakterartma++;
if(karakterartma>30){
karakterartma=0;
if(karaktery>0){
karaktery--;
}
}
}
if(buttondurumu2==LOW){
    tft.drawRect(54, karaktersilmey2, 26, 26, TFT_BLACK);
karakterazalma++;
if(karakterazalma>30){
karakterazalma=0;
if(karaktery<103){
karaktery++;
}
}
}


 enxazalma++;
 if(enxazalma>30){
 enxazalma=0;
 enx[0]--;
  enx[1]--;
 }
if(enx[1]<0){
enx[1]=160;
eny[1]=random(10,100);
    tft.fillRect(0, -1, 7, 127, 0x0);
}
if(enx[0]<0){
enx[0]=160;
eny[0]=random(10,100);
    tft.fillRect(0, -1, 7, 127, 0x0);
}
ensil[0] = enx[1] + 6;
ensil[1] = enx[1] + 6;
    tft.fillRect(55, karaktery, 24, 24, 0xFFFF);
  tft.fillRect(enx[1],eny[1], 6, 6, 0x24BE);
 tft.fillRect(ensil[1],eny[1], 6, 6, TFT_BLACK);
   tft.fillRect(enx[0],eny[0], 6, 6, 0x24BE);
 tft.fillRect(ensil[0],eny[0], 6, 6, TFT_BLACK);
hitbox=55+24;
hitboxarka=55+24;
collisionpoint=karaktery+25;
if(enx[0]<80){
if(enx[0]>54){
if(eny[0]<collisionpoint){
if((eny[0]+6)>karaktery){
menu=0;
drawScreen();
enx[1]=-1;
enx[0]=-1;
}
}
}
}
if(enx[1]<80){
if(enx[1]>54){
if(eny[1]<collisionpoint){
if((eny[1]+6)>karaktery-1){
menu=0;
drawScreen();
enx[1]=-1;
enx[0]=-1;
}
}
}
}
}
if(menu==9){
if(bloksaso==false){
blokazalma++;
if(blokazalma>40){
blokazalma=0;
blokx--;
}
if(blokx<=1){
bloksaso=true;
blokazalma=0;
}
    tft.fillRect((blokx+51),bloky , 50, 21, TFT_BLACK);
}else{
blokazalma++;
if(blokazalma>40){
blokazalma=0;
blokx++;
if(blokx>blokstate[currentstate]){
bloksaso=false;
}
}
    tft.fillRect((blokx-50),bloky , 50, 21, TFT_BLACK);
}
if(buttondurumu2==LOW){
eskixbakma++;
if(eskixbakma==2){
if(bloky==108){
eskix=blokx;
bloky-=21;
}else{
if(blokx>eskix){
if((blokx-20)<(eskix+51)){
blokx=eskix;
bloky-=21;
}
}
}
}
}else{
eskixbakma=0;
}
 tft.fillRect(blokx,bloky , 50, 21, TFT_WHITE);

if(bloky<0){
bloky=108;
tft.fillScreen(TFT_BLACK);
eskix=0;
menu=0;
drawScreen();
}
}
if(menu==10){

}
if(menu==11){
if(buttondurumu==LOW){
silmeon++;
if(silmeon==2){
toggle++;
  tft.fillRect(138, 70, 14, 12, 0x0);
}
if(toggle==2){
toggle=0;
zaman=0;
skor=0;
}
if(toggle==0){
togglebenchmark=false;
}else{
togglebenchmark=true;
}
}else{
silmeon=0;
}
if(togglebenchmark==true){
tft.setCursor(139,73);
tft.print("ON");
if(forbench<100000){
zaman++;
forbench=forbench+1;
}else{
skor=(100000*cpu)/zaman;
tft.setCursor(5,105);
tft.print(skor);
}
}else if(togglebenchmark==false){
tft.setCursor(139,73);
tft.print("OF");
  tft.fillRect(4, 96, 151, 28, 0x0);
}
if(buttondurumu2==LOW){
menu=0;
menu2=0;
drawScreen();
}
}
if(menu==12){
tft.setCursor(7,5);
tft.print("12.Flappy Bird Game");
tft.setCursor(7,15);
tft.print("13.DVD simulator");
tft.setCursor(7,25);
tft.print("14.3D Wall simulator");
tft.setCursor(7,35);
tft.print("15.Collision Physichs");
tft.setCursor(7,45);
tft.print("16.Pong");
tft.setCursor(7,55);
tft.print("17.Ossiloskop++");
tft.setCursor(7,65);
tft.print("18.BLE Terminal++");
tft.setCursor(137,101);
tft.print(menu2);
if(buttondurumuk==LOW){
if(menu2==12){
menu=13;
tft.fillScreen(TFT_BLACK);
}
if(menu2==13){
menu=14;
tft.fillScreen(TFT_BLACK);
}
if(menu2==14){
menu=15;
tft.fillScreen(TFT_BLACK);
}
if(menu2==15){
menu=16;
tft.fillScreen(TFT_BLACK);
}
if(menu2==16){
menu=17;
tft.fillScreen(TFT_BLACK);
}
if(menu2==17){
menu=18;
drawos();
}
if(menu2==18){
menu=19;
drawChat();
}
}
if(menu2<=11){
menu=0;
drawScreen();
}
if(buttondurumu==LOW){
if(BT.hasClient()){
if(ble==0){
tft.fillRect(28, 91, 34, 26, 0x0);
}
ble++;
tft.drawBitmap(33, 95, image_paint_10_bits, 26, 18, 0xFFFF);
}else{
if(ble>2){
ble=0;
    tft.fillRect(28, 91, 34, 26, 0x0);
}
tft.drawBitmap(33, 94, image_paint_11_bits, 22, 20, 0xFFFF);
}
buttoncooldown++;
if(buttoncooldown==3){
   tft.fillEllipse(142, 105, 11, 12, 0x0);
menu2++;
}
}else{
buttoncooldown=0;  
}
//
if(buttondurumu2==LOW){
buttoncooldown2++;
if(buttoncooldown2==3){
 tft.fillEllipse(142, 105, 11, 12, 0x0);
 menu2--;
}
}else{
buttoncooldown2=0;  
}
if(menu2>18){
menu=20;
menupopo();
}
}
if(menu==13){
if(buttondurumu==LOW){
if(tg==false){
birdartmac++;
birdazalmac--;
if(birdartmac>50){
birdartmac=0;
if(birdy>0){
birdy--;
}
}
}
if(birdy<32){
tg=true;
}
motion=10;
}else{
birdazalmac+=2;
birdartmac=0;
if(birdazalmac>motion){
birdazalmac=0;
if(birdy<110){
birdy++;
}
motion+=1;
}
}

 tft.fillRect(40, birdy, 17, 18, 0xFF47);
  tft.drawRect(39,(birdy-1), 19, 20, 0x0);
towerxgelme++;
if(towerxgelme>45){
towerxgelme=0;
towerx--;
}
 tft.fillRect((towerx+10),(129-towersizes[towersizepick]),9,towersizes[towersizepick],0x0);
     tft.fillRect(towerx,(129-towersizes[towersizepick]), 9, towersizes[towersizepick], TFT_WHITE);  
       

if(towerx<-2){
towerx=160;
towersizepick=random(0,5);
    tft.fillRect(0, 0, 7, 129, 0x0);
}
if(tg==true){
birdazalmac+=2;
birdartmac=0;
if(birdazalmac>motion){
birdazalmac=0;
if(birdy<110){
birdy++;
}
motion+=1;
}
if(birdy>94){
tg=false;
}
}
if(towerx<(40+17)){
if(towerx>40){
if(birdy>=(128-towersizes[towersizepick])){
menu2=0;
menu=0;
drawScreen();
birdy=110;
towerx=160;
}
}
}
//
if((towerx+9)<(40+17)){
if((towerx+9)>40){
if(birdy>=(128-towersizes[towersizepick])){
menu2=0;
menu=0;
drawScreen();
birdy=110;
towerx=160;
}
}
}//
}
if(menu==14){
int oldx = dvdx;
int oldy = dvdy;
dvdcooldown++;
if(dvdcooldown>100){
dvdcooldown=0;
dvdx +=vx;
dvdy +=vy;
tft.fillRect(oldx, oldy, 19, 20, TFT_BLACK);
}
if(dvdx>=141 || dvdx<=0){
vx = -vx;
randomrenk=random(0,6);
}
if(dvdy>=108 || dvdy<=0){
vy = -vy;
randomrenk=random(0,6);
}
if(randomrenk==0){
tft.fillRect(dvdx, dvdy, 19, 20, TFT_GREEN);
}
if(randomrenk==1){
tft.fillRect(dvdx, dvdy, 19, 20, TFT_YELLOW);
}
if(randomrenk==2){
tft.fillRect(dvdx, dvdy, 19, 20, TFT_BLUE);
}
if(randomrenk==3){
tft.fillRect(dvdx, dvdy, 19, 20, TFT_WHITE);
}
if(randomrenk==4){
tft.fillRect(dvdx, dvdy, 19, 20, TFT_PURPLE);
}
if(randomrenk==5){
tft.fillRect(dvdx, dvdy, 19, 20, TFT_MAGENTA);
}
if(buttondurumu==LOW){
menu=0;
drawScreen();
}
}
if(menu==15){
tft.drawRect(cizgix,cizgiy, 1, 35, 0xFFFF);
tft.drawRect(cizgix2,cizgiy2, 1, 35, 0xFFFF);
tft.drawLine(cizgix,cizgiy,cizgix2,cizgiy2, 0xFFFF);
tft.drawLine(cizgix,(cizgiy+35),cizgix2,(cizgiy2+35), 0xFFFF);
cizgicooldown++;
if(cizgicooldown>30){
cizgicooldown=0;
     if(cizgimods==0){
     cizgix++;
     cizgix2--;
     cizgiy++;
     cizgiy2--;
     }else{
          cizgix--;
     cizgix2++;
     cizgiy--;
     cizgiy2++;
     }
     if(cizgimods==0){
if(cizgix>=80){
cizgimods=1;
}
}else{
if(cizgix2>=80){
cizgimods=0;
}
}
tft.fillScreen(TFT_BLACK);
 }
 if(buttondurumu==LOW){
 menu=0;
 drawScreen();
 }
}
if(menu==16){
boxvartma++;
if(boxvartma>35){
boxvartma=0;
boxx +=boxv;
boxx2 +=box2v;
tft.fillScreen(TFT_BLACK);
}
if((boxx+26)>boxx2){
boxx=boxx-2;
boxx2=boxx2+2;
boxv =-boxv;
box2v =-box2v;
}
if(boxx2<(boxx+26)){
boxx=boxx-2;
boxx2=boxx2+2;
box2v =-box2v;
boxv =-boxv;
}
if(boxx>134){
boxx=134;
boxv =-boxv;
}
if(boxx<0){
boxx=0;
boxv =-boxv;
}
if(boxx2>134 ){
boxx2=134;
box2v =-box2v;
}
if(boxx2<0){
boxx2=0;
box2v =-box2v;
}
    tft.fillRect(boxx, 104, 26, 24, 0x3A96);
      tft.fillRect(boxx2, 109, 19, 19, 0x55E);
if(buttondurumu==LOW){
menu=0;
menu2=0;
drawScreen();
}
}
if(menu==17){
if(buttondurumu==LOW){
pongartma++;
if(pongartma>30){
pongartma=0;
if(pongx<95){
pongx++;
}
}
}else{
pongartma=0;
}
if(buttondurumu2==LOW){
pongazalma++;
if(pongazalma>30){
pongazalma=0;
if(pongx>0){
pongx--;
}
}
}else{
pongazalma=0;
}
tft.fillRect(pongx, 111, 65, 17, 0xFFFF);
tft.fillRect((pongx-4), 111, 4, 17, 0x0);
 tft.fillRect((pongx+65), 111, 4, 17, 0x0);
pongartma2++;
if(pongartma2>40){
pongartma2=0;
pongtopx +=pongxv;
pongtopy +=pongyv;
    tft.fillRect(0, 0, 160, 111, 0x0);
}
if(pongtopx>144){
pongtopx=144;
pongxv =-pongxv;
}
if(pongtopx<0){
pongtopx=1;
pongxv =-pongxv;
}
if(pongtopy<0){
pongtopy=1;
pongyv =-pongyv;
}
if(pongtopy>94){
if(pongtopx>pongx){
if(pongtopx<(pongx+65)){
pongtopy=93;
pongyv =-pongyv;
}
}else{
if((pongtopx+15)>pongx){
if((pongtopx+15)<(pongx+65)){
pongtopy=93;
pongyv =-pongyv;
}
}
}
}
tft.fillRect(pongtopx,pongtopy, 16, 17, 0x55E);
if(pongtopy>98){
pongtopx=50;
pongtopy=50;
menu=0;
menu2=0;
drawScreen();
}
}
if(menu==18){
if(ostoggle==0){
if(buttondurumu==LOW){
oc++;
if(oc==4){
    tft.fillEllipse(127, 27, 17, 17, 0x0);
if(gpiosecilengorme!=3){
gpiosecilen++;
}
}
}else{
oc=0;
}

if(buttondurumu2==LOW){
oc2++;
if(oc2==4){
    tft.fillEllipse(127, 27, 17, 17, 0x0);
if(gpiosecilengorme>1){
gpiosecilen--;
}
}
}else{
oc2=0;
}
gpiosecilengorme=gpiosecilen+1;
tft.setCursor(120, 17);
tft.print(gpiosecilengorme);
degismecooldown++;
if(buttondurumuk==LOW){
if(degismecooldown>1000){
ostoggle=1;
drawos2();
}
}
}else{

yenilenmerate++;
if(yenilenmerate>5000){
yenilenmerate=0;
if(gpioreada==LOW){
cooldown1=30;
if(cooldown2==30){
cooldown2=0;
tft.fillEllipse(132, 25, 21, 20, 0x0);
}
}else{
cooldown2=30;
if(cooldown1==30){
cooldown1=0;
tft.fillEllipse(132, 25, 21, 20, 0x0);
}
}
tft.setTextSize(4);
tft.setCursor(123,10);
if(gpioreada>2){
tft.print("1");
}else{
tft.print("0");
}
gpioreada=analogRead(gpio1[gpiosecilen]);
tft.setCursor(121,99);
tft.setTextSize(1);
tft.setTextColor(TFT_WHITE,0x0);
tft.print(gpioreada);
if(gpioreada<1000){
    tft.fillRect(138, 98, 7, 9, 0x0);
}
if(gpioreada<10){
    tft.fillRect(132, 98, 7, 9, 0x0);
}
}
baudrate2++;
newy=gpioreada/32;
if(baudrate2>300){
baudrate2=0;
oldy=newy;
oldx=newx;
if(newx>0){
newx--;
}else{
newx=105;
tft.fillRect(0, 0, 106, 128, 0x0);
oldx=0;
oldy=0;
}
}
tft.drawLine(oldx,oldy,newx,newy,TFT_GREEN);
}
}else{
ostoggle=0;
degismecooldown=0;
}
if(menu==19){
if(BT.hasClient()){
tft.setCursor(85,3);
tft.setTextColor(TFT_WHITE,0x0);
tft.print("on ");
saniyecooldown++;
if(saniyecooldown>=101){
saniyecooldown=0;
saniye++;
}
if(saniye>=60){
saniye=0;
tft.fillRect(148, 2, 5, 9, 0x0);
dakika++;
if(dakika>=60){
dakika=0;
 tft.fillRect(131, 2, 7, 9, 0x0);
saat++;
if(saat>=24){
saat=0;
dakika=0;
saniye=0;
 tft.fillRect(131, 2, 7, 9, 0x0);
}
}
} 
if(silbiya<50){
silbiya++;
}
if(silbiya==5){
tft.fillRect(107, 2, 50, 9, 0x0);
silbiya2=0;
}
tft.setTextColor(TFT_WHITE);
   tft.drawString(" :  :", 113, 3);
   tft.setTextColor(TFT_WHITE,0x0);
   tft.setCursor(142,3);
   tft.print(saniye);
      tft.setCursor(125,3);
   tft.print(dakika);
      tft.setCursor(108,3);
   tft.print(saat);
}else{
if(silbiya2<50){
silbiya2++;
}
if(silbiya2==3){
tft.fillRect(107, 2, 50, 9, 0x0);
silbiya=0;
}
tft.setCursor(85,3);
tft.setTextColor(TFT_WHITE,0x0);
tft.print("off");
tft.setCursor(122,3);
tft.print("off");
}

if(BT.available()){
tft.setTextColor(TFT_WHITE);
basicdelay=0;
chatyartma++;
if(chatyartma==4){
spamtime=0;
String chatmesaj=BT.readString();
if(chaty>=100){
chaty=19;
tft.fillRect(0, 13, 161, 114, 0x0);
}else{
chaty +=9;
}
tft.setCursor(5,chaty);
tft.print("<BT>");
if(chatmesaj.length()>21){
tft.setTextColor(0x3A96);
tft.setCursor(30,chaty);
tft.print("Text too long");
}else{
tft.setTextColor(TFT_WHITE);
tft.setCursor(30,chaty);
tft.print(chatmesaj);
}
}else{
spamtime++;
if(spamtime==4){
BT.print("No spaming");
}
}
}else{
basicdelay++;
if(basicdelay>20){
basicdelay=0;
chatyartma=0;
}
if(BT.hasClient()){
if(buttondurumu==LOW){
dotcooldown++;
if(dotcooldown==3){
chaty +=9;
tft.setTextColor(TFT_GREEN);
tft.setCursor(5,chaty);
tft.print("<ESP>");
tft.setCursor(37,chaty);
tft.print("DOT/.");
BT.print(".");
}
}else{
dotcooldown=0;
}
//
if(buttondurumu2==LOW){
beepcooldown++;
if(beepcooldown==3){
chaty +=9;
tft.setTextColor(TFT_GREEN);
tft.setCursor(5,chaty);
tft.print("<ESP>");
tft.setCursor(37,chaty);
tft.print("BEEP/-");
BT.print("-");
}
}else{
beepcooldown=0;
}
}
if(chaty>=100){
chaty=19;
tft.fillRect(0, 13, 161, 114, 0x0);
}else{
}
tft.fillRect(0, (chaty+8), 159, 100, 0x0);
}
}
if(menu==20){
if(buttondurumu==LOW){
menuyirmicooldown++;
if(menuyirmicooldown==3){
tft.fillEllipse(144, 15, 12, 12, 0x0000);
menu2++;
}
}else{
menuyirmicooldown=0;
}
if(buttondurumu2==LOW){
menyirmicooldown2++;
if(menyirmicooldown2==3){
tft.fillEllipse(144, 15, 12, 12, 0x0000);
menu2--;
}
}else{
menyirmicooldown2=0;
}
tft.setCursor(5,10);
tft.print("19.DVD simulator?");
tft.setCursor(5,25);
tft.print("20.Fast Fetch");
tft.setCursor(138,12);
tft.print(menu2);
if(menu2==18){
menu=12;
drawScreen2();
tft.fillEllipse(142, 105, 11, 12, 0x0);
tft.drawBitmap(8, 96, image_bluetooth_connected_bits, 14, 16, 0xFFFF);
}
if(buttondurumuk==LOW){
if(menu2==19){
tft.fillScreen(TFT_BLACK);
menu=21;
}
if(menu2==20){
tft.fillScreen(TFT_BLACK);
menu=22;
}
}
}
if(menu==21){
if(shotdurum==0){
idbullet=2;
tft.fillRect(30,44,20,20,TFT_WHITE);
if(buttondurumu==LOW){
shotdurum=1;
idbullet=0;
shotx=51;
tft.fillRect(30,44,20,20,TFT_GREEN);
}
if(buttondurumu2==LOW){
shotdurum=2;
shotx=51;
idbullet=1;
tft.fillRect(30,44,20,20,TFT_YELLOW);
}
}
if(shotdurum==1){
tft.fillRect(shotx,44,15,15,TFT_GREEN);
bulletvcooldown++;
if(bulletvcooldown>45){
bulletvcooldown=0;
shotx++;
tft.drawRect((shotx-1),43,16,16,0x0);
}
if(shotx>145){
shotdurum=0;
shotx=-51;
}
}
if(shotdurum==2){
tft.fillRect(shotx,44,15,15,TFT_YELLOW);
bulletvcooldown++;
if(bulletvcooldown>45){
bulletvcooldown=0;
shotx++;
tft.drawRect((shotx-1),43,16,16,0x0);
}
if(shotx>145){
shotdurum=0;
shotx=-51;
}
}
cooldo++;
if(cooldo>enemyshotspeed){
cooldo=0;
enemyshotx--;
tft.drawRect((enemyshotx+1),43,16,16,0x0);
}
if(enemyshotid==0){
tft.fillRect(enemyshotx,44,15,15,TFT_GREEN);
}
if(enemyshotid==1){
tft.fillRect(enemyshotx,44,15,15,TFT_YELLOW);
}
if(enemyshotx<=30){
drawScreen2();
menu=12;
shotdurum=0;
enemyshotx=140;
shotx=-51;
cooldo=0;
bulletvcooldown=0;
}
if(shotdurum!=0 && shotx+15>=enemyshotx && shotx<=enemyshotx+15){
if(enemyshotid==idbullet){
shotdurum=0;
shotx=-51;
enemyshotx=170;
enemyshotid=random(0,2);
enemyshotspeed=random(35,90);
cooldo=0;
bulletvcooldown=0;
tft.fillRect(31,1,170,170,0x0);
}else{
drawScreen2();
menu=12;
shotdurum=0;
enemyshotx=140;
shotx=-51;
cooldo=0;
bulletvcooldown=0;
}
}
}
if(menu==22){

}
}






