#ifndef CONTAIMPL_H_
#define CONTAIMPL_H_

#include "CEtcdS.h"
#include <string>
#include <map>

using namespace std;

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif

class CEtcd_impl : public POA_Etcd {
public:
    
    CEtcd_impl(const string& account_id);
    ~CEtcd_impl () {}
    
    string id();
    void put(const string& key, const string& val);
    string get(const string& key);
    void del(const string& key);

private:

    string id_;
    map<string, string> table_;
};

#endif /* CONTAIMPL_H_  */
