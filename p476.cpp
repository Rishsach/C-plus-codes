class Solution {
 public:
  long long maximumBeauty(vector<int>& flowers, long long newFlowers,
                          int target, int full, int partial) {
    const long long n = flowers.size();

    
    for (int& flower : flowers)
      flower = min(flower, target);
    sort(begin(flowers), end(flowers));

    
    if (flowers[0] == target)
      return n * full;

    
    if (newFlowers >=
        n * target - accumulate(begin(flowers), end(flowers), 0LL))
      return max(n * full,
                 (n - 1) * full + static_cast<long long>(target - 1) * partial);

    long long ans = 0;
    long long leftFlowers = newFlowers;
    
    vector<long long> cost(n);

    for (long long i = 1; i < n; ++i)
     
      cost[i] = cost[i - 1] + i * (flowers[i] - flowers[i - 1]);

    int i = n - 1;  
    while (flowers[i] == target)
      --i;

    for (; leftFlowers >= 0; --i) {
      const int j = firstGreater(cost, i, leftFlowers);
      const long long minIncomplete =
          flowers[j - 1] + (leftFlowers - cost[j - 1]) / j;
      ans = max(ans, (n - 1 - i) * full + minIncomplete * partial);
      leftFlowers -= max(0, target - flowers[i]);
    }

    return ans;
  }

 private:
  int firstGreater(const vector<long long>& A, int maxIndex, long long target) {
    return upper_bound(begin(A), begin(A) + maxIndex + 1, target) - begin(A);
  }
};
