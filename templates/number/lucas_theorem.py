# This is the python code to implement luca's theorem 
def compute_factorials(p):
    fact = [1] * p
    for i in range(1, p):
        fact[i] = (fact[i - 1] * i) % p
    return fact

def mod_inverse(a, p):
    return pow(a, p - 2, p)

def nCr_mod_p_small(n, r, p, fact):
    if r > n:
        return 0
    return (fact[n] * mod_inverse(fact[r], p) * mod_inverse(fact[n - r], p)) % p

def nCr_mod_p_lucas(n, r, p):
    fact = compute_factorials(p)
    result = 1
    while n > 0 or r > 0:
        ni = n % p
        ri = r % p
        result = (result * nCr_mod_p_small(ni, ri, p, fact)) % p
        n //= p
        r //= p
    return result

print(nCr_mod_p_lucas(10**19, 31, 10**21+31))