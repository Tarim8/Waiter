//
// Waiter unitTest simillis()
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
// simulated millis() function for testing Waiter class
//
typedef unsigned long clock_t;

clock_t tardisTime = 0;
clock_t simillis() {
    return tardisTime;
}
