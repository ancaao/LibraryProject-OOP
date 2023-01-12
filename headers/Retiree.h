//
// Created by Anca on 12/10/2022.
//

#ifndef UNTITLED1_RETIREE_H
#define UNTITLED1_RETIREE_H
#include <Client.h>

class Retiree: public Client{
public:
    explicit Retiree(const std::string& name);
    ~Retiree() = default;
    std::shared_ptr<Client> clone() const override;

    double get_total() override;

};

#endif //UNTITLED1_RETIREE_H
