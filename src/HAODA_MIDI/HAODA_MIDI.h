#ifndef _HAODA_MIDI_H_
#define _HAODA_MIDI_H_
#include "Arduino.h"
#include "Nova.h"



class HD_MIDI
{
public:

	HD_MIDI(uint8_t port);
	void write(uint8_t b);
	void Send(uint8_t ,uint8_t,uint8_t );

	
private:
	uint8_t _MP3_pin;
};
HD_MIDI::HD_MIDI(uint8_t port)
{
    _MP3_pin = port;
    pinMode(_MP3_pin, OUTPUT);
    digitalWrite(_MP3_pin, HIGH);
}

void HD_MIDI::write(uint8_t b)
{
    pinMode(_MP3_pin, OUTPUT);
    digitalWrite(_MP3_pin, HIGH);

    uint8_t mask;
    digitalWrite(_MP3_pin, LOW);
    delayMicroseconds(30);

    for (mask = 0x01; mask; mask <<= 1) {
        if (b & mask) { // choose bit
            digitalWrite(_MP3_pin, HIGH); // send 1
        }
        else {
            digitalWrite(_MP3_pin, LOW); // send 0
        }
        delayMicroseconds(30);
    }

    digitalWrite(_MP3_pin, HIGH);
    delayMicroseconds(30);

}
void HD_MIDI::Send(uint8_t a, uint8_t b, uint8_t c)
{
    //__disable_irq();
    write(a);
    write(b);
    write(c);
    //__enable_irq();
}

#endif


