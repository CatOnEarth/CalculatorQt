#include "calculatorwindow.h"
#include <QTextCodec> // подключение класса кодека текста
#include <QApplication>

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8")); //изменени€
    QLocale::setDefault(QLocale("ru_RU"));
    QApplication a(argc, argv);
    CalculatorWindow w;
    w.show();
    return a.exec();
}

