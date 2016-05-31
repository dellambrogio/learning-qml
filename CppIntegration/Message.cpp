//=============================================================================
//  Copyright (c) 2016 nextcode:ch
//
//  Author: Michele Dell'Ambrogio (m@nextcode.ch)
//=============================================================================

#include "Message.h"

void Message::setAuthor(const QString &a) {
    if (a != m_author) {
        m_author = a;
        emit authorChanged();
    }
}

QString Message::author() const {
    return m_author;
}
