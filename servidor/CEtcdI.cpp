#include "CEtcdI.h"
#include <iostream>
#include <map>

using namespace std;

extern CORBA::ORB_var orb;

CEtcd_impl::CEtcd_impl (const string& account_id)
{
    id_ = account_id;
    table_["a"] = "a";
}

string CEtcd_impl::id ()
{
    cout <<  "* Retornando ID" << endl;
    return this->id_;
    //return CORBA::string_dup(id_.c_str());	// duplica pois strings possuem tamanho variável
}


void CEtcd_impl::put(string& key, string& val) 
{
    cout <<  "* Inserindo <chave,valor>: " << endl;
    table_[key] = val;
    cout <<  "* " << endl;
}


string CEtcd_impl::get(string& key) 
{
    cout <<  "* Retornando valor da chave: " << endl;
    if (this->table_.find(key) == this->table_.end()) 
    {
        throw invalid_argument("InvalidKey");
    }
    cout <<  "* " << endl;
    return this->table_[key];
}


void CEtcd_impl::del(string& key) 
{
    cout <<  "* Deletando chave" << endl;
    if (table_.find(key) == table_.end()) 
    {
        throw invalid_argument("InvalidKey");
    }
    cout <<  "* " << endl;
    table_.erase(key);
}


void CEtcd_impl::shutdown(string& password)
{
	if (password == "ASDPC") {
	    cout << "* shutdown()" << endl;
    	orb->shutdown();
    } else
    	cout << "* shutdown(): senha invalida" << endl;
}

