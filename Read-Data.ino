// Read data from SD card on Spresense

#include <Arduino.h>
#include <File.h>

File myFile; /**< File object */ 

/**
 * @brief Write to the file and read from the file.
 * 
 * @details The file is located on the SD card.
 */
void setup() {

  /* Open serial communications and wait for port to open */
  Serial.begin(115200);
  while (!Serial) {
    ; /* wait for serial port to connect. Needed for native USB port only */
  }


  /* Re-open the file for reading */
  myFile = File("/Data/test.csv");

  if (myFile) {
    Serial.println("test.csv:");

    /* Read from the file until there's nothing else in it */
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    /* Close the file */
    myFile.close();
  } else {
    /* If the file didn't open, print an error */
    Serial.println("error opening test.csv");
  }
}

void loop() {

}
