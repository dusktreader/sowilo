# -------------------------------------------------
# Project created by QtCreator 2009-09-24T20:17:09
# -------------------------------------------------
QT -= core \
    gui

TARGET = sowilo

CONFIG += console

CONFIG -= app_bundle

TEMPLATE = app

DESTDIR = bin

LIBS += -L \
     /usr/local/lib \
    -lcv \
    -lcxcore \
    -lhighgui

INCLUDEPATH += \
    /usr/local/include/opencv \
    rtmath \
    objects \
    objects/primitives \
    objects/luminaires \
    materials \
    trajectories \
    orientations \
    tools \

SOURCES += \
    tools/tools.cpp \
    main.cpp \
    scene.cpp \
    objects/object.cpp \
    objects/camera.cpp \
    objects/primitives/primitive.cpp \
    objects/primitives/sphere.cpp \
    objects/primitives/triangle.cpp \
    objects/primitives/quadrilateral.cpp \
    objects/luminaires/luminaire.cpp \
    objects/luminaires/directluminaire.cpp \
    objects/luminaires/pointluminaire.cpp \
    rtmath/point.cpp \
    rtmath/vector.cpp \
    rtmath/ray.cpp \
    rtmath/rtmath.cpp \
    rtmath/triple.cpp \
    rtmath/color.cpp \
    materials/material.cpp \
    materials/mattematerial.cpp \
    materials/glossymaterial.cpp \
    materials/mirrormaterial.cpp \
    trajectories/trajectory.cpp \
    trajectories/lineartrajectory.cpp \
    trajectories/circulartrajectory.cpp \
    orientations/orientation.cpp \
    orientations/trackingorientation.cpp \

HEADERS += \
    tools/tools.h \
    scene.h \
    objects/object.h \
    objects/camera.h \
    objects/primitives/primitive.h \
    objects/primitives/sphere.h \
    objects/primitives/triangle.h \
    objects/primitives/quadrilateral.h \
    objects/luminaires/luminaire.h \
    objects/luminaires/directluminaire.h \
    objects/luminaires/pointluminaire.h \
    rtmath/point.h \
    rtmath/vector.h \
    rtmath/ray.h \
    rtmath/rtmath.h \
    rtmath/triple.h \
    rtmath/color.h \
    materials/material.h \
    materials/mattematerial.h \
    materials/glossymaterial.h \
    materials/mirrormaterial.h \
    trajectories/trajectory.h \
    trajectories/lineartrajectory.h \
    trajectories/circulartrajectory.h \
    orientations/orientation.h \
    orientations/trackingorientation.h \


QMAKE_CXXFLAGS_RELEASE += -fopenmp
QMAKE_LFLAGS_RELEASE   += -fopenmp
QMAKE_CXXFLAGS_DEBUG   += -g
