#pragma once

#include <QImage>
#include <QPixmap>
#include "cv.h"
#include "cxcore.h"

QPixmap cvMatToQPixmap( const cv::Mat &src, QSize size=QSize(), Qt::TransformationMode tmode=Qt::FastTransformation, Qt::AspectRatioMode amode=Qt::KeepAspectRatio, unsigned int trimBorder=0 );
