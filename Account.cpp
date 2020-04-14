//
// Created by Jairo Riaño on 13/04/20.
//

#include <sstream>
#include "Account.h"

const double Account::minResidue = 50000;

Account::Account() {
    this->number = std::string();
    this->residue = 0;
    this->consignments = 0;
    this->withdrawals = 0;
}

Account::Account(const std::string &number, double residue) : number(number), residue(residue) {
    setNumber( number );
    setResidue( residue);
    this->consignments = 0;
    this->withdrawals = 0;
}

void Account::setNumber(const std::string &number) {
    Account::number = number;
}

void Account::setResidue(double residue) {
    Account::residue = residue;
}

std::string Account::parseNum(double value) {
    std::ostringstream aux;
    aux << value;

    return aux.str();
}

const std::string &Account::getNumber() const {
    return number;
}

double Account::getResidue() const {
    return residue;
}

int Account::getConsignments() const {
    return consignments;
}

int Account::getWithdrawals() const {
    return withdrawals;
}

void Account::consign(double value) {
    setResidue( getResidue() + value );
    consignments++;
}

Account::~Account() {

}

bool Account::withDraw(double value) {
    if ( value < getResidue() - Account::minResidue ){
        setResidue( getResidue() - value );
        withdrawals++;

        return true;
    }

    return false;
}

bool Account::transfer(Account* account, double value) {
    if ( withDraw( value) ){
        account->consign( value );

        return true;
    }

    return false;
}

std::string Account::toString() {
    return "Account[number=" + number +", residue=" + parseNum( residue ) + ", consignments=" +
           parseNum( consignments) + ", withdrawals=" + parseNum( withdrawals) +"]";
}


