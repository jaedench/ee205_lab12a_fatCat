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


#ifdef DEBUG
    // testing conversions
    assert(Weight::convertWeight(1, Weight::POUND, Weight::KILO) == Weight::KILOS_IN_A_POUND);
    assert(Weight::convertWeight(1, Weight::KILO, Weight::POUND) == (1/Weight::KILOS_IN_A_POUND));
    assert(Weight::convertWeight(1, Weight::POUND, Weight::SLUG) == Weight::SLUGS_IN_A_POUND);
    assert(Weight::convertWeight(1, Weight::SLUG, Weight::POUND) == (1/Weight::SLUGS_IN_A_POUND));

    //testing default values
    Weight testWeight1 = Weight(); // all tests should pass
    assert(testWeight1.getWeight() != 0);
    assert(testWeight1.getMaxWeight() != 0);
    assert(testWeight1.getWeightUnit() > -1);
    assert(testWeight1.isWeightKnown() == false);
    assert(testWeight1.hasMaxWeight() == false);

    // testing weight with parameters
    Weight testWeight2 = Weight(3.5, Weight::KILO, 2);
        // This should fail since 3.5 is not less than the max, 2
        // Should never get past this line
    assert(testWeight2.getWeight() == 3.5);
    assert(testWeight2.getMaxWeight() == 2);
    assert(testWeight2.getWeightUnit() == Weight::KILO);
    assert(testWeight2.isWeightKnown() == true);
    assert(testWeight2.hasMaxWeight() == true);

    Weight testWeight3 = Weight( -10 ); // should also fail
    assert(testWeight3.getWeight() < -1);
    assert(testWeight3.getMaxWeight() != 0);
    assert(testWeight3.getWeightUnit() > -1);
    assert(testWeight3.isWeightKnown() == true);
    assert(testWeight3.hasMaxWeight() == false);

#endif

}
