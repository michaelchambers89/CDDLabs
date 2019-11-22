// Barrier.cpp --- 
// 
// Filename: Barrier.cpp
// Description: 
// Author: Michael Chambers
// Maintainer: 
// Created: Fri 22/11/2019
// Version: 
// Package-Requires: ()
// Last-Updated:  Fri 22/11/2019
//           By: Michael
//     Update #: 2
// URL: 
// Doc URL: 
// Keywords: 
// Compatibility: 
// 
// 

// Commentary: 
// 
// 
// 
// 

// Change Log:
// 
// 
// 
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at
// your option) any later version.
// 
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with GNU Emacs.  If not, see <http://www.gnu.org/licenses/>.
// 
// 

// Code:
#include "Semaphore.h"
#include "Barrier.h"
#include <iostream>


Barrier::Barrier(int numThreads)
{
    this->numThreads = numThreads;
    current_count = 0;
    lock.reset(new Semaphore(1));
    turnstile1.reset(new Semaphore(0));
    turnstile2.reset(new Semaphore(1));
}


Barrier::~Barrier()
{
    lock.reset();
    turnstile1.reset();
    turnstile2.reset();
    std::cout << "Barrier is destroyed" << std::endl;
}


void Barrier::phase1()
{
    lock->Wait();
    ++current_count;
    if (current_count == numThreads)
    {
        turnstile2->Wait();
        turnstile1->Signal();
    }
    lock->Signal();
    turnstile1->Wait();
    turnstile1->Signal();
}


void Barrier::phase2()
{
    lock->Wait();
    --current_count;
    if (current_count == 0)
    {
        turnstile1->Wait();
        turnstile2->Signal();
    }
    lock->Signal();
    turnstile2->Wait();
    turnstile2->Signal();
}


void Barrier::wait()
{
    phase1();
    phase2();
}


// 
// Barrier.cpp ends here
