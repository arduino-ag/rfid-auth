#include <RFID_AUTH.h>

constexpr int resetPin = 10;
constexpr int selectPin = 11;
constexpr int uid_lenth = 12;

Auth auth(resetPin, selectPin, uid_lenth);

void setup() {
    auth.wait_until_confirmed();
}

void loop() {

}
