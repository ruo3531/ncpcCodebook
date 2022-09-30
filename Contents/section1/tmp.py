sorted((4,1,9,6),reverse=True)
fruits = ['apple', 'watermelon', 'pear', 'banana']
a = sorted(fruits, key = lambda x : len(x))
print(a)
# 輸出：['pear', 'apple', 'banana', 'watermelon']
divmod(a,b)
把除數和餘數運算結果結合起來，
返回一個包含商和餘數的元組(a // b, a % b)

pow(base, exp[, mod])
>>> pow(38, -1, mod=97)
23
>>> 23 * 38 % 97 == 1
True

eof 寫法
try:
	while True:
		s = input()
except EOFError:
	pass

eval(expression, globals=None, locals=None)


list(map(int, input().split()))
 L.append(r)
my_list = ['This' , 'is' , 'a' , 'string' , 'in' , 'Python']
my_string = " ".join(my_list)
#This is a string in Python
test = [[0 for j in range(m)] for i in range(n)]