def solution(phone_book):
  phone_book.sort(key = lambda x: len(x))
  phone_list = {}
  for phone in phone_book:
    for i in range(len(phone)):
      if phone[:i+1] in phone_list:
        return False
    phone_list[phone] = 0
  return True

print(solution(["119", "97674223", "1195524421"]))
print(solution(["123","456","789"]))
print(solution(["12","123","1235","567","88"]))
print(solution(["1234", "1235"]))