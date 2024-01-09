#include <M5StickCPlus.h>
#include <SD.h>
#include <SPI.h>

#define SD_SCK 0
#define SD_MISO 36
#define SD_MOSI 26
#define SD_CS -1

SPIClass *SD_SPI = new SPIClass();

void setup() {
  M5.begin();

  M5.Lcd.setRotation(3);
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextSize(2);

  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.println("Initializing SD...");

  // Direciona a comunicação SPI para os GPIOs onde o Shield do SD Card está conectado
  SD_SPI->begin(SD_SCK, SD_MISO, SD_MOSI, SD_CS);

  // Inicia o SD Card com a comunicação SPI customizada
  bool initialized = SD.begin(SD_CS, *SD_SPI);

  if (initialized) {
    M5.Lcd.setTextColor(GREEN);
    M5.Lcd.println("SD initialized!");
    uint64_t sdSizeMB = SD.cardSize() / (1024 * 1024);
    M5.Lcd.println("SD Size: " + String(sdSizeMB) + "MB");
  } else {
    M5.Lcd.setTextColor(RED);
    M5.Lcd.println("Failed to mount SD");
  }
}

void loop() {
}
