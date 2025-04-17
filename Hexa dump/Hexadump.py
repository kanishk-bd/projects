import sys
data = []
lindata= []
finalot =""
rawstr  =""
pair_raw = []
chardata = []
ascii_data =[]
def isHexa(a):
	ascii = ord(a)
	if((ascii>=48 and ascii<=57) or (ascii>=65 and ascii<=70) or (ascii>=97 and ascii<=102)):
		return True
	else:
		return False
file = open(sys.argv[1], 'r')
a= file.readlines()
for i in  a: 
	data.append(i[10:50])
#print(data)
for i in data :
	for j in i :
		if(j!='\n'):
			
			lindata.append(j)
for i in lindata:
	if(isHexa(i)):
		chardata.append(i)
for i in chardata:
	rawstr = rawstr + i 
for i in range(0,len(rawstr),2):
	temp = rawstr[i] + rawstr[i+1]
	pair_raw.append(temp)
#print(pair_raw)
for i in pair_raw:
	ascii_data.append(int(i, 16))
#print(ascii_data)
for i in ascii_data:
	finalot += chr(i)
print(finalot)