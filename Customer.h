//
// Created by Jairo Riaño on 13/04/20.
//

#ifndef PRJBANK_CUSTOMER_H
#define PRJBANK_CUSTOMER_H

#include <vector>
#include "Account.h"
#include "EGender.h"

class Customer {
public:
    Customer();

    Customer(const std::string &idCustomer, const std::string &firstName, const std::string &lastName, EGender gender,
             const std::string &phone);

    const std::string &getIdCustomer() const;

    void setIdCustomer(const std::string &idCustomer);

    const std::string &getFirstName() const;

    void setFirstName(const std::string &firstName);

    const std::string &getLastName() const;

    void setLastName(const std::string &lastName);

    EGender getGender() const;

    void setGender(EGender gender);

    const std::string &getPhone() const;

    void setPhone(const std::string &phone);

    Account* findAccount( std::string );

    bool addAccount( std::string, double );

    std::vector<Account*> getAccounts();

    std::string toString();

    virtual ~Customer();

private:
    std::string idCustomer;
    std::string firstName;
    std::string lastName;
    EGender gender;
    std::string phone;
    std::vector<Account*> accounts;
};


#endif //PRJBANK_CUSTOMER_H
