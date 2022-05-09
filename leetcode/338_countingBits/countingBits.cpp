class Solution {
public:
    vector<int> countBits(int n) {
      vector<int> bit_r;
      /*for (int i = 0; i <= n; i++) {
          bit_r.push_back(__builtin_popcount(i));
      }*/
      bit_r.push_back(0);  // for num=0
      if (n == 0) return bit_r;
      for (int i = 1; i <= n; i++) {
          if (i%2 == 0)
            bit_r.push_back(bit_r[i/2]);
          else
            bit_r.push_back(bit_r[i-1]+1);
      }
      return bit_r;
    }
};
