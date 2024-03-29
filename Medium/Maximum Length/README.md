<h2><a href="https://practice.geeksforgeeks.org/problems/84963d7b5b84aa24f7807d86e672d0f97f41a4b5/1">Maximum Length</a></h2><h3>Difficulty Level : Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000">Given the maximum occurrences of a, b, and c in a string. Your task is to make the string containing only a, b, and c such that no three consecutive characters are the same.</span></span></span></p>

<p><strong><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000">Example 1:</span></span></span></strong></p>

<pre style="position: relative;"><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000"><strong>Input</strong></span></span></span><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000">:</span></span></span><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000">
a = 3, b = 3, c = 3</span></span></span><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000"><strong>
Output:</strong></span></span></span><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000"> </span></span></span><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000">
9</span></span></span><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000"><strong>
Explanation</strong></span></span></span><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000">: </span></span></span><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000">
No three consecutive character of</span></span></span><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000">
the string "abcabcabc" is same.</span></span></span><div class="open_grepper_editor" title="Edit &amp; Save To Grepper"></div></pre>

<p><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000"><strong>Example 2:</strong></span></span></span></p>

<pre style="position: relative;"><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000"><strong>Input:</strong></span></span></span><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000">
a = 11, b = 2, c = 2</span></span></span><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000"><strong>
Output: </strong></span></span></span><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000">
-1</span></span></span><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000"><strong>
Explanation</strong></span></span></span><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000">: </span></span></span><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000">
If we build a string of these character's,</span></span></span><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000">
the string will be"aabaacaabaac<u><strong>aaa</strong></u>", here
we can see that there will be three consecutive <strong>a</strong>. So
there </span></span></span><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000">is no solution exist.</span></span></span><div class="open_grepper_editor" title="Edit &amp; Save To Grepper"></div></pre>

<p><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000"><strong>Your Task:&nbsp;&nbsp;</strong></span></span></span><br>
<span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000">You don't need to read input or print anything. Your task is to complete the function </span></span></span><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000"><strong>solve( )</strong></span></span></span><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000"> which takes </span></span></span><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000"><strong>integers a, b, and c</strong></span></span></span><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000"> as input parameters and <strong>returns </strong>the <strong>string length</strong>. If there is no possible answer return -1.</span></span></span></p>

<p><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000"><strong>Expected Time Complexity:</strong></span></span></span><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000"> O(a+b+c)</span></span></span><br>
<span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000"><strong>Expected Auxiliary Space:</strong></span></span></span><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000"> O(1)</span></span></span></p>

<p><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000"><strong>Constraints:</strong></span></span></span><br>
<span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000">0 ≤ a, b, c ≤ 10</span></span></span><span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000"><sup>5</sup></span></span></span><br>
<span style="font-size:13.5pt"><span style="font-family:Arial"><span style="color:#000000">0 &lt; (a + b + c)&nbsp;</span></span></span></p>
</div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Strings</code>&nbsp;<code>Data Structures</code>&nbsp;