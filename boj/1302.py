import sys
from collections import defaultdict
input = sys.stdin.readline

N = int(input())
books = defaultdict(int)
for _ in range(N):
  title = input()
  books[title] += 1

books = sorted(books.items(), key = lambda x: (-x[1], x[0]))

print(books[0][0].strip())