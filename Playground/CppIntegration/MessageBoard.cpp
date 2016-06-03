//=============================================================================
//  Copyright (c) 2016 nextcode:ch
//
//  Author: Michele Dell'Ambrogio (m@nextcode.ch)
//=============================================================================

#include "MessageBoard.hpp"


#include <QDebug>

bool MessageBoard::postMessage(const QString &msg) {
    qDebug() << "Called the C++ method with" << msg;

    emit newMessagePosted(msg);

    return true;
}

void MessageBoard::refresh() {
    qDebug() << "Called the C++ slot";
}
