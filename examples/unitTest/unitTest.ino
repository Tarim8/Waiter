//
// Waiter unitTest
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

#include <Streaming.h>

// Force Arduino includes above here
;

// comment this out to use real millis()
// though this would take months to complete!
//
#define millis simillis

#include "millis.h"
#include "Waiter.h"
#include "unitTest.h"

void setup() {
    Serial.begin( 115200 );
    delay( 2000 );
    testAll();
};

void loop() {
};
