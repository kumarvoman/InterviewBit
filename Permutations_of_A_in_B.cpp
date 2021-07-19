/*
Permutations of A in B
You are given two strings A and B of size N and M respectively.
You have to find the count of all permutations of A present in B as a substring. You can assume a string will have only lowercase letters.
*/

int Solution::solve(string A, string B) {
    int m = A.size();
	  int n = B.length();
    unordered_map<char, int> ahash;
    unordered_map<char, int> bhash;
    
    for(auto x: A) { 
        ahash[x]++;
    }

    for (int i = 0; i < m; i++) {
      bhash[B[i]]++;
    }
	
    int i = 0, count = 0;
    while (i < n - m+1)
    {
        int flag = true;
        for (auto x : ahash)
        {
          if (x.second != bhash[x.first])
          {
            flag = false;
            break;
          }
        }
        if (flag == true)
          count++;
        if (bhash[B[i]] > 1)
          bhash[B[i]]--;
        else
          bhash.erase(B[i]);
        bhash[B[m + i]]++;
        i++;
    }
    return count;
}

//Time complexity : O(nk)
//Space complexity : O(n+k)
