//
// Created by Jairo Riaño on 13/04/20.
//

#ifndef PRJBANK_ACCOUNT_H
#define PRJBANK_ACCOUNT_H

#include <string>
#include "Customer.h"

class Customer;

class Account {
public:
    const static double minResidue;
    Account();
    Account(Customer*, const std::string &number, double residue);
    void setCustomer( Customer* );
    void setNumber(const std::string &number);
    const std::string &getNumber() const;
    double getResidue() const;
    int getConsignments() const;
    int getWithdrawals() const;
    Customer* getCustomer();
    void consign(double);
    bool withDraw(double);
    bool transfer(Account*, double);
    static std::string parseNum(double);
    std::string toString();
    virtual ~Account();

private:
    std::string number;
    double residue;
    int consignments;
    int withdrawals;
    Customer* customer;

    void setResidue( double );
};


#endif //PRJBANK_ACCOUNT_H
