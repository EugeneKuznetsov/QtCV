#pragma once

#include <QImage>
#include <opencv2/objdetect.hpp>

class FaceDetector
{
public:
    FaceDetector();

    bool parseFace(const QImage &frame);

    inline const QRect& getFaceDetails() const {
        return m_face;
    };

private:
    cv::CascadeClassifier m_faceCascade;
    QImage m_frame;
    QRect m_face;
};
