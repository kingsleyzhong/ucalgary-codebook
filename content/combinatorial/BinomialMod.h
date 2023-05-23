/**
 * Author: Kingsley Zhong
 * Date: 
 * License: 
 * Source: 
 * Description: Binomal coefficients modulo a prime power.
 * Time: O(N)
 * Status: probably works
**/
#pragma once

#include "./number-theory/euclid.h"
#include "./number-theory/ModInverse.h"

vi fact, invfact; // Precompute this
ll binom(ll n, ll k, ll m){
    return fact[n] * invfact[k] % m * invfact[n-k] % m;
}