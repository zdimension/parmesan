#include <iostream>
#include "tester.h"

using namespace std;

int main()
{
    //Tester tester(R"(C:\Users\Emmy\Documents\BOSSAGE\BAC +3\S5\archi\parmesan\parmesan\tests", 50);
    Tester tester("C:\\Users\\thoma\\Documents\\travail\\polytech\\SI3\\archi\\tests\\test_controller.txt", 50);
    tester.generateTest(Tester::LDR);
    return 0;
}
