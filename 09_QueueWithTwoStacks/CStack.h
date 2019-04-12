/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

// 题9-2：用两个队列实现栈
// 题目：用两个队列实现一个栈。栈的声明如下，请实现它的两个函数pushTop
// 和popTop，分别完成在栈顶压入结点和弹出栈顶结点的功能。

#pragma once
#include <queue>
#include <exception>

using namespace std;

template <typename T> class CStack
{
public:
    CStack(void);
    ~CStack(void);
    
    // 在栈顶压入一个结点
    void pushTop(const T& node);

    // 弹出栈顶结点
    T popTop();
    T _doPopTop(queue<T>& queueA, queue<T>& queueB, bool& success);

private:
    queue<T> queue1;
    queue<T> queue2;
};

template <typename T> CStack<T>::CStack(void)
{
}

template <typename T> CStack<T>::~CStack(void)
{
}

template<typename T> void CStack<T>::pushTop(const T& element)
{
    if (!queue2.empty())
    {
        queue2.push(element);
        return;
    }
    else 
    {
        queue1.push(element);
    }
} 

template<typename T> T CStack<T>::_doPopTop(queue<T>& queueA, queue<T>& queueB, bool& success)
{
    while (queueA.size() > 1) {
        T &data = queueA.front();
        queueA.pop();
        queueB.push(data);
    }
    if (queueA.size() == 1) {
        T retFront = queueA.front();
        queueA.pop();
        success = true;
        return retFront;
    }
    return T();
}

template<typename T> T CStack<T>::popTop()
{
    bool success = false;
    T t = this->_doPopTop(queue1, queue2, success);
    if (success)
    {
        return t;
    }

    success = false;
    t = this->_doPopTop(queue2, queue1, success);
    if (success)
    {
        return t;
    }

    throw new exception();
}
