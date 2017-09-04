INCLUDEPATH *= $$PWD

HEADERS += \
    $$PWD/Channels.h

SOURCES += \
    $$PWD/Channels.cpp

HEADERS += \
    $$PWD/private/ChannelEvent.h \
    $$PWD/private/ChannelFuncs.h \
    $$PWD/private/ChannelShared.h \
    $$PWD/private/SharedInvoker.h \
    $$PWD/private/ScopedInvoker.h

SOURCES += \
    $$PWD/private/ChannelEvent.cpp \
    $$PWD/private/ChannelFuncs.cpp \
    $$PWD/private/ChannelShared.cpp \
    $$PWD/private/SharedInvoker.cpp \
    $$PWD/private/ScopedInvoker.cpp
