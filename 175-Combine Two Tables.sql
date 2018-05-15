Table: Person

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| PersonId    | int     |
| FirstName   | varchar |
| LastName    | varchar |
+-------------+---------+
PersonId is the primary key column for this table.

Table: Address

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| AddressId   | int     |
| PersonId    | int     |
| City        | varchar |
| State       | varchar |
+-------------+---------+
AddressId is the primary key column for this table.

 

Write a SQL query for a report that provides the following information for each person in the Person table, regardless if there is an address for each of those people:

FirstName, LastName, City, State


# Write your MySQL query statement below

// MySQL
// 这是一道两表联合查找的问题，我们需要用到Join操作，最直接的方法就是用Left Join来做，根据PersonId这项来把两个表联合起来：

解法一：

SELECT Person.FirstName, Person.LastName, Address.City, Address.State FROM Person LEFT JOIN Address ON Person.PersonId = Address.PersonId;

 

在使用Left Join时，我们也可以使用关键Using来声明我们相用哪个列名来进行联合：

 

解法二：

SELECT Person.FirstName, Person.LastName, Address.City, Address.State FROM Person LEFT JOIN Address USING(PersonId);

 

或者我们可以加上Natural关键字，这样我们就不用声明具体的列，MySQL可以自行搜索相同的列：

 

解法三：

SELECT Person.FirstName, Person.LastName, Address.City, Address.State FROM Person NATURAL LEFT JOIN Address;

