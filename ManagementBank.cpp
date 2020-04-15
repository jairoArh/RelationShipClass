//
// Created by Jairo Riaño on 13/04/20.
//

#include "ManagementBank.h"

ManagementBank::ManagementBank() {

}

Customer *ManagementBank::findCustomer(std::string idCustomer) {
    for( Customer* customer : customers ){
        if( customer->getIdCustomer().compare( idCustomer ) == 0 ){
            return customer;
        }
    }

    return NULL;
}

bool ManagementBank::addCustomer(std::string idCustomer, std::string firstName, std::string lastName, EGender gender, std::string phone) {
    if ( !findCustomer(idCustomer) ){
        customers.push_back(new Customer(idCustomer,firstName,lastName,gender,phone));

        return true;
    }

    return false;
}

Account *ManagementBank::findAccount(std::string number) {
    for( Account* account : accounts ){
        if ( account->getNumber().compare(number) == 0 ){
            return account;
        }
    }

    return NULL;
}

bool ManagementBank::addAccount(std::string idCustomer, std::string number, double value) {
    Customer* customer = findCustomer( idCustomer);
    if ( customer ){
        if ( !findAccount( number ) ){
            Account* account = new Account(customer,number,value);
            accounts.push_back( account );
            customer->addAccount( account );

            return true;
        }

        return false;
    }

    return false;
}

bool ManagementBank::consign(std::string number, double value) {
    Account* account = findAccount( number );
    if( account ){
        account->consign( value );

        return true;
    }

    return false;
}

bool ManagementBank::withDraw(std::string number, double value) {
    Account* account = findAccount( number );
    if( account ){
        return account->withDraw( value );
    }

    return false;
}

bool ManagementBank::transfer(std::string source, std::string target, double value) {
    Account* ctaSource = findAccount(source);
    Account* ctaTarget = findAccount(target);
    if(ctaSource && ctaTarget){
       return ctaSource->transfer( ctaTarget, value );
    }

    return false;
}

std::vector<Customer *> ManagementBank::getCustomers() {
    return std::vector<Customer *>(customers);
}

ManagementBank::~ManagementBank() {

}

std::vector<Account *> ManagementBank::getAccounts() {
    return std::vector<Account *>( accounts );
}

