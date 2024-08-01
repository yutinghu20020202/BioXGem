import random

# 4位数
answer = random.sample(range(1, 10), 4)
print(answer)

a = b = x = 0 

while a != 4:
    a = b = 0  # 重置 a 和 b
    print('Please input four digits (1~9):')
    user_input = input()
    
    user = [int(digit) for digit in user_input] #不只要變成int，還要把它用成陣列，所以不可以再上勉直接打user_input = int(input())
    
    for i in range(4): #把四個數字依序丟到i裡
        if user[i] == answer[i]:
            a += 1
        elif user[i] in answer:
            b += 1

    print(f'The result is: {a}A {b}B')
    x += 1

print(f"You got it!! {x} times!!")