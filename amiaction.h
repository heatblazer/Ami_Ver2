#ifndef AMIACTION_H
#define AMIACTION_H
#include <QByteArray>
#include "amimsg.h"

class AmiMsg;
class AmiClient;

class AmiAction
{
public:
    explicit AmiAction(AmiClient* client, const AmiMsg& msg);
    virtual ~AmiAction();

    const AmiMsg& getCallMsg() const;
    const AmiMsg& getRespondMsg() const;

private:
    friend class Ami;
    AmiClient*   p_callee;
    AmiMsg*      p_respondMsg;
    AmiMsg       m_callMsg;
};


#endif // AMIACTION_H
