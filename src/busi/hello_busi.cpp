//
//  hello_busi.cpp
//  watchMyDraw
//
//  Created by peter chen on 2017/10/8.
//  Copyright © 2017年 chenxiaofei. All rights reserved.
//

#include "hello_busi.h"

namespace hello{
    int Busi::Init(hello::BusiInterface *itf){
        m_itf = itf;
        return HELLO_STATUS_OK;
    }
    
    int Busi::Link(int dstIp){
        
    }
    
    int Busi::Confirm(int dstIp)
    {
        
    }
    
    int Busi::Cancel(int dstIp)
    {
        
    }
    
    int Busi::SendMsg(int dstIp, const char* msg, int size)
    {
        
    }
    
}
