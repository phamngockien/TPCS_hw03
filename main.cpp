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

#include "testing_experiments.hpp" // call testing_experiments for testing
//
// Main function for testing with experiments to generate a “list” of all primes up to a number N.
// The goal is to write a FAST function
//
int main()
{
    //
    // call three test functions in timing namespace to produce all the tasks
    //
    timing::timing_primes_erat();
    timing::timing_primes_vec();
    timing::timing_primes_list();
}