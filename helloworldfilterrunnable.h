#pragma once

#include <QVideoFilterRunnable>

class HelloWorldFilter;

class HelloWorldFilterRunnable : public QVideoFilterRunnable
{
public:
    explicit HelloWorldFilterRunnable(HelloWorldFilter &qmlFilter);

    virtual QVideoFrame run(QVideoFrame *input, const QVideoSurfaceFormat &surfaceFormat, RunFlags) override;

private:
    HelloWorldFilter &m_filter;
};
