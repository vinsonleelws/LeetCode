93. Restore IP Addresses


             // preæŒ‡Oš¸|a /D%¤å¸¦Oš¸|a /D%¤åOš¸|a /D%¤çš„Oš¸|a /D%¤å‰Oš¸|a /D%¤ç»“Oš¸|ç¬¬Oš¸|a /D%¤å¾…Oš¸|a /D%¤ç»“Oš¸|a /D%¤
ã€Oš¸|a /D%¤ã€Oš¸|a /D// 93, front æŒ‡Oš¸|a /Dè®°Oš¸|a /D%¤ä¸ŠOš¸|a /D%¤cï¼ŒOš¸|a /D%ï¼ŒOš¸|a /D%, lastè¡¨Oš¸|a /D%¤åOš¸|a /D%¤åOš¸|a /D%¤çš„Oš¸|a /D%¤æœ€Oš¸|a /D%¤ä¸€Oš¸|a /D%¤èŠ‚Oš¸|a /D%¤ï¼ŒOš¸|a /Dç»“Oš¸|a /D%¤ï¼ˆOš¸|a /D%¤ï¼‰Oš¸|a /D%ä¹ŸOš¸|a /D%¤å³Oš¸|a /D%¤ç¬¬Oš¸|a /D%¤å¾…Oš¸|a /D%
ã€Oš¸|a /D%¤ã€Oš¸|a /D// Runtime beats 100% of cpp submissions.¤åOš¸|a /D%¤ç»“Oš¸|a /D%¤¤estore IP Addresses /D%¤Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

    The number of elements initialized in nums1 and nums2 are m and n respectively.
    You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.

Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]

// é¿å…ä½¿ç”¨è¾…åŠ©æ•°ç»„æˆ–æ’å…¥æ‰°åŠ¨çš„æ–¹æ³•ï¼š
// æ€è·¯ï¼šç”±äºåˆå¹¶åAæ•°ç»„çš„å¤§å°å¿…å®šæ˜¯m+nï¼Œæ‰€ä»¥ä»æœ€åé¢å¼€å§‹å¾€å‰èµ‹å€¼ï¼Œå…ˆæ¯”è¾ƒAå’ŒBä¸­æœ€åä¸€ä¸ªå…ƒç´ çš„å¤§å°ï¼Œ
// æŠŠè¾ƒå¤§çš„é‚£ä¸ªæ’å…¥åˆ°m+n-1çš„ä½ç½®ä¸Šï¼Œå†ä¾æ¬¡å‘å‰æ¨ã€‚å¦‚æœAä¸­æ‰€æœ‰çš„å…ƒç´ éƒ½æ¯”Bå°ï¼Œé‚£ä¹ˆå‰mä¸ªè¿˜æ˜¯AåŸæ¥çš„å†…å®¹ï¼Œæ²¡æœ‰æ”¹å˜ã€‚
// å¦‚æœAä¸­çš„æ•°ç»„æ¯”Bå¤§çš„ï¼Œå½“Aå¾ªç¯å®Œäº†ï¼ŒBä¸­è¿˜æœ‰å…ƒç´ æ²¡åŠ å…¥Aï¼Œç›´æ¥ç”¨ä¸ªå¾ªç¯æŠŠBä¸­æ‰€æœ‰çš„å…ƒç´ è¦†ç›–åˆ°Aå‰©ä¸‹çš„ä½ç½®ã€‚

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int end = m+n-1;
        int i = m-1, j= n-1;
        
        while(i>=0 && j>=0)
            nums1[end--] = nums1[i] >= nums2[j] ? nums1[i--] : nums2[j--];
        
        while(j>=0)
            nums1[end--] = nums2[j--];
    }
};

// Testing cases:
// [4,0,0,0,0,0]
// 1
// [1,2,3,5,6]
// 5
// Expected: [1,2,3,4,5,6]