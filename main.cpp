#include <iostream>
#include "Account.h"
#include "Customer.h"

using namespace std;

int main() {

    Customer* lola = new Customer("43545554","Dolores","Barriga",EGender::FEMALE,"3104862198");
    cout<<lola->toString()<<endl;

    lola->addAccount("596-189484",609000);
    lola->addAccount("270-189484",500000);
    lola->addAccount("847-53445",678929);
    if( lola->findAccount("596-189484")){
        cout<<"Encontrada-->"<<lola->findAccount("596-189484")->toString()<<endl;
    }else{
        cout<<"La Cuenta NO Existe"<<endl;
    }

    for( Account* account : lola->getAccounts() ){
        cout<<account->toString()<<endl;
    }

    delete( lola );

    return 0;
}
