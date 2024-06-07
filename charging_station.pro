QT       += core gui
QT += sql
QT       += core gui sql
QT       += core sql
QT += printsupport
QT += serialport
QT  += core gui gui multimedia
QT += charts
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

QT        += core gui sql core network multimedia multimediawidgets charts serialport printsupport widgets

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
include($$PWD/botan.pri)
SOURCES += \
    DuCrypt.cpp \
    activatoncodeclass.cpp \
    arduino.cpp \
    botan.cpp \
    client.cpp \
    connection.cpp \
    employe2.cpp \
    employee.cpp \
    login.cpp \
    main.cpp \
    profil.cpp \
    profilemp.cpp \
    reglage.cpp \
    service.cpp \
    smtp.cpp \
    station.cpp \
    stock.cpp

HEADERS += \
    DuCrypt.h \
    activatoncodeclass.h \
    arduino.h \
    botan.h \
    client.h \
    connection.h \
    employe2.h \
    employee.h \
    login.h \
    profil.h \
    profilemp.h \
    reglage.h \
    service.h \
    smtp.h \
    station.h \
    stock.h

FORMS += \
    activatoncodeclass.ui \
    client.ui \
    employe2.ui \
    employee.ui \
    login.ui \
    profil.ui \
    profilemp.ui \
    reglage.ui \
    service.ui \
    station.ui \
    stock.ui

QMAKE_CXXFLAGS += -std=gnu++14
QMAKE_POST_LINK += $$quote(copy /Y $$quote($$PWD/ssl/*.dll) $$quote($$OUT_PWD))
TRANSLATIONS += \
    charging_station_en_US.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    angalis.qrc \
    iconn.qrc \
    translations.qrc

DISTFILES += \
    ../../Desktop/close.png \
    ../../Desktop/open.png \
    Notification-25.mp3


