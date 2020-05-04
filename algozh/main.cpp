#include <iostream>
#include "ExamCalculator.h"

int main() {
    ExamCalculator examCalculator("../test.txt");
    examCalculator.parseData();
    examCalculator.mergeExams();
    examCalculator.printExamResult();

    std::cout << "Press a key to quit..." << std::endl;
    std::getchar();
    return 0;
}
