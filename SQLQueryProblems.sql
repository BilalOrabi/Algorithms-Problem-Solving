----------------------------------------------------------------
--Problem (5)
----------------------------------------------------------------
select Makes.Make , COUNT(*) as NumberOfVehicles 
from VehicleDetails inner join Makes
On VehicleDetails.MakeID = Makes.MakeID
where (VehicleDetails.Year between 1950 and 2000) 
Group by Makes.Make 
Having COUNT(*) > 12000
Order by NumberOfVehicles desc
----------------------------------------------------------------
--Problem (5) Another way
----------------------------------------------------------------
select * from
(
   select Makes.Make , COUNT(*) as NumberOfVehicles 
   from VehicleDetails inner join Makes
   On VehicleDetails.MakeID = Makes.MakeID
   where (VehicleDetails.Year between 1950 and 2000) 
   Group by Makes.Make 
  
)R1
where NumberOfVehicles >12000
----------------------------------------------------------------
--Problem (6)
----------------------------------------------------------------
Select Makes.Make , COUNT(*) as NumberOfVehicles , (Select COUNT(*) from VehicleDetails) as TotalVehicles
from VehicleDetails inner join Makes
ON VehicleDetails.MakeID = Makes.MakeID
where VehicleDetails.Year between 1950 and 2000
Group by Makes.Make
Order by NumberOfVehicles desc
----------------------------------------------------------------
--Problem (7)
----------------------------------------------------------------
select *,CAST(NumberOfVehicles as float)/CAST(TotalVehicles as float) as Prec 

  from
 (
     Select Makes.Make , COUNT(*) as NumberOfVehicles , (Select COUNT(*) from VehicleDetails) as TotalVehicles 
     from VehicleDetails inner join Makes
     ON VehicleDetails.MakeID = Makes.MakeID
     where VehicleDetails.Year between 1950 and 2000
     Group by Makes.Make

 )R1
  order by NumberOfVehicles desc
----------------------------------------------------------------
--Problem (8)
----------------------------------------------------------------
Select Makes.Make , FuelTypes.FuelTypeName ,COUNT(*) as NumberOfVehicles
 from Makes inner join VehicleDetails 
 On  VehicleDetails.MakeID = Makes.MakeID 
 inner join FuelTypes 
 On VehicleDetails.MakeID = FuelTypes.FuelTypeID
 Group By Makes.Make , FuelTypes.FuelTypeName
 Order by Makes.Make
----------------------------------------------------------------
--Problem (9)
----------------------------------------------------------------
Select VehicleDetails.*, FuelTypes.FuelTypeName
from VehicleDetails inner join FuelTypes
On VehicleDetails.FuelTypeID = FuelTypes.FuelTypeID
where (FuelTypes.FuelTypeName = N'GAS')
----------------------------------------------------------------
--Problem (10)
----------------------------------------------------------------
Select distinct Makes.Make , FuelTypes.FuelTypeName 
from VehicleDetails inner join Makes 
On VehicleDetails.MakeID = Makes.MakeID 
inner join FuelTypes ON VehicleDetails.FuelTypeID = FuelTypes.FuelTypeID
WHERE (FuelTypeName = N'GAS')
----------------------------------------------------------------
--Problem (11)
----------------------------------------------------------------
Select COUNT(*) as TotalMakesRunsOnGas
from(
  Select distinct Makes.Make , FuelTypes.FuelTypeName 
  from VehicleDetails inner join Makes 
  On VehicleDetails.MakeID = Makes.MakeID 
  inner join FuelTypes ON VehicleDetails.FuelTypeID = FuelTypes.FuelTypeID
  WHERE (FuelTypeName = N'GAS') 
) R1
----------------------------------------------------------------
--Problem (12)
----------------------------------------------------------------
select *
from
(
   select Makes.Make , COUNT(*) as NumberOfVehicles 
   from VehicleDetails inner join Makes
   On VehicleDetails.MakeID = Makes.MakeID 
   Group by Makes.Make 
  
)R1
order by NumberOfVehicles desc
----------------------------------------------------------------
--Problem (13)
----------------------------------------------------------------
select Makes.Make , COUNT(*) as NumberOfVehicles 
from VehicleDetails inner join Makes
On VehicleDetails.MakeID = Makes.MakeID
Group by Makes.Make 
having Count(*) > 20000
Order by NumberOfVehicles desc
----------------------------------------------------------------
--Problem (14)
----------------------------------------------------------------
Select * from Makes
where Makes.Make like 'B%'
----------------------------------------------------------------
--Problem (15)
----------------------------------------------------------------
Select * from Makes
where Makes.Make like '%W'
----------------------------------------------------------------
--Problem (16)
----------------------------------------------------------------
Select distinct Makes.Make, DriveTypes.DriveTypeName 
from VehicleDetails inner join Makes ON Makes.MakeID = VehicleDetails.MakeID
inner join DriveTypes ON VehicleDetails.DriveTypeID = DriveTypes.DriveTypeID
Where DriveTypes.DriveTypeName = 'FWD' 
----------------------------------------------------------------
--Problem (17)
----------------------------------------------------------------
Select COUNT(*) as MakeWithFWD
from(
  Select distinct Makes.Make, DriveTypes.DriveTypeName 
  from VehicleDetails inner join Makes ON Makes.MakeID = VehicleDetails.MakeID
  inner join DriveTypes ON VehicleDetails.DriveTypeID = DriveTypes.DriveTypeID
  Where DriveTypes.DriveTypeName = 'FWD'
) R1
----------------------------------------------------------------
--Problem (18)
----------------------------------------------------------------
Select distinct Makes.Make, DriveTypes.DriveTypeName , Count(*) as Total
from VehicleDetails inner join Makes ON Makes.MakeID = VehicleDetails.MakeID
inner join DriveTypes ON VehicleDetails.DriveTypeID = DriveTypes.DriveTypeID
Group By Makes.Make, DriveTypes.DriveTypeName
Order By Make ASC, Total Desc
----------------------------------------------------------------
--Problem (19)
----------------------------------------------------------------
Select distinct Makes.Make, DriveTypes.DriveTypeName , Count(*) as Total
from VehicleDetails inner join Makes ON Makes.MakeID = VehicleDetails.MakeID
inner join DriveTypes ON VehicleDetails.DriveTypeID = DriveTypes.DriveTypeID
Group By Makes.Make, DriveTypes.DriveTypeName
Having COUNT(*) > 10000
Order By Make ASC, Total Desc
----------------------------------------------------------------
--Problem (20)
----------------------------------------------------------------
select * from VehicleDetails
where NumDoors is Null
----------------------------------------------------------------
--Problem (21)
----------------------------------------------------------------
select count(*) as TotalWithNoSpecifiedDoors from VehicleDetails
where NumDoors is Null
----------------------------------------------------------------
--Problem (22)
----------------------------------------------------------------
Select 
  (
    CAST( (select count(*) as TotalWithNoSpecifiedDoors from VehicleDetails
      where NumDoors is Null) as float)

	  /

	  CAST((Select Count(*) from VehicleDetails as TotalVehicles) as float)

   ) as PercOfNoSpecifiedDoors
----------------------------------------------------------------
--Problem (23)
----------------------------------------------------------------
Select distinct Makes.MakeID,Makes.Make,SubModels.SubModelName 
from VehicleDetails inner join Makes On VehicleDetails.MakeID=Makes. MakeID
inner join SubModels On VehicleDetails.SubModelID = SubModels.SubModelID
where SubModelName = 'Elite'
----------------------------------------------------------------
--Problem (24)
----------------------------------------------------------------
select * from VehicleDetails
where Engine_Liter_Display > 3 and NumDoors = 2
----------------------------------------------------------------
--Problem (25)
----------------------------------------------------------------
SELECT Makes.Make, VehicleDetails.*
FROM VehicleDetails INNER JOIN Makes ON VehicleDetails.MakeID = Makes.MakeID
WHERE (VehicleDetails.Engine LIKE '%OHV%') AND (VehicleDetails.Engine_Cylinders = 4)
----------------------------------------------------------------
--Problem (26)
----------------------------------------------------------------
select BodyName , VehicleDetails.* 
from VehicleDetails inner join Bodies ON Bodies.BodyID = VehicleDetails.BodyID
where (BodyName = 'Sport Utility') and (VehicleDetails.Year > 2020)
----------------------------------------------------------------
--Problem (27)
----------------------------------------------------------------
select BodyName , VehicleDetails.*
from VehicleDetails inner join Bodies ON Bodies.BodyID = VehicleDetails.BodyID
where BodyName in ('Coupe','Hatchback','Sedan')
----------------------------------------------------------------
--Problem (28)
----------------------------------------------------------------
select BodyName , VehicleDetails.*
from VehicleDetails inner join Bodies ON Bodies.BodyID = VehicleDetails.BodyID
where BodyName in ('Coupe','Hatchback','Sedan') and Year in (2008, 2020 ,2021)
----------------------------------------------------------------
--Problem (29)
----------------------------------------------------------------
Select found = 1
where exists
 (
   Select top 1 * from VehicleDetails
   where Year = 1950
 )
 ----------------------------------------------------------------
--Problem (30)
-----------------------------------------------------------------
select Vehicle_Display_Name ,NumDoors, 
CASE
     When NumDoors = 0 Then 'Zero Doors'
     When NumDoors = 1 Then 'One Doors'
     When NumDoors = 2 Then 'Two Doors'
	 When NumDoors = 3 Then 'Three Doors'
	 When NumDoors = 4 Then 'Four Doors'
	 When NumDoors = 5 Then 'Five Doors'
	 When NumDoors = 6 Then 'Six Doors'
	 When NumDoors = 8 Then 'Eight Doors'
	 When NumDoors  is Null Then 'Not Set'
	 ELSE 'UNKNOWN'
End as  DoorDescription
from VehicleDetails
----------------------------------------------------------------
--Problem (31)
----------------------------------------------------------------
select Vehicle_Display_Name , VehicleDetails.Year ,CarAge = (YEAR(GETDATE()) - VehicleDetails.Year)
from VehicleDetails
Order by CarAge desc
----------------------------------------------------------------
--Problem (32)
----------------------------------------------------------------
select Vehicle_Display_Name , VehicleDetails.Year ,CarAge = (YEAR(GETDATE()) - VehicleDetails.Year)
from VehicleDetails
where (YEAR(GETDATE()) - VehicleDetails.Year)  between 15 and 25
----------------------------------------------------------------
--2nd Method
----------------------------------------------------------------
select * from
( 
	Select VehicleDetails.Vehicle_Display_Name, Year, CarAge= YEAR(GetDate()) - VehicleDetails.year
	from VehicleDetails
) R1

Where CarAge between 15 and 25
----------------------------------------------------------------
--Problem (33)
----------------------------------------------------------------
Select MIN(Engine_CC) as MinimumEngineCC, MAX(Engine_CC) as MaximumEngineCC , AVG(Engine_CC) as AverageEngineCC
from VehicleDetails
----------------------------------------------------------------
--Problem (34)
----------------------------------------------------------------
Select VehicleDetails.Vehicle_Display_Name From VehicleDetails
where Engine_CC = (Select MIN(Engine_CC) as MinimumEngineCC from VehicleDetails )
----------------------------------------------------------------
--Problem (35)
----------------------------------------------------------------
Select VehicleDetails.Vehicle_Display_Name From VehicleDetails
where Engine_CC = (Select MAX(Engine_CC) as MaximumEngineCC from VehicleDetails )
----------------------------------------------------------------
--Problem (36)
----------------------------------------------------------------
Select VehicleDetails.Vehicle_Display_Name From VehicleDetails
where Engine_CC < (Select AVG(Engine_CC) as AverageEngineCC from VehicleDetails)
----------------------------------------------------------------
--Problem (37)
----------------------------------------------------------------
Select Count(Vehicle_Display_Name) as TotalVehincleBelowAvg From VehicleDetails
where Engine_CC  > (Select AVG(Engine_CC) as AverageEngineCC from VehicleDetails)
----------------------------------------------------------------
-- Method (2)
----------------------------------------------------------------
select Count(*) as NumberOfVehiclesAboveAverageEngineCC from
(
 
	Select ID,VehicleDetails.Vehicle_Display_Name from VehicleDetails
	where Engine_CC > ( select  Avg(Engine_CC) as MinEngineCC  from VehicleDetails )

) R1
----------------------------------------------------------------
--Problem (38)
----------------------------------------------------------------
Select distinct Engine_CC from VehicleDetails
Order by Engine_CC Desc
----------------------------------------------------------------
--Problem (39)
----------------------------------------------------------------
Select distinct top 3  Engine_CC from VehicleDetails
Order by Engine_CC Desc
----------------------------------------------------------------
--Problem (40)
----------------------------------------------------------------
Select VehicleDetails.Vehicle_Display_Name from VehicleDetails
where Engine_CC in
( 
     Select distinct top 3  Engine_CC as MaxEngineCC
	 from VehicleDetails
     Order by Engine_CC Desc
)
----------------------------------------------------------------
--Problem (41)
----------------------------------------------------------------
Select distinct Makes.Make 
from VehicleDetails inner join Makes on VehicleDetails.MakeID = Makes.MakeID
where Engine_CC in
( 
     Select distinct top 3  Engine_CC as MaxEngineCC
	 from VehicleDetails
     Order by Engine_CC Desc
)
Order By Make
----------------------------------------------------------------
--Problem (42)
----------------------------------------------------------------
select Engine_CC,

	CASE
		 WHEN Engine_CC between 0 and 1000 THEN 100
		 WHEN Engine_CC between 1001 and 2000 THEN 200
		 WHEN Engine_CC between 2001 and 4000 THEN 300
		 WHEN Engine_CC between 4001 and 6000 THEN 400
		 WHEN Engine_CC between 6001 and 8000 THEN 500
		 WHEN Engine_CC > 8000 THEN 600	
		 ELSE 0

	END as Tax
	from 
	(
	   Select distinct Engine_CC
	   from VehicleDetails
	)R1
	Order BY Engine_CC
----------------------------------------------------------------
--Problem (43)
----------------------------------------------------------------
Select Makes.Make ,SUM(NumDoors) as TotalNumberOfDoors
from VehicleDetails inner join Makes On VehicleDetails.MakeID = Makes.MakeID
Group by Makes.Make
Order by TotalNumberOfDoors DESC
----------------------------------------------------------------
--Problem (44)
----------------------------------------------------------------
Select Makes.Make ,SUM(NumDoors) as TotalNumberOfDoors
from VehicleDetails inner join Makes On VehicleDetails.MakeID = Makes.MakeID
Group by Makes.Make
having Makes.Make = 'FORD'
----------------------------------------------------------------
--Problem (45)
----------------------------------------------------------------
SELECT Makes.Make, COUNT(*) AS NumberOfModels
FROM Makes INNER JOIN MakeModels ON Makes.MakeID = MakeModels.MakeID
GROUP BY Makes.Make
Order By NumberOfModels Desc
----------------------------------------------------------------
--Problem (46)
----------------------------------------------------------------
SELECT top 3 Makes.Make, COUNT(*) AS NumberOfModels
FROM Makes INNER JOIN MakeModels ON Makes.MakeID = MakeModels.MakeID
GROUP BY Makes.Make
Order By NumberOfModels Desc
----------------------------------------------------------------
--Problem (47)
----------------------------------------------------------------
select Max(NumberOfModels) as MaxNumberOfModels
from
(

	SELECT Makes.Make, COUNT(*) AS NumberOfModels
	FROM Makes INNER JOIN MakeModels ON Makes.MakeID = MakeModels.MakeID
	GROUP BY Makes.Make
		
) R1
----------------------------------------------------------------
--Problem (48)
----------------------------------------------------------------
-- Get the highest Manufacturers manufactured the highest number of models , 
-- remember that they could be more than one manufacturer have the same high number of models
SELECT Makes.Make, COUNT(*) AS NumberOfModels
FROM Makes INNER JOIN MakeModels ON Makes.MakeID = MakeModels.MakeID
GROUP BY Makes.Make
having COUNT(*) = (
					select Max(NumberOfModels) as MaxNumberOfModels
							from
							(

									SELECT MakeID, COUNT(*) AS NumberOfModels
										FROM MakeModels
										GROUP BY MakeID
												
							) R1

					)
----------------------------------------------------------------
--Problem (49)
----------------------------------------------------------------
-- Get the Lowest  Manufacturers manufactured the lowest number of models , 
-- remember that they could be more than one manufacturer have the same Lowest  number of models
SELECT Makes.Make, COUNT(*) AS NumberOfModels
FROM Makes INNER JOIN MakeModels ON Makes.MakeID = MakeModels.MakeID
GROUP BY Makes.Make
having COUNT(*) = (
					select Min(NumberOfModels) as MinNumberOfModels
							from
							(

									SELECT MakeID, COUNT(*) AS NumberOfModels
										FROM MakeModels
										GROUP BY MakeID
												
							) R1

					)
----------------------------------------------------------------
--Problem (50)
----------------------------------------------------------------
select * from FuelTypes
order by NewID()
----------------------------------------------------------------
--                          FIN :)                            --
----------------------------------------------------------------

