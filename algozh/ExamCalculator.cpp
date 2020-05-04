//
// Created by molna on 2020. 05. 02..
//

#include "ExamCalculator.h"
#include <sstream>
#include <iostream>

void ExamCalculator::parseData() {
    std::string line;
    auto firstExam = true;
    while(std::getline(in, line)) {
        std::string code;
        int points = 0;
        std::istringstream iss(line);
        while (iss >> code >> points) {
            auto newStudent = std::make_unique<Student_t>(code, points);
            firstExam ? _exam.push_back(std::move(newStudent)) : _correctionExam.push_back(std::move(newStudent));
        }
        if (firstExam) {
            firstExam = false;
        }
    }
}

void ExamCalculator::mergeExams() {
   for (auto& item : _exam) {
       if (item->_examValue < _correctionExam.front()->_examValue) {
           item->_examValue = _correctionExam.front()->_examValue;
       }
       _correctionExam.pop_front();
   }
}

void ExamCalculator::printExamResult() {
    for (const auto& e : _exam) {
        std::cout << e->_code << " " << e->_examValue << std::endl;
    }
}
