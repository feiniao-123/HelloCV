#include  "Menu.h"
#include <iostream>
using namespace std;

int main() {
    int choice;
    do {
        Menu::showMenu();
        cin >> choice;
        Menu::handleChoice(choice);
    } while (choice != 0);
    return 0;
}