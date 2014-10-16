dep = {}
dep['foo.js'] = ['bar.js', 'main.js']
dep['bar.js'] = ['lib.js']

dep_order = {}
count = 0

def assign_topo_order(d, v):
  global count
  if v not in d:
  	dep_order[v] = count
  	count += 1
  	return
  for k in d[v]:
  	assign_topo_order(d, k)
  dep_order[v] = count
  count += 1



assign_topo_order(dep, 'foo.js')

print dep_order
