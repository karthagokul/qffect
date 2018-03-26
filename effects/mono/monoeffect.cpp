#include "monoeffect.h"
#include <QColor>


MonoEffect::MonoEffect(QImage aImage):IEffect(aImage)
{

}

QImage MonoEffect::process()
{
    //qDebug()<<"Started";
    QImage resultImage(mSourceImage.size(),mSourceImage.format());
    resultImage.fill(Qt::black);
    for ( int row = 0; row < mSourceImage.width() ; ++row )
    {
        for ( int col = 0; col < mSourceImage.height() ; ++col )
        {
            QColor clrCurrent( mSourceImage.pixel( row, col ) );
            int  grey = (clrCurrent.red() + clrCurrent.green() + clrCurrent.blue())/3;
            QColor newColor;
            newColor.setRed((grey>255)?255:grey);
            newColor.setGreen((grey>255)?255:grey);
            newColor.setBlue((grey>255)?255:grey);
            resultImage.setPixel(row,col,newColor.rgba());
            //qDebug()<<clrCurrent;
        }
    }
    return resultImage;
}
