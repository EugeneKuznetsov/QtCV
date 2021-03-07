#pragma once

#include <QVideoFilterRunnable>
#include <QSharedPointer>

class HelloWorldFilter;
class FaceDetector;

class HelloWorldFilterRunnable : public QVideoFilterRunnable
{
public:
    explicit HelloWorldFilterRunnable(HelloWorldFilter &qmlFilter);

    virtual QVideoFrame run(QVideoFrame *input, const QVideoSurfaceFormat &surfaceFormat, RunFlags) override;

private:
    HelloWorldFilter &m_filter;
    QSharedPointer<FaceDetector> m_detector;
};
