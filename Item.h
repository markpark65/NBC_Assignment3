#pragma once
#include <iostream>
#include <string>

using namespace std;

class Item {
public:
    Item() : name_("공백"), price_(0) {}
    Item(string name, int price) : name_(name), price_(price) {}

    void PrintInfo() const {
        cout << "[이름: " << name_ << ", 가격: " << price_ << "G]" << endl;
    }

    int GetPrice() const { return price_; }
    string GetName() const { return name_; }

private:
    string name_;
    int price_;
};