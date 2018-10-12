//
// Created by Pham Ngoc Kien on 10/11/2018.
//

#ifndef TPCS_HW03_TESTING_EXPERIMENTS_HPP
#define TPCS_HW03_TESTING_EXPERIMENTS_HPP
#include <iostream>
#include <chrono>
#include <cmath>

#include "primes.hpp"
//
//create a function called "print_container" to print container.
//referenced from Mr. Erik Sevre
//
template<typename T>
void print_container(const T &t)
{
       //
       // print first ten primes
       //
       std::cout<<"the first ten primes found is: \n";
       auto j=t.begin();
       for (int k = 1; k < 10; ++k) {
           std::cout<< *j << " ";
           ++j;
       }
       std::cout<<std::endl;
       std::cout<<"the last prime found is: \n";
       auto i=t.end(); --i;
        std::cout << *i << std::endl;
}
namespace timing {
    void timing_primes_vec() {
        std::chrono::time_point<std::chrono::system_clock> start, stop;

        start = std::chrono::system_clock::now();
        auto f1 = primes_vec(69999999);
        stop = std::chrono::system_clock::now();

        std::chrono::duration<double> elapsed_seconds = stop - start;
        std::time_t end_time = std::chrono::system_clock::to_time_t(stop);

        std::cout << "generating primes (vector): \n";
        print_container(f1);
        std::cout << "finished computation at " << std::ctime(&end_time)
                  << "elapsed time: " << elapsed_seconds.count() << "s\n";
        std::cout << "----------------------------------------------------------\n";
    }

    void timing_primes_list() {
        std::chrono::time_point<std::chrono::system_clock> start, stop;

        start = std::chrono::system_clock::now();
        auto f1 = primes_list(69999999);
        stop = std::chrono::system_clock::now();

        std::chrono::duration<double> elapsed_seconds = stop - start;
        std::time_t end_time = std::chrono::system_clock::to_time_t(stop);

        std::cout << "generating primes (list): \n";
        print_container(f1);
        std::cout << "finished computation at " << std::ctime(&end_time)
                  << "elapsed time: " << elapsed_seconds.count() << "s\n";
    }

}


#endif //TPCS_HW03_TESTING_EXPERIMENTS_HPP
