//
//  hello_busi.h
//  watchMyDraw
//
//  Created by peter chen on 2017/10/8.
//  Copyright © 2017年 chenxiaofei. All rights reserved.
//

#ifndef hello_busi_hpp
#define hello_busi_hpp

#include <stdio.h>




namespace hello{
    
    class BusiInterface{
    public:
        

        virtual int onLink(int srcIp);
        virtual int onConfirm(int srcIp);
        virtual int onCancel(int srcIp);
        virtual int onMsg(int srcIp, const char* msg, int size);
        
        
       
        
    };
    
    class Busi{
    public:
        Busi();
        virtual ~Busi();
        virtual int Init(BusiInterface* itf);
        virtual int Link(int dstIp);
        virtual int Confirm(int dstIp);
        virtual int Cancel(int dstIp);
        virtual int SendMsg(int dstIp, const char* msg, int size);
        
    private:
        
        Busi*					m_busi;
        
    };
    
}

#endif /* hello_busi_h */
