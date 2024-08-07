def check(idNum):
    letterMap = {'A':10,'B':11,'C':12,'D':13,'E':14,'F':15,'G':16,'H':17,'J':18,'K':19,'L':20,'M':21,'N':22,'P':23,'Q':24,'R':25,'S':26, 'T':27,'U':28,'V':29,'X':30,'Y':31, 'I':34, 'O':35, 'W':32, 'Z':33 }
    if len(idNum) != 10: #是否是十位數
        return "身分證字號錯誤！"
    if idNum[0] not in letterMap: #第一個字是否大寫字母
        return "身分證字號錯誤！" 
    for charCheck in idNum[1:]:
        if not charCheck.isdigit(): #後面九位是否是數字
            return "身分證字號錯誤！"
    A1=letterMap[idNum[0]]//10
    A2=letterMap[idNum[0]]%10
    D=[int(char) for char in idNum[1:] ]
    Y=A1+A2*9+sum(D[i]*(8-i)for i in range(9))
    checkCode=(10-Y%10)%10
    if checkCode == D[-1]:
        return "身分證字號正確！！"
    else:
        return "身分證字號錯誤！"
idNum=input() #input進來都會是字串
print(check(idNum))