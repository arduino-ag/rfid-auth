#include "RFID_AUTH.h"

Auth::Auth() : uid_length(4) {};

Auth::Auth(byte resetPowerDownPin, size_t uid_length) : mfrc522(resetPowerDownPin), uid_length(uid_length) {};

Auth::Auth(byte chipSelectPin, byte resetPowerDownPin, size_t uid_length) : mfrc522(chipSelectPin, resetPowerDownPin), uid_length(uid_length) {};

void Auth::wait_until_confirmed()
{
    bool done = false;

    while (!done)
    {
        while (true)
        {
            if (this->mfrc522.PICC_IsNewCardPresent())
            {
                break;
            }

            if (this->mfrc522.PICC_ReadCardSerial())
            {
                break;
            }
        }

        for (size_t eeprom_offset = 0; eeprom_offset < EEPROM.length() / this->uid_length; eeprom_offset++)
        {
            bool current_iteration = true;
            for (byte i = 0; i < this->mfrc522.uid.size; i++)
            {
                current_iteration &= (this->mfrc522.uid.uidByte[i] == EEPROM[i + eeprom_offset * this->mfrc522.uid.size]);
            }

            done |= current_iteration;
        }
    }
};
