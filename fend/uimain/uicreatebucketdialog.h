#pragma once

#include <QWidget>

#include <fend/uicom/uiqosdialog.h>

#include <middle/models/cloudmodels.h>

namespace Ui {
class UiCreateBucketDialog;
}

class UiCreateBucketDialog : public UiQosDialog
{
    Q_OBJECT

public:
    explicit UiCreateBucketDialog(QWidget *parent = nullptr);
    ~UiCreateBucketDialog();

    MyBucket getBucket();

private:
    Ui::UiCreateBucketDialog *ui;
};
