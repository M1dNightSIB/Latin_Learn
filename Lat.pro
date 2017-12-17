#-------------------------------------------------
#
# Project created by QtCreator 2017-09-18T20:06:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LaLatina
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    startwindow.cpp \
    wordswindow.cpp \
    trainingwindow.cpp \
    wordenter.cpp \
    latinrus.cpp \
    rus_lat.cpp \
    statistic.cpp

HEADERS += \
        mainwindow.h \
    startwindow.h \
    wordswindow.h \
    trainingwindow.h \
    wordenter.h \
    latinrus.h \
    rus_lat.h \
    statistic.h

FORMS += \
        mainwindow.ui \
    wordswindow.ui \
    trainingwindow.ui \
    wordenter.ui \
    latinrus.ui \
    rus_lat.ui \
    startwindow.ui \
    statistic.ui

CONFIG += mobility
MOBILITY = 

RESOURCES += \
    res.qrc

DISTFILES += \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/gradle.properties~ \
    android/local.properties~ \
    android/res/values/libs.xml \
    android/res/drawable-hdpi/icon.png \
    android/res/drawable-ldpi/icon.png \
    android/res/drawable-mdpi/icon.png \
    images/bg.png \
    images/logo.png \
    images/statistic.png \
    images/traning.png \
    images/wordbook.png \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/build.gradle \
    android/gradlew.bat \
    style/style.qss \
    android/gradle.properties \
    android/local.properties \
    images/wordbook.png \
    images/traning.png \
    images/statistic.png \
    images/logo.png \
    images/bg.png \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat \
    images/logo.png

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

