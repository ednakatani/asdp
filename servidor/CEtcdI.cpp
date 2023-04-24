#include "CEtcdI.h"
#include <iostream>
#include <map>

using namespace std;

extern CORBA::ORB_var orb;

CEtcd_impl::CEtcd_impl (const string& account_id)
{
    id_ = account_id;
    table_ = map<string, string>();
}

string CEtcd_impl::id ()
{
    cout <<  "* Retornando ID" << endl;
    return id_;
}


void CEtcd_impl::put(const string& key, const string& val) 
{
    cout <<  "* Inserindo <chave,valor>: " << endl;
    table_[key] = val;
    cout <<  "* " << endl;
}


string CEtcd_impl::get(const string& key) 
{
    cout <<  "* Retornando valor da chave: " << endl;
    if (table_.find(key) == table_.end()) 
    {
        throw invalid_argument("InvalidKey");
    }
    cout <<  "* " << endl;
    return table_[key];
}


void CEtcd_impl::del(const string& key) 
{
    cout <<  "* Deletando chave" << endl;
    if (table_.find(key) == table_.end()) 
    {
        throw invalid_argument("InvalidKey");
    }
    cout <<  "* " << endl;
    table_.erase(key);
}




