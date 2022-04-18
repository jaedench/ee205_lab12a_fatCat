///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab12a_fatCat - EE 205 - Spr 2022
///
/// @file weight.h
/// @version 1.0
///
/// @author Jaeden Chang <jaedench@hawaii.edu>
/// @date   17_Apr_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <iostream>
#include <string>

#define PROGRAM_NAME "Fat Cat"

class Weight {
public:
    ////////////// Public Types //////////////
    enum UnitOfWeight{ POUND, KILO, SLUG};  /// units of measure for weight.


    ////////////// Static Public Attributes ///////////////
    // conversion constants
    static const float KILOS_IN_A_POUND ;
    static const float SLUGS_IN_A_POUND ;
    static const float UNKNOWN_WEIGHT ;

    // labels
    static const std::string POUND_LABEL ;
    static const std::string KILO_LABEL ;
    static const std::string SLUG_LABEL ;


    /////////////// Static Public Member Functions ////////////////
    static float fromKilogramToPound( float kilogram ) noexcept;    /// Convert kilogram to pound.

    static float fromPoundToKilogram( float pound ) noexcept;       /// Convert pound to kilogram.

    static float fromSlugToPound( float slug ) noexcept;            /// Convert slug to pound.

    static float fromPoundToSlug( float pound ) noexcept;           /// Convert pound to slug.

    static float convertWeight( float fromWeight, UnitOfWeight fromUnit, UnitOfWeight toUnit ) noexcept;
    /// Conversion fromWeight in fromUnit to the wight in toUnit.


    /////////////////// Public Member Functions ////////////////////
    //////////////// Constructors //////////////////
    Weight() noexcept;      /// A default weight.
    Weight( float newWeight );      /// A weight with a value.
    Weight( UnitOfWeight newUnitOfWeight ) noexcept;    /// A weight with a UnitOfWeight.
    Weight( float newWeight, UnitOfWeight newUnitOfWeight);     /// A weight with a value and a UnitOfWeight.
    Weight( float newWeight, float newMaxWeight);   /// A weight with a UnitOfWeight and a maximum weight.
    Weight( UnitOfWeight newUnitOfWeight, float newMaxWeight);    /// A weight with a UnitOfWeight and a maximum weight.
    Weight( float newWeight, UnitOfWeight newUnitOfWeight, float newMaxWeight);     /// A weight with a value, UnitOfWeight and a maximum weight.


    ////////////// Getters and Setters ///////////////
    // Getters
    float getWeight() const noexcept;       /// Get the weight in the weight's units.

    UnitOfWeight getWeightUnit() const noexcept;

    float getWeight (UnitOfWeight weightUnits) const noexcept;      /// Get the weight in a specific unit.

    float getMaxWeight() const noexcept;       /// Get the maximum weight.


    // Setters
    void setWeight( float newWeight );     /// Set weight.

    void setWeight( float newWeight, UnitOfWeight weightUnits );     /// Set the weight with specific unit.


    /////////// Validation /////////////
    bool isWeightKnown() const noexcept;

    bool hasMaxWeight() const noexcept;

    bool isWeightValid(float checkWeight) const noexcept;

    bool validate() const noexcept;


    //////////////// Dump /////////////////
    void dump() const noexcept;     /// Print the Weight class.


    ///////////////  Numeric Operators ////////////////
    bool operator==( const Weight& rhs_Weight ) const; /// Weights are equal.

    bool operator<( const Weight& rhs_Weight ) const; /// Compare two weights.

    Weight& operator+=( float rhs_addToWeight ); /// Add to existing weight and assume rhs_addToWeight is in the same units as Weight.


private:
    ////////////////// Private Attributes ////////////////////
    float weight = UNKNOWN_WEIGHT;
    float maxWeight = UNKNOWN_WEIGHT;
    enum UnitOfWeight unitOfWeight = POUND;
    bool weightIsKnown = false;
    bool weightHasMax = false;

    ///////////////// Private Member Functions //////////////////
    void setMaxWeight( float newMaxWeight );

};



