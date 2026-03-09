#include "Inventory.h"
#include "Item.h"

// 도전 기능: 가격 기준 비교 함수
bool compareItemsByPrice(const Item& a, const Item& b) {
    return a.GetPrice() < b.GetPrice();
}

int main() {
    // 1. 인벤토리 생성 (초기 용량 2)
    Inventory<Item> myInven(2);

    // 2. 아이템 추가 및 자동 확장 테스트
    myInven.AddItem(Item("강철 검", 500));
    myInven.AddItem(Item("낡은 방패", 150));
    myInven.AddItem(Item("고급 포션", 300));

    myInven.PrintAllItems();

    // 3. 정렬 테스트
    myInven.SortItems(compareItemsByPrice);
    myInven.PrintAllItems();

    // 4. 제거 테스트
    cout << "마지막 아이템 제거 실행..." << endl;
    myInven.RemoveLastItem();
    myInven.PrintAllItems();

    // 5. 복사 생성자 테스트 (깊은 복사 확인)
    {
        Inventory<Item> subInven = myInven;
        subInven.AddItem(Item("복사본 전용 템", 9999));
        cout << "--- 복사된 인벤토리 ---" << endl;
        subInven.PrintAllItems();
    }

    cout << "--- 원본 인벤토리 유지 확인 ---" << endl;
    myInven.PrintAllItems();

    return 0;
}