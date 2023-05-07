graph={
	'5':['3','7'],
	'3':['2','4'],
	'7':['8'],
	'2':[],
	'4':['8'],
	'8':[]
}

visited=[]

def dfs(visited,graph,node):
	if node not in visited:
		print(node,end=" ")
		visited.append(node)
		for neighbour in graph[node]:
			dfs(visited,graph,neighbour)

dfs(visited,graph,'5')
