#include <iostream>
#include "tester.h"

using namespace std;

int main()
{
    Tester tester("C:\\Users\\thoma\\Documents\\travail\\polytech\\SI3\\archi\\tests\\test_controller.txt", 50);
    tester.generateTest(Tester::LSL);
    tester.generateTest(Tester::LSR);
    tester.generateTest(Tester::ADD);
    return 0;
}
