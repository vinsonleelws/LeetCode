Write a SQL query to find all duplicate emails in a table named Person.

+----+---------+
| Id | Email   |
+----+---------+
| 1  | a@b.com |
| 2  | c@d.com |
| 3  | a@b.com |
+----+---------+

For example, your query should return the following for the above table:

+---------+
| Email   |
+---------+
| a@b.com |
+---------+

Note: All emails are in lowercase.

# Write your MySQL query statement below
这道题让我们求重复的邮箱，那么最直接的方法就是用Group by...Having Count(*)...的固定搭配来做，代码如下：

解法一：

SELECT Email FROM Person GROUP BY Email
HAVING COUNT(*) > 1;

 

我们还可以用内交来做，用Email来内交两个表，然后返回Id不同的行，则说明两个不同的人使用了相同的邮箱：

解法二：

SELECT DISTINCT p1.Email FROM Person p1
JOIN Person p2 ON p1.Email = p2.Email
WHERE p1.Id <> p2.Id;

