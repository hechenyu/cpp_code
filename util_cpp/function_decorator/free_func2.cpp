#include <iostream>
#include <type_traits>

template <typename Ret, 
    typename = typename std::enable_if<!std::is_void<Ret>::value>::type, typename ...Args>
Ret decorator(Ret (*func)(Args ...args), Args ...args)
{
    try {
        Ret ret = func(args...);
        std::cout << "exec ok" << std::endl;
        return ret;
    } catch (...) {
        std::cout << "catch exception" << std::endl;
        return Ret();
    }
}

template <typename ...Args>
void decorator(void (*func)(Args ...args), Args ...args)
{
    try {
        func(args...);
        std::cout << "exec ok" << std::endl;
    } catch (...) {
        std::cout << "catch exception" << std::endl;
    }
}

int no_throw_func(int a, int b)
{
    std::cout << __func__ << ", a: " << a << ", b: " << b << std::endl;
    return -1;
}

int throw_func(int a, int b)
{
    std::cout << __func__ << ", a: " << a << ", b: " << b << std::endl;
    throw std::runtime_error(__func__);
    return 0;
}

int no_args_func()
{
    std::cout << __func__ << std::endl;
    return 1;
}

void void_ret_func(int a, int b)
{
    std::cout << __func__ << "a: " << a << ", b: " << b << std::endl;
}

int main()
{
    std::cout << "decorator(&no_throw_func, 1, 2): " << decorator(&no_throw_func, 1, 2) << std::endl;
    std::cout << "decorator(&throw_func, 1, 2): " << decorator(&throw_func, 1, 2) << std::endl;
    std::cout << "decorator(&no_args_func): " << decorator(&no_args_func) << std::endl;
    decorator(&void_ret_func, 1, 2);
    
    return 0;
}
