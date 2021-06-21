TARGET = ProjektaufgabeLib
TEMPLATE = lib
CONFIG += staticlib

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11 console
CONFIG -= app_bundle qt

SOURCES += \
        befehl.cpp \
        befehle/backupbefehl.cpp \
        befehle/exitbefehl.cpp \
        befehle/exportbefehl.cpp \
        befehle/getpalettebefehl.cpp \
        befehle/listtempsensorenbefehl.cpp \
        befehle/removelagerbedingungenbefehl.cpp \
        befehle/removewarebefehl.cpp \
        befehle/setanzahlbefehl.cpp \
        befehle/setdefektbefehl.cpp \
        befehle/setlagerbedingungenbefehl.cpp \
        befehle/setwarebefehl.cpp \
        befehle/swappalettebefehl.cpp \
        befehle/transferpalettebefehl.cpp \
        befehle/updatetempsensorbefehl.cpp \
        lagerhalle.cpp \
        palette.cpp \
        palettenode.cpp \
        regalcontroller.cpp \
        temperaturcontroller.cpp \
        temperatursensor.cpp \
        umlaute.cpp

HEADERS += \
        befehl.h \
        befehle/backupbefehl.h \
        befehle/exitbefehl.h \
        befehle/exportbefehl.h \
        befehle/getpalettebefehl.h \
        befehle/listtempsensorenbefehl.h \
        befehle/removelagerbedingungenbefehl.h \
        befehle/removewarebefehl.h \
        befehle/setanzahlbefehl.h \
        befehle/setdefektbefehl.h \
        befehle/setlagerbedingungenbefehl.h \
        befehle/setwarebefehl.h \
        befehle/swappalettebefehl.h \
        befehle/transferpalettebefehl.h \
        befehle/updatetempsensorbefehl.h \
        ints.h \
        lagerhalle.h \
        palette.h \
        palettenode.h \
        regalcontroller.h \
        temperaturcontroller.h \
        temperatursensor.h \
        umlaute.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
