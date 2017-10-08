//
//  hello_log.hpp
//  watchMyDraw
//
//  Created by peter chen on 2017/10/8.
//  Copyright © 2017年 chenxiaofei. All rights reserved.
//

#ifndef hello_log_hpp
#define hello_log_hpp

#include <stdio.h>
#include <string>


#define hellolog(level, ...) \
Log::getInstance().RealLog(level, __FILE__, __LINE__, __func__, __VA_ARGS__);



#define debug(...) hellolog(LOG__DEBUG, __VA_ARGS__)
#define info(...)  hellolog(LOG__INFO, __VA_ARGS__)
#define warn(...)  hellolog(LOG__WARN, __VA_ARGS__)
#define error(...) hellolog(LOG__ERROR, __VA_ARGS__)
#define fatal(...) hellolog(LOG__FATAL, __VA_ARGS__)

namespace hello{
    
    enum LogLevel{LOG__FATAL=0, LOG__ERROR, LOG__WARN, LOG__INFO, LOG__DEBUG};
   
    class Log{
    public:
        Log();
        ~Log();
        
        void SetPath(const std::string& path);
        void SetLogLevel(LogLevel l){ m_level = l > LOG__DEBUG ? LOG__DEBUG : l;}
        void RealLog(int l, const char* file, int line, const char* func, const char* fmt ...);
        
        static Log& getInstance(){
            static Log log;
            return log;
        }
        
    private:
        LogLevel        m_level;
        int 			m_logFd;
        long long 		m_threadID;
        std::string     m_logPath;
    };
}

#endif /* hello_log_hpp */
