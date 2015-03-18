//
// Waiter unitTest TESTER template
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
// TESTER template based on WAITER template
//
// badly in need of comments
//
template < class A, uint8_t S >
class TESTER: public WAITER<A,S> {
public:
    typedef A alarm_t;
    static const uint8_t shift = S;
    clock_t now, last, milli, initial, tardisStep, tardisWarp;
    alarm_t duration;

    void testmS( const clock_t initial ) {
        Serial << endl << initial << " ms: ";
        testUnits( initial, initial );
    };

    void test8mS( const clock_t initial ) {
        Serial << endl << initial << "x8ms: ";
        testUnits( initial * 8l, initial );
    };

    void testSeconds( const clock_t initial ) {
        Serial << endl << initial << " seconds: ";
        testUnits( initial*1000l, this->seconds( initial ) );
    };

    void testMinutes( const clock_t initial ) {
        Serial << endl << initial << " minutes: ";
        testUnits( initial*1000l*60l, this->minutes( initial ) );
    };

    void testDays( const clock_t initial ) {
        Serial << endl << initial << " days: ";
        testUnits( initial*1000l*60l*60l*24l, this->days( initial ), 0x003fffff );
    };

    void testUnits( const clock_t milli_, const alarm_t duration_, const clock_t warp_ = 0 ) {
        milli = milli_;
        duration = duration_;
        tardisStep = 1;
        tardisWarp = warp_;

        Serial  << "|-" << (short int)(32 - sizeof(alarm_t)*8 - shift)
                << "-><-" << (short int)(sizeof(alarm_t)*8)
                << "-><-" << (short int)shift
                << "-|"
                << " ms: " << milli
                << ", duration: " << (clock_t)duration
                << endl;
        testWraps();
    };

    void testWraps() {
        testWait( -1l );
        testWait( 1ul<<31 );
    };

    void testWait( const clock_t tardisStart, int hits = 5 ) {
        tardisTime = tardisStart - (hits+1)/2 * milli;

        last = millis();
        Serial << "  start: " << _HEX( last ) << endl;
        this->set( 0 );

        while( hits > 0 ) {
            #ifdef REPORTALL
                Serial << (signed long)this->difference( millis(), this->alarmTime + duration ) << " ";
            #endif
            if( this->wait( duration ) ) {
                report();
                --hits;

            } else {
                #ifdef REPORTALL
                    report();
                #endif
                tardisTime = ( tardisTime | tardisWarp ) + tardisStep;
            }
        }
    };

    void report() {
        now = millis();

        Serial  << "diff: " << now - last
                << " millis: " << _HEX( now )
                << " alarmTime: " << _HEX( (clock_t)this->alarmTime )
                << endl;
        last = now;
    };
};
 
void testAll() {
    TESTER<int32_t, 0> waitmS;
    TESTER<int16_t, 0> wait16mS;
    TESTER<int8_t, 3> wait8mSTiny;
    TESTER<int16_t, 10> waitSeconds;
    TESTER<int8_t, 10> waitSecondsTiny;
    TESTER<int16_t, 16> waitMinutes;
    TESTER<int8_t, 24> wait4HoursTiny;

    waitmS.testmS( 1 );
    waitmS.testmS( 12 );

    wait8mSTiny.test8mS( 1 );
    wait8mSTiny.test8mS( wait8mSTiny.TIME_MAX );

    waitSeconds.testSeconds( 3 );
    waitSecondsTiny.testSeconds( 3 );
    wait16mS.testSeconds( 3 );

    waitMinutes.testMinutes( 1 );
    waitMinutes.testMinutes( 3 );

    wait4HoursTiny.testDays( 23 );

    #ifdef OVERFLOW_TEST
        TESTER<int8_t, 25> wait8HoursTiny;
        wait8HoursTiny.reset();
    #endif

};
