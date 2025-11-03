#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <filesystem>
#include <iomanip>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
using namespace std;
namespace fs = std::filesystem;

void listFiles(const fs::path &path) {
    if (!fs::exists(path)) {
        cout << "Path not found.\n";
        return;
    }
    for (const auto &entry : fs::directory_iterator(path)) {
        if (entry.is_directory())
            cout << "[DIR]  " << entry.path().filename().string() << "\n";
        else
            cout << "[FILE] " << entry.path().filename().string() << "\n";
    }
}

bool changeDir(const string &dir) {
    fs::path newPath = fs::current_path() / dir;
    if (dir == "..") newPath = fs::current_path().parent_path();
    if (fs::exists(newPath) && fs::is_directory(newPath)) {
        fs::current_path(newPath);
        return true;
    } else {
        cout << "Directory not found.\n";
        return false;
    }
}

void makeDir(const string &name) {
    if (fs::create_directory(name))
        cout << "Directory created.\n";
    else
        cout << "Failed to create directory.\n";
}

void makeFile(const string &name) {
    ofstream file(name);
    if (file) cout << "File created.\n";
    else cout << "Failed to create file.\n";
}

void removePath(const string &name) {
    if (!fs::exists(name)) {
        cout << "File/Directory not found.\n";
        return;
    }
    fs::remove_all(name);
    cout << "Removed successfully.\n";
}

void searchFile(const fs::path &root, const string &name) {
    for (auto &p : fs::recursive_directory_iterator(root)) {
        if (p.path().filename().string().find(name) != string::npos)
            cout << "Found: " << p.path().string() << "\n";
    }
}

void fileInfo(const string &path) {
    if (!fs::exists(path)) {
        cout << "File/Directory not found.\n";
        return;
    }
    cout << "Path: " << fs::absolute(path) << "\n";
    cout << "Type: " << (fs::is_directory(path) ? "Directory" : "File") << "\n";
    if (fs::is_regular_file(path))
        cout << "Size: " << fs::file_size(path) << " bytes\n";
}

int main() {
    string cmd, arg;
    while (true) {
        cout << "\n" << fs::current_path().string() << " > ";
        cin >> cmd;
        if (cmd == "ls") listFiles(fs::current_path());
        else if (cmd == "cd") { cin >> arg; changeDir(arg); }
        else if (cmd == "mkdir") { cin >> arg; makeDir(arg); }
        else if (cmd == "touch") { cin >> arg; makeFile(arg); }
        else if (cmd == "rm") { cin >> arg; removePath(arg); }
        else if (cmd == "search") { cin >> arg; searchFile(fs::current_path(), arg); }
        else if (cmd == "info") { cin >> arg; fileInfo(arg); }
        else if (cmd == "exit") break;
        else cout << "Unknown command.\n";
    }
    return 0;
}
