//
// Created by useer on 10/11/2018.
//

#ifndef TPCS_HW03_PRIMES_HPP
#define TPCS_HW03_PRIMES_HPP

#include <c++/vector>
#include <cmath>
#include <list>
#include <iostream>

namespace timing{
    //
    // function to generate a “list” of all primes up to a number n
    // using the sieve of Eratosthenes
    //
    std::vector<unsigned long> primes_vec(unsigned long n)
    {
        //
        // if n < 2 then end the function
        //
        if (n < 2)
        {
            std::cout<<"there is no prime smaller than 2\n";
        }
        //
        // creating vector v of boolean values
        // indexed by integers 2 to n
        //
        std::vector<bool> v(n);
        //
        // initially set all numbers are primes
        //
        std::fill(v.begin(), v.end(), true);
        //
        // set numbers: 0 and 1 are not primes
        //
        v[0]= false;
        v[1]= false;
        //
        // using the sieve of Eratosthenes to
        // cross out the numbers which are not primes
        // count the number of primes from 2 to n
        //
        for (unsigned long i = 2; i < sqrt(n) ; ++i) {
            if (v[i])
            {
                for (unsigned long j = i*i; j < n; j=j+i)
                {
                    v[j]=false;

                }
            }
        }
        //
        // create a vector to store primes
        //
       // unsigned long count=0;
        //for (unsigned long i = 2; i < n ; ++i)
        //{
         //   if (v[i]) {
           //     ++count;
            //}
       // }
        //
        // return index value (i) of v[i]=true into
        // a vector of primes
        //
        //unsigned long j=0;
        //std::vector<unsigned long> result(count);
        //for (unsigned long i = 2; i < n ; ++i) {
          //  if (v[i]) {
            //    result[j]=i;
              //  ++j;
            //}
        //}
        std::vector<unsigned long> result;
        unsigned long j=0;
        for (unsigned long i = 2; i < n ; ++i) {
            if (v[i]) {
                result.insert(result.end(),i);
                ++j;
            }
        }
        return result;
    }
//
// other function using list
//
    std::list <unsigned long> primes_list(unsigned long n)
    {
        //
        // if n < 2 then end the function
        //
        if (n < 2)
        {
           std::cout<<"there is no prime smaller than 2\n";
        }
        //
        // creating vector v of boolean values
        // indexed by integers 2 to n
        //
        std::vector<bool> v(n);
        //
        // initially set all numbers are primes
        //
        std::fill(v.begin(), v.end(), true);
        //
        // set numbers: 0 and 1 are not primes
        //
        v[0]= false;
        v[1]= false;
        //
        // using the sieve of Eratosthenes to
        // cross out the numbers which are not primes
        // count the number of primes from 2 to n
        //
        for (unsigned long i = 2; i < sqrt(n) ; ++i) {
            if (v[i]){
                for (unsigned long j = i*i; j < n; j=j+i) {
                    v[j]=false;
                }
            }
        }
        //
        // return index value of v[i]=true into
        // a list of primes
        //
        std::list<unsigned long> result;
        unsigned long j=0;
        for (unsigned long i = 2; i < n ; ++i) {
            if (v[i]) {
                result.insert(result.end(),i);
                ++j;
            }
        }
        return result;
    }
}
#endif //TPCS_HW03_PRIMES_HPP
