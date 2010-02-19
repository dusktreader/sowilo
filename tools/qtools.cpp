#include "qtools.h"

QPixmap cvMatToQPixmap( const cv::Mat &src,
                         QSize size,
                         Qt::TransformationMode tmode,
                         Qt::AspectRatioMode amode,
                         unsigned int trimBorder ){
    QImage timg;
    cv::Mat tmp;
    if( src.type() == CV_8UC3 )
        tmp = src;
    else{
        tmp = cv::Mat( src.size(), CV_8UC3 );
        cv::cvtColor( src, tmp, CV_GRAY2RGB );
    }
    timg = QImage( tmp.data, tmp.cols, tmp.rows, tmp.step, QImage::Format_RGB888 );
    if( !size.isNull() ){
        if( trimBorder > 0 ){
            size.rwidth() -= 2 * trimBorder;
            size.rheight() -= 2  * trimBorder;
        }
        timg = timg.scaled( size, amode, tmode );
    }
    return QPixmap::fromImage( timg, Qt::ColorOnly );
}
