# Solutions
1.
```
SELECT (First_name + " " + Last_name) AS "Employee Name" FROM Employee;
```
2.
```
SELECT * FROM Employee ORDER BY First_name ASC, Salary DESC;
```
3.
```
SELECT Department, SUM(Salary) FROM Employee GROUP BY Department;
```
4.
```
SELECT * FROM (SELECT Department, SUM(Salary) AS total_salary FROM Employee GROUP BY Department) AS T1 WHERE T1.total_salary > 150000; 
```
5.
```
SELECT T1.First_name, T2.Incentive_date, T2.Incentive_amount FROM Employee AS T1 JOIN Incentives AS T2 ON T1.Employee_Id = T2.Employee_ref_Id;
```
6.
```
SELECT T1.First_name, T2.Incentive_date, T2.Incentive_amount FROM Employee AS T1 LEFT JOIN Incentives AS T2 ON T1.Employee_Id = T2.Employee_ref_Id;
```
