//
// Created by Jairo Riaño on 13/04/20.
//

#include "Customer.h"
#include <iostream>

Customer::Customer(const string &idCustomer, const string &firstName, const string &lastName, EGender gender,
                   const string &phone) : idCustomer(idCustomer), firstName(firstName), lastName(lastName),
                                          gender(gender), phone(phone) {}

const string &Customer::getIdCustomer() const {
    return idCustomer;
}

void Customer::setIdCustomer(const string &idCustomer) {
    Customer::idCustomer = idCustomer;
}

const string &Customer::getFirstName() const {
    return firstName;
}

void Customer::setFirstName(const string &firstName) {
    Customer::firstName = firstName;
}

const string &Customer::getLastName() const {
    return lastName;
}

void Customer::setLastName(const string &lastName) {
    Customer::lastName = lastName;
}

EGender Customer::getGender() const {
    return gender;
}

void Customer::setGender(EGender gender) {
    Customer::gender = gender;
}

const string &Customer::getPhone() const {
    return phone;
}

void Customer::setPhone(const string &phone) {
    Customer::phone = phone;
}

Account *Customer::findAccount(string number) {
    for( Account* account : accounts ){
        if( account->getNumber().compare( number ) == 0 ){
            return account;
        }
    }

    return NULL;
}

bool Customer::addAccount(string number, double value) {
    if ( !findAccount( number) ){
        accounts.push_back( new Account(number,value));

        return true;
    }

    return false;
}

vector<Account *> Customer::getAccounts() {
    return vector<Account *>( Customer::accounts );
}

string Customer::toString() {
    string gender = Customer::gender == EGender::FEMALE ? "Femenino" : "Masculino";
    return "Customer[idCustomer=" + idCustomer + ", lastName=" + lastName + ", firstName=" + firstName +
           ", gender=" + gender + ", phone=" + phone + "]\n";
}

Customer::~Customer() {
    for (Account* account : accounts ){
        delete( account );
        std::cout<<"Byte"<<endl;
    }
}
