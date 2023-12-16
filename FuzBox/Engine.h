/*Bebtek engine v2*/
/*More optimized and faster version of Bebtek engine v1*/
/*Created Dec 16th, 2023*/

#include <iostream>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <ncurses.h>
#include <unistd.h>
#include <sys/types.h>
#include <cstdlib>
#include <termios.h>
#include <curl/curl.h>
#include <cstring>

#include "logo.h"
#include "calculator.h"

double version = 1.0;

void printCurrentTime() {
    // Get the current time
    time_t currentTime = time(0);
    struct tm *now = localtime(&currentTime);

    // Print the current time in HH:MM:SS format
    std::cout << "Current Time: "
              << (now->tm_hour < 10 ? "0" : "") << now->tm_hour << ":"
              << (now->tm_min < 10 ? "0" : "") << now->tm_min << ":"
              << (now->tm_sec < 10 ? "0" : "") << now->tm_sec << std::endl;
}

class Engine {
public:
    static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
        size_t total_size = size * nmemb;
        output->append(static_cast<char*>(contents), total_size);
        return total_size;
    }

    void waitForInput() {
        setTerminalMode();
        char c;
        while (true) {
            std::cout << "\033[95mFuzBox\033[0m [\033[96mBebtek2\033[0m] : ";
            std::cin.get(c);
            if (c == 'q') {
                system("clear");
                break;
            } else if (c == 'w') {
                std::cout << "\n";
                system("cowsay Welcome to FuzBox!");
            } else if (c == 'p') {
                system("clear");
                printLogo();
                printMenu();
            } else if (c == 'l') {
                std::cout << "\n";
                system("lsblk");
            } else if (c == 't') {
                system("alacritty");
            } else if (c == 'n') {
                system("neofetch");
            } else if (c == 'c') {
                std::cout << "\n";
                system("sudo pacman -Syu --noconfirm");
            } else if (c == 'u') {
                std::cout << "\n";
                system("uptime");
            } else if (c == 'i') {
                std::cout << "\n";
                printInfo();
            } else if (c == 's') {
                std::cout << "\n";
                system("whoami");
            } else if (c == 'g') {
                std::cout << "\n";
                system("getping.sh");
            } else if (c == 'm') {
                system("shutdown -P now");
            } else if (c == 'y') {
                std::cout << "\n";
                cout << version << endl;
            } else if (c == 'j') {
                system("htop");
            } else if (c == 'f') {
                std::cout << "\n";
                calculator();
            } else if (c == 'k') {
                std::cout << "\n";
                printCurrentTime();
            } else if (c == 'h') {
                std::cout << "\n";
                system("hollywood");
            } else if (c == 'd') {
                std::cout << "\n";
                system("curl ifconfig.me");
                std::cout << "\n";
            } else {
                std::cout << "Unknown command..." << std::endl;
                refresh();
            }
        }
        restoreTerminalMode();
    }
private:
    struct termios originalTermios;

    void setTerminalMode() {
        tcgetattr(STDIN_FILENO, &originalTermios);

        struct termios newTermios = originalTermios;
        newTermios.c_lflag &= ~ICANON; // Disable canonical mode
        newTermios.c_lflag &= ~ECHO;   // Disable echoing input characters

        tcsetattr(STDIN_FILENO, TCSANOW, &newTermios);
    }

    void restoreTerminalMode() {
        tcsetattr(STDIN_FILENO, TCSANOW, &originalTermios);
    }
};