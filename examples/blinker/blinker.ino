//
// Waiter - blinker example
//
// Copyright Tarim - 2015
//
// Waiter is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Waiter is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Waiter.  If not, see <http://www.gnu.org/licenses/>.

//
// A pair of LEDs which blink slightly out of phase.
// Try doing this neatly using delay()!
//

#include <Waiter.h>

// The precision of the timer
// 0: 1ms, 1: 2ms, 2: 4ms, 3: 8ms ... 10: 1s
const byte TIMER_SIZE = 2;

// alarm type must be signed
typedef int8_t alarm_t;
typedef WAITER<alarm_t, TIMER_SIZE> WaitTiny;

// LED pins
const byte LEFT_LED = 10;
const byte RIGHT_LED = 13;

// Blink duration in the units of the timer
// eg, for TIMER_SIZE=2, duration=120:
//     time of the duration = 120x4ms = 480ms = ~ half a second
//
const alarm_t LEFT_DURATION = 120;
const alarm_t RIGHT_DURATION = 121;

//
// Blinker class
//
class Blinker {
public:
    byte pin;           // pin number (1 byte)
    alarm_t duration;   // duration in units of the timer (1 byte)
    WaitTiny timer;     // timer (1 byte)

    //
    // initialise variables, set pin to output, reset the timer
    //
    void init( const byte pin_, const alarm_t duration_ ) {
        pin = pin_;
        duration = duration_;

        pinMode( pin, OUTPUT );
        timer.reset();
    };

    //
    // call this repeatedly from loop()
    //
    void poll() {
        if( timer.wait( duration ) ) {
            digitalWrite( pin, !digitalRead( pin ) );
        }
    };
};

// declare a couple of blinking LEDs
Blinker left, right;

//
// Initialise the LEDs
//
void setup() {
    left.init( LEFT_LED, LEFT_DURATION );
    right.init( RIGHT_LED, RIGHT_DURATION );
};

//
// Repeatedly poll the LEDs
//
void loop() {
    left.poll();
    right.poll();
};
