///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab12a_fatCat - EE 205 - Spr 2022
///
/// @file weight.cpp
/// @version 1.0
///
/// @author Jaeden Chang <jaedench@hawaii.edu>
/// @date   17_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>
#include <iomanip>

#include "weight.h"

const float Weight::KILOS_IN_A_POUND = 0.453592 ;
const float Weight::SLUGS_IN_A_POUND = 0.031081 ;

///////////////// Static Methods ///////////////////
float Weight::fromKilogramToPound( const float kilogram ) noexcept {
    return kilogram / KILOS_IN_A_POUND ;
}

float Weight::fromPoundToKilogram(const float pound) noexcept {
    return pound * KILOS_IN_A_POUND;
}

float Weight::fromSlugToPound(const float slug) noexcept {
    return slug / SLUGS_IN_A_POUND;
}

float Weight::fromPoundToSlug(const float pound) noexcept {
    return pound * SLUGS_IN_A_POUND;
}

float Weight::convertWeight(float fromWeight, Weight::UnitOfWeight fromUnit, Weight::UnitOfWeight toUnit) noexcept {
    float commonWeight;
    switch (fromUnit) {           // convert to common unit, pounds
        case POUND:
            commonWeight = fromWeight;
            break;
        case KILO:
            commonWeight = fromKilogramToPound(fromWeight);
            break;
        case SLUG:
            commonWeight = fromSlugToPound(fromWeight);
            break;
    }

    float toWeight;
    switch (toUnit) {             // converts from common unit, pounds, to unit of choice
        case POUND:
            toWeight = commonWeight;
            break;
        case KILO:
            toWeight = fromPoundToKilogram(commonWeight);
            break;
        case SLUG:
            toWeight = fromPoundToSlug(commonWeight);
            break;
    }
    return toWeight;
}
