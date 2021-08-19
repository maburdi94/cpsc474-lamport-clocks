# 474-Project-1
Project 1: Lamport's Logical Clocks

Group members:

Michael Burdi   maburdi@csu.fullerton.edu

3 test cases for algorithm calculate

Input 1<br>
{ "a", "s1", "r3", "b"},<br>
{ "c", "r2", "s3", "" },<br>
{ "r1", "d", "s2", "e" }<br>

Input 2<br>
{ "s1", "b", "r3", "e"},<br>
{ "a", "r2", "s3", "" },<br>
{ "r1", "c", "d", "s2" }<br>

Input 3<br>
{ "r1", "b", "r2", "s3"},<br>
{ "a", "s1", "d", "" },<br>
{ "s2", "c", "r3", "" }<br>


2 test cases for algorithm verify

Input 1<br>
{1, 2, 8, 9},<br>
{1, 6, 7, 0},<br>
{3, 4, 5, 6}<br>

Input 2<br>
{1, 2, 8, 9},<br>
{1, 6, 7, 0},<br>
{2, 4, 5, 6}<br>





## Example execution
```console
CALCULATING...
1 2 8 9 
1 6 7 0 
3 4 5 6 

CALCULATING...
1 2 8 9 
1 6 7 0 
2 3 4 5 

CALCULATING...
3 4 5 6 
1 2 3 0 
1 2 7 0 

VERIFYING...
1 2 8 9 
1 6 7 0 
3 4 5 6 

a s1 r3 d 
b r2 s3  
r1 c s2 e 

VERIFYING...
1 2 8 9 
1 6 7 0 
2 4 5 6 

NO SOLUTION!
```
