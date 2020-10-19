#include "stack.h"
#include "malloc.h"
#include <string.h>
#include <stdio.h>


class node
{
    unsigned int val = -1;
};

class stack
{
private:
    int * buff;
    int read_idx;
    int write_idx;
    int num_elements;
    int max_elements;
    int max_val = 0;

public:
    stack() : read_idx(0), write_idx(0), num_elements(0), buff(0x00), max_elements(0), max_val(0)
    {

    }
    ~stack()
    {
        if (buff)
        {
            free(buff);
        }

    }
    void push(int val)
    {
        if (max_elements <= num_elements)
        {
            // stack is full

            int new_max_elements = (max_elements == 0) ? 1 : max_elements * 2;

            int * new_buff = (int *) malloc(new_max_elements * sizeof(int));
            if (new_buff)
            {
                if (buff)
                {
                    memcpy(new_buff, buff, max_elements * sizeof(int));
                    free(buff);
                }

                max_elements = new_max_elements;
                buff = new_buff;
            }
        }
        if (num_elements < max_elements)
        {
            if (buff)
            {
                buff[write_idx++] = val;
                num_elements++;
                write_idx %= max_elements;
            }
        }
        max_val = (val > max_val) ? val : max_val;
    }

    int pop(void)
    {
        int val = -1;
        if (num_elements && buff)
        {
            val = buff[read_idx++];
            num_elements--;
            read_idx %= max_elements;
        }

        if (val == max_val)
        {
            max_val = 0;
            for (int i = read_idx; i < (read_idx + num_elements); i++)
            {
                int j = i % max_elements;
                max_val = (buff[j] > max_val) ? buff[j] : max_val;
            }
        }
        return val;        
    }

    int max()
    {
        return max_val;
    }
};

int main(int argc, char** argv)
{
    stack s;

    s.push(1);
    printf("% 5d, % 5d, % 5d\n", s.max(), s.pop(), s.max());
    s.push(21);
    printf("% 5d, % 5d, % 5d\n", s.max(), s.pop(), s.max());
    s.push(15);
    printf("% 5d, % 5d, % 5d\n", s.max(), s.pop(), s.max());
    s.push(25);
    s.push(35);
    printf("% 5d, % 5d, % 5d\n", s.max(), s.pop(), s.max());
    printf("% 5d, % 5d, % 5d\n", s.max(), s.pop(), s.max());
    s.push(45);
    s.push(15);
    printf("% 5d, % 5d, % 5d\n", s.max(), s.pop(), s.max());
    printf("% 5d, % 5d, % 5d\n", s.max(), s.pop(), s.max());
    s.push(25);
    s.push(25);
    s.push(41);
    s.push(12);
    s.push(13);

    printf("% 5d, % 5d\n", s.max(), s.pop());
    printf("% 5d, % 5d\n", s.max(), s.pop());
    printf("% 5d, % 5d\n", s.max(), s.pop());
    printf("% 5d, % 5d\n", s.max(), s.pop());
    printf("% 5d, % 5d\n", s.max(), s.pop());
    printf("% 5d, % 5d\n", s.max(), s.pop());

    return 0;
}
