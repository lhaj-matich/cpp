#include <iostream>
#include <ctime>
#include <chrono>

int myFunction() {
    return (23143455 + 3482233);
}

int main() {
    clock_t start = clock();
    
    myFunction();
    
    clock_t end = clock();
    double elapsed = ((double) (end - start)) / CLOCKS_PER_SEC * 1000000;;
    
    std::cout << "Function took " << elapsed << " us" << std::endl;
    
    return 0;
}