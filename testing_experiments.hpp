//
// Created by Pham Ngoc Kien on 10/11/2018.
//
// SNU-ID: 2018-36543
//
// Homework 03
// The codes here have been uploaded to https://github.com/phamngockien/TPCS_hw03
// In this homework I will write a function to generate a “list” of all primes up to a number N,
// and check for what functions worked well, and what did not.
//

//
// In this header file:
//  + timing_primes_erat() tests the function to generate a vector of all primes up to a number n
//    using the sieve of Eratosthenes algorithm
//  + timing_primes_vec() tests the function to generate a vector of all primes up to a number n
//    using the sieve of Eratosthenes algorithm, including a common optimization
//  + timing_primes_list() tests the function to generate a list of all primes up to a number n
//    using the sieve of Eratosthenes algorithm, including a common optimization
// Comments about experiments:
// - The first function "primes_erat" using the "ancient" sieve of Eratosthenes algorithm without any optimization.
//   It iteratively marks as composite (i.e., not prime) the multiples of each prime,
//   starting with the first prime number, 2.
//   The multiples of a given prime are generated as a sequence of numbers starting from that prime,
//   with constant difference between them that is equal to that prime.
//   In this function I let the iteration running from 2 to n. This takes more than 12 seconds with my laptop to
//   finish the algorithm and store all primes into a vector.
// - The second function "primes_vec" using the sieve of Eratosthenes algorithm with an optimization.
//   It starts enumerating the multiples of each prime i from i square,
//   and stores the result into a vector like the first function.
//   Therefore, the number of iterations is reduced significantly.
//   This leads to the fact that elapsed time for the second function is usually more than 7 seconds,
//   which is 5 seconds faster than the first function.
// - The third function "primes_list" using the same algorithm as the second one.
//   However, it stores the result into a list instead of a vector.
//   My purpose is to compare the speed of storing data into these two different containers.
//   The elapsed time for the third function in my computer is more than 7 seconds,
//   but it is about 0.4 - 0.6 seconds slower than that of the second function.
//
//   Conclusion:
//   - When we change the algorithm to reduce the number of iterations to list primes,
//   the time to do this task is shorter.
//   - A vector stores data faster than a list.
//

//
// definition of header file
//
#ifndef TPCS_HW03_TESTING_EXPERIMENTS_HPP
#define TPCS_HW03_TESTING_EXPERIMENTS_HPP
//
#include <iostream> // for output
#include <chrono> // for timing
#include "primes.hpp" // call all functions to generate prime numbers for testing

//
// Create a function called "print_container" to print container.
// referenced from Mr. Erik Sevre
//
template<typename T>
void print_container(const T &t)
{
    //
    // if the size of container is either equal to or smaller than 10,
    // print all elements of the container
    //
    if (t.size()<=10)
    {
           for (auto v:t)
           {
               std::cout<<v<<" ";
           }
           std::cout<<"\n";
    }
    //
    // if the size of container is larger than 10,
    // print the first ten elements and the last element of the container
    //
    if (t.size()>10)
    {
        //
        // print the first ten primes
        //
        std::cout<<"the first ten primes found is: \n";
        auto j=t.begin();
        for (int k = 1; k < 10; ++k)
        {
            std::cout<< *j << " ";
            ++j;
        }
        std::cout<<std::endl;
        //
        // print the last prime
        //
        std::cout<<"the last prime found is: \n";
        auto i=t.end(); --i;
        std::cout << *i << std::endl;
    }
}
//
// create a timing namespace to calculate how much time it takes for each function
//
namespace timing
{
    //
    // this function is to test the function "primes_erat" to generate a vector of all primes up to a number n
    // using the sieve of Eratosthenes algorithm
    //
    void timing_primes_erat()
    {
        //
        // create start and stop variables to measure the time for testing the function
        //
        std::chrono::time_point<std::chrono::system_clock> start, stop;
        //
        // start counting the time
        //
        start = std::chrono::system_clock::now();
        //
        // run the "primes_erat" function
        //
        auto f1 = primes_erat(69999999);
        //
        // stop counting the time, store the end time and calculate the elapsed seconds
        //
        stop = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = stop - start;
        std::time_t end_time = std::chrono::system_clock::to_time_t(stop);
        //
        // printing results
        //
        std::cout << "generating primes (vector) by Eratosthenes' method: \n";
        print_container(f1);
        std::cout << "finished computation at " << std::ctime(&end_time)
                  << "elapsed time: " << elapsed_seconds.count() << "s\n";
        std::cout << "----------------------------------------------------------\n";
    }
    //
    // this function is to test the function "primes_vec" to generate a vector of all primes up to a number n
    // using the sieve of Eratosthenes algorithm that includes a common optimization
    //
    void timing_primes_vec()
    {
        //
        // create start and stop variables to measure the time for testing the function
        //
        std::chrono::time_point<std::chrono::system_clock> start, stop;
        //
        // start counting the time
        //
        start = std::chrono::system_clock::now();
        //
        // run the "primes_vec" function
        //
        auto f1 = primes_vec(69999999);
        //
        // stop counting the time, store the end time and calculate the elapsed seconds
        //
        stop = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = stop - start;
        std::time_t end_time = std::chrono::system_clock::to_time_t(stop);
        //
        // printing results
        //
        std::cout << "generating primes (vector) by Eratosthenes' method including an optimization: \n";
        print_container(f1);
        std::cout << "finished computation at " << std::ctime(&end_time)
                  << "elapsed time: " << elapsed_seconds.count() << "s\n";
        std::cout << "----------------------------------------------------------\n";
    }
    //
    // this function is to test the function "primes_list" to generate a list of all primes up to a number n
    // using the sieve of Eratosthenes algorithm that includes a common optimization
    //
    void timing_primes_list()
    {
        //
        // create start and stop variables to measure the time for testing the function
        //
        std::chrono::time_point<std::chrono::system_clock> start, stop;
        //
        // start counting the time
        //
        start = std::chrono::system_clock::now();
        //
        // run the "primes_vec" function
        //
        auto f1 = primes_list(69999999);
        //
        // stop counting the time, store the end time and calculate the elapsed seconds
        //
        stop = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = stop - start;
        std::time_t end_time = std::chrono::system_clock::to_time_t(stop);
        //
        // printing results
        //
        std::cout << "generating primes (list) by Eratosthenes' method including an optimization: \n";
        print_container(f1);
        std::cout << "finished computation at " << std::ctime(&end_time)
                  << "elapsed time: " << elapsed_seconds.count() << "s\n";
    }
}
//
// end of header file
//
#endif //TPCS_HW03_TESTING_EXPERIMENTS_HPP
