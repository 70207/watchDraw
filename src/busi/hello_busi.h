//
//  hello_busi.hpp
//  watchMyDraw
//
//  Created by peter chen on 2017/10/8.
//  Copyright © 2017年 chenxiaofei. All rights reserved.
//

#ifndef hello_busi_hpp
#define hello_busi_hpp

#include <stdio.h>

#include "../util/hello_log.h"
#include "../util/hello_status.h"

#include "../net/hello_net.h"
#include "../package/hello_package.h"


namespace hello{
    
    class BusiInterface{
    public:
        
        
        virtual int recvLink(int srcIp)
        {
            info("not implemented, recv link from src ip :%d", srcIp);
            return HELLO_STATUS_NOT_IMPLEMENTED;
        }
        virtual int recvConfirm(int srcIp)
        {
            info("not implemented, recv confirm from src ip :%d", srcIp);
            return HELLO_STATUS_NOT_IMPLEMENTED;
        }
        virtual int recvMessage(int srcIp, const char* msg, int size)
        {
            info("not implemented, recv message from src ip :%d", srcIp);
            return HELLO_STATUS_NOT_IMPLEMENTED;
        }
    };
    
    class Busi{
    public:
        Busi():m_itf(0){
            
        }
        
        ~Busi(){
            
        }
        
        int Init(BusiInterface* itf);
        
        int Link(int dstIp);
        int Confirm(int dstIp);
        int Cancel(int dstIp);
        
        int SendMsg(int dstIp, const char* msg, int size);
        
    private:
        BusiInterface*			m_itf;
        Net 					m_net;
        Package 				m_package;
    };
    
}

#endif /* hello_busi_hpp */
