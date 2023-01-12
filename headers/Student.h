//
// Created by Anca on 12/9/2022.
//

#ifndef UNTITLED1_STUDENT_H
#define UNTITLED1_STUDENT_H
#include <Client.h>

class Student: public Client{

public:
    explicit Student(const std::string& name);
    ~Student() = default;
    std::shared_ptr<Client> clone() const override;

    double get_total() override;
};

#endif //UNTITLED1_STUDENT_H
