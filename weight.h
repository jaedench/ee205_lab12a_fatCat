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

class Weight {
public:
    ////////////// Enums //////////////
    enum UnitOfWeight{ POUND, KILO, SLUG};  /// units of measure for weight

    /// conversion constants
    static const float KILOS_IN_A_POUND ;
    static const float SLUGS_IN_A_POUND ;

    /// labels
    static const std::string POUND_LABEL ;
    static const std::string KILO_LABEL ;
    static const std::string SLUG_LABEL ;

    /////////////// Static Methods ////////////////
    // kilogram to pound
    static float fromKilogramToPound( float kilogram ) noexcept;
    // pound to kilogram
    static float fromPoundToKilogram( float pound ) noexcept;
    // slug to pound
    static float fromSlugToPound( float slug ) noexcept;
    // pound to slug
    static float fromPoundToSlug( float pound ) noexcept;

    /// Conversion between unit types
    static float convertWeight( float fromWeight, UnitOfWeight fromUnit, UnitOfWeight toUnit ) noexcept;

};

