#ifndef MONOEFFECT_H
#define MONOEFFECT_H

#include "ieffect.h"

class MonoEffect:public IEffect
{
public:
    MonoEffect(QImage aImage);
    QImage process();
};
#endif
