#pragma execution_character_set("utf-8")

#include "UiTableView.h"
#include <fend/uidelegates/UiTableItemDelegate.h>

UiTableView::UiTableView(QWidget *parent):QTableView(parent)
{
    setItemDelegate(new UiTableItemDelegate(this));
}
