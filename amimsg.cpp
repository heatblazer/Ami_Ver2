#include "amimsg.h"

#include <QRegularExpression>

// stdio //
#include <iostream>

// tipi`en mesij
//
// Action: Originate
// ActionId: SDY4-12837-123878782
// Channel: PJSIP/kermit-00000002
// Context: outbound
// Exten: s
// Priority: 1
// CallerID: "Kermit the Frog" <123-4567>
// Account: FrogLegs
// Variable: MY_VAR=frogs
// Variable: HIDE_FROM_CHEF=true
//
// "ActionId: ()$"
AmiMsg::AmiMsg() :
    m_command() // empty
{
}

AmiMsg::AmiMsg(const AmiMsg& other) :
    m_command(other.m_command)
{
}

AmiMsg::AmiMsg(const QString& buf) :
    m_command(buf)
{
}


AmiMsg::~AmiMsg()
{
}


const QString& AmiMsg::toString() const
{
    return m_command;
}


// ttry detect the type
MsgType AmiMsg::amiType() const
{
    // TODO implemet it (if startWith())
}

// try extract ActionId
QString AmiMsg::actionID() const
{
    QRegularExpression rx("ActionId .*$",
                          QRegularExpression::CaseInsensitiveOption);
    QRegularExpressionMatch mach = rx.match(m_command);

    QStringList match_list = m_command.split("\r\n");
    for(int i=0; i < match_list.size(); ++i) {
        if (match_list.at(i).contains("actionid", Qt::CaseInsensitive))
        {
            std::cout << "MATCHED ACTION ID\n";
            QString debug = match_list.at(i).split(":").at(1);
            return debug;
        }
    }
    return QString("");
}


//!
//! \brief AmiMsg::addMore
//! \param append more text. You are responsible for the NEWLINE!!!
//! \return AmiMsg for building
//!
AmiMsg& AmiMsg::addField(const QString& app, bool* ok)
{
    if (!app.contains(":")) {
        *ok = false;
    }

    m_command.append(app);
    m_command.append("\r\n");

    return *this;
}
