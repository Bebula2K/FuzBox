#include <iostream>
#include "Engine.h"
#include "logo.h"

using namespace std;

int main(){
    system("clear");
    while(1){
        printLogo();
        printMenu();
        Engine engine;
        engine.waitForInput();
        return 0;
    }
}