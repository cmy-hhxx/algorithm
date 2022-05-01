# Acwing round 49
## couple
this is an easy problem, just simulate the process as it required
## subsequence
This is a dynamic programming problem. We need find the sum of subsequence which needs to be satisfied the following tow:
1. the sum must be odd.
2. the sum must be the maxium of all subsequence.
It is necessary to convert the problem into some model we have already met.
The sum of subsenquence equals to the value k items in the sequence.
Sounds like 01-backpack model!
We have a general method to analyse this sort of problem.  
- DP
    - state retpresentation
        - set
            - ```f[i][0]``` represents the set of all odd sum of subsequence which range from 1 to i.
            - ```f[i][1]``` represents the set of all even sum of subsequence whick range from 1 to i.
        - attribute the maxium sum
    - state calculation
        for ```f[i][0]```, when enumerating to item[i], ```f[i][0] = f[i - 1][0]```, this is an initial equation and easy to understand. If item[i] is odd, odd + odd = even, so ```f[i][1]``` is updated by the equation ```f[i][1] = max(f[i][1], f[i - 1][1] + item[i])```, else if brthe item[i] is even, odd + even = odd, so ```f[i][0]``` is updated by the equation ```f[i][0] = max(f[i][0], f[i - 1][0] + item[i]```.

Befor starting, we need to figure out the leagal initial state.
```f[0][0]``` in our definition means picking from top 0 items whose sum is the maxium and must be odd, so, at the very begining, we can't make it.
```f[0][1]``` in our definition means picking from top 0 items whose sum is the maxium and must be even, so, at the very begining, we can make it happen. Keep it zero!

