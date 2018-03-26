#ifndef SEPIAEFFECT_H
#define SEPIAEFFECT_H

#include "ieffect.h"

class SepiaEffect:public IEffect
{
public:
    SepiaEffect(QImage aImage);
    QImage process();
};
#endif
