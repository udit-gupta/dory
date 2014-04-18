#ifndef _LOG_H
#define _LOG_H
#include <iostream>

#ifdef DEBUG
#define LOG(x) cout << __FILE__ << ':' << __LINE__ << ' ' << __PRETTY_FUNCTION__ << ':' << x << endl
#else
#define LOG(x) ;
#endif

#endif

