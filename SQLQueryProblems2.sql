----------------------------------------------------------------
--Problem (51)
----------------------------------------------------------------
Select Employees.Name, Employees.ManagerID, Employees.Salary, Managers.Name as ManagerName
from Employees inner join Employees as Managers On Employees.ManagerID = Managers.EmployeeID
----------------------------------------------------------------
--Problem (52)
----------------------------------------------------------------
SELECT Employees.Name, Employees.ManagerID, Employees.Salary, Managers.Name AS ManagerName
FROM Employees Left JOIN Employees AS Managers ON Employees.ManagerID = Managers.EmployeeID
----------------------------------------------------------------
--Problem (53)
----------------------------------------------------------------
Select Employees.Name, Employees.ManagerID ,Employees.Salary , 
CASE
     when Managers.Name is null then Employees.Name
	 else Managers.Name
END  as ManagerName
from Employees left join Employees as Managers ON Employees.ManagerID = Managers.EmployeeID
----------------------------------------------------------------
--Problem (54)
----------------------------------------------------------------
SELECT Employees.Name, Employees.ManagerID, Employees.Salary, Managers.Name AS ManagerName
FROM Employees INNER JOIN Employees AS Managers ON Employees.ManagerID = Managers.EmployeeID
where Managers.Name='Mohammed'