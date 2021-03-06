#include "helloworldfilter.h"

HelloWorldFilter::HelloWorldFilter(QObject *parent/* = nullptr*/)
    : QAbstractVideoFilter(parent)
{
}

QVideoFilterRunnable *HelloWorldFilter::createFilterRunnable()
{
    return nullptr;
}
