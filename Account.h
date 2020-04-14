//
// Created by Jairo Riaño on 13/04/20.
//

#ifndef PRJBANK_ACCOUNT_H
#define PRJBANK_ACCOUNT_H

#include <string>

class Account {
public:
    const static double minResidue;
    Account();
    Account(const std::string &number, double residue);
    void setNumber(const std::string &number);
    const std::string &getNumber() const;
    double getResidue() const;
    int getConsignments() const;
    int getWithdrawals() const;
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

    void setResidue( double );
};


#endif //PRJBANK_ACCOUNT_H
