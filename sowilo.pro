# -------------------------------------------------
# Project created by QtCreator 2009-09-24T20:17:09
# -------------------------------------------------
QT += core \
    gui
TARGET = sowilo
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
DESTDIR = bin
INCLUDEPATH += rtmath \
    objects \
    objects/primitives \
    objects/luminaires \
    materials \
    trajectories \
    orientations \
    tools

# main.cpp \
SOURCES += camera_test.cpp \ # rtmath_test.cpp \
    tools/tools.cpp \
    rtmath/point.cpp \
    rtmath/vector.cpp \
    rtmath/triple.cpp \
    rtmath/color.cpp \
    rtmath/rtmath.cpp \
    rtmath/ray.cpp \
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
    materials/material.cpp \
    materials/mattematerial.cpp \
    materials/glossymaterial.cpp \
    materials/mirrormaterial.cpp \
    trajectories/trajectory.cpp \
    trajectories/lineartrajectory.cpp \
    trajectories/circulartrajectory.cpp \
    orientations/orientation.cpp \
    orientations/trackingorientation.cpp \
    futurescene.cpp \
    objects/futurecamera.cpp
HEADERS += tools/tools.h \
    rtmath/triple.h \
    rtmath/color.h \
    rtmath/point.h \
    rtmath/vector.h \
    rtmath/ray.h \
    rtmath/rtmath.h \
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
    materials/material.h \
    materials/mattematerial.h \
    materials/glossymaterial.h \
    materials/mirrormaterial.h \
    trajectories/trajectory.h \
    trajectories/lineartrajectory.h \
    trajectories/circulartrajectory.h \
    orientations/orientation.h \
    orientations/trackingorientation.h \
    futurescene.h \
    objects/futurecamera.h
QMAKE_CXXFLAGS_RELEASE += -fopenmp
QMAKE_LFLAGS_RELEASE += -fopenmp
