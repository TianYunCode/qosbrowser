#pragma execution_character_set("utf-8")

#include "uitableview.h"
#include <fend/uidelegates/uitableitemdelegate.h>

UiTableView::UiTableView(QWidget *parent):QTableView(parent)
{
    setItemDelegate(new UiTableItemDelegate(this));
}
