QT       += core gui charts sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    View/OnlineExam/mrzanswersheetwidget.cpp \
    View/OnlineExam/mrzexaminationwidget.cpp \
    View/OnlineExam/mrzexampaperpagewidget.cpp \
    View/OnlineExam/mrzexampapertitlewidget.cpp \
    View/OnlineExam/mrzfaceidentificationwidget.cpp \
    View/OnlineExam/mrzfacerecognitiondialog.cpp \
    View/OnlineExam/mrzmygametitlebar.cpp \
    View/OnlineExam/mrzmygamwidget.cpp \
    View/OnlineExam/mrzonlineexamwidget.cpp \
    View/OnlineExam/mrzquestionwidget.cpp \
    View/OnlineExercise/mrzexercisebutton.cpp \
    View/OnlineExercise/mrzmyexercisewidget.cpp \
    View/OnlineExercise/mrzonlineexercisewidget.cpp \
    View/PersonalCenter/FaceRecognition/mrzfacerecognitionwidget.cpp \
    View/PersonalCenter/mrzchangepasswordwidget.cpp \
    View/PersonalCenter/mrzpersonalcenterwidget.cpp \
    View/PersonalCenter/mrzpersonaldatawidget.cpp \
    View/mrztitlebar.cpp \
    View/subassembly/mrzcamerafacedisplaywidget.cpp \
    main.cpp \
    mainwidget.cpp

HEADERS += \
    View/OnlineExam/mrzanswersheetwidget.h \
    View/OnlineExam/mrzexaminationwidget.h \
    View/OnlineExam/mrzexampaperpagewidget.h \
    View/OnlineExam/mrzexampapertitlewidget.h \
    View/OnlineExam/mrzfaceidentificationwidget.h \
    View/OnlineExam/mrzfacerecognitiondialog.h \
    View/OnlineExam/mrzmygametitlebar.h \
    View/OnlineExam/mrzmygamwidget.h \
    View/OnlineExam/mrzonlineexamwidget.h \
    View/OnlineExam/mrzquestionwidget.h \
    View/OnlineExercise/mrzexercisebutton.h \
    View/OnlineExercise/mrzmyexercisewidget.h \
    View/OnlineExercise/mrzonlineexercisewidget.h \
    View/PersonalCenter/FaceRecognition/mrzfacerecognitionwidget.h \
    View/PersonalCenter/mrzchangepasswordwidget.h \
    View/PersonalCenter/mrzpersonalcenterwidget.h \
    View/PersonalCenter/mrzpersonaldatawidget.h \
    View/mrztitlebar.h \
    View/subassembly/mrzcamerafacedisplaywidget.h \
    mainwidget.h


win32{
# 导入windows第三方库

INCLUDEPATH += E:\Qt\openCV3.4.12\build\install\include\
               E:\Qt\openCV3.4.12\build\install\include\opencv\
               E:\Qt\openCV3.4.12\build\install\include\opencv2

LIBS += -L E:\Qt\openCV3.4.12\build\install\x64\mingw\lib\libopencv_*.a
}

macx{
QMAKE_CXXFLAGS += -x objective-c++
# 导入mac第三方库
}


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
