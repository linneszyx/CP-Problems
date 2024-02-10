<h2><a href="https://www.geeksforgeeks.org/problems/peak-element/1">Peak element</a></h2><h3>Difficulty Level : Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given an array of integers <strong>arr[] </strong>of size <strong>n</strong>, find any one of its peak elements. An element is considered to be peak if it's <strong>value is greater than or equal to the values of its adjacent elements</strong> (if they exist). The array is guaranteed to be in ascending order before the peak element and in descending order after it.</span></p>
<p><span style="font-size: 18px;"><strong>Note:</strong> The output will be&nbsp;<strong>1</strong> if the index returned by your function is correct; otherwise, it will be <strong>0</strong>.</span></p>
<p><br><strong><span style="font-size: 18px;">Example 1:</span></strong></p>
<pre><strong><span style="font-size: 18px;">Input: 
</span></strong><span style="font-size: 18px;">n = 3
arr[] = {1, 2, 3}
</span><strong><span style="font-size: 18px;">Possible Answer: </span></strong><span style="font-size: 18px;">2
<strong>Generated Output:</strong> 1
<strong>Explanation:</strong> The index returned is 2, which corresponds to the value 3. Since 3 is indeed a peak element in this array, the generated output is 1, indicating that the returned index is correct.</span>
</pre>
<p><strong><span style="font-size: 18px;">Example 2:</span></strong></p>
<pre><strong><span style="font-size: 18px;">Input:
</span></strong><span style="font-size: 18px;">n = 3
arr[] = {3, 4, 2}
</span><strong><span style="font-size: 18px;">Possible Answer: </span></strong><span style="font-size: 18px;">1
<strong>Output: </strong>1<strong>
Explanation: </strong></span><span style="font-size: 18px;">The index returned is 1, which corresponds to the value 4. Since 4 is indeed a peak element in this array, the generated output is 1, indicating that the returned index is correct.</span></pre>
<p><strong><span style="font-size: 18px;">Your Task:</span></strong><br><span style="font-size: 18px;">You don't have to read&nbsp;input or print anything. Complete the function <strong>peakElement</strong>() which takes the array <strong>arr[]</strong> and its size <strong>n</strong> as input parameters and return the index of any one of its peak elements.<br><br>Can you solve the problem in expected time complexity?</span></p>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(log n).<br><strong>Expected Auxiliary Space:</strong>&nbsp;O(1)</span></p>
<p><br><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ n ≤ 10<sup>5</sup><br>1 ≤ arr[i] ≤ 10<sup>6</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Accolite</code>&nbsp;<code>Amazon</code>&nbsp;<code>Visa</code>&nbsp;<code>Adobe</code>&nbsp;<code>Google</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Searching</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;