/********************************************************************************
** Form generated from reading UI file 'calculatorwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATORWINDOW_H
#define UI_CALCULATORWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CalculatorWindow
{
public:
    QWidget *centralwidget;
    QFrame *line;
    QFrame *line_2;
    QLabel *label_journal_list;
    QPushButton *pushButton_action_result;
    QTextEdit *textEdit_inputexpression;
    QPushButton *pushButton_action_plus;
    QPushButton *pushButton_number_1;
    QPushButton *pushButton_action_minus;
    QPushButton *pushButton_number_3;
    QPushButton *pushButton_number_0;
    QPushButton *pushButton_action_comma;
    QPushButton *pushButton_action_point;
    QPushButton *pushButton_number_2;
    QPushButton *pushButton_action_multiply;
    QPushButton *pushButton_number_6;
    QPushButton *pushButton_number_5;
    QPushButton *pushButton_number_4;
    QPushButton *pushButton_number_7;
    QPushButton *pushButton_number_8;
    QPushButton *pushButton_number_9;
    QPushButton *pushButton_action_divide;
    QLabel *label_result;
    QTextBrowser *textBrowser_result;
    QLabel *label_2;
    QLabel *label_3;
    QTextBrowser *textBrowser_postfix_expression;
    QPushButton *pushButton_clear_input;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *pushButton_action_sin;
    QPushButton *pushButton_action_cos;
    QPushButton *pushButton_action_log;
    QPushButton *pushButton_action_ln;
    QPushButton *pushButton_action_e;
    QPushButton *pushButton_action_Pi;
    QWidget *tab_2;
    QPushButton *pushButton_action_close_square_bracket;
    QPushButton *pushButton_action_open_round_bracket;
    QPushButton *pushButton_action_close_round_bracket;
    QPushButton *pushButton_action_open_square_bracket;
    QPushButton *pushButton_action_degree;
    QListWidget *listWidget_journal;
    QPushButton *pushButton_action_balance;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CalculatorWindow)
    {
        if (CalculatorWindow->objectName().isEmpty())
            CalculatorWindow->setObjectName(QString::fromUtf8("CalculatorWindow"));
        CalculatorWindow->resize(1018, 732);
        centralwidget = new QWidget(CalculatorWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(640, 0, 20, 721));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(0, 150, 651, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label_journal_list = new QLabel(centralwidget);
        label_journal_list->setObjectName(QString::fromUtf8("label_journal_list"));
        label_journal_list->setGeometry(QRect(680, 150, 281, 16));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(12);
        label_journal_list->setFont(font);
        pushButton_action_result = new QPushButton(centralwidget);
        pushButton_action_result->setObjectName(QString::fromUtf8("pushButton_action_result"));
        pushButton_action_result->setGeometry(QRect(350, 380, 71, 71));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        font1.setPointSize(28);
        pushButton_action_result->setFont(font1);
        textEdit_inputexpression = new QTextEdit(centralwidget);
        textEdit_inputexpression->setObjectName(QString::fromUtf8("textEdit_inputexpression"));
        textEdit_inputexpression->setGeometry(QRect(30, 40, 531, 111));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Times New Roman"));
        font2.setPointSize(16);
        textEdit_inputexpression->setFont(font2);
        textEdit_inputexpression->setLayoutDirection(Qt::LeftToRight);
        pushButton_action_plus = new QPushButton(centralwidget);
        pushButton_action_plus->setObjectName(QString::fromUtf8("pushButton_action_plus"));
        pushButton_action_plus->setGeometry(QRect(260, 470, 71, 71));
        pushButton_action_plus->setFont(font1);
        pushButton_number_1 = new QPushButton(centralwidget);
        pushButton_number_1->setObjectName(QString::fromUtf8("pushButton_number_1"));
        pushButton_number_1->setGeometry(QRect(20, 380, 71, 71));
        pushButton_number_1->setFont(font1);
        pushButton_action_minus = new QPushButton(centralwidget);
        pushButton_action_minus->setObjectName(QString::fromUtf8("pushButton_action_minus"));
        pushButton_action_minus->setGeometry(QRect(260, 380, 71, 71));
        pushButton_action_minus->setFont(font1);
        pushButton_number_3 = new QPushButton(centralwidget);
        pushButton_number_3->setObjectName(QString::fromUtf8("pushButton_number_3"));
        pushButton_number_3->setGeometry(QRect(180, 380, 71, 71));
        pushButton_number_3->setFont(font1);
        pushButton_number_0 = new QPushButton(centralwidget);
        pushButton_number_0->setObjectName(QString::fromUtf8("pushButton_number_0"));
        pushButton_number_0->setGeometry(QRect(100, 470, 71, 71));
        pushButton_number_0->setFont(font1);
        pushButton_action_comma = new QPushButton(centralwidget);
        pushButton_action_comma->setObjectName(QString::fromUtf8("pushButton_action_comma"));
        pushButton_action_comma->setGeometry(QRect(20, 470, 71, 71));
        pushButton_action_comma->setFont(font1);
        pushButton_action_point = new QPushButton(centralwidget);
        pushButton_action_point->setObjectName(QString::fromUtf8("pushButton_action_point"));
        pushButton_action_point->setGeometry(QRect(180, 470, 71, 71));
        pushButton_action_point->setFont(font1);
        pushButton_number_2 = new QPushButton(centralwidget);
        pushButton_number_2->setObjectName(QString::fromUtf8("pushButton_number_2"));
        pushButton_number_2->setGeometry(QRect(100, 380, 71, 71));
        pushButton_number_2->setFont(font1);
        pushButton_action_multiply = new QPushButton(centralwidget);
        pushButton_action_multiply->setObjectName(QString::fromUtf8("pushButton_action_multiply"));
        pushButton_action_multiply->setGeometry(QRect(260, 290, 71, 71));
        pushButton_action_multiply->setFont(font1);
        pushButton_number_6 = new QPushButton(centralwidget);
        pushButton_number_6->setObjectName(QString::fromUtf8("pushButton_number_6"));
        pushButton_number_6->setGeometry(QRect(180, 290, 71, 71));
        pushButton_number_6->setFont(font1);
        pushButton_number_5 = new QPushButton(centralwidget);
        pushButton_number_5->setObjectName(QString::fromUtf8("pushButton_number_5"));
        pushButton_number_5->setGeometry(QRect(100, 290, 71, 71));
        pushButton_number_5->setFont(font1);
        pushButton_number_4 = new QPushButton(centralwidget);
        pushButton_number_4->setObjectName(QString::fromUtf8("pushButton_number_4"));
        pushButton_number_4->setGeometry(QRect(20, 290, 71, 71));
        pushButton_number_4->setFont(font1);
        pushButton_number_7 = new QPushButton(centralwidget);
        pushButton_number_7->setObjectName(QString::fromUtf8("pushButton_number_7"));
        pushButton_number_7->setGeometry(QRect(20, 200, 71, 71));
        pushButton_number_7->setFont(font1);
        pushButton_number_8 = new QPushButton(centralwidget);
        pushButton_number_8->setObjectName(QString::fromUtf8("pushButton_number_8"));
        pushButton_number_8->setGeometry(QRect(100, 200, 71, 71));
        pushButton_number_8->setFont(font1);
        pushButton_number_9 = new QPushButton(centralwidget);
        pushButton_number_9->setObjectName(QString::fromUtf8("pushButton_number_9"));
        pushButton_number_9->setGeometry(QRect(180, 200, 71, 71));
        pushButton_number_9->setFont(font1);
        pushButton_action_divide = new QPushButton(centralwidget);
        pushButton_action_divide->setObjectName(QString::fromUtf8("pushButton_action_divide"));
        pushButton_action_divide->setGeometry(QRect(260, 200, 71, 71));
        pushButton_action_divide->setFont(font1);
        label_result = new QLabel(centralwidget);
        label_result->setObjectName(QString::fromUtf8("label_result"));
        label_result->setGeometry(QRect(30, 560, 121, 31));
        label_result->setFont(font);
        textBrowser_result = new QTextBrowser(centralwidget);
        textBrowser_result->setObjectName(QString::fromUtf8("textBrowser_result"));
        textBrowser_result->setGeometry(QRect(20, 590, 611, 71));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 10, 131, 21));
        label_2->setFont(font);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(680, 20, 291, 21));
        label_3->setFont(font);
        textBrowser_postfix_expression = new QTextBrowser(centralwidget);
        textBrowser_postfix_expression->setObjectName(QString::fromUtf8("textBrowser_postfix_expression"));
        textBrowser_postfix_expression->setGeometry(QRect(670, 50, 311, 71));
        pushButton_clear_input = new QPushButton(centralwidget);
        pushButton_clear_input->setObjectName(QString::fromUtf8("pushButton_clear_input"));
        pushButton_clear_input->setGeometry(QRect(580, 70, 41, 41));
        pushButton_clear_input->setFont(font1);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(450, 200, 191, 291));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        pushButton_action_sin = new QPushButton(tab);
        pushButton_action_sin->setObjectName(QString::fromUtf8("pushButton_action_sin"));
        pushButton_action_sin->setGeometry(QRect(10, 10, 71, 71));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Times New Roman"));
        font3.setPointSize(22);
        pushButton_action_sin->setFont(font3);
        pushButton_action_cos = new QPushButton(tab);
        pushButton_action_cos->setObjectName(QString::fromUtf8("pushButton_action_cos"));
        pushButton_action_cos->setGeometry(QRect(100, 10, 71, 71));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Times New Roman"));
        font4.setPointSize(20);
        pushButton_action_cos->setFont(font4);
        pushButton_action_log = new QPushButton(tab);
        pushButton_action_log->setObjectName(QString::fromUtf8("pushButton_action_log"));
        pushButton_action_log->setGeometry(QRect(10, 90, 71, 71));
        pushButton_action_log->setFont(font4);
        pushButton_action_ln = new QPushButton(tab);
        pushButton_action_ln->setObjectName(QString::fromUtf8("pushButton_action_ln"));
        pushButton_action_ln->setGeometry(QRect(100, 90, 71, 71));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Times New Roman"));
        font5.setPointSize(24);
        pushButton_action_ln->setFont(font5);
        pushButton_action_e = new QPushButton(tab);
        pushButton_action_e->setObjectName(QString::fromUtf8("pushButton_action_e"));
        pushButton_action_e->setGeometry(QRect(10, 180, 71, 71));
        pushButton_action_e->setFont(font1);
        pushButton_action_Pi = new QPushButton(tab);
        pushButton_action_Pi->setObjectName(QString::fromUtf8("pushButton_action_Pi"));
        pushButton_action_Pi->setGeometry(QRect(100, 180, 71, 71));
        pushButton_action_Pi->setFont(font1);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        pushButton_action_close_square_bracket = new QPushButton(tab_2);
        pushButton_action_close_square_bracket->setObjectName(QString::fromUtf8("pushButton_action_close_square_bracket"));
        pushButton_action_close_square_bracket->setGeometry(QRect(100, 100, 71, 71));
        pushButton_action_close_square_bracket->setFont(font1);
        pushButton_action_open_round_bracket = new QPushButton(tab_2);
        pushButton_action_open_round_bracket->setObjectName(QString::fromUtf8("pushButton_action_open_round_bracket"));
        pushButton_action_open_round_bracket->setGeometry(QRect(20, 10, 71, 71));
        pushButton_action_open_round_bracket->setFont(font1);
        pushButton_action_close_round_bracket = new QPushButton(tab_2);
        pushButton_action_close_round_bracket->setObjectName(QString::fromUtf8("pushButton_action_close_round_bracket"));
        pushButton_action_close_round_bracket->setGeometry(QRect(100, 10, 71, 71));
        pushButton_action_close_round_bracket->setFont(font1);
        pushButton_action_open_square_bracket = new QPushButton(tab_2);
        pushButton_action_open_square_bracket->setObjectName(QString::fromUtf8("pushButton_action_open_square_bracket"));
        pushButton_action_open_square_bracket->setGeometry(QRect(20, 100, 71, 71));
        pushButton_action_open_square_bracket->setFont(font1);
        tabWidget->addTab(tab_2, QString());
        pushButton_action_degree = new QPushButton(centralwidget);
        pushButton_action_degree->setObjectName(QString::fromUtf8("pushButton_action_degree"));
        pushButton_action_degree->setGeometry(QRect(350, 200, 71, 71));
        pushButton_action_degree->setFont(font1);
        listWidget_journal = new QListWidget(centralwidget);
        listWidget_journal->setObjectName(QString::fromUtf8("listWidget_journal"));
        listWidget_journal->setGeometry(QRect(670, 180, 321, 501));
        pushButton_action_balance = new QPushButton(centralwidget);
        pushButton_action_balance->setObjectName(QString::fromUtf8("pushButton_action_balance"));
        pushButton_action_balance->setGeometry(QRect(350, 290, 71, 71));
        pushButton_action_balance->setFont(font1);
        CalculatorWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CalculatorWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1018, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        CalculatorWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(CalculatorWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CalculatorWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());

        retranslateUi(CalculatorWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CalculatorWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CalculatorWindow)
    {
        CalculatorWindow->setWindowTitle(QCoreApplication::translate("CalculatorWindow", "CalculatorWindow", nullptr));
        label_journal_list->setText(QCoreApplication::translate("CalculatorWindow", "\320\226\321\203\321\200\320\275\320\260\320\273", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_action_result->setToolTip(QCoreApplication::translate("CalculatorWindow", "=", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_action_result->setText(QCoreApplication::translate("CalculatorWindow", "=", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_action_plus->setToolTip(QCoreApplication::translate("CalculatorWindow", "+", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_action_plus->setText(QCoreApplication::translate("CalculatorWindow", "+", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_number_1->setToolTip(QCoreApplication::translate("CalculatorWindow", "1", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_number_1->setText(QCoreApplication::translate("CalculatorWindow", "1", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_action_minus->setToolTip(QCoreApplication::translate("CalculatorWindow", "-", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_action_minus->setText(QCoreApplication::translate("CalculatorWindow", "-", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_number_3->setToolTip(QCoreApplication::translate("CalculatorWindow", "3", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_number_3->setText(QCoreApplication::translate("CalculatorWindow", "3", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_number_0->setToolTip(QCoreApplication::translate("CalculatorWindow", "0", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_number_0->setText(QCoreApplication::translate("CalculatorWindow", "0", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_action_comma->setToolTip(QCoreApplication::translate("CalculatorWindow", ",", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_action_comma->setText(QCoreApplication::translate("CalculatorWindow", ",", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_action_point->setToolTip(QCoreApplication::translate("CalculatorWindow", ".", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_action_point->setText(QCoreApplication::translate("CalculatorWindow", ".", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_number_2->setToolTip(QCoreApplication::translate("CalculatorWindow", "2", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_number_2->setText(QCoreApplication::translate("CalculatorWindow", "2", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_action_multiply->setToolTip(QCoreApplication::translate("CalculatorWindow", "*", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_action_multiply->setText(QCoreApplication::translate("CalculatorWindow", "*", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_number_6->setToolTip(QCoreApplication::translate("CalculatorWindow", "6", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_number_6->setText(QCoreApplication::translate("CalculatorWindow", "6", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_number_5->setToolTip(QCoreApplication::translate("CalculatorWindow", "5", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_number_5->setText(QCoreApplication::translate("CalculatorWindow", "5", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_number_4->setToolTip(QCoreApplication::translate("CalculatorWindow", "4", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_number_4->setText(QCoreApplication::translate("CalculatorWindow", "4", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_number_7->setToolTip(QCoreApplication::translate("CalculatorWindow", "7", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_number_7->setText(QCoreApplication::translate("CalculatorWindow", "7", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_number_8->setToolTip(QCoreApplication::translate("CalculatorWindow", "8", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_number_8->setText(QCoreApplication::translate("CalculatorWindow", "8", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_number_9->setToolTip(QCoreApplication::translate("CalculatorWindow", "9", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_number_9->setText(QCoreApplication::translate("CalculatorWindow", "9", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_action_divide->setToolTip(QCoreApplication::translate("CalculatorWindow", "/", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_action_divide->setText(QCoreApplication::translate("CalculatorWindow", "/", nullptr));
        label_result->setText(QCoreApplication::translate("CalculatorWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202", nullptr));
        label_2->setText(QCoreApplication::translate("CalculatorWindow", "\320\222\321\213\321\200\320\260\320\266\320\265\320\275\320\270\320\265", nullptr));
        label_3->setText(QCoreApplication::translate("CalculatorWindow", "\320\237\320\276\321\201\321\202\321\204\320\270\320\272\321\201\320\275\320\260\321\217 \320\267\320\260\320\277\320\270\321\201\321\214 \320\262\321\213\321\200\320\260\320\266\320\265\320\275\320\270\321\217", nullptr));
        pushButton_clear_input->setText(QCoreApplication::translate("CalculatorWindow", "C", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_action_sin->setToolTip(QCoreApplication::translate("CalculatorWindow", "sin()", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_action_sin->setText(QCoreApplication::translate("CalculatorWindow", "sin()", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_action_cos->setToolTip(QCoreApplication::translate("CalculatorWindow", "cos()", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_action_cos->setText(QCoreApplication::translate("CalculatorWindow", "cos()", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_action_log->setToolTip(QCoreApplication::translate("CalculatorWindow", "log()", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_action_log->setText(QCoreApplication::translate("CalculatorWindow", "log()", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_action_ln->setToolTip(QCoreApplication::translate("CalculatorWindow", "ln()", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_action_ln->setText(QCoreApplication::translate("CalculatorWindow", "ln()", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_action_e->setToolTip(QCoreApplication::translate("CalculatorWindow", "e", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_action_e->setText(QCoreApplication::translate("CalculatorWindow", "e", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_action_Pi->setToolTip(QCoreApplication::translate("CalculatorWindow", "Pi", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_action_Pi->setText(QCoreApplication::translate("CalculatorWindow", "Pi", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("CalculatorWindow", "\321\204\321\203\320\275\320\272\321\206\320\270\320\270", nullptr));
        pushButton_action_close_square_bracket->setText(QCoreApplication::translate("CalculatorWindow", "]", nullptr));
        pushButton_action_open_round_bracket->setText(QCoreApplication::translate("CalculatorWindow", "(", nullptr));
        pushButton_action_close_round_bracket->setText(QCoreApplication::translate("CalculatorWindow", ")", nullptr));
        pushButton_action_open_square_bracket->setText(QCoreApplication::translate("CalculatorWindow", "[", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("CalculatorWindow", "\320\241\320\272\320\276\320\261\320\272\320\270", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_action_degree->setToolTip(QCoreApplication::translate("CalculatorWindow", "^", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_action_degree->setText(QCoreApplication::translate("CalculatorWindow", "^", nullptr));
        pushButton_action_balance->setText(QCoreApplication::translate("CalculatorWindow", "%", nullptr));
        menu->setTitle(QCoreApplication::translate("CalculatorWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CalculatorWindow: public Ui_CalculatorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATORWINDOW_H
