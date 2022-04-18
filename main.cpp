#include <iostream>
#include <cassert>
#include <stdexcept>
#include <iomanip>
#include <string>

#include "weight.h"

//#define DEBUG

using namespace std;

int main() {
    // Cats 1-7 follow all the "rules" so they should dump fine
    Weight cat1;
    Weight cat2( 2.2 );
    Weight cat3( Weight::KILO );
    Weight cat4( 4.4, Weight::KILO );
    Weight cat5( 5.5, 6.0);
    Weight cat6( Weight::SLUG, 6.0);
    Weight cat7( 3.14, Weight::KILO, 20.0);

    cat1.dump();
    cat2.dump();
    cat3.dump();
    cat4.dump();
    cat5.dump();
    cat6.dump();
    cat7.dump();

//#ifdef DEBUG

//#endif
}
