#ifndef EFFECTCOMMAND_H
#define EFFECTCOMMAND_H
#include <QThread>
#include "ieffect.h"

class EffectCommand:public QThread
{
    Q_OBJECT
public:
    EffectCommand(IEffect *aEffect,QObject *aParent);
    ~EffectCommand();
protected:
    void run();
signals:
    void ready(const QImage &aImage);
private:
    IEffect *mEffect;
};

#endif
