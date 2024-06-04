#ifndef NEGATIVECALORIEEXCEPTION_H
#define NEGATIVECALORIEEXCEPTION_H
#include <exception>

using namespace std;

class NegativeCalorieException: public exception
{
public:
    const char * what() const throw()
    {
        return "Negative calorie exception\n";
    }
};

#endif // NEGATIVECALORIEEXCEPTION_H
