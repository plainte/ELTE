//
// Created by molna on 2020. 05. 02..
//

#ifndef ALGOZH_EXAMCALCULATOR_H
#define ALGOZH_EXAMCALCULATOR_H

#include <string>
#include <list>
#include <memory>
#include <utility>
#include <fstream>

typedef struct Student {
    Student(const std::string& code, int examValue) : _code(code), _examValue(examValue) {}
    std::string _code;
    int _examValue;
} Student_t;


class ExamCalculator {
public:
    ExamCalculator(const std::string& filename) { in.open(filename); }
    ~ExamCalculator() { if(in) { in.close(); }}

    void parseData();

    void mergeExams();

    void printExamResult();
private:
    std::ifstream in;
    std::list<std::unique_ptr<Student_t>> _exam;
    std::list<std::unique_ptr<Student_t>> _correctionExam;
};


#endif //ALGOZH_EXAMCALCULATOR_H
