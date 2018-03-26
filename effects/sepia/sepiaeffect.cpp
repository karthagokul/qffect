#include "sepiaeffect.h"
#include <QColor>


SepiaEffect::SepiaEffect(QImage aImage):IEffect(aImage)
{

}

QImage SepiaEffect::process()
{
    //qDebug()<<"Started";
    QImage resultImage(mSourceImage.size(),mSourceImage.format());
    resultImage.fill(Qt::black);
    for ( int row = 0; row < mSourceImage.width() ; ++row )
    {
        for ( int col = 0; col < mSourceImage.height() ; ++col )
        {
            QColor clrCurrent( mSourceImage.pixel( row, col ) );
            int  outputRed = (clrCurrent.red() * .393) + ( clrCurrent.green() *.769) + ( clrCurrent.blue() * .189);
            int outputGreen = (clrCurrent.red() * .349) + ( clrCurrent.green() *.686) + (clrCurrent.blue() * .168);
            int outputBlue = (clrCurrent.red() * .272) + ( clrCurrent.green() *.534) + (clrCurrent.blue() * .131);
            QColor newColor;
            newColor.setRed((outputRed>255)?255:outputRed);
            newColor.setGreen((outputGreen>255)?255:outputGreen);
            newColor.setBlue((outputBlue>255)?255:outputBlue);
            resultImage.setPixel(row,col,newColor.rgba());
            //qDebug()<<clrCurrent;
        }
    }
    return resultImage;
}
