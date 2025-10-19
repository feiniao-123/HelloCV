#include "Menu.h"
#include "Crypto.h"
#include "FileHandler.h"
#include <iostream>
#include <string>
using namespace std;

void Menu::showMenu() {
    cout << "=== 文本加密解密工具 ===\n";
    cout << "1. 加密文本\n";
    cout << "2. 解密文本\n";
    cout << "3. 加密文件\n";
    cout << "4. 解密文件\n";
    cout << "0. 退出\n";
    cout << "请选择功能：";
}

void Menu::handleChoice(int choice) {
    string text, keyStr, filepath1, filepath2;
    int key;

    switch (choice) {
        case 1:
            cout << "请输入要加密的文本：";
            cin.ignore();
            getline(cin, text);
            cout << "请输入密钥：";
            cin >> keyStr;
            key = stoi(keyStr);
            cout << "加密结果：" << crypto::encrypt(text, key) << "\n";
            break;
        case 2:
            cout << "请输入要解密的文本：";
            cin.ignore();
            getline(cin, text);
            cout << "请输入密钥：";
            cin >> keyStr;
            key = stoi(keyStr);
            cout << "解密结果：" << crypto::decrypt(text, key) << "\n";
            break;
        case 3:
            cout << "请输入要加密的文件路径：";
            cin >> filepath1;
            cout << "请输入密钥：";
            cin >> keyStr;
            key = stoi(keyStr);
            if (FileHandler::read(filepath1, text)) {
                string encrypted = crypto::encrypt(text, key);
                filepath2 = "encrypted.txt";
                if (FileHandler::write(filepath2, encrypted)) {
                    cout << "加密结果已保存到：" << filepath2 << "\n";
                } else {
                    cout << "保存失败！\n";
                }
            } else {
                cout << "文件读取失败！\n";
            }
            break;
        case 4:
            cout << "请输入要解密的文件路径：";
            cin >> filepath1;
            cout << "请输入密钥：";
            cin >> keyStr;
            key = stoi(keyStr);
            if (FileHandler::read(filepath1, text)) {
                string decrypted = crypto::decrypt(text, key);
                filepath2 = "decrypted.txt";
                if (FileHandler::write(filepath2, decrypted)) {
                    cout << "解密结果已保存到：" << filepath2 << "\n";
                } else {
                    cout << "保存失败！\n";
                }
            } else {
                cout << "文件读取失败！\n";
            }
            break;
        case 0:
            cout << "再见！\n";
            break;
        default:
            cout << "无效选择！\n";
    }
}