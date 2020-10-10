# 474-Project-1
Project 1: Lamport's Logical Clocks

Group members:

Michael Burdi   maburdi@csu.fullerton.edu



3 test cases for algorithm calculate

Input 1
{ "a", "s1", "r3", "b"},
{ "c", "r2", "s3", "" },
{ "r1", "d", "s2", "e" }

Input 2
{ "s1", "b", "r3", "e"},
{ "a", "r2", "s3", "" },
{ "r1", "c", "d", "s2" }

Input 3
{ "r1", "b", "r2", "s3"},
{ "a", "s1", "d", "" },
{ "s2", "c", "r3", "" }


2 test cases for algorithm verify

Input 1
{1, 2, 8, 9},
{1, 6, 7, 0},
{3, 4, 5, 6}

Input 2
{1, 2, 8, 9},
{1, 6, 7, 0},
{2, 4, 5, 6}
