//
//  hello_busi_core.cpp
//  watchMyDraw
//
//  Created by peter chen on 2017/10/8.
//  Copyright © 2017年 chenxiaofei. All rights reserved.
//

#include "hello_busi_core.h"

#include "../package/hello_proto.h"

namespace  hello {
    
    int BC::Init(hello::BusiInterface *itf){
        m_itf = itf;
        m_package.Init(this);
        m_net.Init(this);
        return HELLO_STATUS_OK;
    }
    
    
    
    int BC::Link(int dstIp)
    {
        char buffer[256];
        int  bufSize = 256;
        
        int status = m_package.Link(buffer, bufSize);
        if(status != HELLO_STATUS_OK){
            info("package link failed for dst ip:%d", dstIp);
            return status;
        }
        
        return m_net.SendMsg(dstIp, buffer, bufSize);
     
    }
    
    int BC::Confirm(int dstIp)
    {
        char buffer[256];
        int  bufSize = 256;
        
        int status = m_package.Confirm(buffer, bufSize);
        if(status != HELLO_STATUS_OK){
            info("package link failed for dst ip:%d", dstIp);
            return status;
        }
        
        return m_net.SendMsg(dstIp, buffer, bufSize);
        
    }
    
    int BC::Cancel(int dstIp)
    {
        char buffer[256];
        int  bufSize = 256;
        
        int status = m_package.Cancel(buffer, bufSize);
        if(status != HELLO_STATUS_OK){
            info("package link failed for dst ip:%d", dstIp);
            return status;
        }
        
        return m_net.SendMsg(dstIp, buffer, bufSize);
        
    }
    
    int BC::SendMsg(int dstIp, const char* msg, int size)
    {
        char buffer[1024];
        int  bufSize = 1024;
        char* _buf = 0;
        char* buf = buffer;
        
        int status = m_package.Link(buf, bufSize);
        if(status == HELLO_STATUS_PROTO_BUFFER_NOT_ENOUGH){
            if(bufSize > 4096){
                warn("send msg must not bigger than 4096");
                return HELLO_STATUS_MSG_TOO_BIG;
            }
            else if(bufSize <= 0){
                warn("send msg failed, package size is 0!");
                return HELLO_STATUS_PACKAGE_FAILED;
            }
            
            _buf = (char*)malloc(bufSize);
            if(!_buf){
                warn("send msg failed, malloc failed for size:%d", bufSize);
                return HELLO_STATUS_SYS_MALLOC_FAILED;
            }
            
            buf = _buf;
            
            status = m_package.Link(buf, bufSize);
        }
        
        if(status != HELLO_STATUS_OK){
            info("package link failed for dst ip:%d", dstIp);
            free(_buf);
            return status;
        }
        
        status = m_net.SendMsg(dstIp, buffer, bufSize);
        
        free(_buf);
        
        return status;
    }
    
    
    int BC::onNetMsg(int srcIp, const char* msg, int size)
    {
        m_package.Parse(srcIp, msg, size);
        return HELLO_STATUS_OK;
    }
    
    
    int BC::onMsgParse(int srcIp, int cmd, const char* msg, int size)
    {
        switch(cmd){
            case HELLO_PROTO_CMD_LINK:
                m_itf->onLink(srcIp);
                break;
            case HELLO_PROTO_CMD_CONFIRM:
                m_itf->onConfirm(srcIp);
                break;
            case HELLO_PROTO_CMD_CANCEL:
                m_itf->onCancel(srcIp);
                break;
            case HELLO_PROTO_CMD_MSG:
                m_itf->onMsg(srcIp, msg, size);
                break;
                
        }
       return HELLO_STATUS_OK;
    }
    
    
}

