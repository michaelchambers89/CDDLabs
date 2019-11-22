/*
 *Project: CDD Labs
 *Author: Michael Chambers
 *License:https://creativecommons.org/licenses/by/4.0/legalcode
 *Date: 22/11/2019
 */
#include "SafeBuffer.h"
#include <iostream>
#include <stdlib.h>
#include "Event.h"

/*! \fn SafeBuffer()
    \brief Constructor for SafeBuffer object. Sets the mutex and semaphore.
*/
SafeBuffer::SafeBuffer()
{
    theMutex = std::make_shared<Semaphore>(1);
    theSemaphore = std::make_shared<Semaphore>(0);
}

/*! \fn int push(Event newEvent)
    \brief Pushes the event onto the buffer.
    \param newEvent the event that is to be pushed.
*/
int SafeBuffer::push(Event newEvent)
{
    theMutex->Wait();
    theData.push_back(newEvent);
    int size = theData.size();
    theMutex->Signal();
    theSemaphore->Signal();
    return size;
}//push

/*! \fn Event pop()
    \brief Pops the element from the buffer.
*/
Event SafeBuffer::pop()
{
    theSemaphore->Wait();
    theMutex->Wait();
    Event ev = theData.back();
    theData.pop_back();
    theMutex->Signal();
    return ev;
}//pop
