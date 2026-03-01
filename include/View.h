#pragma once
#include <string>
#include"Document.h"
#include<iostream>

class View
{
public:
    virtual ~View() = default;
    virtual void showMessage(const std::string& msg) = 0;
    virtual void displayDocument(const Document& doc) = 0;
};

class ConsoleView :public View
{
public:
    void showMessage(const std::string& msg) override;
    void displayDocument(const Document& doc) override;
    virtual ~ConsoleView() {};
};
