#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
    list<string> books;
    string command;

    while (cin >> command) {
        if (command == "add_front") {
            string book;
            cin >> book;
            books.push_front(book);
            cout << "ok" << endl;
        }
        else if (command == "add_back") {
            string book;
            cin >> book;
            books.push_back(book);
            cout << "ok" << endl;
        }
        else if (command == "erase_front") {
            if (!books.empty()) {
                cout << books.front() << endl;
                books.pop_front();
            } else {
                cout << "error" << endl;
            }
        }
        else if (command == "erase_back") {
            if (!books.empty()) {
                cout << books.back() << endl;
                books.pop_back();
            } else {
                cout << "error" << endl;
            }
        }
        else if (command == "front") {
            if (!books.empty()) {
                cout << books.front() << endl;
            } else {
                cout << "error" << endl;
            }
        }
        else if (command == "back") {
            if (!books.empty()) {
                cout << books.back() << endl;
            } else {
                cout << "error" << endl;
            }
        }
        else if (command == "clear") {
            books.clear();
            cout << "ok" << endl;
        }
        else if (command == "exit") {
            cout << "goodbye" << endl;
            break;
        }
    }
    return 0;
}