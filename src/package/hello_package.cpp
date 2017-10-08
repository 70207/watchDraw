//
//  hello_package.cpp
//  watchMyDraw
//
//  Created by peter chen on 2017/10/8.
//  Copyright © 2017年 chenxiaofei. All rights reserved.
//

#include <string.h>

#include "hello_package.h"
#include "hello_proto.h"
#include "../util/hello_status.h"
#include "../util/hello_log.h"

namespace hello{

    int PackageInterface::onMsgParse(int srcIp, int cmd, const char* msg, int size)
    {
        info("on parse message, not implemented");
        return HELLO_STATUS_NOT_IMPLEMENTED;
    }
    
    
    void Package::Init(PackageInterface* itf)
    {
        m_itf = itf;
    }
    
    void Package::Parse(int srcIp, const char* msg, int size)
    {
        if(size <= sizeof(proto::Msg)){
            return;
        }
        
        if(!msg){
            error("parse msg failed, msg pointer is null!");
            return;
        }
        
        proto::Msg* __msg = (proto::Msg*)msg;
        
        int dtSize = size - sizeof(proto::Msg);
        if(dtSize < 0){
            error("parse msg failed, msg size is wrong, msg size:%d", size);
        }
        
        if(!m_itf){
            return;
        }
        
        m_itf->onMsgParse(srcIp, __msg->header.cmd, __msg->data, dtSize);
    
    }
    
    int Package::Link(char* buf, int& bufSize)
    {
        int __size = sizeof(proto::Header);
        if(bufSize <= __size){
            bufSize = __size;
            return HELLO_STATUS_PROTO_BUFFER_NOT_ENOUGH;
        }
        bufSize = __size;
        if(!buf){
            return HELLO_STATUS_OK;
        }
        
        proto::Header* header = (proto::Header*)buf;
        header->size = __size;
        header->cmd = HELLO_PROTO_CMD_LINK;
        
        return HELLO_STATUS_OK;
    }
    
    
    int Package::Confirm(char* buf, int& bufSize)
    {
        
        int __size = sizeof(proto::Header);
        if(bufSize <= __size){
            bufSize = __size;
            return HELLO_STATUS_PROTO_BUFFER_NOT_ENOUGH;
        }
        bufSize = __size;
        if(!buf){
            return HELLO_STATUS_OK;
        }
        
        proto::Header* header = (proto::Header*)buf;
        header->size = __size;
        header->cmd = HELLO_PROTO_CMD_CONFIRM;
        return HELLO_STATUS_OK;
    }
    
    int Package::Cancel(char* buf, int& bufSize)
    {
        
        int __size = sizeof(proto::Header);
        if(bufSize <= __size){
            bufSize = __size;
            return HELLO_STATUS_PROTO_BUFFER_NOT_ENOUGH;
        }
        bufSize = __size;
        if(!buf){
            return HELLO_STATUS_OK;
        }
        
        proto::Header* header = (proto::Header*)buf;
        header->size = __size;
        header->cmd = HELLO_PROTO_CMD_CANCEL;
        return HELLO_STATUS_OK;
    }
    
    int Package::SendMsg(char* msg, int size, char* buf, int& bufSize)
    {
        
        int __size = sizeof(proto::Msg) + size;
        if(bufSize <= __size){
            bufSize = __size;
            return HELLO_STATUS_PROTO_BUFFER_NOT_ENOUGH;
        }
        bufSize = __size;
        if(!buf){
            return HELLO_STATUS_OK;
        }
        
        proto::Header* header = (proto::Header*)buf;
        header->size = __size;
        header->cmd = HELLO_PROTO_CMD_MSG;
        
        proto::Msg*   __msg = (proto::Msg*)buf;
        memcpy(__msg->data, msg, size);
        
        return HELLO_STATUS_OK;
    }
}
