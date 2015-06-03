TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++14

SOURCES += \
    main.cpp \
    compiler.cpp \
    file.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    compiler.h \
    compilerexception.h \
    file.h \
    fileutils.h \
    fileexception.h

