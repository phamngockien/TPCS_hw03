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
// definition of header file
//
#ifndef TPCS_HW03_PRIMES_HPP
#define TPCS_HW03_PRIMES_HPP
//
#include <c++/vector> // for vector
#include <cmath> // for calculating square root
#include <list> // for list
#include <iostream> // for output
//
// create functions in timing namespace
//
namespace timing {
    //
    // function to generate a vector of all primes up to a number n
    // using the sieve of Eratosthenes algorithm
    //
    std::vector<unsigned long> primes_erat(unsigned long n) {
        //
        // creating vector v of boolean values (n+1 elements)
        // indexed by integers 0 to n
        //
        std::vector<bool> v(n+1);
        //
        // initially set all numbers are primes
        //
        std::fill(v.begin(), v.end(), true);
        //
        // set 0 and 1 are not primes
        //
        v[0] = false;
        v[1] = false;
        //
        // using the sieve of Eratosthenes to create an iteration to
        // cross out the numbers which are not primes (the multiples of i)
        // i is the verified prime number, the initial i is 2.
        //
        for (unsigned long i = 2; i < n; ++i) {
            if (v[i]) {
                for (unsigned long j = i + i; j <= n; j = j + i) {
                    v[j] = false;

                }
            }
        }
        //
        // return index value of v[i]=true into
        // a vector of primes
        //
        std::vector<unsigned long> result;
        for (unsigned long i = 2; i <= n; ++i) {
            if (v[i]) {
                result.insert(result.end(), i);
            }
        }
        return result;
    }

    //
    // function to generate a vector of all primes up to a number n
    // using the sieve of Eratosthenes algorithm that
    // includes a common optimization, which is to start enumerating the multiples of each prime i from i square
    //
    std::vector<unsigned long> primes_vec(unsigned long n) {
        //
        // creating vector v of boolean values (n+1 elements)
        // indexed by integers 0 to n
        //
        std::vector<bool> v(n+1);
        //
        // initially set all numbers are primes
        //
        std::fill(v.begin(), v.end(), true);
        //
        // set numbers: 0 and 1 are not primes
        //
        v[0] = false;
        v[1] = false;
        //
        // using the sieve of Eratosthenes to
        // cross out the numbers which are not primes
        // includes a common optimization, which is to start enumerating the multiples of each prime i from i square
        //
        for (unsigned long i = 2; i <= sqrt(n); ++i) {
            if (v[i]) {
                for (unsigned long j = i * i; j <= n; j = j + i) {
                    v[j] = false;

                }
            }
        }
        //
        // return index value of v[i]=true into
        // a vector of primes
        //
        std::vector<unsigned long> result;
        for (unsigned long i = 2; i <= n; ++i) {
            if (v[i]) {
                result.insert(result.end(), i);
            }
        }
        return result;
    }

    //
    // function to generate a list of all primes up to a number n
    // using the sieve of Eratosthenes algorithm that
    // includes a common optimization, which is to start enumerating the multiples of each prime i from i square
    //
    std::list<unsigned long> primes_list(unsigned long n) {
        //
        // creating vector v of boolean values (n+1 elements)
        // indexed by integers 0 to n
        //
        std::vector<bool> v(n+1);
        //
        // initially set all numbers are primes
        //
        std::fill(v.begin(), v.end(), true);
        //
        // set numbers: 0 and 1 are not primes
        //
        v[0] = false;
        v[1] = false;
        //
        // using the sieve of Eratosthenes to
        // cross out the numbers which are not primes
        // includes a common optimization, which is to start enumerating the multiples of each prime i from i square
        //
        for (unsigned long i = 2; i <= sqrt(n); ++i) {
            if (v[i]) {
                for (unsigned long j = i * i; j <= n; j = j + i) {
                    v[j] = false;
                }
            }
        }
        //
        // return index value of v[i]=true into
        // a list of primes
        //
        std::list<unsigned long> result;
        for (unsigned long i = 2; i <= n; ++i) {
            if (v[i]) {
                result.insert(result.end(), i);
            }
        }
        return result;
    }
};
//
// end of header file
//
#endif //TPCS_HW03_PRIMES_HPP
