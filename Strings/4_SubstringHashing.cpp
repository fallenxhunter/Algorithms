/*
    calculation Hash value of a string of size N = O(N)
    modulo inverse preprocessing = O(LogN)
    Hash value of subtring = O(1)

    example:    
        suppose Hash("code") = c*p^0 + o*p^1 + d*p^2 + e*p^3
        now Hash("de") = d*p^0 + e*p^1

        therefore we can find Hash("de") = Hash("code") / p^x
            

    Now we create a prefix Array to store 
    the hashvalue of subtring from 0 to i in ith position;

    DP[0] = c*p^0
    DP[1] = c*p^0 + o*p^1
    ...


    thus at last Hash(substring(L,R)) = (DP[R] - DP[L-1]) / P^L
*/