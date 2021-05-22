#include "delegate.h"
#include <iostream>

#include "delegate.h"
#include <iostream>
#include <QtWidgets>

Delegate::Delegate(QObject *parent) : QItemDelegate(parent)
{

}

QWidget* Delegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QLineEdit* editor = new QLineEdit(parent);

    std::cout << "(1) Delegate::createEditor(): Selecting cell " << index.row() << " in the view..." << std::endl;

    return editor;
}

void Delegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QString value = index.model()->data(index, Qt::EditRole).toString();

    std::cout << "(2) Delegate::setEditorData(): [VIEW] The value in the editing cell is: " << value.toStdString() << std::endl;

    QLineEdit* lineEdit = static_cast<QLineEdit*>(editor);
    lineEdit->setText(value);
}

void Delegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QLineEdit* lineEdit = static_cast<QLineEdit*>(editor);
    QString value = lineEdit->text();

    std::cout << "(3) Delegate::setModelData(): [MODEL] Cell changed in the model to: " << value.toStdString() << std::endl;

    model->setData(index, value, Qt::EditRole);
}

void Delegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    // This function adjusts the editor (the spin box) in the cell
    editor->setGeometry(option.rect);
}

