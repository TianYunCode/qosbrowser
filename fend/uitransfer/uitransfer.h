#pragma once

#include <QWidget>

#include <fend/uicom/uiqosdialog.h>

namespace Ui {
class UiTransfer;
}

class UiTransfer : public UiQosDialog
{
    Q_OBJECT

public:
    explicit UiTransfer(QWidget *parent = nullptr);
    ~UiTransfer();

private:
    Ui::UiTransfer *ui;
};
