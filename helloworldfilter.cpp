#include "helloworldfilter.h"
#include "helloworldfilterrunnable.h"

HelloWorldFilter::HelloWorldFilter(QObject *parent/* = nullptr*/)
    : QAbstractVideoFilter(parent)
{
}

QVideoFilterRunnable *HelloWorldFilter::createFilterRunnable()
{
    // QVideoFilterRunnable instances are managed by Qt Multimedia
    // and will be automatically destroyed and recreated when necessary
    return new HelloWorldFilterRunnable(*this);
}
