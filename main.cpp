#include <QApplication>
#include "maskcreator.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MaskCreator w;

    w.show();
    return a.exec();
}
