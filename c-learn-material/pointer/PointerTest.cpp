//
// Created by Caishangqi on 2022/9/14.
//

#include "PointerTest.h"

/**
 * ����ָ�����
 */
void testPointer() {
    //����ָ��
    int a = 10;
    //�������� * ָ�����
    int *pointer;
    //��ָ���¼����a�ĵ�ַ
    pointer = &a;

    cout << "ָ���ַΪ " << pointer << endl;

    //ʹ��ָ��
    //ָ��ǰ�� * ��ʾ�����ã��ҵ�ָ��ָ���ڴ��е�����
    *pointer = 1000; //ͨ��ָ��ֱ���޸�ָ��ָ���ڴ��е�����
    cout << "a ��ֵΪ " << a << endl;
    cout << "ָ��pointer�ĵ�ַ�� " << &pointer << endl;


}

//ָ�������ռ�õ��ڴ��С, 32λ 4���ֽ� 64λ 8���ֽ�
void pointerSize() {

    int a = 100;
    int *pointer = &a;

    cout << "ָ��Ĵ�СΪ " << sizeof pointer << endl;


}

//����Ұָ��
void testPointer2() {

    cout << "==========" << endl;

    int *pointer = (int *) 0x68935ff5d0;
    cout << *pointer << endl;

    cout << "==========" << endl;

}
