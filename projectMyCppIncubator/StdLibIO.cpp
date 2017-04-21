#include "stdafx.h"
#include "StdLibIO.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using std::cin;
using std::endl;
using std::cout;
using std::cerr;
using std::istream;
using std::string;
using std::flush;
using std::ends;
using std::unitbuf;
using std::nounitbuf;
using std::ostream;
using std::ifstream;
using std::ofstream;
using std::fstream;

StdLibIO::StdLibIO()
{
}


StdLibIO::~StdLibIO()
{
}

void getCinStateBits(void)
{
    // 查看constexpr标志位的值，可用于位操作置或清标志位
    cout << "istream bit: badbit[" << istream::badbit   // 系统级错误，流已崩溃
        << "] failbit[" << istream::failbit             // IO操作失败，可修正继续使用
        << "] eofbit[" << istream::eofbit               // 流到达文件结束，会同时置fail
        << "] gootbit[" << istream::goodbit             // 流未处于错误状态
        << "]" << endl;
}

void getCinStateFunc(void)
{
    cout << "istream bitfun: bad()[" << cin.bad()       // badbit置位时返回true
        << "] fail()[" << cin.fail()                    // failbit或bad置位时返回true
        << "] eof()[" << cin.eof()                      // eofbit置位时返回true
        << "] good()[" << cin.good()                    // 流处于有效状态时返回true
        << "]" << endl;
}

void StdLibIO::conditionState(void)
{
    // iostate是机器相关的类型，提供了表达条件状态的完整功能
    istream::iostate curCondStat = cin.rdstate(); // rdstate()返回当前条件状态
    getCinStateBits();
    cout << "---Initial---" << endl;
    getCinStateFunc();

    // 输入的类型和期望类型不匹配，产生fail
    int intInput = 0;
    cout << "---Test fail. Expect int, but enter string.---" << endl;
    cin >> intInput;
    getCinStateFunc();

    // 需要清除错误状态，才能继续使用
    cout << "---Clear cin.---" << endl;
    cin.clear(); // 所有条件状态位复位，流状态置为有效
    getCinStateFunc();

    // 输入EOF，产生eof和fail
    char charAryInput[50];
    cout << "---Test EOF. Enter Ctrl+D (Unix) or Ctrl+Z (Win)---" << endl;
    cin >> charAryInput; // 把之前输入的字符串读取掉
    cin >> charAryInput;
    getCinStateFunc();

    // 用位操作清除错误状态
    cout << "---Bit clear cin.---" << endl;
    cin.clear(cin.rdstate() & ~cin.failbit & ~cin.eofbit); // 清除fail和eof位
    getCinStateFunc();
}

void StdLibIO::outputBuffer(void)
{
    // 导致缓冲刷新的原因：
    // - 程序正常结束，缓冲刷新作为main函数return操作的一部分
    // - 缓冲区满
    // - endl显式刷新
    // - 输出操作之后用操纵符unitbuf设置流内部状态来清空缓冲区。cerr默认设置unitbuf，写到ceer的内容立即刷新
    // - 当输出流被关联到其他流时，读写被关联的流导致刷新。默认cin和cerr关联到cout，故读cin或写cerr会刷新cout缓冲区
    // * 程序崩溃时不会刷新缓冲区
    
    cout << "flush" << flush; // 输出后刷新缓冲区，不附加额外字符
    cout << "ends" << ends; // 输出内容和一个空字符，刷新缓冲区
    cout << "endl" << endl; // 输出内容和一个换行，刷新缓冲区

    cout << unitbuf; // 此后的输出操作都立即刷新缓冲区
    cout << "unitbufed";
    cout << nounitbuf; // 此后的输出操作恢复正常缓冲方式
    cout << endl;

    // 交互式系统一般关联输入流和输出流，这样在读操作之前保证要输出的用户提示信息都已经被打印出来
    // 可以将istream对象关联到ostream，也可以将ostream对象关联到ostream
    if (&cout == cin.tie()) // 如果已经关联则返回关联的流指针，否则返回空指针
    { cout << "cin already tied to cout." << endl; }

    ostream *oldTieOstream = cin.tie(nullptr); // cin不关联其他流
    cin.tie(oldTieOstream); // cin关联cout
    cout << "End of tie testing" << endl;
}

void StdLibIO::fileStream(void)
{
    // ifstream 从给定文件读取数据
    // ofstream 向给定文件写入数据
    // fstream  读写给定文件

    // 创建文件流，绑定文件
    ifstream iFileStream; // 创建文件流但不绑定文件
    cout << "Is iFileStream open: " << iFileStream.is_open() << endl;
    iFileStream.open(".\\Resources\iFile.txt"); // 以默认模式绑定文件
    cout << "Is iFileStream open: " << iFileStream.is_open() << endl;
    ofstream oFileStream(string(".\\Resources\\oFile.txt")); // 创建文件流并用默认模式绑定文件
    fstream fileStream(string{ ".\\Resources\\file.txt" }, fstream::in | fstream::out); // 创建文件流并以指定模式绑定

    // 关闭绑定的文件
    iFileStream.close();
    oFileStream.close();
    fileStream.close();
}
