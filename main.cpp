#include "mylist.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyList w;
    w.resize(300, 100);
    w.show();

    if (w.ShowListState())
    {
        w.DeactivateDeleteFunc();
    }

    return a.exec();
}
