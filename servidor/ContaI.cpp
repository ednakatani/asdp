#include "ContaI.h"
#include <iostream>

using namespace std;

extern CORBA::ORB_var orb;

Conta_i::Conta_i (const std::string& account_id)
{
    id_ = account_id;
    saldo_ = 0.0;
}

string Conta_i::id ()
{
    cout <<  "* Retornando ID" << endl;
    return id_;
    //return CORBA::string_dup(id_.c_str());	// duplica pois strings possuem tamanho variável
}

::CORBA::Float Conta_i::saldo ()
{
    cout << "* saldo()" << endl;
    return saldo_;
}

void Conta_i::deposito (::CORBA::Float amount)
{
    if (amount < 0)
		amount = -amount;
	bool limited = false;
	if (amount > 1000.0) {
		amount = 1000.0;
		limited = true;
	}
    cout << "* deposito(" << amount << ")" << endl;
    if (limited)
    	cout << "[deposito limitado a 1000.00]" << endl;
    saldo_ += amount;
}

void Conta_i::saque (::CORBA::Float amount)
{
    if (amount < 0)
		amount = -amount;
    cout << "* saque(" << amount << ")" << flush;
    if (amount > saldo_) {
		cout << " [SaldoInsuficiente]" << endl;
		throw SaldoInsuficiente();
    }

    saldo_ -= amount;
    cout << endl;
}

void Conta_i::transfere (::CORBA::Float amount, Conta_ptr dest)
{
    cout << "* transfere(" << amount << ","
    	<< dest->id() << ")" << endl;
    this->saque(amount);
    try {
		dest->deposito(amount);
    } catch (CORBA::Exception&) {
		cerr << "\tErro no deposito. Desfazendo saque." << endl;
		this->deposito(amount);
    }
}

void Conta_i::shutdown (const string password)
{
	if (password == "ASDPC") {
	    cout << "* shutdown()" << endl;
    	orb->shutdown();
    } else
    	cout << "* shutdown(): senha invalida" << endl;
}
