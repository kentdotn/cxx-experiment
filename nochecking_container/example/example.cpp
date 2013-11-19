#include <nochecking_sequence.hpp>

#include <vector>
#include <iostream>
#include <string>
#include <boost/timer/timer.hpp>

using namespace std;
using namespace boost::timer;
using xxcxx::nochecking;

struct X
{
    X(size_t size = 0)
    {
        while (size > 0) {
            value += "foo";
            --size;
        }
    }

    string value;
};

void push_back_without_reserve(size_t size)
{
    for (size_t n = 0 ; n < 10 ; ++n) {
        cout << "without reserve()\t";
	    vector<X> v;
	    {
	        auto_cpu_timer t;
	        for (size_t i = 0 ; i < size ; ++i) {
	            v.push_back(1);
	        }
	    }
    }
}

void push_back_with_reserve(size_t size)
{
    for (size_t n = 0 ; n < 10 ; ++n) {
        cout << "with reserve()\t";
	    vector<X> v;
        v.reserve(size);
	    {
	        auto_cpu_timer t;
	        for (size_t i = 0 ; i < size ; ++i) {
	            v.push_back(1);
	        }
	    }
    }
}

void push_back_with_wrap(size_t size)
{
    for (size_t n = 0 ; n < 10 ; ++n) {
        cout << "with nochecking\t";
	    vector<X> v;
	    v.resize(size);
	    auto w = nochecking(v);
	    {
	        auto_cpu_timer t;
	        for (size_t i = 0 ; i < size ; ++i) {
	            w.push_back(1);
	        }
	    }
    }
}

int main()
{
    const size_t size = 1024 * 1024;

    push_back_without_reserve(size);
    push_back_with_reserve(size);
    push_back_with_wrap(size);
}
