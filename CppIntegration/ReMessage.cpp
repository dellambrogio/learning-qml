//=============================================================================
//  Copyright (c) 2016 nextcode:ch
//
//  Author: Michele Dell'Ambrogio (m@nextcode.ch)
//=============================================================================

#include "ReMessage.hpp"



void ReMessage::setText(const QString &a)
{
    if (a != m_text) {
        m_text = a;
        emit textChanged();
    }
}

QString ReMessage::getText() const
{
    return m_text;
}

