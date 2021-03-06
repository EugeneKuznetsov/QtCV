#pragma once

#include <QAbstractVideoFilter>

class HelloWorldFilterRunnable;

class HelloWorldFilter : public QAbstractVideoFilter
{
    Q_OBJECT

public:
    explicit HelloWorldFilter(QObject *parent = nullptr);

    virtual QVideoFilterRunnable *createFilterRunnable() override;

signals:
    void sayHelloWorld(int mouthX, int mouthY, int mouthWidth, int mouthHeight);
    void shutUp();
};
