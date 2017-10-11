//
//  hello_busi_core.hpp
//  watchMyDraw
//
//  Created by peter chen on 2017/10/8.
//  Copyright © 2017年 chenxiaofei. All rights reserved.
//

#ifndef hello_busi_core_hpp
#define hello_busi_core_hpp

#include <stdio.h>
#include "hello_busi.h"

#include "../net/hello_net.h"
#include "../package/hello_package.h"

namespace  hello {
    
    
    class BC : public Busi, public NetInterface, public PackageInterface{
    public:
        BC():
        m_itf(0){
            
        }
        
        ~BC(){
            
        }
        
    public: //busi
        
        int Init(BusiInterface* itf);
        int Link(int dstIp);
        int Confirm(int dstIp);
        int Cancel(int dstIp);
        int SendMsg(int dstIp, const char* msg, int size);
        
    public: //net
        int onNetMsg(int srcIp, const char* msg, int size);
        
    public: //package
        int onMsgParse(int srcIp, int cmd, const char* msg, int size);
        
        
    private:
        
        
        BusiInterface*            m_itf;
        Net                       m_net;
        Package                   m_package;
    };
    
}

#endif /* hello_busi_core_hpp */
