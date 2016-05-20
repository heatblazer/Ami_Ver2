#ifndef PTT_H
#define PTT_H
#include <QThread>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QObject>

#include "ami.h"
#include "amiclient.h"
#include "amimsg.h"
#include "amiaction.h"

class AmiAction;
class ptt;

// implplementing the AmiInterface //
class ptt : public QObject, public AmiClient
{
    Q_OBJECT
public:
    explicit ptt(const QString name, QObject* parent = nullptr);
    virtual ~ptt();

    virtual void handleAmiRespond(const AmiAction* action);
    void registerAmi(Ami* pami);    //for now register an outside ami //

private slots:
    void hClick(void);
    void hPress(void);
    void hReleased(void);

public:
    static QHBoxLayout hlayout;

private:

    Ami*            p_ami; // reference to the AMI , I`ll talk with this //
    QPushButton*    m_button; // pedal simulation //
    QString         m_name;
};

#endif // PTT_H
