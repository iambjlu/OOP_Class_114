#include <iostream>
#include <string>
using namespace std;

void visit() {
    static int times = 0;
    times++;
    cout << "這個函式已被呼叫 " << times << " 次" << endl;
}

int main() {
    string name = "小華";
    int age = 18;
    double height = 172.3;

    cout << "=== 個人資料 ===" << endl;
    cout << "姓名: " << name << endl;
    cout << "年齡: " << age << endl;
    cout << "身高: " << height << endl;

    int math = 80;
    int english = 90;
    int total = math + english;
    double average = total / 2.0;

    cout << "\n=== 成績資料 ===" << endl;
    cout << "數學: " << math << endl;
    cout << "英文: " << english << endl;
    cout << "總分: " << total << endl;
    cout << "平均: " << average << endl;

    cout << "\n=== static 示範 ===" << endl;
    visit();
    visit();
    visit();
    return 0;
}
