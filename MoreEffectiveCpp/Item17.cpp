#include "stdafx.h"
#include "Item17.h"

void Item17::ItemEntry()
{
  // Item17: Consider using lazy egvaluation
  // Lazy evaluation: 实现类的时候，尽量延迟计算，知道需要这些计算结果的时候才去计算。
  // 只适用于明确知道不会经常需要进行所有计算的情况，比如矩阵使用时时常只使用部分元素，而不是整个矩阵的所有元素。
  // 四个实例：

  // 1. Reference Counting
  // 实现string类，拷贝构造函数如果直接用new分配堆内存，用strcpy复制字符串内容，则称为eager evaluation。
  // 虽然构造了新的对象，但其中的字符串尚未被使用，故可以使用lazy evaluation：
  // 拷贝构造函数让新对象共享被拷贝对象的字符串。此时读操作可直接执行。只有对两个对象其中之一执行写操作时，才需要真正执行拷贝。

  // 2. Distinguishing Reads from Writes
  // 用proxy类来区分同一个操作会被用在读逻辑还是写逻辑，以便在读逻辑时避免拷贝
  // 如:
  // cout << s[3]; //[]之后为读逻辑
  // s[3] = 's';   //[]之后为写逻辑

  // 3. Lazy Fetching
  // 考虑一个有很多成员的类，其对象存在数据库里。
  // 当用id从数据库获取对象时，如果把所有成员都读出来用于创建对象，会非常耗时。
  // Lazy fetching在创建对象时不读取任何成员，而是用到成员的时候才去数据库获取。
  // 实现的例子：用mutable的各种指针来指向实际成员，构造函数置所有指针为null，使用成员时如为空指针，则加载该成员。
  //            mutable是为了让const的getter成员函数可以修改成员指针指向的对象。

  // 4. Lazy Expression Evaluation
  // 如有两个矩阵(Matrix为自定义的矩阵模板类)：
  // Matrix<int> m1(1000, 1000);
  // Matrix<int> m2(1000, 1000);
  // Matrix<int> m3 = m1 + m2;
  // 此时m3不实际做内存分配和1000*1000次加法操作，而是记录操作符+，以及操作数m1和m2
  // 如果之后执行语句：
  // m3 = m4 * m1;
  // 则直接更新操作符和操作数即可。
  // cout << m3[3];
  // 此时也只计算这一个元素，而非计算所有元素。
}
