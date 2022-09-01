#ifndef DIALOGSETVARIABLES_H
#define DIALOGSETVARIABLES_H

#include <QDialog>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>


namespace Ui {
class DialogSetVariables;
}

class DialogSetVariables : public QDialog
{
    Q_OBJECT
    QFormLayout* flowLayout = new QFormLayout;

public:
    explicit DialogSetVariables(const std::vector<QString>& data, QWidget *parent = nullptr);
    ~DialogSetVariables();
    void add_textview(const std::vector<QString>&);
    std::vector<QString> getNumbers();

private:
    void check_input_number(QString&);
    Ui::DialogSetVariables *ui;
    std::vector<QString> data_;

};

#endif // DIALOGSETVARIABLES_H
