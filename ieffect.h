#ifndef EFFECT_H
#define EFFECT_H

#include <QObject>
#include <QImage>

class IEffect:public QObject
{
public:
    IEffect(QImage aImage);
protected:
    //need to see the result image
    QImage mSourceImage;
public:
    virtual QImage process()=0;
    QImage revert();
};


#endif
