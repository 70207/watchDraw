//
//  hello_net.hpp
//  watchMyDraw
//
//  Created by peter chen on 2017/10/8.
//  Copyright © 2017年 chenxiaofei. All rights reserved.
//

#ifndef hello_net_hpp
#define hello_net_hpp

#include <stdio.h>
#include "../util/hello_log.h"
#include "../util/hello_status.h"

namespace hello{
    class NetInterface{
    public:
        /**
         * recv message
         * @param {int} [srcIp] the src ip
         * @param {const char*} [msg] rcvd msg
         * @param {int}  [size] rcvd msg size
         * @return {int}  status
         */
        virtual int onNetMsg(int srcIp, const char* msg, int size)
        {
            info("net recv message, not implemented, recv message from src ip :%d", srcIp);
            return HELLO_STATUS_NOT_IMPLEMENTED;
        }
    };
    
    class Net{
    public:
        Net();
        ~Net();
        
        int Init(NetInterface* itf);
        int SendMsg(int dstIp, const char* msg, int size);
        
    private:
        int CreateServer();
        void RecvFunc();
        
        
     private:
        
        NetInterface*      m_itf;
        int 			   m_serverFd;
        
        
        
    };
    
}

#endif /* hello_net_hpp */
