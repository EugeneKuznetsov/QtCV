#pragma once

#include <QAbstractVideoFilter>

class HelloWorldFilter : public QAbstractVideoFilter
{
    Q_OBJECT

public:
    explicit HelloWorldFilter(QObject *parent = nullptr);

    virtual QVideoFilterRunnable *createFilterRunnable() override;
};
