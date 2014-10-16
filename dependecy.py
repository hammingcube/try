dep = {}
dep['foo.js'] = ['bar.js', 'main.js']
dep['bar.js'] = ['lib.js']

def assign_topo_order(d):
  for k, v in d.items():
    print k,v

assign_topo_order(dep)
