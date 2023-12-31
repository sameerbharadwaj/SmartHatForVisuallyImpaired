#include "Talkie.h"
#include "Vocab_US_Large.h"
Talkie voice;
void setup() {
    voice.say(sp2_DANGER);
    voice.say(sp2_DANGER);
    delay(20);
    voice.say(sp2_DANGER);
    voice.say(sp2_ON);
    voice.say(sp2_LEFT);
}
void loop() {
}
