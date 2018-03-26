#include <effectcommand.h>


EffectCommand::EffectCommand(IEffect *aEffect,QObject *aParent):QThread(aParent),mEffect(aEffect)
{

}
EffectCommand::~EffectCommand()
{

}

void EffectCommand::run()
{
    QImage myImage;
    myImage=mEffect->process();
    emit ready(myImage);
}
