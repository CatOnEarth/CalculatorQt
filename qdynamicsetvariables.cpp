#include "qdynamicsetvariables.h"

qdynamicSetVariables::qdynamicSetVariables(QWidget* parent) :
    QLabel(parent) {
    ++ResID;            // Увеличение счетчика на единицу
    TextEditID = ResID;
}

qdynamicSetVariables::~qdynamicSetVariables()
{

}

/* Метод для возврата значения номера кнопки
 * */
int qdynamicSetVariables::getID()
{
    return TextEditID;
}

/* Инициализация статической переменной класса.
 * Статическая переменная класса должна инициализироваться в обязательном порядке
 * */
int qdynamicSetVariables::ResID = 0;
