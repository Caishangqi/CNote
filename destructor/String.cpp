#include "String.h"
#include <cstdio>
#include <cstring>

//Define the constructor and destructor
String::String(const char* ch)
{
    sizeOfText = strlen(ch) + 1;

    // Dynamically allocate the correct amount of memory.
    text_ = new char[sizeOfText];

    // If the allocation succeeds, copy the initialization string.
    if (text_)
        strcpy_s(text_, sizeOfText, ch);
    printf("String �Ĺ������Ե���");
}

// Define the destructor
String::~String()
{
    // Deallocate the memory that was previously reserved
    //  for this string.
    delete[] text_;
    printf("String ��ɾ���������Ե���");
}
