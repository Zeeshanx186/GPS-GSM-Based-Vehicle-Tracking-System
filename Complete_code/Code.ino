
#include <TinyGPS++.h>
#include <SoftwareSerial.h>



#include <SPI.h>
#include <Adafruit_GFX.h>
#include <TFT_ILI9163C.h>

#if defined(_SAM3X8E_)
#undef __FlashStringHelper::F(string_literal)
#define F(string_literal) string_literal
#endif


// Color definitions
#define  BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
uint8_t errorCode = 0;

TFT_ILI9163C tft = TFT_ILI9163C(10, 9, 12);

static const int RXPin = 4, TXPin =5;
static const uint32_t GPSBaud = 9600;

TinyGPSPlus gps;
int temp=0,i;
// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);
String stringVal = "";
void setup(){
 Serial.begin(9600);
  unsigned long start = micros();
  long unsigned debug_start = millis ();
  while (!Serial && ((millis () - debug_start) <= 5000)) ;
  tft.begin();

  errorCode = tft.errorCode();
  if (errorCode != 0) {
    Serial.print("Init error! ");
    if (bitRead(errorCode, 0)) Serial.print("MOSI or SCLK pin mismach!\n");
    if (bitRead(errorCode, 1)) Serial.print("CS or DC pin mismach!\n");
  } else {
    Serial.println(F("Benchmark                Time (microseconds)"));
  }
  if (errorCode == 0) {


    Serial.print(F("Text                     "));

 
 
  ss.begin(GPSBaud);
//  lcd.begin(16,2);
  pinMode(7,OUTPUT);
  digitalWrite(7,LOW);
  tft.setCursor(0, 0);
  tft.setTextColor(WHITE);
  tft.setTextSize(1);
  tft.println("Vehicle Tracking");
   delay(3000);

  gsm_init();
 
  Serial.println("AT+CNMI=2,2,0,0,0");
  tft.setTextColor(RED);
  tft.setTextSize(1);
  tft.println("GPS Initializing");
   delay(3000);


  tft.setTextColor(WHITE);
  tft.setTextSize(1);
  tft.println("System Ready");
   delay(3000);
  temp=0;
}
}

void loop()
{
serialEvent();

      while(temp)
      {
        while (ss.available() > 0)
        {
          gps.encode(ss.read());
                if (gps.location.isUpdated())
                {
                 temp=0;
                 digitalWrite(7,HIGH);
                 tracking();
                }
          if(!temp)
          break;  
        }
      }
      digitalWrite(7,LOW);
}
void serialEvent()
{
  while(Serial.available()>0)
  {
    if(Serial.find("Track Vehicle"))
    {
      temp=1;
      break;
    }
    else
    {
    temp=0;
    }
  }
}
void gsm_init()
{
  unsigned long start = micros();
tft.setTextColor(WHITE);
  tft.setTextSize(1);
  tft.println("Finding Module..");
   delay(3000);
  boolean at_flag=1;
  while(at_flag)
  {
    Serial.println("AT");
    delay(1);
    while(Serial.available()>0)
    {
       tft.setTextColor(WHITE);
  tft.setTextSize(1);
  tft.println("OK");
   delay(3000);
      if(Serial.find("OK"))
      at_flag=0;
    }
                                                                         
    delay(1000);
  }

tft.setTextColor(WHITE);
  tft.setTextSize(1);
  tft.println("Module Connected..");
   delay(3000);
  boolean echo_flag=1;
  while(echo_flag)
  {
    Serial.println("ATE0");
    while(Serial.available()>0)
    {
      if(Serial.find("OK"))
      echo_flag=0;
    }
    delay(1000);
  }
//  lcd.clear();
//  lcd.print("Echo OFF");
//  delay(1000);
//  lcd.clear();
//  lcd.print("Finding Network..");
  boolean net_flag=1;
  while(net_flag)
  {
    Serial.println("AT+CPIN?");
    while(Serial.available()>0)
    {
      if(Serial.find("+CPIN: READY"))
      net_flag=0;
    }
    delay(1000);
  }
//  lcd.clear();
tft.setTextColor(RED);
  tft.setTextSize(1);
  tft.println("Network Found..");
   delay(3000);
//  lcd.print("Network Found..");
 
//  delay(1000);
//  lcd.clear();
}
void init_sms()
{
  Serial.println("AT+CMGF=1");
  delay(400);
  Serial.println("AT+CMGS=\"+923313727449\"");   // use your 10 digit cell no. here
  delay(400);
}
void send_data(String message)
{
  Serial.print(message);
 delay(200);
}
void send_sms()
{
  Serial.write(26);
}
void led_status(){
  unsigned long start = micros();
tft.setTextColor(WHITE);
  tft.setTextSize(1);
  tft.println("Message Sent");
   delay(3000);
   tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.println("System Ready");
   delay(3000);
}

void tracking()
{
    init_sms();
    send_data("Vehicle Tracking Alert:");
    Serial.println(" ");
    send_data("Your Vehicle Current Location is:");
    Serial.println(" ");
    Serial.print("Latitude: ");
    Serial.print(gps.location.lat(), 6);
    Serial.print("\n Longitude: ");
    Serial.println(gps.location.lng(), 6);

   // https://www.google.com/maps/@8.2630696,77.3022699,14z
   Serial.print("https://www.google.com/maps/@");
   Serial.print(gps.location.lat(), 6);
   Serial.print(',');
   Serial.print(gps.location.lng(), 6);
   Serial.print(",14z");
    send_sms();
    delay(3000);
    led_status();
   
}
