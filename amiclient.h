#ifndef AMIINTERFACE_H
#define AMIINTERFACE_H
#include "amiaction.h"

class AmiAction;
// I want you to implement it forcibly and never instante it //
class AmiClient
{
public:
    AmiClient();
    virtual ~AmiClient() = 0;
    // as for newer C++ we can provide default body but we don`t want to
    virtual void handleAmiRespond(const AmiAction* respond) = 0;

};


#endif // AMIINTERFACE_H
