#pragma once

#include "middle/models/CloudModels.h"
#include <QWidget>

namespace Ui {
class UiBucketsListWidget;
}

class UiBucketsListWidget : public QWidget
{
    Q_OBJECT

public:
    explicit UiBucketsListWidget(QWidget *parent = nullptr);
    ~UiBucketsListWidget();

private slots:
    void onBucketsSuccess(const QList<MyBucket> &buckets);

    void on_listView_doubleClicked(const QModelIndex &index);
    void showBucketObjects(const QString& bucketName);
    void onTextEdited(const QString& text);

private:
    Ui::UiBucketsListWidget *ui;

};
