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
#include <cstring>

#include "weight.h"

#define FORMAT_LINE( className, member ) std::cout << std::setw(8) << (className) << std::setw(20) << (member) << std::setw(52)

////////////// Static Public Attributes ///////////////
const float Weight::KILOS_IN_A_POUND = 0.453592 ;
const float Weight::SLUGS_IN_A_POUND = 0.031081 ;
const float Weight::UNKNOWN_WEIGHT   = -1 ;

const std::string Weight::POUND_LABEL = "Pound" ;
const std::string Weight::KILO_LABEL  = "Kilogram" ;
const std::string Weight::SLUG_LABEL  = "Slug" ;


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


//////////////// Constructors //////////////////
Weight::Weight() noexcept {
    weight = UNKNOWN_WEIGHT;
    maxWeight = UNKNOWN_WEIGHT;
    unitOfWeight = POUND;
    weightIsKnown = false;
    weightHasMax = false;
}

Weight::Weight(float newWeight) {
    setWeight( newWeight );
    unitOfWeight = POUND;
    maxWeight = UNKNOWN_WEIGHT;
}

Weight::Weight( Weight::UnitOfWeight newUnitOfWeight ) noexcept {
    weight = UNKNOWN_WEIGHT;
    maxWeight = UNKNOWN_WEIGHT;
    unitOfWeight = newUnitOfWeight;
}

Weight::Weight( float newWeight, Weight::UnitOfWeight newUnitOfWeight) {
    setWeight( newWeight, newUnitOfWeight);
    maxWeight = UNKNOWN_WEIGHT;
}

Weight::Weight( float newWeight, float newMaxWeight) {
    setWeight( newWeight );
    setMaxWeight( newMaxWeight );
}

Weight::Weight( Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight) {
    weight = UNKNOWN_WEIGHT;
    unitOfWeight = newUnitOfWeight;
    setMaxWeight( newMaxWeight );
}

Weight::Weight( float newWeight, Weight::UnitOfWeight newUnitOfWeight, float newMaxWeight) {
    setWeight( newWeight, newUnitOfWeight);
    setMaxWeight( newMaxWeight );
}


////////////// Getters and Setters ///////////////
// Getters
float Weight::getWeight() const noexcept {
    return weight;
}

Weight::UnitOfWeight Weight::getWeightUnit() const noexcept {
    return unitOfWeight;
}

float Weight::getWeight(Weight::UnitOfWeight weightUnits) const noexcept {
    return convertWeight( getWeight(), getWeightUnit(), weightUnits);
}

float Weight::getMaxWeight() const noexcept {
    return maxWeight;
}

// Setters
void Weight::setWeight(float newWeight) {
    assert(isWeightValid(newWeight));
    weight = newWeight;
    weightIsKnown = true;
}

void Weight::setWeight(float newWeight, Weight::UnitOfWeight weightUnits) {
    assert(isWeightValid(newWeight));
    weight = newWeight;
    unitOfWeight = weightUnits;
    weightIsKnown = true;
}

void Weight::setMaxWeight(float newMaxWeight) {
    assert(isWeightValid(newMaxWeight));
    maxWeight = newMaxWeight;
    weightHasMax = true;
}

/////////// Validation /////////////
bool Weight::isWeightKnown() const noexcept {
    if ( weight == UNKNOWN_WEIGHT ) {
        return false;
    }
    return true;
}

bool Weight::hasMaxWeight() const noexcept {
    if ( maxWeight == UNKNOWN_WEIGHT ) {
        return false;
    }
    return true;
}

bool Weight::isWeightValid( float checkWeight ) const noexcept {
    assert((checkWeight > 0) || (checkWeight == UNKNOWN_WEIGHT));
    if (weightHasMax) {
        assert(checkWeight <= maxWeight);
    }
    return true;
}

bool Weight::validate() const noexcept {
    assert( isWeightValid(weight) );
    assert( isWeightValid(maxWeight) );
    return true;
}

///////////////// Numeric Operators ///////////////////
bool Weight::operator==( const Weight& rhs_Weight ) const {
    /// Remember to convert the two weight's units into a common unit!
    /// Treat unknown weights as 0 (so we can sort them without dealing
    /// with exceptions)
    float lhs_weight = (weightIsKnown) ? getWeight(Weight::POUND) : 0;
    float rhs_weight = (rhs_Weight.weightIsKnown) ?
                       rhs_Weight.getWeight(Weight::POUND) : 0;
    return lhs_weight == rhs_weight;
}

bool Weight::operator<( const Weight& rhs_Weight ) const {
    float lhs_weight = (weightIsKnown) ? getWeight(Weight::POUND) : 0;
    float rhs_weight = (rhs_Weight.weightIsKnown) ?
                       rhs_Weight.getWeight(Weight::POUND) : 0;
    return lhs_weight < rhs_weight;
}

Weight& Weight::operator+=( float rhs_addToWeight ) {
    weight += rhs_addToWeight;
    return *this;
}


////////////////// Put To Stream Output Operator ///////////////////////
std::ostream& operator<<( std::ostream& lhs_stream, const Weight::UnitOfWeight rhs_UnitOfWeight ) {
    switch( rhs_UnitOfWeight ) {
        case Weight::POUND: return lhs_stream << Weight::POUND_LABEL ;
        case Weight::KILO: return lhs_stream << Weight::KILO_LABEL ;
        case Weight::SLUG: return lhs_stream << Weight::SLUG_LABEL ;
        default:
            throw std::out_of_range( "The unit can’t be mapped to a string" );
    }
}


///////////////// Dump ////////////////////
void Weight::dump() const noexcept{
    std::cout << std::setw(80) << std::setfill( '=' ) << "" << std::endl ;
    std::cout << std::setfill( ' ' ) ;
    std::cout << std::left ;
    std::cout << std::boolalpha ;
    FORMAT_LINE( "Weight", "this")          << this            << std::endl;
    FORMAT_LINE( "Weight", "isKnown" )      << isWeightKnown() << std::endl ;
    FORMAT_LINE( "Weight", "weight" )       << weight          << std::endl ;
    FORMAT_LINE( "Weight", "unitOfWeight" ) << getWeightUnit() << std::endl ;
    FORMAT_LINE( "Weight", "hasMax" )       << hasMaxWeight()  << std::endl ;
    FORMAT_LINE( "Weight", "maxWeight" )    << maxWeight       << std::endl ;
}
