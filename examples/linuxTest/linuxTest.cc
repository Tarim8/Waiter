//
// Waiter Linux unitTest
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
// Linux version of Waiter unit testing
// not definitive, but usually faster
// try: make -B linuxTest
//

#include <iostream>
#include <iomanip>
#include <stdint.h>

// If someone provides a millis(), could comment this out to run in real time
#define millis simillis

// define these Arduino specifics
#define clock_t local_clock_t
#define Serial cout
#define _HEX(x) hex << uppercase << (x) << dec << nouppercase
#define bit(x) (1ul << (x))

using namespace std;

#include "../unitTest/millis.h"
#include "../../Waiter.h"
#include "../unitTest/unitTest.h"

int main() {
    testAll();
};
