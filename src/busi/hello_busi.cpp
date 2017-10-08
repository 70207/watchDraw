//
//  hello_busi.cpp
//  watchMyDraw
//
//  Created by peter chen on 2017/10/8.
//  Copyright © 2017年 chenxiaofei. All rights reserved.
//

#include "hello_busi.h"

#include "../util/hello_log.h"
#include "../util/hello_status.h"

#include "hello_busi_core.h"


namespace hello{
    
    int BusiInterface::onLink(int srcIp)
    {
        info("not implemented, recv link from src ip :%d", srcIp);
        return HELLO_STATUS_NOT_IMPLEMENTED;
    }
    
    
    int BusiInterface::onConfirm(int srcIp)
    {
        info("not implemented, recv confirm from src ip :%d", srcIp);
        return HELLO_STATUS_NOT_IMPLEMENTED;
    }
    
    
    int BusiInterface::onCancel(int srcIp)
    {
        info("not implemented, recv cancel from src ip :%d", srcIp);
        return HELLO_STATUS_NOT_IMPLEMENTED;
    }
    
    
    int BusiInterface::onMsg(int srcIp, const char* msg, int size)
    {
        info("not implemented, recv message from src ip :%d", srcIp);
        return HELLO_STATUS_NOT_IMPLEMENTED;
    }
    
    
    Busi::Busi():m_busi(0){
        
	}
    
    Busi::~Busi(){
        delete m_busi;
    }
    
    int Busi::Init(hello::BusiInterface *itf){
        m_busi = new BC();
        return m_busi->Init(itf);
    }
    
    int Busi::Link(int dstIp){
        return m_busi->Link(dstIp);
    }
    
    int Busi::Confirm(int dstIp)
    {
        return m_busi->Confirm(dstIp);
    }
    
    int Busi::Cancel(int dstIp)
    {
        return m_busi->Cancel(dstIp);
    }
    
    int Busi::SendMsg(int dstIp, const char* msg, int size)
    {
        return m_busi->SendMsg(dstIp, msg, size);
    }
    
}
