#ifdef BigNumber_EXPORTS
#define BigNumber_API __declspec(dllexport) 
#else
#define BigNumber_API __declspec(dllimport) 
#endif

#include <string>
#include <iomanip>
#include <string.h>

class BigNumber {
public:
    unsigned long long* number;

    BigNumber(std::string value);

    void setHex(std::string value);

    std::string getHex();
};