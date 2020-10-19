#include <stdio.h>
// This problem was asked by Jane Street.
// 
// cons(a, b) constructs a pair, and car(pair) and cdr(pair) returns the first and last element of that pair.For example, car(cons(3, 4)) returns 3, and cdr(cons(3, 4)) returns 4.
// 
// Given this implementation of cons :
// 
// def cons(a, b) :
//     def pair(f) :
//     return f(a, b)
//     return pair
//     Implement car and cdr.
// 

class pair
{
public:
    int first;
    int last;

    pair(int first, int last)
    {
        this->first = first;
        this->last = last;
    }
};

pair cons(int first, int last)
{
    return pair(first, last);
}

int car(pair p)
{
    return p.first;
}

int cdr(pair p)
{
    return p.last;
}

int main(int argc, char** argv)
{
    printf("car(cons(3, 4)) = % 5d\n", car(cons(3, 4)));
    printf("cdr(cons(3, 4)) = % 5d\n", cdr(cons(3, 4)));

    return 0;
}
