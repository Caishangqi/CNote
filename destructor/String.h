#pragma once

class String
{
public:
    /* declare constructor*/
    String(const char* ch);
    /* declare destructor*/
    ~String();

private:
    char* text_;
    size_t sizeOfText;
};
