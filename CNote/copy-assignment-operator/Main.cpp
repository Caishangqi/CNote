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

    if (this != &objToCopy) //��� �Լ� = �Լ� ָ����ͬ��ȡ����ֵ
    {
                                                // 1. ��Ҫ�Լ����Լ���ֵ
        delete dataObject;                      // 2. �ͷ��Լ���ֵ���ڴ�
        dataObject = new int;                   // 3. �½�һ��intָ��׼������ֵ
        *dataObject = *(objToCopy.dataObject);  // 4. �ӵ��ں��ұߵ���ͬ���Ͷ����е�ֵ�����ٸ�ֵ
    }

    return *this;                               // 5. *this��rvalues�����Ա�����ֵlvalue����
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
