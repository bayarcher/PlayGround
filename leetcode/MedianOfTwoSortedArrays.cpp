class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size() + nums2.size();
        int mid = size / 2;
        int even = (size % 2 == 0)? 1:0;
        if(even != 1) mid++;
        int cur = 0;
        vector<int>::iterator num1Itr = nums1.begin();
        vector<int>::iterator num2Itr = nums2.begin();
        if(size == 1) {
            if(nums1.size() == 0) {
                return nums2[0];
            } else return nums1[0];
        }
        while(1) {
            cur++;
               if(num1Itr != nums1.end() && num2Itr != nums2.end()) {
                   
                  if(cur == mid) {
                      double ans = 0;
                      if((*num1Itr) < (*num2Itr)) {
                          ans = *num1Itr;
                          if(even) {
                              num1Itr++;
                              if(num1Itr == nums1.end()) {
                                  ans += (*num2Itr);
                                  return ans /2;
                              } else {
                                  if((*num1Itr) < (*num2Itr)) {
                                      ans += (*num1Itr);
                                  } else {
                                      ans += (*num2Itr);
                                  }
                                  return ans /2;
                              }
                          } else return ans;
                      } else {
                          ans += (*num2Itr);
                          if(even) {
                              num2Itr++;
                              if(num2Itr == nums2.end()) {
                                  ans += (*num1Itr);
                                  return ans /2;
                              } else {
                                  if((*num1Itr) < (*num2Itr)) {
                                      ans += (*num1Itr);
                                  } else {
                                      ans += (*num2Itr);
                                  }
                                  return ans /2;
                              }
                          } else return ans;
                          
                      }
                  } else {
                    if((*num1Itr) < (*num2Itr)) {
                        num1Itr++;
                     } else {
                         num2Itr++;
                     }
                     }
                  } else {
                      // cur--;
                      int delta = mid - cur;
                      
                      if(num1Itr == nums1.end()) {
                          while(delta) {
                              num2Itr++;
                              delta--;
                          }
                          double ans = (*num2Itr);
                          if(even) {
                              num2Itr++;
                              ans += (*num2Itr);
                              return ans/2;
                          } else return ans;
                      } else {
                          while(delta){
                              num1Itr++;
                              delta--;
                          }
                          double ans = (*num1Itr);
                          if(even) {
                              num1Itr++;
                              ans += (*num1Itr);
                              return ans/2;
                          } else return ans;
                      }
               }
        
    }
    }
};
