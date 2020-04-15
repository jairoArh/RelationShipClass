//
// Created by Jairo Riaño on 13/04/20.
//

#include "Customer.h"

Customer::Customer(const std::string &idCustomer, const std::string &firstName, const std::string &lastName, EGender gender,
                   const std::string &phone) : idCustomer(idCustomer), firstName(firstName), lastName(lastName),
                                          gender(gender), phone(phone) {}

const std::string &Customer::getIdCustomer() const {
    return idCustomer;
}

void Customer::setIdCustomer(const std::string &idCustomer) {
    Customer::idCustomer = idCustomer;
}

const std::string &Customer::getFirstName() const {
    return firstName;
}

void Customer::setFirstName(const std::string &firstName) {
    Customer::firstName = firstName;
}

const std::string &Customer::getLastName() const {
    return lastName;
}

void Customer::setLastName(const std::string &lastName) {
    Customer::lastName = lastName;
}

EGender Customer::getGender() const {
    return gender;
}

void Customer::setGender(EGender gender) {
    Customer::gender = gender;
}

const std::string &Customer::getPhone() const {
    return phone;
}

void Customer::setPhone(const std::string &phone) {
    Customer::phone = phone;
}

void Customer::addAccount(Account* account) {
   accounts.push_back( account );
}

std::vector<Account *> Customer::getAccounts() {
    return std::vector<Account *>( Customer::accounts );
}

std::string Customer::toString() {
    std::string gender = Customer::gender == EGender::FEMALE ? "Femenino" : "Masculino";
    return "Customer[idCustomer=" + idCustomer + ", lastName=" + lastName + ", firstName=" + firstName +
           ", gender=" + gender + ", phone=" + phone + "]\n";
}

Customer::~Customer() {
    for (Account* account : accounts ){
        delete( account );
    }
}
