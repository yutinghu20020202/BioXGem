print("Please input string #1")
string1 = input()
print("Please input string #2")
string2 = input()
label = True
for i in range(len(string2)):
    for j in range(len(string1)):
        if string1[i] == string2[i]:
            label = True
        elif string1[j] == string2[i]:
            label = True
        else:
            label = False
if label == False:
    print("No")
else :
    print("Yes")