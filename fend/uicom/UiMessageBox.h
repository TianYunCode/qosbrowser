#pragma once

#include "UiQosDialog.h"
#include <QWidget>
#include "config/Common.h"

namespace Ui {
class UiMessageBox;
}

class UiMessageBox : public UiQosDialog
{
    Q_OBJECT

public:
    explicit UiMessageBox(QWidget *parent = nullptr);
    ~UiMessageBox();

    QString showMessage(const QString& title,
                        const QString& text,
                        const QStringList &btnTextList = QStringList(STR("确定")));

private:
    void createBtns(const QStringList& textList);

private:
    Ui::UiMessageBox *ui;
    QString m_text;
};
