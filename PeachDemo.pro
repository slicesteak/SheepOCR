#-------------------------------------------------
#
# Project created by QtCreator 2020-09-02T22:09:28
#
#-------------------------------------------------

QT       += core gui
QT+= network
QT +=sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

RC_ICONS = logo.ico

TARGET = PeachDemo
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    configwidget.cpp \
    login.cpp \
        main.cpp \
    modifywidget.cpp \
    opticalsever.cpp \
    register.cpp \
    screenwidget.cpp \
        widget.cpp \
    appinit.cpp \
    mymessagebox.cpp

HEADERS += \
    configwidget.h \
    httpSDK-cpp/ocr.h \
    login.h \
    modifywidget.h \
    opticalsever.h \
    register.h \
    screenwidget.h \
        widget.h \
    appinit.h \
    mymessagebox.h

FORMS += \
    configwidget.ui \
    login.ui \
    modifywidget.ui \
        widget.ui \
    mymessagebox.ui

RESOURCES += \
    qss.qrc


## 添加的外部库json
#win32:CONFIG(release, debug|release): LIBS += -L'C:/Program Files (x86)/jsoncpp/lib/' -ljsoncpp_static
#else:win32:CONFIG(debug, debug|release): LIBS += -L'C:/Program Files (x86)/jsoncpp/lib/' -ljsoncpp_staticd

#INCLUDEPATH += 'C:/Program Files (x86)/jsoncpp/include'
#DEPENDPATH += 'C:/Program Files (x86)/jsoncpp/include'

## 添加的外部库curl
#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../temp_download/curl-7.82.0/mybuild/lib/release/ -llibcurl_imp
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../temp_download/curl-7.82.0/mybuild/lib/debug/ -llibcurl_imp

#INCLUDEPATH += $$PWD/../../../temp_download/curl-7.82.0/mybuild/lib/Release
#DEPENDPATH += $$PWD/../../../temp_download/curl-7.82.0/mybuild/lib/Release





