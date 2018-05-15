Suppose that a website contains two tables, the Customers table and the Orders table. Write a SQL query to find all customers who never order anything.

Table: Customers.

+----+-------+
| Id | Name  |
+----+-------+
| 1  | Joe   |
| 2  | Henry |
| 3  | Sam   |
| 4  | Max   |
+----+-------+

Table: Orders.

+----+------------+
| Id | CustomerId |
+----+------------+
| 1  | 3          |
| 2  | 1          |
+----+------------+

Using the above tables as example, return the following:

+-----------+
| Customers |
+-----------+
| Henry     |
| Max       |
+-----------+

# Write your MySQL query statement below

这道题让我们给了我们一个Customers表和一个Orders表，让我们找到从来没有下单的顾客，那么我们最直接的方法就是找没有在Orders表中出现的顾客Id就行了，用Not in关键字，如下所示：
解法一：

SELECT Name AS Customers FROM Customers 
WHERE Id NOT IN (SELECT CustomerId FROM Orders);

 

或者我们也可以用左交来联合两个表，只要找出右边的CustomerId为Null的顾客就是木有下单的：
解法二：

SELECT Name AS Customers FROM Customers
LEFT JOIN Orders ON Customers.Id = Orders.CustomerId
WHERE Orders.CustomerId IS NULL;

 

我们还可以用Not exists关键字来做，原理和Not in很像，参见代码如下：
解法三：

SELECT Name AS Customers FROM Customers c
WHERE NOT EXISTS (SELECT * FROM Orders o WHERE o.CustomerId = c.Id);

