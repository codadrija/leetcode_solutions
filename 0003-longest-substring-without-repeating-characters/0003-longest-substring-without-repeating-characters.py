class Solution(object):
    def lengthOfLongestSubstring(self, s):
        maxm = 0
        char_set = set()
        left = 0  

        for right in range(len(s)):
            while s[right] in char_set:
                char_set.remove(s[left])  
                left += 1  
            char_set.add(s[right])  
            maxm = max(maxm, right - left + 1) 
        
        return maxm