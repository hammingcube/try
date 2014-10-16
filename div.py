# First implementation
# TODO: handle d = 0
# TODO : handle neatives
# TODO : write test cases
# TODO : improve algo (maybe use binary search)

def divide(n, d):
	q = 0
	while q*d < n:
		q += 1
	r = n - q*d
	print (q, r)

divide(10,5)
