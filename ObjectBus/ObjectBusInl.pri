INCLUDEPATH *= $$PWD

HEADERS += \
    $$PWD/include/ObjectBus.h \
    $$PWD/include/ScopedBus.h \
    $$PWD/include/SharedBus.h

SOURCES += \
    $$PWD/src/ScopedBus.cpp \
    $$PWD/src/SharedBus.cpp

OTHER_FILES += \
    $$PWD/include/ObjectBus \
    $$PWD/include/ScopedBus \
    $$PWD/include/SharedBus

HEADERS += \
    $$PWD/src/internals/ChannelEvent.h \
    $$PWD/src/internals/ChannelFuncs.h \
    $$PWD/src/internals/ChannelShared.h \
    $$PWD/src/internals/SharedInvoker.h \
    $$PWD/src/internals/ScopedInvoker.h

SOURCES += \
    $$PWD/src/internals/ChannelEvent.cpp \
    $$PWD/src/internals/ChannelFuncs.cpp \
    $$PWD/src/internals/ChannelShared.cpp \
    $$PWD/src/internals/SharedInvoker.cpp \
    $$PWD/src/internals/ScopedInvoker.cpp
