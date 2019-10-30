/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Structs.h
 * Author: Jade Braun
 *
 * Created on October 29, 2019, 6:06 PM
 */
#include<string>
using namespace std;
#ifndef STRUCTS_H
#define STRUCTS_H


struct Customer {
    string name, address;
    int account;
    float totalChecks[100];
    float totalDepo[100];
    float amount;
};
struct Gross 
{
    char company[100]; //company name
    char add[100]; //address
    char name[100]; //worker name
    char boss[100];//Authorized signature
    int work; //hours which worker worked
    float rate; //rate of hourly pay
    float total; //Total pay for the worker
};

struct Array
{
    int size;
    int *data;
};
struct Stats
{
    float avg;
    float median;
    Array *mode;
    int modFreq;
};

struct Prime
{
    unsigned short prime;
   unsigned char power;
};
struct Primes
{
    Prime *prime;
    unsigned char nPrimes;
};


#endif /* STRUCTS_H */

