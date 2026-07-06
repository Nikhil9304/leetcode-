1class Solution {
2public:
3    int lengthOfLastWord(string s) {
4
5        int i = s.size() - 1;
6
7        // Skip trailing spaces
8        while (i >= 0 && s[i] == ' ') {
9            i--;
10        }
11
12        int count = 0;
13
14        // Count the characters of the last word
15        while (i >= 0 && s[i] != ' ') {
16            count++;
17            i--;
18        }
19
20        return count;
21    }
22};