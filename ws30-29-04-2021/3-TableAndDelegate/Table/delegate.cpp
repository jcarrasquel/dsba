#include "delegate.h"
#include <iostream>

Delegate::Delegate(QObject *parent) : QItemDelegate(parent)
{

}

QWidget* Delegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    std::cout << "(1) Delegate::createEditor(): Selecting a new cell in the view..." << std::endl;

    // This is spinbox is nice for modifying integers in the cell.
    QSpinBox *editor = new QSpinBox(parent);
    editor->setMinimum(0);
    editor->setMaximum(100);
    return editor;
}

void Delegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    int value = index.model()->data(index, Qt::EditRole).toInt();

    std::cout << "(2) Delegate::setEditorData(): [VIEW] The value in the editing cell is: " << value << std::endl;

    QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
    spinBox->setValue(value);
}

void Delegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
    spinBox->interpretText();
    int value = spinBox->value();

    std::cout << "(3) Delegate::setModelData(): [MODEL] Cell changed in the model to: " << value << std::endl;

    model->setData(index, value, Qt::EditRole);
}

void Delegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    // This function adjusts the editor (the spin box) in the cell
    editor->setGeometry(option.rect);
}
