class Trie:
  def __init__(self):
    self.children = {}
    self.flag = False

  # def __del__(self):
  #   print(len(self.children))
  #   for i in range(26):
  #     if self.children[i]:
  #       del self.children[i]

  def insert(self, c):
    if len(c) == 0:
      self.flag = True
      return
    
    if not c[0] in self.children:
      self.children[c[0]] = Trie()
    self.children[c[0]].insert(c[1:])

  # def search(self, c, cnt):
  #   if len(c) == 0:
  #     return cnt
    
  #   index = ord(c[0]) - ord('a')

  #   if self.count > 1 or (self.count == 1 and self.flag):
  #     return self.nodes[index].search(c[1:], cnt+1)
  #   else:
  #     return self.nodes[index].search(c[1:], cnt)

temp = 0
def dfs(node, cnt):
  global temp

  if node.flag:
    temp += cnt

  if node.flag or len(node.children) > 1:
    cnt += 1

  for value in node.children.values():
    dfs(value, cnt)
  
while True:
  try:
    N = int(input())
    root = Trie()
    temp = 0
    for _ in range(N):
      s = input()
      root.insert(s)
    
    for value in root.children.values():
      dfs(value, 1)
    
    print(round(temp/N,2))
    del root

  except:
    exit()