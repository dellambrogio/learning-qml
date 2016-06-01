//=============================================================================
//  Copyright (c) 2016 nextcode:ch
//
//  Author: Michele Dell'Ambrogio (m@nextcode.ch)
//=============================================================================

#include <Signaler.hpp>



Signaler::Signaler()
    : m_counter(0)
{
    connect(&m_timer, SIGNAL(timeout()), this, SLOT(increaseCounter()));

    m_timer.start(500);
}

void Signaler::increaseCounter()
{
    m_counter++;
    emit counterChanged(m_counter);
}
