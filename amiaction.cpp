#include "amiaction.h"
#include "amimsg.h"
#include <QString>

AmiAction::AmiAction(AmiClient* client, const AmiMsg& msg) :
    p_callee(client),
    p_respondMsg(nullptr),
    m_callMsg(msg)
{
}

AmiAction::~AmiAction()
{
    if (p_respondMsg != nullptr) {
        delete p_respondMsg;
    }
}

const AmiMsg& AmiAction::getCallMsg() const
{
    return m_callMsg;
}

const AmiMsg& AmiAction::getRespondMsg() const
{
    return *p_respondMsg;
}
