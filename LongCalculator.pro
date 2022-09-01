QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    BigInt.cpp \
    calculatorwindow.cpp \
    checkinputcorrection.cpp \
    cutexpression.cpp \
    dialog_err.cpp \
    dialogsetvariables.cpp \
    inputexpressionclass.cpp \
    main.cpp \
    make_operations.cpp \
    qdynamicsetvariables.cpp \
    stack_qstring.cpp \
    stack_tokens.cpp

HEADERS += \
    BigInt.h \
    SafeInt.h \
    calculatorwindow.h \
    checkinputcorrection.h \
    cutexpression.h \
    dialog_err.h \
    dialogsetvariables.h \
    inputexpressionclass.h \
    make_operations.h \
    qdynamicsetvariables.h \
    resource.h \
    stack_int.h \
    stack_qstring.h \
    stack_tokens.h \
    ui_calculatorwindow.h \
    ui_dialog_err.h \
    ui_dialogsetvariables.h

FORMS += \
    calculatorwindow.ui \
    dialog_err.ui \
    dialogsetvariables.ui

TRANSLATIONS += \
    LongCalculator_en_GB.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
