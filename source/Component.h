#pragma once
#include <string>

class Component{
public:
     std::string name;
public:
    Component();
    ~Component();
    virtual int run() = 0;
    virtual int init() = 0;
};
