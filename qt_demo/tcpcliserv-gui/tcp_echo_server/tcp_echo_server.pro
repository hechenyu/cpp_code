######################################################################
# Automatically generated by qmake (3.0) ??? ?? 11 15:04:33 2014
######################################################################

TEMPLATE = app
TARGET = tcp_echo_server
INCLUDEPATH += . ../include
CONFIG += debug c++11
QT += widgets network
VPATH += . ../src ../include
LIBS += -lboost_system -lboost_date_time

win32 {
  LIBS += -lws2_32
}

# Input
HEADERS += tcp_echo_server.h load_host_list.h
SOURCES += tcp_echo_server.cpp load_host_list.cpp main.cpp
