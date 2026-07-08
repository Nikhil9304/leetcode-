1class Solution {
2public:
3    const int M = 1e9 + 7;
4    typedef long long ll;
5
6    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
7        int n = s.size();
8
9        vector<int> nonZeroCount(n, 0);   // count of non-zero digits up to index i
10        vector<ll> numUpto(n, 0);         // value formed by non-zero digits up to i, mod M
11        vector<ll> prefixsum(n, 0);       // sum of digits up to index i (zeros add 0 anyway)
12        vector<ll> pow10(n + 1, 0);       // pow10[k] = 10^k mod M
13
14        // precompute powers of 10 mod M
15        pow10[0] = 1;
16        for (int i = 1; i <= n; i++)
17            pow10[i] = (pow10[i - 1] * 10) % M;
18
19        // non-zero digit prefix count
20        nonZeroCount[0] = (s[0] != '0') ? 1 : 0;
21        for (int i = 1; i < n; i++) {
22            int digit = s[i] - '0';                          // fixed: was s[0]
23            nonZeroCount[i] = nonZeroCount[i - 1] + (digit != 0 ? 1 : 0);
24        }
25
26        // build number using ONLY non-zero digits, skip zeros (don't shift on zero)
27        numUpto[0] = s[0] - '0';                              // if s[0]=='0' this is 0, fine
28        for (int i = 1; i < n; i++) {                         // fixed: loop starts at 1, not 0
29            int num = s[i] - '0';
30            if (num != 0)
31                numUpto[i] = (numUpto[i - 1] * 10 + num) % M; // append non-zero digit
32            else
33                numUpto[i] = numUpto[i - 1];                  // skip zero, carry forward
34        }
35
36        // digit sum prefix (zeros contribute 0, so this equals sum of non-zero digits too)
37        prefixsum[0] = s[0] - '0';
38        for (int i = 1; i < n; i++)
39            prefixsum[i] = prefixsum[i - 1] + (s[i] - '0');
40
41        vector<int> ans;
42        for (auto& q : queries) {
43            int l = q[0], r = q[1];
44
45            // sum of digits in [l, r]
46            ll sum = prefixsum[r] - (l == 0 ? 0 : prefixsum[l - 1]);
47
48            // value built from non-zero digits before index l (needs shifting off)
49            ll beforeL = (l == 0 ? 0 : numUpto[l - 1]);
50
51            // number of non-zero digits in [l, r] -> shift amount for beforeL
52            int k = nonZeroCount[r] - (l == 0 ? 0 : nonZeroCount[l - 1]);
53
54            // x = numUpto[r] with the beforeL prefix contribution removed
55            ll x = ((numUpto[r] - beforeL * pow10[k]) % M + M) % M;  // fixed: real pow, mod-safe
56
57            // answer = x * sum, mod M
58            ll result = (x * (sum % M)) % M;                          // fixed: reduce before pushing
59
60            ans.push_back((int)result);
61        }
62
63        return ans;
64    }
65};