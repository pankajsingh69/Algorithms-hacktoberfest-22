// NON DECREASING ARRAY 
// 1.https://leetcode.com/problems/non-decreasing-array/description/   ->  LEETCODE
2. https://www.codingninjas.com/codestudio/problems/non-decreasing-array_699920 -> CODESTUDIO  

import java.util.* ;
import java.io.*; 
public class Solution {
	public static boolean isPossible(int[] arr, int n) {
			int count = 0;
			for(int i = 1; i<n; i++){
				if(arr[i] < arr[i-1]){
					count++; 
					// since previous element is smaller so modify 
					if(i-2 < 0 || arr[i-2] <= arr[i]){
						arr[i-1] = arr[i];
					}else{
						arr[i] = arr[i-1];
					}
		}
	}
	return count<=1;
	}
}
