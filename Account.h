//
// Created by Jairo Riaño on 13/04/20.
//

#ifndef PRJBANK_ACCOUNT_H
#define PRJBANK_ACCOUNT_H

#include <string>

using namespace std;


class Account {
public:
    const static double minResidue;
    Account();
    Account(const string &number, double residue);
    void setNumber(const string &number);
    const string &getNumber() const;
    double getResidue() const;
    int getConsignments() const;
    int getWithdrawals() const;
    void consign(double);
    bool withDraw(double);
    bool transfer(Account*, double);
    static string parseNum(double);
    string toString();
    virtual ~Account();

private:
    string number;
    double residue;
    int consignments;
    int withdrawals;

    void setResidue( double );
};


#endif //PRJBANK_ACCOUNT_H
