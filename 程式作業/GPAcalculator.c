#include<stdio.h>

double GPA(int credit, char grade, char sign){ //學分、級距、符號
    float score;
    if (grade == 'A'){
        score = 4.0;
        if (sign == '+'){
            score += 0.3;
        }else if(sign == '-'){
            score -= 0.3;
        }
    }
    if (grade == 'B'){
        score = 3.0;
        if (sign == '+'){
            score += 0.3;
        }else if(sign == '-'){
            score -= 0.3;
        }
    }
    if (grade == 'C'){
        score = 2.0;
        if (sign == '+'){
            score += 0.3;
        }else if(sign == '-'){
            score -= 0.3;
        }
    }
    if (grade == 'F'){
        score = 0.0;
    }
    return (credit * score);
}

int main () {
    int index=0;
    char grade, sign;
    char arr[50];
    float credit, output = 0;
    float realGpa;
    float totalCredit=0;

    scanf("%s", arr);

    while(arr[index]!='\0'){
        credit = arr[index] - '0';//把字串送進arr的方法（考試記起來喔）
        index++;
        grade = arr[index];
        index++;
        
        sign = '\0';//為了解決sign可能是空值，給他一個空白，然後位置index不要跳。
        //如果sign是int就設0，如果是char string就設'\0'來補空缺值（再不記起來會被當掉）
        // if (sign=='+'||sign=='-'){
        //     sign = arr[index];
        //     index++;
        // }

        if (arr[index]=='+'||arr[index]=='-'){
            sign = arr[index];
            index++;
        }
        output += GPA(credit, grade, sign);
        totalCredit += credit;
    } 
    
    realGpa = output/totalCredit;

    printf("%.2f\n", realGpa);

    return 0;
}
