# Google Test Dependency

include(gtest_dependency.pri)

# Project information

TARGET = ProjektaufgabeTests
TEMPLATE = app

# Project configuration

CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

# Project source files

HEADERS += \
        tst_exitbefehl.h \
        tst_regalcontroller.h \
        tst_removelagerbedingungenbefehl.h \
        tst_removewarebefehl.h \
        tst_setanzahlbefehl.h \
        tst_setdefektbefehl.h \
        tst_setlagerbedingungenbefehl.h \
        tst_setwarebefehl.h

SOURCES += \
        main.cpp

# Library depdency

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../lib/release/ -lProjektaufgabeLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../lib/debug/ -lProjektaufgabeLib
else:unix: LIBS += -L$$OUT_PWD/../lib/ -lProjektaufgabeLib

INCLUDEPATH += $$PWD/../lib
DEPENDPATH += $$PWD/../lib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../lib/release/libProjektaufgabeLib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../lib/debug/libProjektaufgabeLib.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../lib/release/ProjektaufgabeLib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../lib/debug/ProjektaufgabeLib.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../lib/libProjektaufgabeLib.a
