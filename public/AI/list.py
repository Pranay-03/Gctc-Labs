#Nested List
matrix=[]
for i in range(5):
	matrix.append([])
	for j in range(5):
		matrix.append(j)

print(matrix)

#length

print(len(matrix))

#Concatition
l1=[1,3,4,5]
l2=[10,11,12]

for i in l1:
	l2.append(i)
print(l1)

#membership

l1=[1,2,3,4,5]

if 4 in l1:
	print("4 is present ")
else:
	print("4 is not present ")

#iteration
mytuple = ("apple", "banana", "cherry")

for x in mytuple:
  print(x)

#slicing 
s=[10,20,20,30]
print(s[0])

del s[-1]
print(s)

s.append(10)
print(s)
