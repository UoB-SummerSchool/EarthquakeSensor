#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>

byte deviceName[5] = "XXXXX"; // The name of this device - this should be unique !
int payloadSize = 9;

void setup()
{
  Mirf.spi = &MirfHardwareSpi;
  Mirf.init();
  Mirf.setRADDR(deviceName);  // Tell the radio board the name of this device
  Mirf.setTADDR("GRAPH");     // Tell the radio board the device to transmit messages to
  Mirf.payload = payloadSize; // Set the size of the message packet to 9 bytes
  Mirf.channel = 90;          // Set radio communications to channel 90
  Mirf.config();
}

void loop()
{
  byte message[payloadSize];
  message[0] = 0x00;
  // Need to add some code to insert the name of this device into the message (must be in bytes 1-5)
  // Also needs some code to insert the magnitude reading into the message (must be in bytes 6 and 7)
  // Need to use the highByte and lowByte functions to split the magnitude reading into two bytes
  message[8] = 0xFF;
  Mirf.send(message);
  while (Mirf.isSending()) delay(1);
}
