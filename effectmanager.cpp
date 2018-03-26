#include "effectmanager.h"
#include <effectcommand.h>
#include <QColor>
#include <QDebug>

EffectManager::EffectManager(QObject *aParent)
    :QObject(aParent)
{

}

void EffectManager::apply(EffectCommand *aCommand)
{
    connect(aCommand,SIGNAL(ready(QImage)),this,SIGNAL(ready(QImage)));
    aCommand->start();
    mCommands.push(aCommand);
}
