QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  \
    test_main.cpp \
    test_math.cpp \
    # Include necessary project source files to conduct unit tests.
    ../shipyard/fitness.cpp \
    ../shipyard/inputoutput.cpp \
    ../shipyard/math.cpp \
    ../shipyard/neuralnetwork.cpp \
    ../shipyard/settings.cpp \
    ../shipyard/subjectcore.cpp \

HEADERS += \
    test_math.hh
