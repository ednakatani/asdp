#ifndef CETCDIMPL_H_
#define CETCDIMPL_H_

#include "CEtcdS.h"
#include <string>
#include <map>

using namespace std;

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif

class CEtcd_impl : public virtual POA_CEtcd
{
public:
    
    CEtcd_impl(const string& account_id);
    virtual ~CEtcd_impl () {}
    
    virtual string id() override;
    virtual void put(string& key, string& val);
    virtual string get(string& key);
    virtual void del(string& key);
    virtual void shutdown(string& password);

private:

    string id_;
    map<string, string> table_;
};

#endif /* CETCDIMPL_H_  */
