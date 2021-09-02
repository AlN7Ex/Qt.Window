#include "mylist.h"

MyList::MyList(QWidget *parent)
    : QDialog(parent)
{
    BtnAddElement = new QPushButton("Append element");
    BtnDeleteElement = new QPushButton("Delete last element");
    BtnListSize = new QPushButton("List size");
    SBInputElement = new QSpinBox;
    SBShowListSize = new QSpinBox;
    SBShowDeletedElement = new QSpinBox;
    Layout = new QGridLayout;

    SBInputElement->setButtonSymbols(QAbstractSpinBox::NoButtons);
    SBShowListSize->setButtonSymbols(QAbstractSpinBox::NoButtons);
    SBShowDeletedElement->setButtonSymbols(QAbstractSpinBox::NoButtons);

    Layout->addWidget(BtnAddElement, 0, 0);
    Layout->addWidget(BtnDeleteElement, 1, 0);
    Layout->addWidget(BtnListSize, 2, 0);

    Layout->addWidget(SBInputElement, 0, 1);
    Layout->addWidget(SBShowDeletedElement, 1, 1);
    Layout->addWidget(SBShowListSize, 2, 1);

    setLayout(Layout);

    connect(BtnAddElement, &QPushButton::clicked, this, &MyList::AddRandElement);
    connect(BtnDeleteElement, &QPushButton::clicked, this, &MyList::DeleteFromBack);
    connect(BtnListSize, &QPushButton::clicked, this, &MyList::ShowListSize);
}

void MyList::ActivateDeleteFunc()
{
        SBShowDeletedElement->setEnabled(true);
        BtnDeleteElement->setEnabled(true);
}
void MyList::DeactivateDeleteFunc()
{
    SBShowDeletedElement->clear();
    SBShowDeletedElement->setEnabled(false);
    BtnDeleteElement->setEnabled(false);
}

bool MyList::ShowListState() const
{
    return List.isEmpty();
}

MyList::~MyList()
{
}

void MyList::AddRandElement()
{
    int random = rand() % 100;
    List.push_back(random);
    SBInputElement->setValue(random);
    if (!(List.isEmpty()))
    {
        ActivateDeleteFunc();
    }
}

void MyList::ShowListSize() const
{
    SBShowListSize->setValue(List.size());
}

void MyList::DeleteFromBack()
{
    if (!(List.isEmpty()))
    {
        SBShowDeletedElement->setValue(List[List.size() - 1]);
        List.pop_back();
    }
    else
    {
        DeactivateDeleteFunc();
    }

}

