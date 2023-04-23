#ifndef CONTAIMPL_H_
#define CONTAIMPL_H_

#include "ContaS.h"
#include <string>

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif

class  Conta_i  : public virtual POA_Conta {
public:

    Conta_i (const std::string& account_id);
    virtual ~Conta_i () {}

    virtual std::string id ();
    virtual ::CORBA::Float saldo ();
    virtual void deposito (::CORBA::Float amount);

private:

    std::string     id_;
    ::CORBA::Float  saldo_;
};

#endif /* CONTAIMPL_H_  */
