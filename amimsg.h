#ifndef AMIMSG_H
#define AMIMSG_H

// Qt headers //
#include <QString>

class AmiClient;

enum class MsgType {EVENT, ACTION, RESPONSE};

class AmiMsg
{
public:
    explicit AmiMsg();
    explicit AmiMsg(const AmiMsg& other);
    explicit AmiMsg(const QString& buf);

    virtual ~AmiMsg();

    const QString& toString() const;
    MsgType amiType() const;
    QString actionID() const;

    AmiMsg& addField(const QString& app, bool *ok);

private:
    QString m_command;


};

#endif // AMIMSG_H
