#ifndef EFFECTMANAGER_H
#define EFFECTMANAGER_H

#include <QObject>
#include <QStack>

class EffectCommand;

class EffectManager : public QObject
{
    Q_OBJECT
public:
    EffectManager(QObject *aParent);
    void apply(EffectCommand *aCommand);
signals:
    void ready(const QImage &aImage);
private:
    QStack<EffectCommand *> mCommands;
};

#endif // EFFECTMANAGER_H
