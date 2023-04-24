#ifndef CETCDIMPL_H_
#define CETCDIMPL_H_

#include "CEtcdS.h"
#include <string>
#include <map>


#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif

class CEtcd_impl : public virtual POA_CEtcd
{
public:
    
    CEtcd_impl(const std::string& account_id);
    ~CEtcd_impl () {}
    
    std::string id();
    void put(std::string key, std::string val);
    std::string get(std::string key);
    void del(std::string key);
    void shutdown(std::string password);

private:

    std::string id_;
    std::map<std::string, std::string> table_;
};

#endif /* CETCDIMPL_H_  */
