#ifndef CONTAIMPL_H_
#define CONTAIMPL_H_

#include "CEtcdS.h"
#include <string>
#include <map>

using namespace std;

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif

class CEtcd_impl : public virtual POA_Etcd {
public:
    
    CEtcd_impl(const string& account_id);
    virtual ~CEtcd_impl () {}
    
    virtual string id();
    virtual void put(const string& key, const string& val);
    virtual string get(const string& key);
    virtual void del(const string& key);

private:

    string id_;
    map<string, string> table_;
};

#endif /* CONTAIMPL_H_  */
