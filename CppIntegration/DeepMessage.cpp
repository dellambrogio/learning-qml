//=============================================================================
//  Copyright (c) 2016 nextcode:ch
//
//  Author: Michele Dell'Ambrogio (m@nextcode.ch)
//=============================================================================

#include "DeepMessage.h"



void MessageBody::setText(const QString &a)
{
    if (a != m_text) {
        m_text = a;
        emit textChanged();
    }
}

QString MessageBody::getText() const
{
    return m_text;
}

void DeepMessage::setBody(MessageBody *body)
{
    if (body != m_body) {
        m_body = body;
        emit bodyChanged();
    }
}

MessageBody *DeepMessage::getBody() const
{
    return m_body;
}

