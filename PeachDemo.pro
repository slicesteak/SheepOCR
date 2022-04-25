#-------------------------------------------------
#
# Project created by QtCreator 2020-09-02T22:09:28
#
#-------------------------------------------------

QT       += core gui
QT+= network

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
    capture/capturemodification.cpp \
    capture/screenshot.cpp \
    capture/tools/applauncher.cpp \
    capture/tools/capturetool.cpp \
    capture/tools/copytool.cpp \
    capture/tools/exittool.cpp \
    capture/tools/markertool.cpp \
    capture/tools/movetool.cpp \
    capture/tools/savetool.cpp \
    capture/tools/sizeindicatortool.cpp \
    capture/tools/toolfactory.cpp \
    capture/widget/amplifierwidget.cpp \
    capture/widget/buttonhandler.cpp \
    capture/widget/capturebutton.cpp \
    capture/widget/capturewidget.cpp \
    capture/workers/imgur/imagelabel.cpp \
    capture/workers/imgur/loadspinner.cpp \
    capture/workers/imgur/notificationwidget.cpp \
        main.cpp \
    opticalsever.cpp \
    screenwidget.cpp \
    utils/confighandler.cpp \
    utils/desktopfileparse.cpp \
    utils/desktopinfo.cpp \
    utils/screengrabber.cpp \
        widget.cpp \
    appinit.cpp \
    mymessagebox.cpp

HEADERS += \
    capture/capturemodification.h \
    capture/screenshot.h \
    capture/tools/applauncher.h \
    capture/tools/capturetool.h \
    capture/tools/copytool.h \
    capture/tools/exittool.h \
    capture/tools/markertool.h \
    capture/tools/movetool.h \
    capture/tools/savetool.h \
    capture/tools/sizeindicatortool.h \
    capture/tools/toolfactory.h \
    capture/widget/amplifierwidget.h \
    capture/widget/buttonhandler.h \
    capture/widget/capturebutton.h \
    capture/widget/capturewidget.h \
    capture/workers/imgur/imagelabel.h \
    capture/workers/imgur/loadspinner.h \
    capture/workers/imgur/notificationwidget.h \
    httpSDK-cpp/ocr.h \
    opticalsever.h \
    screenwidget.h \
    utils/confighandler.h \
    utils/desktopfileparse.h \
    utils/desktopinfo.h \
    utils/screengrabber.h \
        widget.h \
    appinit.h \
    mymessagebox.h

FORMS += \
    capture/widget/amplifierwidget.ui \
        widget.ui \
    mymessagebox.ui

RESOURCES += \
    qss.qrc \
    Img/Arrow.png \
    Img/Brush.PNG \
    Img/Circle.png \
    Img/Exit.png \
    Img/Finish.png \
    Img/Magnifier.png \
    Img/Mosaic.png \
    Img/Rectangle.png \
    Img/Save.png \
    Img/Text.png \
    Img/Undo.png \
    Img/cursor-move.png \
    Img/line_weight_3.png \
    Img/line_weight_4.png \
    Img/line_weight_5.png


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






