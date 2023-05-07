a=int(input("Enter Jug A capacity :"))
b=int(input("Enter Jug B capacity :"))

ai=int(input("Initial State in Jug A :"))
bi=int(input("Initial State in Jug B :"))

af=int(input("Final State in Jug A :"))
bf=int(input("Final State in Jug B :"))

print("1.Fill Jug A")
print("2.Fill Jug B")
print("3.Pour some water out of Jug A ")
print("4.Pour some water out of Jug B ")
print("5.Empty 4 Gallons on ground ")
print("6.Empty 3 Gallons on ground ")
print("7.Pour from 3 Gallons to 4 Gallons until 4 Gallons is Full ")
print("8.Pour from 4 Gallons to 3 Gallons until 3 Gallons is Full ")
print("9.Pour all water from Jug 3 into Jug 4 ")
print("10.Pour all water from Jug 4 into Jug 3 ")
print("11.Pour 2 Gallons from 3 Gallons jug into 4 Gallons Jug")
print("12.Pour 2 Gallons from 4 Gallons jug into 3 Gallons Jug")

while ai != af or bi != bf:
	op=int(input("Enter a Valid Option: "))
	if op == 1:
		ai=a
	elif op == 2:
		bi=b
	elif op == 3:
		ai=ai-1
	elif op == 4:
		bi=bi-1
	elif op == 5:
		ai=0
	elif op == 6:
		bi=0
	elif op == 7:
		while ai != af:
			bi=bi-1
			ai=ai+1
	elif op == 8:
		while bi != bf:
			ai=ai-1
			bi=bi+1
	elif op == 9:
		while ai != af:
			bi=bi-1
			ai=ai+1
		if bi != 0:
			bi=0
	elif op == 10:
		while bi != bf:
			ai=ai-1
			bi=bi+1
		if ai != 0:
			ai=1
	elif op == 11:
		bi=bi-2
		ai=ai+2
	elif op == 12:
		ai=ai-2
		bi=bi+2
	print(ai,bi)





