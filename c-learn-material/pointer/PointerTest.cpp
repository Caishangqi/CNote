//
// Created by Caishangqi on 2022/9/14.
//

#include "PointerTest.h"

/**
 * 基础指针操作
 */
void testPointer() {
    //定义指针
    int a = 10;
    //数据类型 * 指针变量
    int *pointer;
    //让指针记录变量a的地址
    pointer = &a;

    cout << "指针地址为 " << pointer << endl;

    //使用指针
    //指针前加 * 表示解引用，找到指针指向内存中的数据
    *pointer = 1000; //通过指针直接修改指针指向内存中的数据
    cout << "a 的值为 " << a << endl;
    cout << "指针pointer的地址是 " << &pointer << endl;


}

//指针变量所占用的内存大小, 32位 4个字节 64位 8个字节
void pointerSize() {

    int a = 100;
    int *pointer = &a;

    cout << "指针的大小为 " << sizeof pointer << endl;


}

//测试野指针
void testPointer2() {

    cout << "==========" << endl;

    int *pointer = (int *) 0x68935ff5d0;
    cout << *pointer << endl;

    cout << "==========" << endl;

}
