//
// Created by Anca on 12/19/2022.
//

#ifndef MAIN_CPP_REGULAR_H
#define MAIN_CPP_REGULAR_H
#include <Client.h>

class Regular: public Client{
public:
    explicit Regular(const std::string& name);
    ~Regular() = default;
    std::shared_ptr<Client> clone() const override;

    double get_total() override;
};

#endif //MAIN_CPP_REGULAR_H
