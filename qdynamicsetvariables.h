#ifndef QDYNAMICSETVARIABLES_H
#define QDYNAMICSETVARIABLES_H

#include <QObject>

#include <QLabel>

class qdynamicSetVariables : public QLabel
{

    Q_OBJECT
public:
    explicit qdynamicSetVariables(QWidget* parent = 0);
    ~qdynamicSetVariables();
    static int ResID;   // Статическая переменная, счетчик номеров кнопок
    int getID();        // Функция для возврата локального номера кнопки


public slots:

private:
    int TextEditID = 0;   // Локальная переменная, номер кнопки
};

#endif // QDYNAMICSETVARIABLES_H
