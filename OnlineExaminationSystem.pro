QT       += core gui charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    View/OnlineExam/mrzfaceidentificationwidget.cpp \
    View/OnlineExam/mrzfacerecognitiondialog.cpp \
    View/OnlineExam/mrzmygametitlebar.cpp \
    View/OnlineExam/mrzmygamwidget.cpp \
    View/OnlineExam/mrzonlineexamwidget.cpp \
    View/OnlineExercise/mrzexercisebutton.cpp \
    View/OnlineExercise/mrzmyexercisewidget.cpp \
    View/OnlineExercise/mrzonlineexercisewidget.cpp \
    View/mrztitlebar.cpp \
    main.cpp \
    mainwidget.cpp

HEADERS += \
    View/OnlineExam/mrzfaceidentificationwidget.h \
    View/OnlineExam/mrzfacerecognitiondialog.h \
    View/OnlineExam/mrzmygametitlebar.h \
    View/OnlineExam/mrzmygamwidget.h \
    View/OnlineExam/mrzonlineexamwidget.h \
    View/OnlineExercise/mrzexercisebutton.h \
    View/OnlineExercise/mrzmyexercisewidget.h \
    View/OnlineExercise/mrzonlineexercisewidget.h \
    View/mrztitlebar.h \
    mainwidget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
