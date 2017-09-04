#include <QtCore>
#include <QtTest>

#include "include/ObjectBus"

class SignalSpy : public QObject
{
    Q_OBJECT

public:
    SignalSpy();

private Q_SLOTS:
    void testSlot();
    void testSlot(int a0);
    void testSlot(int a0, int a1);
    void testSlot(int a0, int a1, int a2);
    void testSlot(int a0, int a1, int a2, int a3);
    void testSlot(int a0, int a1, int a2, int a3, int a4);
    void testSlot(int a0, int a1, int a2, int a3, int a4,
                  int a5);
    void testSlot(int a0, int a1, int a2, int a3, int a4,
                  int a5, int a6);
    void testSlot(int a0, int a1, int a2, int a3, int a4,
                  int a5, int a6, int a7);
    void testSlot(int a0, int a1, int a2, int a3, int a4,
                  int a5, int a6, int a7, int a8);
    void testSlot(int a0, int a1, int a2, int a3, int a4,
                  int a5, int a6, int a7, int a8, int a9);

public:
    void resetCounter();
    int counter() const;
private:
    int m_counter;

public:
    void setArguments(const QVariantList &arguments);
private:
    QVariantList m_arguments;
};

SignalSpy::SignalSpy()
{
}

void SignalSpy::testSlot()
{
    QVERIFY(m_arguments.count() == 0);

    ++m_counter;
}

void SignalSpy::testSlot(int a0)
{
    QVERIFY(m_arguments.count() == 1);

    QVERIFY(m_arguments.at(0).canConvert<int>());
    QVERIFY(m_arguments.at(0).toInt() == a0);

    ++m_counter;
}

void SignalSpy::testSlot(int a0, int a1)
{
    QVERIFY(m_arguments.count() == 2);

    QVERIFY(m_arguments.at(0).canConvert<int>());
    QVERIFY(m_arguments.at(0).toInt() == a0);

    QVERIFY(m_arguments.at(1).canConvert<int>());
    QVERIFY(m_arguments.at(1).toInt() == a1);

    ++m_counter;
}

void SignalSpy::testSlot(int a0, int a1, int a2)
{
    QVERIFY(m_arguments.count() == 3);

    QVERIFY(m_arguments.at(0).canConvert<int>());
    QVERIFY(m_arguments.at(0).toInt() == a0);

    QVERIFY(m_arguments.at(1).canConvert<int>());
    QVERIFY(m_arguments.at(1).toInt() == a1);

    QVERIFY(m_arguments.at(2).canConvert<int>());
    QVERIFY(m_arguments.at(2).toInt() == a2);

    ++m_counter;
}

void SignalSpy::testSlot(int a0, int a1, int a2, int a3)
{
    QVERIFY(m_arguments.count() == 4);

    QVERIFY(m_arguments.at(0).canConvert<int>());
    QVERIFY(m_arguments.at(0).toInt() == a0);

    QVERIFY(m_arguments.at(1).canConvert<int>());
    QVERIFY(m_arguments.at(1).toInt() == a1);

    QVERIFY(m_arguments.at(2).canConvert<int>());
    QVERIFY(m_arguments.at(2).toInt() == a2);

    QVERIFY(m_arguments.at(3).canConvert<int>());
    QVERIFY(m_arguments.at(3).toInt() == a3);

    ++m_counter;
}

void SignalSpy::testSlot(int a0, int a1, int a2, int a3, int a4)
{
    QVERIFY(m_arguments.count() == 5);

    QVERIFY(m_arguments.at(0).canConvert<int>());
    QVERIFY(m_arguments.at(0).toInt() == a0);

    QVERIFY(m_arguments.at(1).canConvert<int>());
    QVERIFY(m_arguments.at(1).toInt() == a1);

    QVERIFY(m_arguments.at(2).canConvert<int>());
    QVERIFY(m_arguments.at(2).toInt() == a2);

    QVERIFY(m_arguments.at(3).canConvert<int>());
    QVERIFY(m_arguments.at(3).toInt() == a3);

    QVERIFY(m_arguments.at(4).canConvert<int>());
    QVERIFY(m_arguments.at(4).toInt() == a4);

    ++m_counter;
}

void SignalSpy::testSlot(int a0, int a1, int a2, int a3, int a4,
                         int a5)
{
    QVERIFY(m_arguments.count() == 6);

    QVERIFY(m_arguments.at(0).canConvert<int>());
    QVERIFY(m_arguments.at(0).toInt() == a0);

    QVERIFY(m_arguments.at(1).canConvert<int>());
    QVERIFY(m_arguments.at(1).toInt() == a1);

    QVERIFY(m_arguments.at(2).canConvert<int>());
    QVERIFY(m_arguments.at(2).toInt() == a2);

    QVERIFY(m_arguments.at(3).canConvert<int>());
    QVERIFY(m_arguments.at(3).toInt() == a3);

    QVERIFY(m_arguments.at(4).canConvert<int>());
    QVERIFY(m_arguments.at(4).toInt() == a4);

    QVERIFY(m_arguments.at(5).canConvert<int>());
    QVERIFY(m_arguments.at(5).toInt() == a5);

    ++m_counter;
}

void SignalSpy::testSlot(int a0, int a1, int a2, int a3, int a4,
                         int a5, int a6)
{
    QVERIFY(m_arguments.count() == 7);

    QVERIFY(m_arguments.at(0).canConvert<int>());
    QVERIFY(m_arguments.at(0).toInt() == a0);

    QVERIFY(m_arguments.at(1).canConvert<int>());
    QVERIFY(m_arguments.at(1).toInt() == a1);

    QVERIFY(m_arguments.at(2).canConvert<int>());
    QVERIFY(m_arguments.at(2).toInt() == a2);

    QVERIFY(m_arguments.at(3).canConvert<int>());
    QVERIFY(m_arguments.at(3).toInt() == a3);

    QVERIFY(m_arguments.at(4).canConvert<int>());
    QVERIFY(m_arguments.at(4).toInt() == a4);

    QVERIFY(m_arguments.at(5).canConvert<int>());
    QVERIFY(m_arguments.at(5).toInt() == a5);

    QVERIFY(m_arguments.at(6).canConvert<int>());
    QVERIFY(m_arguments.at(6).toInt() == a6);

    ++m_counter;
}

void SignalSpy::testSlot(int a0, int a1, int a2, int a3, int a4,
                         int a5, int a6, int a7)
{
    QVERIFY(m_arguments.count() == 8);

    QVERIFY(m_arguments.at(0).canConvert<int>());
    QVERIFY(m_arguments.at(0).toInt() == a0);

    QVERIFY(m_arguments.at(1).canConvert<int>());
    QVERIFY(m_arguments.at(1).toInt() == a1);

    QVERIFY(m_arguments.at(2).canConvert<int>());
    QVERIFY(m_arguments.at(2).toInt() == a2);

    QVERIFY(m_arguments.at(3).canConvert<int>());
    QVERIFY(m_arguments.at(3).toInt() == a3);

    QVERIFY(m_arguments.at(4).canConvert<int>());
    QVERIFY(m_arguments.at(4).toInt() == a4);

    QVERIFY(m_arguments.at(5).canConvert<int>());
    QVERIFY(m_arguments.at(5).toInt() == a5);

    QVERIFY(m_arguments.at(6).canConvert<int>());
    QVERIFY(m_arguments.at(6).toInt() == a6);

    QVERIFY(m_arguments.at(7).canConvert<int>());
    QVERIFY(m_arguments.at(7).toInt() == a7);

    ++m_counter;
}

void SignalSpy::testSlot(int a0, int a1, int a2, int a3, int a4,
                         int a5, int a6, int a7, int a8)
{
    QVERIFY(m_arguments.count() == 9);

    QVERIFY(m_arguments.at(0).canConvert<int>());
    QVERIFY(m_arguments.at(0).toInt() == a0);

    QVERIFY(m_arguments.at(1).canConvert<int>());
    QVERIFY(m_arguments.at(1).toInt() == a1);

    QVERIFY(m_arguments.at(2).canConvert<int>());
    QVERIFY(m_arguments.at(2).toInt() == a2);

    QVERIFY(m_arguments.at(3).canConvert<int>());
    QVERIFY(m_arguments.at(3).toInt() == a3);

    QVERIFY(m_arguments.at(4).canConvert<int>());
    QVERIFY(m_arguments.at(4).toInt() == a4);

    QVERIFY(m_arguments.at(5).canConvert<int>());
    QVERIFY(m_arguments.at(5).toInt() == a5);

    QVERIFY(m_arguments.at(6).canConvert<int>());
    QVERIFY(m_arguments.at(6).toInt() == a6);

    QVERIFY(m_arguments.at(7).canConvert<int>());
    QVERIFY(m_arguments.at(7).toInt() == a7);

    QVERIFY(m_arguments.at(8).canConvert<int>());
    QVERIFY(m_arguments.at(8).toInt() == a8);

    ++m_counter;
}

void SignalSpy::testSlot(int a0, int a1, int a2, int a3, int a4,
                         int a5, int a6, int a7, int a8, int a9)
{
    QVERIFY(m_arguments.count() == 10);

    QVERIFY(m_arguments.at(0).canConvert<int>());
    QVERIFY(m_arguments.at(0).toInt() == a0);

    QVERIFY(m_arguments.at(1).canConvert<int>());
    QVERIFY(m_arguments.at(1).toInt() == a1);

    QVERIFY(m_arguments.at(2).canConvert<int>());
    QVERIFY(m_arguments.at(2).toInt() == a2);

    QVERIFY(m_arguments.at(3).canConvert<int>());
    QVERIFY(m_arguments.at(3).toInt() == a3);

    QVERIFY(m_arguments.at(4).canConvert<int>());
    QVERIFY(m_arguments.at(4).toInt() == a4);

    QVERIFY(m_arguments.at(5).canConvert<int>());
    QVERIFY(m_arguments.at(5).toInt() == a5);

    QVERIFY(m_arguments.at(6).canConvert<int>());
    QVERIFY(m_arguments.at(6).toInt() == a6);

    QVERIFY(m_arguments.at(7).canConvert<int>());
    QVERIFY(m_arguments.at(7).toInt() == a7);

    QVERIFY(m_arguments.at(8).canConvert<int>());
    QVERIFY(m_arguments.at(8).toInt() == a8);

    QVERIFY(m_arguments.at(9).canConvert<int>());
    QVERIFY(m_arguments.at(9).toInt() == a9);

    ++m_counter;
}

void SignalSpy::resetCounter()
{
    m_counter = 0;
}

int SignalSpy::counter() const
{
    return m_counter;
}

void SignalSpy::setArguments(const QVariantList &arguments)
{
    resetCounter();

    m_arguments = arguments;
}

class ChannelsTest : public QObject
{
    Q_OBJECT

public:
    ChannelsTest();

Q_SIGNALS:
    void testSignal();
    void testSignal(int a0);
    void testSignal(int a0, int a1);
    void testSignal(int a0, int a1, int a2);
    void testSignal(int a0, int a1, int a2, int a3);
    void testSignal(int a0, int a1, int a2, int a3, int a4);
    void testSignal(int a0, int a1, int a2, int a3, int a4,
                    int a5);
    void testSignal(int a0, int a1, int a2, int a3, int a4,
                    int a5, int a6);
    void testSignal(int a0, int a1, int a2, int a3, int a4,
                    int a5, int a6, int a7);
    void testSignal(int a0, int a1, int a2, int a3, int a4,
                    int a5, int a6, int a7, int a8);
    void testSignal(int a0, int a1, int a2, int a3, int a4,
                    int a5, int a6, int a7, int a8, int a9);

private Q_SLOTS:
    void testConnections();
    void testComConnections();
};

ChannelsTest::ChannelsTest()
{
}

void ChannelsTest::testConnections()
{
    SignalSpy signalSpy;

    // 测试错误类型绑定.
    ScopedBus::attach(this, SIGNAL(testSignal(int)),
                          MAPPED(TestSignal::update(bool)));
    ScopedBus::attach(this, SIGNAL(testSignal(bool)),
                          MAPPED(TestSignal::update(int)));

    // 测试 subject 绑定接口.
    ScopedBus::attach(this, SIGNAL(testSignal()),
                          MAPPED(TestSignal::update()));
    ScopedBus::attach(this, SIGNAL(testSignal(int)),
                          MAPPED(TestSignal::update(int)));
    ScopedBus::attach(this, SIGNAL(testSignal(int,int)),
                          MAPPED(TestSignal::update(int,int)));
    ScopedBus::attach(this, SIGNAL(testSignal(int,int,int)),
                          MAPPED(TestSignal::update(int,int,int)));
    ScopedBus::attach(this, SIGNAL(testSignal(int,int,int,int)),
                          MAPPED(TestSignal::update(int,int,int,int)));
    ScopedBus::attach(this, SIGNAL(testSignal(int,int,int,int,int)),
                          MAPPED(TestSignal::update(int,int,int,int,int)));
    ScopedBus::attach(this, SIGNAL(testSignal(int,int,int,int,int,int)),
                          MAPPED(TestSignal::update(int,int,int,int,int,int)));
    ScopedBus::attach(this, SIGNAL(testSignal(int,int,int,int,int,int,int)),
                          MAPPED(TestSignal::update(int,int,int,int,int,int,int)));
    ScopedBus::attach(this, SIGNAL(testSignal(int,int,int,int,int,int,int,int)),
                          MAPPED(TestSignal::update(int,int,int,int,int,int,int,int)));
    ScopedBus::attach(this, SIGNAL(testSignal(int,int,int,int,int,int,int,int,int)),
                          MAPPED(TestSignal::update(int,int,int,int,int,int,int,int,int)));
    ScopedBus::attach(this, SIGNAL(testSignal(int,int,int,int,int,int,int,int,int,int)),
                          MAPPED(TestSignal::update(int,int,int,int,int,int,int,int,int,int)));

    // 测试错误类型绑定.
    ScopedBus::attach(MAPPED(TestSignal::update(int)),
                          &signalSpy, SLOT(testSlot(bool)));
    ScopedBus::attach(MAPPED(TestSignal::update(bool)),
                          &signalSpy, SLOT(testSlot(int)));

    // 测试 Channel 绑定接口.
    ScopedBus::attach(MAPPED(TestSignal::update()),
                          &signalSpy, SLOT(testSlot()));
    ScopedBus::attach(MAPPED(TestSignal::update(int)),
                          &signalSpy, SLOT(testSlot(int)));
    ScopedBus::attach(MAPPED(TestSignal::update(int,int)),
                          &signalSpy, SLOT(testSlot(int,int)));
    ScopedBus::attach(MAPPED(TestSignal::update(int,int,int)),
                          &signalSpy, SLOT(testSlot(int,int,int)));
    ScopedBus::attach(MAPPED(TestSignal::update(int,int,int,int)),
                          &signalSpy, SLOT(testSlot(int,int,int,int)));
    ScopedBus::attach(MAPPED(TestSignal::update(int,int,int,int,int)),
                          &signalSpy, SLOT(testSlot(int,int,int,int,int)));
    ScopedBus::attach(MAPPED(TestSignal::update(int,int,int,int,int,int)),
                          &signalSpy, SLOT(testSlot(int,int,int,int,int,int)));
    ScopedBus::attach(MAPPED(TestSignal::update(int,int,int,int,int,int,int)),
                          &signalSpy, SLOT(testSlot(int,int,int,int,int,int,int)));
    ScopedBus::attach(MAPPED(TestSignal::update(int,int,int,int,int,int,int,int)),
                          &signalSpy, SLOT(testSlot(int,int,int,int,int,int,int,int)));
    ScopedBus::attach(MAPPED(TestSignal::update(int,int,int,int,int,int,int,int,int)),
                          &signalSpy, SLOT(testSlot(int,int,int,int,int,int,int,int,int)));
    ScopedBus::attach(MAPPED(TestSignal::update(int,int,int,int,int,int,int,int,int,int)),
                          &signalSpy, SLOT(testSlot(int,int,int,int,int,int,int,int,int,int)));

    // 测试重复连接 subject.
    ScopedBus::attach(this, SIGNAL(testSignal()),
                          MAPPED(TestSignal::update()));
    ScopedBus::attach(this, SIGNAL(testSignal(int)),
                          MAPPED(TestSignal::update(int)));
    // 测试重复连接 Channel.
    ScopedBus::attach(MAPPED(TestSignal::update()),
                          &signalSpy, SLOT(testSlot()));
    ScopedBus::attach(MAPPED(TestSignal::update(int)),
                          &signalSpy, SLOT(testSlot(int)));


    qDebug("test 0 parameter");
    signalSpy.setArguments(QVariantList());
    emit testSignal();
    QVERIFY(signalSpy.counter() == 1);
    ScopedBus::notify(MAPPED(TestSignal::update()));
    QVERIFY(signalSpy.counter() == 2);

    qDebug("test 1 parameter");
    signalSpy.setArguments(QVariantList() << 5);
    emit testSignal(5);
    QVERIFY(signalSpy.counter() == 1);
    ScopedBus::notify(MAPPED(TestSignal::update(int)), 5);
    QVERIFY(signalSpy.counter() == 2);

    // 测试参数类型不匹配
    ScopedBus::notify(MAPPED(TestSignal::update(int)), QLatin1Literal("string"));
    ScopedBus::notify(MAPPED(TestSignal::update(int)), QLatin1Literal("5"));

    qDebug("test 2 parameters");
    signalSpy.setArguments(QVariantList() << 5 << 6);
    emit testSignal(5, 6);
    QVERIFY(signalSpy.counter() == 1);
    ScopedBus::notify(MAPPED(TestSignal::update(int,int)), 5, 6);
    QVERIFY(signalSpy.counter() == 2);

    // 测试参数类型不匹配
    ScopedBus::notify(MAPPED(TestSignal::update(int,int)), 5, QLatin1Literal("string"));
    ScopedBus::notify(MAPPED(TestSignal::update(int,int)), 5, QLatin1Literal("6"));
    ScopedBus::notify(MAPPED(TestSignal::update(int,int)), 5);

    // 测试不存在的映射.
    ScopedBus::notify(MAPPED(TestSignal::foo()));

    qDebug("test 3 parameters");
    signalSpy.setArguments(QVariantList() << 5 << 6 << 2);
    emit testSignal(5, 6, 2);
    QVERIFY(signalSpy.counter() == 1);
    ScopedBus::notify(MAPPED(TestSignal::update(int,int,int)), 5, 6, 2);
    QVERIFY(signalSpy.counter() == 2);

    qDebug("test 4 parameters");
    signalSpy.setArguments(QVariantList() << 5 << 6 << 2 << 4);
    emit testSignal(5, 6, 2, 4);
    QVERIFY(signalSpy.counter() == 1);
    ScopedBus::notify(MAPPED(TestSignal::update(int,int,int,int)), 5, 6, 2, 4);
    QVERIFY(signalSpy.counter() == 2);

    qDebug("test 5 parameters");
    signalSpy.setArguments(QVariantList() << 5 << 6 << 2 << 4 << 8);
    emit testSignal(5, 6, 2, 4, 8);
    QVERIFY(signalSpy.counter() == 1);
    ScopedBus::notify(MAPPED(TestSignal::update(int,int,int,int,int)), 5, 6, 2, 4, 8);
    QVERIFY(signalSpy.counter() == 2);

    qDebug("test 6 parameters");
    signalSpy.setArguments(QVariantList() << 5 << 6 << 2 << 4 << 8 << 9);
    emit testSignal(5, 6, 2, 4, 8, 9);
    QVERIFY(signalSpy.counter() == 1);
    ScopedBus::notify(MAPPED(TestSignal::update(int,int,int,int,int,int)), 5, 6, 2, 4, 8, 9);
    QVERIFY(signalSpy.counter() == 2);

    qDebug("test 7 parameters");
    signalSpy.setArguments(QVariantList() << 5 << 6 << 2 << 4 << 8 << 9 << 3);
    emit testSignal(5, 6, 2, 4, 8, 9, 3);
    QVERIFY(signalSpy.counter() == 1);
    ScopedBus::notify(MAPPED(TestSignal::update(int,int,int,int,int,int,int)), 5, 6, 2, 4, 8, 9, 3);
    QVERIFY(signalSpy.counter() == 2);

    qDebug("test 8 parameters");
    signalSpy.setArguments(QVariantList() << 5 << 6 << 2 << 4 << 8 << 9 << 3 << 1);
    emit testSignal(5, 6, 2, 4, 8, 9, 3, 1);
    QVERIFY(signalSpy.counter() == 1);
    ScopedBus::notify(MAPPED(TestSignal::update(int,int,int,int,int,int,int,int)), 5, 6, 2, 4, 8, 9, 3, 1);
    QVERIFY(signalSpy.counter() == 2);

    qDebug("test 9 parameters");
    signalSpy.setArguments(QVariantList() << 5 << 6 << 2 << 4 << 8 << 9 << 3 << 1 << 7);
    emit testSignal(5, 6, 2, 4, 8, 9, 3, 1, 7);
    QVERIFY(signalSpy.counter() == 1);
    ScopedBus::notify(MAPPED(TestSignal::update(int,int,int,int,int,int,int,int,int)), 5, 6, 2, 4, 8, 9, 3, 1, 7);
    QVERIFY(signalSpy.counter() == 2);

    qDebug("test 10 parameters");
    signalSpy.setArguments(QVariantList() << 5 << 6 << 2 << 4 << 8 << 9 << 3 << 1 << 7 << 0);
    emit testSignal(5, 6, 2, 4, 8, 9, 3, 1, 7, 0);
    QVERIFY(signalSpy.counter() == 1);
    ScopedBus::notify(MAPPED(TestSignal::update(int,int,int,int,int,int,int,int,int,int)), 5, 6, 2, 4, 8, 9, 3, 1, 7, 0);
    QVERIFY(signalSpy.counter() == 2);

    // 测试断开连接 Channel.
    ScopedBus::detach(MAPPED(TestSignal::update()),
                          &signalSpy, SLOT(testSlot()));
    ScopedBus::detach(MAPPED(TestSignal::update(int)),
                          &signalSpy, SLOT(testSlot(int)));

    qDebug("test 0 parameter");
    signalSpy.setArguments(QVariantList());
    emit testSignal();
    QVERIFY(signalSpy.counter() == 0);
    ScopedBus::notify(MAPPED(TestSignal::update()));
    QVERIFY(signalSpy.counter() == 0);

    qDebug("test 1 parameter");
    signalSpy.setArguments(QVariantList() << 5);
    emit testSignal(5);
    QVERIFY(signalSpy.counter() == 0);
    ScopedBus::notify(MAPPED(TestSignal::update(int)), 5);
    QVERIFY(signalSpy.counter() == 0);

    // 测试断开连接 subject.
    ScopedBus::detach(this, SIGNAL(testSignal()),
                          MAPPED(TestSignal::update()));
    ScopedBus::detach(this, SIGNAL(testSignal(int)),
                          MAPPED(TestSignal::update(int)));

    ScopedBus::attach(MAPPED(TestSignal::update()),
                          &signalSpy, SLOT(testSlot()));
    ScopedBus::attach(MAPPED(TestSignal::update(int)),
                          &signalSpy, SLOT(testSlot(int)));

    qDebug("test 0 parameter");
    signalSpy.setArguments(QVariantList());
    emit testSignal();
    QVERIFY(signalSpy.counter() == 0);
    ScopedBus::notify(MAPPED(TestSignal::update()));
    QVERIFY(signalSpy.counter() == 1);

    qDebug("test 1 parameter");
    signalSpy.setArguments(QVariantList() << 5);
    emit testSignal(5);
    QVERIFY(signalSpy.counter() == 0);
    ScopedBus::notify(MAPPED(TestSignal::update(int)), 5);
    QVERIFY(signalSpy.counter() == 1);
}

void ChannelsTest::testComConnections()
{
    SignalSpy signalSpy;

    // 测试错误类型绑定.
    SharedBus::attach(this, SIGNAL(testSignal(int)),
                          MAPPED(TestSignal::update(bool)));
    SharedBus::attach(this, SIGNAL(testSignal(bool)),
                          MAPPED(TestSignal::update(int)));

    // 测试 subject 绑定接口.
    SharedBus::attach(this, SIGNAL(testSignal()),
                          MAPPED(TestSignal::update()));
    SharedBus::attach(this, SIGNAL(testSignal(int)),
                          MAPPED(TestSignal::update(int)));
    SharedBus::attach(this, SIGNAL(testSignal(int,int)),
                          MAPPED(TestSignal::update(int,int)));
    SharedBus::attach(this, SIGNAL(testSignal(int,int,int)),
                          MAPPED(TestSignal::update(int,int,int)));
    SharedBus::attach(this, SIGNAL(testSignal(int,int,int,int)),
                          MAPPED(TestSignal::update(int,int,int,int)));
    SharedBus::attach(this, SIGNAL(testSignal(int,int,int,int,int)),
                          MAPPED(TestSignal::update(int,int,int,int,int)));
    SharedBus::attach(this, SIGNAL(testSignal(int,int,int,int,int,int)),
                          MAPPED(TestSignal::update(int,int,int,int,int,int)));
    SharedBus::attach(this, SIGNAL(testSignal(int,int,int,int,int,int,int)),
                          MAPPED(TestSignal::update(int,int,int,int,int,int,int)));
    SharedBus::attach(this, SIGNAL(testSignal(int,int,int,int,int,int,int,int)),
                          MAPPED(TestSignal::update(int,int,int,int,int,int,int,int)));
    SharedBus::attach(this, SIGNAL(testSignal(int,int,int,int,int,int,int,int,int)),
                          MAPPED(TestSignal::update(int,int,int,int,int,int,int,int,int)));
    SharedBus::attach(this, SIGNAL(testSignal(int,int,int,int,int,int,int,int,int,int)),
                          MAPPED(TestSignal::update(int,int,int,int,int,int,int,int,int,int)));

    // 测试错误类型绑定.
    SharedBus::attach(MAPPED(TestSignal::update(int)),
                          &signalSpy, SLOT(testSlot(bool)));
    SharedBus::attach(MAPPED(TestSignal::update(bool)),
                          &signalSpy, SLOT(testSlot(int)));

    // 测试 Channel 绑定接口.
    SharedBus::attach(MAPPED(TestSignal::update()),
                          &signalSpy, SLOT(testSlot()));
    SharedBus::attach(MAPPED(TestSignal::update(int)),
                          &signalSpy, SLOT(testSlot(int)));
    SharedBus::attach(MAPPED(TestSignal::update(int,int)),
                          &signalSpy, SLOT(testSlot(int,int)));
    SharedBus::attach(MAPPED(TestSignal::update(int,int,int)),
                          &signalSpy, SLOT(testSlot(int,int,int)));
    SharedBus::attach(MAPPED(TestSignal::update(int,int,int,int)),
                          &signalSpy, SLOT(testSlot(int,int,int,int)));
    SharedBus::attach(MAPPED(TestSignal::update(int,int,int,int,int)),
                          &signalSpy, SLOT(testSlot(int,int,int,int,int)));
    SharedBus::attach(MAPPED(TestSignal::update(int,int,int,int,int,int)),
                          &signalSpy, SLOT(testSlot(int,int,int,int,int,int)));
    SharedBus::attach(MAPPED(TestSignal::update(int,int,int,int,int,int,int)),
                          &signalSpy, SLOT(testSlot(int,int,int,int,int,int,int)));
    SharedBus::attach(MAPPED(TestSignal::update(int,int,int,int,int,int,int,int)),
                          &signalSpy, SLOT(testSlot(int,int,int,int,int,int,int,int)));
    SharedBus::attach(MAPPED(TestSignal::update(int,int,int,int,int,int,int,int,int)),
                          &signalSpy, SLOT(testSlot(int,int,int,int,int,int,int,int,int)));
    SharedBus::attach(MAPPED(TestSignal::update(int,int,int,int,int,int,int,int,int,int)),
                          &signalSpy, SLOT(testSlot(int,int,int,int,int,int,int,int,int,int)));

    // 测试重复连接 subject.
    SharedBus::attach(this, SIGNAL(testSignal()),
                          MAPPED(TestSignal::update()));
    SharedBus::attach(this, SIGNAL(testSignal(int)),
                          MAPPED(TestSignal::update(int)));
    // 测试重复连接 Channel.
    SharedBus::attach(MAPPED(TestSignal::update()),
                          &signalSpy, SLOT(testSlot()));
    SharedBus::attach(MAPPED(TestSignal::update(int)),
                          &signalSpy, SLOT(testSlot(int)));


    qDebug("test 0 parameter");
    signalSpy.setArguments(QVariantList());
    emit testSignal();
    QVERIFY(signalSpy.counter() == 1);
    SharedBus::notify(MAPPED(TestSignal::update()));
    QVERIFY(signalSpy.counter() == 2);

    qDebug("test 1 parameter");
    signalSpy.setArguments(QVariantList() << 5);
    emit testSignal(5);
    QVERIFY(signalSpy.counter() == 1);
    SharedBus::notify(MAPPED(TestSignal::update(int)), 5);
    QVERIFY(signalSpy.counter() == 2);

    // 测试参数类型不匹配
    SharedBus::notify(MAPPED(TestSignal::update(int)), QLatin1Literal("string"));
    SharedBus::notify(MAPPED(TestSignal::update(int)), QLatin1Literal("5"));

    qDebug("test 2 parameters");
    signalSpy.setArguments(QVariantList() << 5 << 6);
    emit testSignal(5, 6);
    QVERIFY(signalSpy.counter() == 1);
    SharedBus::notify(MAPPED(TestSignal::update(int,int)), 5, 6);
    QVERIFY(signalSpy.counter() == 2);

    // 测试参数类型不匹配
    SharedBus::notify(MAPPED(TestSignal::update(int,int)), 5, QLatin1Literal("string"));
    SharedBus::notify(MAPPED(TestSignal::update(int,int)), 5, QLatin1Literal("6"));
    SharedBus::notify(MAPPED(TestSignal::update(int,int)), 5);

    // 测试不存在的映射.
    SharedBus::notify(MAPPED(TestSignal::foo()));

    qDebug("test 3 parameters");
    signalSpy.setArguments(QVariantList() << 5 << 6 << 2);
    emit testSignal(5, 6, 2);
    QVERIFY(signalSpy.counter() == 1);
    SharedBus::notify(MAPPED(TestSignal::update(int,int,int)), 5, 6, 2);
    QVERIFY(signalSpy.counter() == 2);

    qDebug("test 4 parameters");
    signalSpy.setArguments(QVariantList() << 5 << 6 << 2 << 4);
    emit testSignal(5, 6, 2, 4);
    QVERIFY(signalSpy.counter() == 1);
    SharedBus::notify(MAPPED(TestSignal::update(int,int,int,int)), 5, 6, 2, 4);
    QVERIFY(signalSpy.counter() == 2);

    qDebug("test 5 parameters");
    signalSpy.setArguments(QVariantList() << 5 << 6 << 2 << 4 << 8);
    emit testSignal(5, 6, 2, 4, 8);
    QVERIFY(signalSpy.counter() == 1);
    SharedBus::notify(MAPPED(TestSignal::update(int,int,int,int,int)), 5, 6, 2, 4, 8);
    QVERIFY(signalSpy.counter() == 2);

    qDebug("test 6 parameters");
    signalSpy.setArguments(QVariantList() << 5 << 6 << 2 << 4 << 8 << 9);
    emit testSignal(5, 6, 2, 4, 8, 9);
    QVERIFY(signalSpy.counter() == 1);
    SharedBus::notify(MAPPED(TestSignal::update(int,int,int,int,int,int)), 5, 6, 2, 4, 8, 9);
    QVERIFY(signalSpy.counter() == 2);

    qDebug("test 7 parameters");
    signalSpy.setArguments(QVariantList() << 5 << 6 << 2 << 4 << 8 << 9 << 3);
    emit testSignal(5, 6, 2, 4, 8, 9, 3);
    QVERIFY(signalSpy.counter() == 1);
    SharedBus::notify(MAPPED(TestSignal::update(int,int,int,int,int,int,int)), 5, 6, 2, 4, 8, 9, 3);
    QVERIFY(signalSpy.counter() == 2);

    qDebug("test 8 parameters");
    signalSpy.setArguments(QVariantList() << 5 << 6 << 2 << 4 << 8 << 9 << 3 << 1);
    emit testSignal(5, 6, 2, 4, 8, 9, 3, 1);
    QVERIFY(signalSpy.counter() == 1);
    SharedBus::notify(MAPPED(TestSignal::update(int,int,int,int,int,int,int,int)), 5, 6, 2, 4, 8, 9, 3, 1);
    QVERIFY(signalSpy.counter() == 2);

    qDebug("test 9 parameters");
    signalSpy.setArguments(QVariantList() << 5 << 6 << 2 << 4 << 8 << 9 << 3 << 1 << 7);
    emit testSignal(5, 6, 2, 4, 8, 9, 3, 1, 7);
    QVERIFY(signalSpy.counter() == 1);
    SharedBus::notify(MAPPED(TestSignal::update(int,int,int,int,int,int,int,int,int)), 5, 6, 2, 4, 8, 9, 3, 1, 7);
    QVERIFY(signalSpy.counter() == 2);

    qDebug("test 10 parameters");
    signalSpy.setArguments(QVariantList() << 5 << 6 << 2 << 4 << 8 << 9 << 3 << 1 << 7 << 0);
    emit testSignal(5, 6, 2, 4, 8, 9, 3, 1, 7, 0);
    QVERIFY(signalSpy.counter() == 1);
    SharedBus::notify(MAPPED(TestSignal::update(int,int,int,int,int,int,int,int,int,int)), 5, 6, 2, 4, 8, 9, 3, 1, 7, 0);
    QVERIFY(signalSpy.counter() == 2);

    // 测试断开连接 Channel.
    SharedBus::detach(MAPPED(TestSignal::update()),
                          &signalSpy, SLOT(testSlot()));
    SharedBus::detach(MAPPED(TestSignal::update(int)),
                          &signalSpy, SLOT(testSlot(int)));

    qDebug("test 0 parameter");
    signalSpy.setArguments(QVariantList());
    emit testSignal();
    QVERIFY(signalSpy.counter() == 0);
    SharedBus::notify(MAPPED(TestSignal::update()));
    QVERIFY(signalSpy.counter() == 0);

    qDebug("test 1 parameter");
    signalSpy.setArguments(QVariantList() << 5);
    emit testSignal(5);
    QVERIFY(signalSpy.counter() == 0);
    SharedBus::notify(MAPPED(TestSignal::update(int)), 5);
    QVERIFY(signalSpy.counter() == 0);

    // 测试断开连接 subject.
    SharedBus::detach(this, SIGNAL(testSignal()),
                          MAPPED(TestSignal::update()));
    SharedBus::detach(this, SIGNAL(testSignal(int)),
                          MAPPED(TestSignal::update(int)));

    SharedBus::attach(MAPPED(TestSignal::update()),
                          &signalSpy, SLOT(testSlot()));
    SharedBus::attach(MAPPED(TestSignal::update(int)),
                          &signalSpy, SLOT(testSlot(int)));

    qDebug("test 0 parameter");
    signalSpy.setArguments(QVariantList());
    emit testSignal();
    QVERIFY(signalSpy.counter() == 0);
    SharedBus::notify(MAPPED(TestSignal::update()));
    QVERIFY(signalSpy.counter() == 1);

    qDebug("test 1 parameter");
    signalSpy.setArguments(QVariantList() << 5);
    emit testSignal(5);
    QVERIFY(signalSpy.counter() == 0);
    SharedBus::notify(MAPPED(TestSignal::update(int)), 5);
    QVERIFY(signalSpy.counter() == 1);
}

QTEST_APPLESS_MAIN(ChannelsTest)

#include "tst_busestest.moc"
