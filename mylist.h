#ifndef MYLIST_H
#define MYLIST_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QSpinBox>
#include <QPushButton>
#include <QList>

class MyList : public QDialog
{
    Q_OBJECT

public:
    explicit MyList(QWidget *parent = nullptr);
    ~MyList();
    void DeactivateDeleteFunc();
    void ActivateDeleteFunc();
    bool ShowListState() const;

private:
    QHBoxLayout *HFirstLayout;
    QHBoxLayout *HSecondLayout;
    QGridLayout *Layout;
    QPushButton *BtnAddElement;
    QPushButton *BtnDeleteElement;
    QPushButton *BtnListSize;
    QSpinBox *SBInputElement;
    QSpinBox *SBShowListSize;
    QSpinBox *SBShowDeletedElement;
    QList<int> List;
private slots:
    void AddRandElement();
    void ShowListSize() const;
    void DeleteFromBack();


};
#endif // MYLIST_H
