#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// 定義一個簡單的結購物代表學生
struct Student {
    string name;
    int score;
};

int main() {
    // 1. STL Vector 操作：準備要序列化的資料
    vector<Student> classList;
    classList.push_back({"Alice", 95});
    classList.push_back({"Bob", 82});
    classList.push_back({"Eve", 58});

    string filename = "scores.csv";

    // --- 序列化 (Serialization)：將 Vector 寫入 CSV 檔案 ---
    ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto& student : classList) {
            // 用逗號分隔資料並換行
            outFile << student.name << "," << student.score << "\n";
        }
        outFile.close();
        cout << "資料序列化成功！已儲存至 " << filename << endl;
    } else {
        cerr << "檔案開啟失敗！" << endl;
    }

    // --- 反序列化 (Deserialization)：從 CSV 讀取並裝回 Vector ---
    vector<Student> loadedList;
    ifstream inFile(filename);
    string line;

    if (inFile.is_open()) {
        while (getline(inFile, line)) { // 一次讀取一行
            stringstream ss(line);      // 使用字串串流進行切割
            string nameStr, scoreStr;

            // 用逗號切割字串串流
            if (getline(ss, nameStr, ',') && getline(ss, scoreStr, ',')) {
                // 將成績字串轉回整數 (stoi)
                loadedList.push_back({nameStr, stoi(scoreStr)});
            }
        }
        inFile.close();
        cout << "\n資料反序列化成功！讀取結果：" << endl;
        for (const auto& student : loadedList) {
            cout << "姓名: " << student.name << " | 成績: " << student.score << endl;
        }
    } else {
        cerr << "無法讀取檔案！" << endl;
    }

    return 0;
}