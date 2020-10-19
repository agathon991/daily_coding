#include <string>

// This problem was asked by Facebook.
// 
// Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.
// 
// For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.
// 
// You can assume that the messages are decodable.For example, '001' is not allowed.
// 

using namespace std;


int num_ways(string s, int offset = 0)
{
    string s1;
    string s2;
    int ways = 0;
    size_t l = s.length();

    if (offset    >= l) return 0;
    if (offset + 1 < l) s1 = s.substr(offset, 1);
    if (offset + 2 < l) s2 = s.substr(offset, 2);

    int v1 = atoi(s1.c_str());
    int v2 = atoi(s2.c_str());

    if ((v1 >= 1) && (v1 <= 26))
    {
        // valid decoding of the message
        ways += num_ways(s, offset + 1) + 1;
    }

    if ((v2 >= 1) && (v2 <= 26))
    {
        // valid decoding of the message
        ways += num_ways(s, offset + 2) + 1;
    }

    return ways;
}

int main(int argc, char** argv)
{
    string msg = "111";

    printf("Num ways to decode string %s: %d", msg.c_str(), num_ways(msg));
}





