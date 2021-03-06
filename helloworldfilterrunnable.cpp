#include "helloworldfilterrunnable.h"
#include "helloworldfilter.h"

HelloWorldFilterRunnable::HelloWorldFilterRunnable(HelloWorldFilter &qmlFilter)
    : m_filter(qmlFilter)
{
}

QVideoFrame HelloWorldFilterRunnable::run(QVideoFrame *input, const QVideoSurfaceFormat &surfaceFormat, RunFlags)
{
    input->map(QAbstractVideoBuffer::ReadOnly);

    if (QAbstractVideoBuffer::NoHandle == surfaceFormat.handleType()) {
        emit m_filter.sayHelloWorld(0, 0, 100, 20);
    }

    input->unmap();
    return *input;
}
