#include <corecrt.h>
// This problem was asked by Google.
// 
// An XOR linked list is a more memory efficient doubly linked list.Instead of each node 
// holding next and prev fields, it holds a field named both, which is an XOR of the next 
// node and the previous node.Implement an XOR linked list; it has an add(element) which 
// adds the element to the end, and a get(index) which returns the node at index.
// 
// If using a language that has no pointers(such as Python), you can assume you have access
// to get_pointer and dereference_pointer functions that converts between nodes and memory
// addresses.
// 

class xor_list
{
protected:

    __int64 xor_addr;

#ifdef _DEBUG
    xor_list * prev;
    xor_list * next;
    int v = 0;
#endif

public:
    xor_list()
    {
#ifdef _DEBUG
        static int c = 0;
        this->prev = NULL;
        this->next = NULL;
        this->v = c++;
#endif
        this->xor_addr = NULL;
    }

    void add_to_end(xor_list * n)
    {
        xor_list * prev_addr = 0x00;
        xor_list * curr_addr = this;
        xor_list * next_addr = 0x00;

        while (curr_addr && curr_addr->xor_addr)
        {
            next_addr = (xor_list *)((__int64)curr_addr->xor_addr ^ (__int64)prev_addr);
            if (next_addr)
            {
                prev_addr = curr_addr;
                curr_addr = next_addr;
            }
            else
            {
                break;
            }
        }

        curr_addr->xor_addr = (__int64)prev_addr ^ (__int64)n;
        n->xor_addr = (__int64)curr_addr;

#ifdef _DEBUG
        curr_addr->prev = prev_addr;
        curr_addr->next = n;
        n->next = NULL;
        n->prev = curr_addr;
        prev_addr = (xor_list *)((__int64)curr_addr->xor_addr ^ (__int64)next_addr);;
        next_addr = (xor_list *)((__int64)curr_addr->xor_addr ^ (__int64)prev_addr);
#endif
    }

    xor_list * get_element(int index)
    {
        xor_list * prev_addr = 0x00;
        xor_list * curr_addr = this;
        xor_list * next_addr = 0x00;

        if (index < 0) return NULL;

        while (curr_addr && curr_addr->xor_addr && index)
        {
            index--;
            next_addr = (xor_list *)((__int64)curr_addr->xor_addr ^ (__int64)prev_addr);
            prev_addr = curr_addr;
            curr_addr = next_addr;
        }
        if (index == 0)
            return curr_addr;
        else
            return NULL;
    }

};

int main(int argc, char** argv)
{
    xor_list n;

    n.add_to_end(new xor_list());
    n.add_to_end(new xor_list());
    n.add_to_end(new xor_list());
    n.add_to_end(new xor_list());
    n.add_to_end(new xor_list());
    n.add_to_end(new xor_list());
    n.add_to_end(new xor_list());

    xor_list * elem_0 = n.get_element(0);
    xor_list * elem_1 = n.get_element(1);
    xor_list * elem_2 = n.get_element(2);
    xor_list * elem_3 = n.get_element(3);
    xor_list * elem_4 = n.get_element(4);
    xor_list * elem_5 = n.get_element(5);
    xor_list * elem_6 = n.get_element(6);
    xor_list * elem_7 = n.get_element(7);

}
