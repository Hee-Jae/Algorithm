def main():
	tmp = 0
	l = int(input())
	bs = []
	p = input().split()
	for i in range(l):
		bs.append( int(p[i]) )

	for i in range(l):
		cmp2 = [0 for i in range(l)]

		for j in range(l):
			cmp2[j] =  bs[j] - bs[i]
		tmp1 = going(cmp2[i+1:])
		if(tmp <= tmp1 ):
			tmp = tmp1
	return tmp+1
		# if(searchminus(cmp2[i+1:])):
		# 	print(going(cmp2[i+1:]))
		# 	return 0
def going(arg):
	uplen = 0
	up = 0
	for i in arg:
		if( 0 < i ):
			uplen+=1
		up = uplen
	return int(up)
	
print(main())