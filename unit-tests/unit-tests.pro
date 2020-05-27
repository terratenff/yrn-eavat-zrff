QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  \
    ../shipyard/fitness.cpp \
    ../shipyard/inputoutput.cpp \
    ../shipyard/math.cpp \
    ../shipyard/settings.cpp \
    ../shipyard/scenario.cpp \
    test_inputoutput.cpp \
    test_main.cpp \
    test_math.cpp \
    test_fitness.cpp \
    test_scenario.cpp

HEADERS += \
    test_inputoutput.hh \
    test_fitness.hh \
    test_math.hh \
    test_scenario.hh
