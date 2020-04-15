//
// Created by Jairo Riaño on 13/04/20.
//

#ifndef PRJBANK_MANAGEMENTBANK_H
#define PRJBANK_MANAGEMENTBANK_H

#include "Account.h"
#include "Customer.h"

class ManagementBank {
public:
    ManagementBank();
    Customer* findCustomer(std::string);
    bool addCustomer(std::string, std::string, std::string, EGender, std::string);
    Account* findAccount( std::string );
    bool addAccount( std::string, std::string, double );
    bool consign(std::string,double);
    bool withDraw( std::string, double );
    bool transfer(std::string, std::string, double );
    std::vector<Customer*> getCustomers();
    std::vector<Account*> getAccounts();

    virtual ~ManagementBank();

private:
    std::vector<Account*> accounts;
    std::vector<Customer*> customers;
};


#endif //PRJBANK_MANAGEMENTBANK_H
