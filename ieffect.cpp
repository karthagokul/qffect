#include <ieffect.h>
IEffect::IEffect(QImage aImage):mSourceImage(aImage)
{
}
QImage IEffect::revert()
{
    return mSourceImage;
}

