#include <QDebug>
#include "helloworldfilterrunnable.h"
#include "helloworldfilter.h"
#include "facedetector.h"

HelloWorldFilterRunnable::HelloWorldFilterRunnable(HelloWorldFilter &qmlFilter)
    : m_filter(qmlFilter)
    , m_detector(QSharedPointer<FaceDetector>::create())
{
}

QVideoFrame HelloWorldFilterRunnable::run(QVideoFrame *input, const QVideoSurfaceFormat &surfaceFormat, RunFlags)
{
    input->map(QAbstractVideoBuffer::ReadOnly);

    if (QAbstractVideoBuffer::NoHandle == surfaceFormat.handleType()) {
        if (m_detector->parseFace(input->image())) {
            auto face = m_detector->getFaceDetails();
            emit m_filter.sayHelloWorld(face.x(), face.y(), face.width(), face.height());
        } else {
            emit m_filter.shutUp();
        }
    }

    input->unmap();
    return *input;
}
