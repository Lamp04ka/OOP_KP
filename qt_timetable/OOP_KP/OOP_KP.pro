QT       += core gui

include(C:\Qt\QtXlsxWriter\src\xlsx\qtxlsx.pri)
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets



CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    bd.cpp \
    cabinet.cpp \
    days_in_week.cpp \
    gruppa.cpp \
    lesson.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    para.cpp \
    position.cpp \
    predmet.cpp \
    teacher.cpp \
    type_lesson.cpp \
    uchebni_plan.cpp

HEADERS += \
    admin.h \
    bd.h \
    cabinet.h \
    days_in_week.h \
    gruppa.h \
    lesson.h \
    login.h \
    mainwindow.h \
    para.h \
    position.h \
    predmet.h \
    teacher.h \
    type_lesson.h \
    uchebni_plan.h

FORMS += \
    admin.ui \
    login.ui \
    login.ui \
    mainwindow.ui

TRANSLATIONS += \
    OOP_KP_ru_RU.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
