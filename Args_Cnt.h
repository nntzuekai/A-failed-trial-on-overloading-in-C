#ifndef ARGS_CNT_H
#define ARGS_CNT_H

#define COUNT_ARGS(...) COUNT_ARGS_(,##__VA_ARGS__,6,5,4,3,2,1,0)
#define COUNT_ARGS_(z,a,b,c,d,e,f,cnt,...) cnt

#define CNT_ COUNT_ARGS
#define PASTE(x,y) PASTE_(x,y)
#define PASTE_(x,y) x ## y
#define CNT(...) PASTE(ARGVS,PASTE(CNT_(__VA_ARGS__),CNT_(1,##__VA_ARGS__)))
//you know its 0 if its 11 or 01
#define ARGVS11 0
#define ARGVS01 0
#define ARGVS12 1
#define ARGVS23 2
#define ARGVS34 3

#endif // ARGS_CNT_H
