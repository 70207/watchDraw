//
//  hello_package.hpp
//  watchMyDraw
//
//  Created by peter chen on 2017/10/8.
//  Copyright © 2017年 chenxiaofei. All rights reserved.
//

#ifndef hello_package_hpp
#define hello_package_hpp

#include <stdio.h>

namespace hello{
    class PackageInterface{
    public:
        virtual int onMsgParse(int srcIp, int cmd, const char* msg, int size);
        
    };
    
    class Package{
    public:
        
        Package(){}
        ~Package(){}
        
        void Init(PackageInterface* itf);
        
        void Parse(int srcIp, const char* msg, int size);
        
        int Link(char* buf, int& bufSize);
        

        int Confirm(char* buf, int& bufSize);
        int Cancel(char* buf, int& bufSize);
        int SendMsg(char* msg, int size, char* buf, int& bufSize);
        
    private:
        
        PackageInterface*   m_itf;
        
    };
    
}


#endif /* hello_package_hpp */
