print("請翰入介於1~3999之間的阿拉伯數字：")
num = int(input())

if(num<1 or num>=3999):
    print("請翰入介於1~3999之間的阿拉伯數字：")

val=[1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
sym=['M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I']

romanNum=''

for i in range(len(val)):
    while num >= val[i]:
        romanNum += sym[i]
        num -= val[i]
        
print(f"轉羅馬數字為 {romanNum}")