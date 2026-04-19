// main.cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// --- 三十五、抽象類別 (Abstract Class) ---
class Character {
protected:
    string name;
    int power;
    // 三十八、靜態成員：用來計算總共創造了幾個角色
    static int totalCharacters;

public:
    Character(string n, int p) : name(n), power(p) {
        totalCharacters++;
    }

    // 三十四、虛擬函式：允許子類別複寫行為
    // 三十五、純虛擬函式：等於 0 代表這是一個「畫餅」類別，不能直接產生物件
    virtual void attack() = 0;

    // Getter
    int getPower() const { return power; }
    string getName() const { return name; }

    // 三十八、this 指標示範
    void introduce() {
        cout << "我是 " << this->name << "，戰力值：" << this->power << endl;
    }

    static int getTotal() { return totalCharacters; }

    // 虛擬解構子是個好習慣
    virtual ~Character() {}
};

int Character::totalCharacters = 0;

// --- 三十三、複寫 (Overriding) ---
class Warrior : public Character {
public:
    Warrior(string n, int p) : Character(n, p) {}

    // 複寫父類別的 attack
    void attack() override {
        cout << "[戰士] " << name << " 發動「大劍斬擊」，造成物理傷害！" << endl;
    }
};

class Mage : public Character {
public:
    Mage(string n, int p) : Character(n, p) {}

    void attack() override {
        cout << "[法師] " << name << " 吟唱「火球術」，造成魔法爆破！" << endl;
    }
};

// --- 三十六、運算子多載 (Operator Overloading) ---
// 讓兩個角色可以「+」在一起，回傳總戰力值
int operator+(const Character& c1, const Character& c2) {
    return c1.getPower() + c2.getPower();
}

int main() {
    // 三十七、指標 (Pointer) 與 動態分配
    // 使用父類別指標指向子類別物件（多型的精髓）
    Character* hero1 = new Warrior("亞瑟", 800);
    Character* hero2 = new Mage("梅林", 950);

    cout << "=== 冒險開始 ===" << endl;
    hero1->introduce();
    hero2->introduce();

    // 三十四、動態綁定示範：雖然都是 Character*，但跑出來的攻擊不同
    hero1->attack();
    hero2->attack();

    // 三十六、運算子多載示範
    int combinedPower = (*hero1) + (*hero2);
    cout << "\n小隊總戰力 (運算子多載)：" << combinedPower << endl;

    // 三十八、靜態成員存取
    cout << "目前世界上的角色總數：" << Character::getTotal() << endl;

    // 三十七、記憶體釋放（出來混總是要還的）
    delete hero1;
    delete hero2;
    hero1 = nullptr;
    hero2 = nullptr;

    cout << "\n=== 程式結束，空間已釋放 ===" << endl;

    return 0;
}
