/*
 *Project: CDD Labs
 *Author: Michael Chambers
 *License:https://creativecommons.org/licenses/by/4.0/legalcode
 *Date: 22/11/2019
 */
#include "Event.h"
#include <iostream>
#include <stdlib.h>

/*! \fn Event()
    \brief Constructor for the Event class. Creates a random character and prints it out.
*/
Event::Event()
{
    charVal = 'a' + rand() % 26;
    std::cout << charVal;
}


/*! \fn bool consume()
    \brief Consumes, creates a character in CAPS and prints it out.
*/
bool Event::consume()
{
    char charUpper = charVal - 32;
    std::cout << charUpper;
}
