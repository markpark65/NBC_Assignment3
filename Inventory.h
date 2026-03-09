#pragma once
#pragma once
#include <iostream>
#include <algorithm> // std::sort 사용

using namespace std;

template <typename T>
class Inventory {
public:

    Inventory(int capacity = 10) {
        if (capacity <= 0) capacity = 1;
        capacity_ = capacity;
        size_ = 0;
        pItems_ = new T[capacity_];
        cout << "인벤토리 생성 (용량: " << capacity_ << ")" << endl;
    }

    ~Inventory() {
        if (pItems_ != nullptr) {
            delete[] pItems_;
            pItems_ = nullptr;
        }
        cout << "인벤토리 소멸 및 메모리 해제 완료" << endl;
    }


    Inventory(const Inventory<T>& other) {
        capacity_ = other.capacity_;
        size_ = other.size_;
        pItems_ = new T[capacity_];
        for (int i = 0; i < size_; ++i) {
            pItems_[i] = other.pItems_[i];
        }
        cout << "인벤토리 복사 생성 완료 (깊은 복사)" << endl;
    }

    void Resize(int newCapacity) {
        if (newCapacity <= capacity_) return;

        T* pNewItems = new T[newCapacity];
        for (int i = 0; i < size_; i++) {
            pNewItems[i] = pItems_[i];
        }

        delete[] pItems_;
        pItems_ = pNewItems;
        capacity_ = newCapacity;
        cout << "인벤토리 확장: " << capacity_ << "칸" << endl;
    }

    void AddItem(const T& item) {
        if (size_ >= capacity_) {
            cout << "인벤토리가 꽉 찼습니다! 용량을 2배로 늘립니다." << endl;
            Resize(capacity_ * 2);
        }
        pItems_[size_] = item;
        size_++;
    }


    void RemoveLastItem() {
        if (size_ <= 0) {
            cout << "인벤토리가 비어있습니다." << endl;
            return;
        }
        size_--;
    }


    void PrintAllItems() const {
        if (size_ == 0) {
            cout << "인벤토리가 비어있음" << endl;
            return;
        }
        cout << "--- 인벤토리 목록 (Size: " << size_ << "/" << capacity_ << ") ---" << endl;
        for (int i = 0; i < size_; i++) {
            pItems_[i].PrintInfo();
        }
        cout << "------------------------------------------" << endl;
    }


    void SortItems(bool (*compare)(const T&, const T&)) {
        std::sort(pItems_, pItems_ + size_, compare);
        cout << "아이템 정렬 완료!" << endl;
    }

    int GetSize() const { return size_; }
    int GetCapacity() const { return capacity_; }

private:
    T* pItems_;
    int capacity_;
    int size_;
};