TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    data.cpp \
    core.cpp \
    pre_build.cpp \
    dependency.cpp \
    debug.cpp

HEADERS += \
    data.h \
    core.h \
    pre_build.h \
    dependency.h \
    debug.h
