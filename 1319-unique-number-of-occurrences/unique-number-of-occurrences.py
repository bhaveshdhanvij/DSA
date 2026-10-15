class Solution:
    def uniqueOccurrences(self, arr: list[int]) -> bool:
        mp={}
        for num in arr:
            mp[num]=mp.get(num,0)+1
        f=list(mp.values())
        return len(f)==len(set(f))
        