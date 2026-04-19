// Week8_Inheritance_BMW.cpp
#include <iostream>
#include <string>

using namespace std;

// --- 組合概念：引擎類別 ---
class Engine {
public:
    string type;
    Engine(string t) : type(t) {}
    void start() { cout << "引擎 (" << type << ") 已啟動。" << endl; }
};

// --- 父類別 (Base Class)：汽車 ---
class Car {
protected:
    string brand;
    Engine engine; // 組合 (Composition)

public:
    Car(string b, string eType) : brand(b), engine(eType) {}

    virtual void drive() { // virtual 關鍵字允許子類別複寫
        engine.start();
        cout << brand << " 正在行駛中..." << endl;
    }
};

// --- 子類別 (Derived Class)：電動車 ---
class ElectricCar : public Car {
private:
    int batteryLevel;

public:
    // 透過初始化列表呼叫父類別構造函數
    ElectricCar(string b, int battery) : Car(b, "電動馬達"), batteryLevel(battery) {}

    void charge() {
        batteryLevel = 100;
        cout << brand << " 已充滿電。" << endl;
    }

    void drive() override { // 複寫父類別方法
        cout << "[EV 模式] " << brand << " 靜音行駛中，剩餘電量: " << batteryLevel << "%" << endl;
    }
};

// --- 子類別 (Derived Class)：燃油車 ---
class GasCar : public Car {
public:
    GasCar(string b) : Car(b, "內燃機") {}

    void drive() override {
        cout << "[燃油模式] " << brand << " 咆哮行駛中，展現排氣聲浪。" << endl;
    }
};

int main() {
    // 實例化 BMW 燃油車
    GasCar m440i("BMW M440i");

    // 實例化 BMW 電動車
    ElectricCar i4M50("BMW i4 M50", 85);

    cout << "--- 測試 BMW M440i (燃油車) ---" << endl;
    m440i.drive();

    cout << "\n--- 測試 BMW i4 M50 (電動車) ---" << endl;
    i4M50.drive();
    i4M50.charge();

    return 0;
}