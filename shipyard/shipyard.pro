QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    fitness.cpp \
    help/about.cpp \
    help/instructions.cpp \
    inputoutput.cpp \
    main.cpp \
    mainwindow.cpp \
    manager.cpp \
    math.cpp \
    networkwindow.cpp \
    neuralnetwork.cpp \
    scenario.cpp \
    settings.cpp \
    subject.cpp \
    subjectcore.cpp \
    subjectwindow.cpp \
    target.cpp

HEADERS += \
    fitness.hh \
    help/about.hh \
    help/instructions.hh \
    inputoutput.hh \
    mainwindow.hh \
    manager.hh \
    math.hh \
    networkwindow.hh \
    neuralnetwork.hh \
    scenario.hh \
    settings.hh \
    subject.hh \
    subjectcore.hh \
    subjectwindow.hh \
    target.hh

FORMS += \
    help/about.ui \
    help/instructions.ui \
    mainwindow.ui \
    networkwindow.ui \
    subjectwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
