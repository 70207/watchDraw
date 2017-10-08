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
        
        /**
         * recv link request
         * @param {int} [srcIp] the src ip
         * @return {int}  status
         */
        virtual int onLink(int srcIp);
        
        /**
         * recv confirm request
         * @param {int} [srcIp] the src ip
         * @return {int}  status
         */
        virtual int onConfirm(int srcIp);
        
        
        
        /**
         * recv cancel request
         * @param {int} [srcIp] the src ip
         * @return {int}  status
         */
        virtual int onCancel(int srcIp);
        
        /**
         * recv message
         * @param {int} [srcIp] the src ip
         * @param {const char*} [msg] rcvd msg
         * @param {int}  [size] rcvd msg size
         * @return {int}  status
         */
        virtual int onMsg(int srcIp, const char* msg, int size);
        
        
       
        
    };
    
    class Busi{
    public:
        Busi();
        virtual ~Busi();
        
        /**
         * init busi
         * @param {BusiInterface} [itf] callback object
         * @return {int}  status
         */
        virtual int Init(BusiInterface* itf);
        
        /**
         * link to destination
         * @param {int} [dstIp] destination address
         * @return {int}  status
         */
        virtual int Link(int dstIp);
        
        /**
         * confirm link to destination
         * @param {int} [dstIp] destination address
         * @return {int}  status
         */
        virtual int Confirm(int dstIp);
        
        /**
         * cancel link to destination
         * @param {int} [dstIp] destination address
         * @return {int}  status
         */
        virtual int Cancel(int dstIp);
        
        /**
         * send msg to destination
         * @param {int} [dstIp] destination address
         * @param {const char*} [msg] rcvd msg
         * @param {int}  [size] rcvd msg size
         * @return {int}  status
         */
        virtual int SendMsg(int dstIp, const char* msg, int size);
        
    private:
        
        Busi*					m_busi;
        
    };
    
}

#endif /* hello_busi_h */
