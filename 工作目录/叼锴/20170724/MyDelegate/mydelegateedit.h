#ifndef MYDELEGATEEDIT_H
#define MYDELEGATEEDIT_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
class MyDelegateEdit : public QWidget
{
    Q_OBJECT
public:
    explicit MyDelegateEdit(QString content,QWidget *parent=0);
    
signals:
    void clicked1();
public slots:
    void push_ok_button();
    void push_cancel_button();
private:
    QLineEdit *edit;
    QPushButton *ok;
    QPushButton *cancel;
    
};

#endif // MYDELEGATEEDIT_H
