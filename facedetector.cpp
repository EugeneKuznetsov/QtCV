#include <QDebug>
#include <QCoreApplication>
#include <QFile>
#include <opencv2/opencv.hpp>
#include "facedetector.h"

FaceDetector::FaceDetector()
    : m_faceCascade()
    , m_frame()
    , m_face()
{
    QString tmp_cascade_file = QCoreApplication::applicationDirPath().append("/frontalface.xml");
    QFile::copy(":/haarcascade_frontalface_default.xml" , tmp_cascade_file);
    m_faceCascade.load(tmp_cascade_file.toStdString().c_str());
    QFile::remove(tmp_cascade_file);
}

bool FaceDetector::parseFace(QImage &&frame)
{
    m_frame = std::move(frame);
    m_frame = m_frame.convertToFormat(QImage::Format_RGB888);

    cv::Mat convertedFrame(m_frame.height(), m_frame.width(), CV_8UC3, m_frame.bits(), m_frame.bytesPerLine());

    cv::cvtColor(convertedFrame, convertedFrame, cv::COLOR_BGR2GRAY);

    std::vector<cv::Rect> faces;
    m_faceCascade.detectMultiScale(convertedFrame, faces);

    if (faces.empty())
        return false;

    auto lastFace = faces.back();
    m_face = {lastFace.x, lastFace.y, lastFace.width, lastFace.height};

    return true;
}
