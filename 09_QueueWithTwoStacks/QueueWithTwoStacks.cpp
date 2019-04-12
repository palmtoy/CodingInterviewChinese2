/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

// 题9-1：用两个栈实现队列
// 题目：用两个栈实现一个队列。队列的声明如下，请实现它的两个函数appendTail
// 和deleteHead，分别完成在队列尾部插入结点和在队列头部删除结点的功能。

// 题9-2：用两个队列实现栈
// 题目：用两个队列实现一个栈。栈的声明如下，请实现它的两个函数pushTop
// 和popTop，分别完成在栈顶压入结点和弹出栈顶结点的功能。

#include "Queue.h"
#include "CStack.h"

// ====================测试代码====================
void Test(char actual, char expected)
{
    if(actual == expected)
        printf("Test passed.\n");
    else
        printf("Test failed.\n");
}

int main(int argc, char* argv[])
{
    printf("09_QueueWithTwoStacks/QueueWithTwoStacks is running ...\n");

    CQueue<char> queue;

    queue.appendTail('a');
    queue.appendTail('b');
    queue.appendTail('c');

    char head = queue.deleteHead();
    Test(head, 'a');

    head = queue.deleteHead();
    Test(head, 'b');

    queue.appendTail('d');
    head = queue.deleteHead();
    Test(head, 'c');

    queue.appendTail('e');
    head = queue.deleteHead();
    Test(head, 'd');

    head = queue.deleteHead();
    Test(head, 'e');

    printf("=======\n");

    CStack<char> s;

    s.pushTop('a');
    s.pushTop('b');
    s.pushTop('c');

    char t = s.popTop();
    Test(t, 'c');

    t = s.popTop();
    Test(t, 'b');

    s.pushTop('d');
    t = s.popTop();
    Test(t, 'd');

    s.pushTop('e');
    t = s.popTop();
    Test(t, 'e');

    t = s.popTop();
    Test(t, 'a');

    return 0;
}
