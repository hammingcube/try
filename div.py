# First implementation
def divide(n, d):
	q = 0
	while q*d < n:
		q += 1
	r = n - q*d
	print (q, r)

divide(10,5)
