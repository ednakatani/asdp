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
    virtual void put(const string& key, const string& val) override;
    virtual string get(const string& key) override;
    virtual void del(const string& key) override;
    virtual void shutdown(const string& password) override;

private:

    string id_;
    map<string, string> table_;
};

#endif /* CETCDIMPL_H_  */
