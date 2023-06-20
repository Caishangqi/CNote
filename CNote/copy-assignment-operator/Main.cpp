#include <iostream>
using namespace std;

class MyClass
{
public:
    MyClass();
    ~MyClass();
    MyClass& operator=(const MyClass& objToCopy);

    // Set member value dataObject
    void SetDataObject(const int setVal)
    {
        *dataObject = setVal;
    }

    // Return member value dataObject
    int GetDataObject() const
    {
        return *dataObject;
    }

private:
    int* dataObject; // Data member
};

// Default constructor
MyClass::MyClass()
{
    cout << "Constructor called." << endl;
    dataObject = new int; // Allocate mem for data
    *dataObject = 0;
}

// Destructor
MyClass::~MyClass()
{
    cout << "Destructor called." << endl;
    delete dataObject;
}

MyClass& MyClass::operator=(const MyClass& objToCopy)
{
    cout << "Assignment op called." << endl;

    if (this != &objToCopy) //如果 自己 = 自己 指针相同则取消赋值
    {
                                                // 1. 不要自己给自己赋值
        delete dataObject;                      // 2. 释放自己旧值的内存
        dataObject = new int;                   // 3. 新建一个int指针准备接收值
        *dataObject = *(objToCopy.dataObject);  // 4. 从等于号右边的相同类型对象中的值解引再赋值
    }

    return *this;                               // 5. *this是rvalues，可以被引用值lvalue储存
}

int main()
{
    MyClass classObj1; // Create object of type MyClass
    MyClass classObj2; // Create object of type MyClass

    // Set and print object 1 data member value
    classObj1.SetDataObject(9);

    // Copy class object using copy assignment operator
    classObj2 = classObj1;

    // Set object 1 data member value
    classObj1.SetDataObject(1);

    // Print data values for each object
    cout << "classObj1:" << classObj1.GetDataObject() << endl;
    cout << "classObj2:" << classObj2.GetDataObject() << endl;

    return 0;
}
