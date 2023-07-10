class Solution:
    def longestSubstring(self, s, k):
        if len(s) < k:
            return 0
        
        count = {}
        for char in s:
            count[char] = count.get(char, 0) + 1
        
        for char, freq in count.items():
            if freq < k:
                substrings = s.split(char)
                return max(self.longestSubstring(substring, k) for substring in substrings)
        
        return len(s)
