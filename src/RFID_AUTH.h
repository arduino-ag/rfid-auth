#ifndef RFID_AUTH_H
#define RFID_AUTH_H

#include <Arduino.h>
#include <EEPROM.h>
#include <stdint.h>

#include <MFRC522.h>

class Auth {
private:
    MFRC522 mfrc522; 
    size_t uid_length = 0;

    Auth();
public:
	Auth(byte resetPowerDownPin, size_t uid_length);
	Auth(byte chipSelectPin, byte resetPowerDownPin, size_t uid_length);

    void wait_until_confirmed();
};

#endif