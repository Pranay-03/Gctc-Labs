def factorial(x):
	fact=1
	while x!=0:
		fact=fact*x
		x=x-1
	print(fact)

y=int(input("Enter a Number :"))
factorial(y)
