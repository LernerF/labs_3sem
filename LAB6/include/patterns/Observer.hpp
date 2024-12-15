#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

class Observer {
public:
    virtual void update(const std::string& event) = 0;
    virtual ~Observer() = default;
};

class ConsoleObserver : public Observer {
public:
    void update(const std::string& event) override {
        std::cout << event << std::endl;
    }
};

class FileObserver : public Observer {
private:
    std::string filename;
public:
    explicit FileObserver(const std::string& file) : filename(file) {}
    void update(const std::string& event) override {
        std::ofstream log_file(filename, std::ios::app);
        if (log_file.is_open()) {
            log_file << event << std::endl;
            log_file.close();
        }
    }
};